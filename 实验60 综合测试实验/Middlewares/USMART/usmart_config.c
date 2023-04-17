#include "./USMART/usmart.h"
#include "./USMART/usmart_str.h"

/******************************************************************************************/
/* 用户配置区
 * 这下面要包含所用到的函数所申明的头文件(用户自己添加)
 */
 
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/delay/delay.h"
#include "./FATFS/exfuns/fattester.h"
#include "./BSP/I2S/i2s.h"
#include "./BSP/ES8388/es8388.h"
#include "./PICTURE/piclib.h"
#include "./BSP/OV2640/ov2640.h"
#include "./BSP/NORFLASH/norflash.h"


/* 函数名列表初始化(用户自己添加)
 * 用户直接在这里输入要执行的函数名及其查找串
 */
struct _m_usmart_nametab usmart_nametab[] =
{
#if USMART_USE_WRFUNS == 1      /* 如果使能了读写操作 */
    (void *)read_addr, "uint32_t read_addr(uint32_t addr)",
    (void *)write_addr, "void write_addr(uint32_t addr, uint32_t val)",
#endif
    (void *)delay_ms, "void delay_ms(uint16_t nms)",
    (void *)delay_us, "void delay_us(uint32_t nus)",
    (void *)norflash_erase_chip, "void norflash_erase_chip(void)",

    (void *)ov2640_read_reg, "uint8_t ov2640_read_reg(uint16_t reg)",
    (void *)ov2640_write_reg, "uint8_t ov2640_write_reg(uint16_t reg, uint8_t data)",
        
    (void *)es8388_i2s_cfg, "void es8388_i2s_cfg(uint8_t fmt, uint8_t len)",
    (void *)es8388_read_reg, "uint8_t es8388_read_reg(uint8_t reg)",
    (void *)es8388_write_reg, "uint8_t es8388_write_reg(uint8_t reg, uint8_t val)",
    (void *)i2s_init, "void i2s_init(uint32_t std, uint32_t mode, uint32_t cpol, uint32_t datalen)",

    (void*)mf_scan_files,"u8 mf_scan_files(u8 * path)",
    (void*)piclib_ai_load_picfile,"uint8_t piclib_ai_load_picfile(char *filename,uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t fast)", 	 
    (void*)minibmp_decode,"uint8_t minibmp_decode(uint8_t *filename,uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint16_t acolor,uint8_t mode)", 
    (void*)bmp_encode,"uint8_t bmp_encode(uint8_t *filename, uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t mode)", 
};


/******************************************************************************************/

/* 函数控制管理器初始化
 * 得到各个受控函数的名字
 * 得到函数总数量
 */
struct _m_usmart_dev usmart_dev =
{
    usmart_nametab,
    usmart_init,
    usmart_cmd_rec,
    usmart_exe,
    usmart_scan,
    sizeof(usmart_nametab) / sizeof(struct _m_usmart_nametab), /* 函数数量 */
    0,      /* 参数数量 */
    0,      /* 函数ID */
    1,      /* 参数显示类型,0,10进制;1,16进制 */
    0,      /* 参数类型.bitx:,0,数字;1,字符串 */
    0,      /* 每个参数的长度暂存表,需要MAX_PARM个0初始化 */
    0,      /* 函数的参数,需要PARM_LEN个0初始化 */
};



















