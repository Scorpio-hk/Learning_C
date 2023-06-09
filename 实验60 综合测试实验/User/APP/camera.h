/**
 ****************************************************************************************************
 * @file        camera.h
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-11-30
 * @brief       APP-照相机 代码
 * @license     Copyright (c) 2022-2032, 广州市星翼电子科技有限公司
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
 * V1.0 20221130
 * 1, 修改注释方式
 * 2, 修改u8/u16/u32为uint8_t/uint16_t/uint32_t
 ****************************************************************************************************
 */

#ifndef __CAMERA_H
#define __CAMERA_H
#include "common.h"


#define OV2640_RGB565_MODE      0       /* rgb565模式 */
#define OV2640_JPEG_MODE        1       /* jpeg模式 */

extern volatile uint8_t hsync_int;      /* 帧中断标志 */
extern volatile uint8_t jpeg_size;      /* jpeg图片分辨率 */
extern volatile uint8_t ov2640_mode;    /* 工作模式:0,RGB565模式;1,JPEG模式 */

extern volatile uint32_t jpeg_buf_size; /* 定义JPEG数据缓存jpeg_buf的大小(*4字节) */
extern volatile uint32_t jpeg_data_len; /* buf中的JPEG有效数据长度 */
extern volatile uint8_t jpeg_data_ok;   /* JPEG数据采集完成标志
                                         * 0,数据没有采集完;
                                         * 1,数据采集完了,但是还没处理;
                                         * 2,数据已经处理完成了,可以开始下一帧接收
                                         */
                                         
extern uint32_t *jpeg_buf;              /* JPEG数据缓存buf,通过malloc申请内存 */


void jpeg_data_process(void);
void sw_ov2640_mode(void);
void sw_sdcard_mode(void);
void camera_new_pathname(uint8_t *pname, uint8_t mode);
uint8_t ov2640_jpg_photo(uint8_t *pname);
uint8_t camera_play(void);
#endif























