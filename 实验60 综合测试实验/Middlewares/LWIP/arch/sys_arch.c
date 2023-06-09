/**
 ****************************************************************************************************
 * @file        sys_arch.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-12-02
 * @brief       lwip-系统层接口驱动 代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 * 修改说明
 * V1.0 20221202
 * 1, 修改注释方式
 * 2, 修改u8/u16/u32为uint8_t/uint16_t/uint32_t
 ****************************************************************************************************
 */

#define SYS_ARCH_GLOBALS

/* lwIP includes. */
#include "lwip/debug.h"
#include "lwip/def.h"
#include "lwip/lwip_sys.h"
#include "lwip/mem.h"
#include "os.h"
#include "arch/sys_arch.h"


/**
 * 当消息指针为空时,指向一个常量pvNullPointer所指向的值.
 * 在UCOS中如果OSQPost()中的msg==NULL会返回一条OS_ERR_POST_NULL
 * 错误,而在lwip中会调用sys_mbox_post(mbox,NULL)发送一条空消息,我们
 * 在本函数中把NULL变成一个常量指针0Xffffffff
 */
const void *const pvNullPointer = (mem_ptr_t *)0xffffffff;

/**
 * @brief       创建一个消息邮箱
 * @param       mbox            : 消息邮箱
 * @param       size            : 邮箱大小
 * @retval      ERR_OK,创建成功; 其他,创建失败;
 */
err_t sys_mbox_new( sys_mbox_t *mbox, int size)
{
    (*mbox) = mymalloc(SRAMIN, sizeof(TQ_DESCR));   /* 为消息邮箱申请内存 */
    my_mem_set((*mbox), 0, sizeof(TQ_DESCR));       /* 清除mbox的内存 */

    if (*mbox)  /* 内存分配成功 */
    {
        if (size > MAX_QUEUE_ENTRIES)size = MAX_QUEUE_ENTRIES;      /* 消息队列最多容纳MAX_QUEUE_ENTRIES消息数目 */

        (*mbox)->pQ = OSQCreate(&((*mbox)->pvQEntries[0]), size);   /* 使用UCOS创建一个消息队列 */
        LWIP_ASSERT("OSQCreate", (*mbox)->pQ != NULL);

        if ((*mbox)->pQ != NULL)return ERR_OK; /* 返回ERR_OK,表示消息队列创建成功 ERR_OK=0 */
        else
        {
            myfree(SRAMIN, (*mbox));
            return ERR_MEM;         /* 消息队列创建错误 */
        }
    }
    else return ERR_MEM;            /* 消息队列创建错误 */
}

/**
 * @brief       释放并删除一个消息邮箱
 * @param       mbox            : 消息邮箱
 * @retval      无
 */
void sys_mbox_free(sys_mbox_t *mbox)
{
    u8_t ucErr;
    sys_mbox_t m_box = *mbox;
    (void)OSQDel(m_box->pQ, OS_DEL_ALWAYS, &ucErr);
    LWIP_ASSERT( "OSQDel ", ucErr == OS_ERR_NONE );
    myfree(SRAMIN, m_box);
    *mbox = NULL;
}

/**
 * @brief       向消息邮箱中发送一条消息(必须发送成功)
 * @param       mbox            : 消息邮箱
 * @param       msg             : 要发送的消息
*/
void sys_mbox_post(sys_mbox_t *mbox, void *msg)
{
    if (msg == NULL)msg = (void *)&pvNullPointer;       /* 当msg为空时 msg等于pvNullPointer指向的值 */

    while (OSQPost((*mbox)->pQ, msg) != OS_ERR_NONE);   /* 死循环等待消息发送成功 */
}

/**
 * @brief       尝试向一个消息邮箱发送消息
 *  @note       此函数相对于sys_mbox_post函数只发送一次消息，
 *              发送失败后不会尝试第二次发送
 * @param       mbox            : 消息邮箱
 * @param       msg             : 要发送的消息
 * @retval      ERR_OK,发送OK; ERR_MEM,发送失败;
 */
err_t sys_mbox_trypost(sys_mbox_t *mbox, void *msg)
{
    if (msg == NULL)msg = (void *)&pvNullPointer; /* 当msg为空时 msg等于pvNullPointer指向的值 */

    if ((OSQPost((*mbox)->pQ, msg)) != OS_ERR_NONE)return ERR_MEM;

    return ERR_OK;
}
 
/**
 * @brief       等待邮箱中的消息
 * @param       mbox            : 消息邮箱
 * @param       msg             : 要发送的消息
 * @param       timeout         : 超时时间
 * @retval      等待消息所用的时间/SYS_ARCH_TIMEOUT
 */
u32_t sys_arch_mbox_fetch(sys_mbox_t *mbox, void **msg, u32_t timeout)
{
    u8_t ucErr;
    u32_t ucos_timeout, timeout_new;
    void *temp;
    sys_mbox_t m_box = *mbox;

    if (timeout != 0)
    {
        ucos_timeout = (timeout * OS_TICKS_PER_SEC) / 1000; /* 转换为节拍数,因为UCOS延时使用的是节拍数,而LWIP是用ms */

        if (ucos_timeout < 1)ucos_timeout = 1;              /* 至少1个节拍 */
    }
    else ucos_timeout = 0;

    timeout = OSTimeGet();                                  /* 获取系统时间 */
    temp = OSQPend(m_box->pQ, (u16_t)ucos_timeout, &ucErr); /* 请求消息队列,等待时限为ucos_timeout */

    if (msg != NULL)
    {
        if (temp == (void *)&pvNullPointer)*msg = NULL;     /* 因为lwip发送空消息的时候我们使用了pvNullPointer指针,所以判断pvNullPointer指向的值 */
        else *msg = temp;                                   /* 就可知道请求到的消息是否有效 */
    }

    if (ucErr == OS_ERR_TIMEOUT)timeout = SYS_ARCH_TIMEOUT; /* 请求超时 */
    else
    {
        LWIP_ASSERT("OSQPend ", ucErr == OS_ERR_NONE);
        timeout_new = OSTimeGet();

        if (timeout_new > timeout) timeout_new = timeout_new - timeout; /* 算出请求消息或使用的时间 */
        else timeout_new = 0xffffffff - timeout + timeout_new;

        timeout = timeout_new * 1000 / OS_TICKS_PER_SEC + 1;
    }

    return timeout;
}

/**
 * @brief       尝试获取消息
 * @param       mbox            : 消息邮箱
 * @param       msg             : 消息
 * @retval      等待消息所用的时间/SYS_ARCH_TIMEOUT
 */
u32_t sys_arch_mbox_tryfetch(sys_mbox_t *mbox, void **msg)
{
    return sys_arch_mbox_fetch(mbox, msg, 1); /* 尝试获取一个消息 */
}

/**
 * @brief       检查一个消息邮箱是否有效
 * @param       mbox            : 消息邮箱
 * @retval      1,有效; 0,无效;
 */
int sys_mbox_valid(sys_mbox_t *mbox)
{
    return (int)(*mbox);
}

/**
 * @brief       设置一个消息邮箱为无效
 * @param       mbox            : 消息邮箱
 */
void sys_mbox_set_invalid(sys_mbox_t *mbox)
{
    *mbox = NULL;
}

/**
 * @brief       创建一个信号量
 * @param       sem             : 创建的信号量
 * @param       count           : 信号量值
 * @retval      ERR_OK,创建OK; ERR_MEM,创建失败;
 */
err_t sys_sem_new(sys_sem_t *sem, u8_t count)
{
    u8_t err;
    *sem = OSSemCreate((u16_t)count);

    if (*sem == NULL)return ERR_MEM;

    OSEventNameSet(*sem, "LWIP Sem", &err);
    LWIP_ASSERT("OSSemCreate ", *sem != NULL );
    return ERR_OK;
}

/**
 * @brief       等待一个信号量
 * @param       sem             : 要等待的信号量
 * @param       timeout         : 超时时间
 * @retval      等待信号量所用的时间/SYS_ARCH_TIMEOUT
 */
u32_t sys_arch_sem_wait(sys_sem_t *sem, u32_t timeout)
{
    u8_t ucErr;
    u32_t ucos_timeout, timeout_new;

    if (	timeout != 0)
    {
        ucos_timeout = (timeout * OS_TICKS_PER_SEC) / 1000;    /* 转换为节拍数,因为UCOS延时使用的是节拍数,而LWIP是用ms */

        if (ucos_timeout < 1)
            ucos_timeout = 1;
    }
    else ucos_timeout = 0;

    timeout = OSTimeGet();
    OSSemPend (*sem, (u16_t)ucos_timeout, (u8_t *)&ucErr);

    if (ucErr == OS_ERR_TIMEOUT)timeout = SYS_ARCH_TIMEOUT;    /* 请求超时 */
    else
    {
        timeout_new = OSTimeGet();

        if (timeout_new >= timeout) timeout_new = timeout_new - timeout;
        else timeout_new = 0xffffffff - timeout + timeout_new;

        timeout = (timeout_new * 1000 / OS_TICKS_PER_SEC + 1); /* 算出请求消息或使用的时间(ms) */
    }

    return timeout;
}

/**
 * @brief       发送一个信号量
 * @param       sem             : 信号量指针
 */
void sys_sem_signal(sys_sem_t *sem)
{
    OSSemPost(*sem);
}

/**
 * @brief       释放并删除一个信号量
 * @param       sem             : 信号量指针
 */
void sys_sem_free(sys_sem_t *sem)
{
    u8_t ucErr;
    (void)OSSemDel(*sem, OS_DEL_ALWAYS, &ucErr );

    if (ucErr != OS_ERR_NONE)LWIP_ASSERT("OSSemDel ", ucErr == OS_ERR_NONE);

    *sem = NULL;
}

/**
 * @brief       查询一个信号量的状态,无效或有效
 * @param       sem             : 信号量指针 
 * @retval      1,有效; 0,无效;
 */
int sys_sem_valid(sys_sem_t *sem)
{
    OS_SEM_DATA  sem_data;
    return (OSSemQuery (*sem, &sem_data) == OS_ERR_NONE ) ? 1 : 0;
}

/**
 * @brief       设置一个信号量无效
 * @param       sem             : 信号量指针
 */
void sys_sem_set_invalid(sys_sem_t *sem)
{
    *sem = NULL;
}

/* arch初始化 */
void sys_init(void)
{
    /* 这里,我们在该函数,不做任何事情 */
}

extern OS_STK *TCPIP_THREAD_TASK_STK; /* TCP IP内核任务堆栈,在lwip_comm函数定义 */

/**
 * @brief       创建一个新进程
 * @param       *name           : 进程名称
 * @param       thred           : 进程任务函数
 * @param       *arg            : 进程任务函数的参数
 * @param       stacksize       : 进程任务的堆栈大小
 * @param       prio            : 进程任务的优先级
 */
sys_thread_t sys_thread_new(const char *name, lwip_thread_fn thread, void *arg, int stacksize, int prio)
{
    OS_CPU_SR cpu_sr;

    if (strcmp(name, TCPIP_THREAD_NAME) == 0) /* 创建TCP IP内核任务 */
    {
        OS_ENTER_CRITICAL();                  /* 进入临界区 */
        OSTaskCreate(thread, arg, (OS_STK *)&TCPIP_THREAD_TASK_STK[stacksize - 1], prio); /* 创建TCP IP内核任务 */
        OS_EXIT_CRITICAL();                   /* 退出临界区 */
    }

    return 0;
}

/**
 * @param       lwip            : 延时函数
 * @param       ms              : 要延时的ms数
 */
void sys_msleep(u32_t ms)
{
    delay_ms(ms);
}

/**
 * @brief       获取系统时间,LWIP1.4.1增加的函数
 * @retval      当前系统时间(单位:毫秒)
 */
u32_t sys_now(void)
{
    u32_t ucos_time, lwip_time;
    ucos_time = OSTimeGet();                                /* 获取当前系统时间 得到的是UCSO的节拍数 */
    lwip_time = (ucos_time * 1000 / OS_TICKS_PER_SEC + 1);  /* 将节拍数转换为LWIP的时间MS */
    return lwip_time;                                       /* 返回lwip_time; */
}













































