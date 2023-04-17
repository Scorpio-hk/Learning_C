/**
 ****************************************************************************************************
 * @file        lcd_ex.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2020-03-23
 * @brief       lcd_ex.c存放各个LCD驱动IC的寄存器初始化部分代码,以简化lcd.c,该.c文件
 *              不直接加入到工程里面,只有lcd.c会用到,所以通过include的形式添加.(不要在
 *              其他文件再包含该.c文件!!否则会报错!) 
 * 
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 STM32H750开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 * 修改说明
 * V1.0 20200323
 * 第一次发布
 *
 ****************************************************************************************************
 */
 
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LCD/lcd.h"


/**
 * @brief       ST7789 寄存器初始化代码
 * @param       无
 * @retval      无
 */
void lcd_ex_st7789_reginit(void)
{
    lcd_wr_regno(0x11);

    delay_ms(120); 

    lcd_wr_regno(0x36);
    lcd_wr_data(0x00);


    lcd_wr_regno(0x3A);
    lcd_wr_data(0X05);

    lcd_wr_regno(0xB2);
    lcd_wr_data(0x0C);
    lcd_wr_data(0x0C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x33);
    lcd_wr_data(0x33);

    lcd_wr_regno(0xB7);
    lcd_wr_data(0x35);

    lcd_wr_regno(0xBB); /* vcom */
    lcd_wr_data(0x32);  /* 30 */

    lcd_wr_regno(0xC0);
    lcd_wr_data(0x0C);

    lcd_wr_regno(0xC2);
    lcd_wr_data(0x01);

    lcd_wr_regno(0xC3); /* vrh */
    lcd_wr_data(0x10);  /* 17 0D */

    lcd_wr_regno(0xC4); /* vdv */
    lcd_wr_data(0x20);  /* 20 */

    lcd_wr_regno(0xC6);
    lcd_wr_data(0x0f);

    lcd_wr_regno(0xD0);
    lcd_wr_data(0xA4); 
    lcd_wr_data(0xA1); 

    lcd_wr_regno(0xE0); /* Set Gamma  */
    lcd_wr_data(0xd0);
    lcd_wr_data(0x00);
    lcd_wr_data(0x02);
    lcd_wr_data(0x07);
    lcd_wr_data(0x0a);
    lcd_wr_data(0x28);
    lcd_wr_data(0x32);
    lcd_wr_data(0X44);
    lcd_wr_data(0x42);
    lcd_wr_data(0x06);
    lcd_wr_data(0x0e);
    lcd_wr_data(0x12);
    lcd_wr_data(0x14);
    lcd_wr_data(0x17);


    lcd_wr_regno(0XE1);  /* Set Gamma */
    lcd_wr_data(0xd0);
    lcd_wr_data(0x00);
    lcd_wr_data(0x02);
    lcd_wr_data(0x07);
    lcd_wr_data(0x0a);
    lcd_wr_data(0x28);
    lcd_wr_data(0x31);
    lcd_wr_data(0x54);
    lcd_wr_data(0x47);
    lcd_wr_data(0x0e);
    lcd_wr_data(0x1c);
    lcd_wr_data(0x17);
    lcd_wr_data(0x1b); 
    lcd_wr_data(0x1e);


    lcd_wr_regno(0x2A);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0xef);

    lcd_wr_regno(0x2B);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x01);
    lcd_wr_data(0x3f);

    lcd_wr_regno(0x29); /* display on */
}

/**
 * @brief       ILI9341寄存器初始化代码
 * @param       无
 * @retval      无
 */
void lcd_ex_ili9341_reginit(void)
{
    lcd_wr_regno(0xCF);
    lcd_wr_data(0x00);
    lcd_wr_data(0xC1);
    lcd_wr_data(0X30);
    lcd_wr_regno(0xED);
    lcd_wr_data(0x64);
    lcd_wr_data(0x03);
    lcd_wr_data(0X12);
    lcd_wr_data(0X81);
    lcd_wr_regno(0xE8);
    lcd_wr_data(0x85);
    lcd_wr_data(0x10);
    lcd_wr_data(0x7A);
    lcd_wr_regno(0xCB);
    lcd_wr_data(0x39);
    lcd_wr_data(0x2C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x34);
    lcd_wr_data(0x02);
    lcd_wr_regno(0xF7);
    lcd_wr_data(0x20);
    lcd_wr_regno(0xEA);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_regno(0xC0); /* Power control */
    lcd_wr_data(0x1B);  /* VRH[5:0] */
    lcd_wr_regno(0xC1); /* Power control */
    lcd_wr_data(0x01);  /* SAP[2:0];BT[3:0] */
    lcd_wr_regno(0xC5); /* VCM control */
    lcd_wr_data(0x30);  /* 3F */
    lcd_wr_data(0x30);  /* 3C */
    lcd_wr_regno(0xC7); /* VCM control2 */
    lcd_wr_data(0XB7);
    lcd_wr_regno(0x36); /*  Memory Access Control */
    lcd_wr_data(0x48);
    lcd_wr_regno(0x3A);
    lcd_wr_data(0x55);
    lcd_wr_regno(0xB1);
    lcd_wr_data(0x00);
    lcd_wr_data(0x1A);
    lcd_wr_regno(0xB6); /*  Display Function Control */
    lcd_wr_data(0x0A);
    lcd_wr_data(0xA2);
    lcd_wr_regno(0xF2); /*  3Gamma Function Disable */
    lcd_wr_data(0x00);
    lcd_wr_regno(0x26); /* Gamma curve selected */
    lcd_wr_data(0x01);
    lcd_wr_regno(0xE0); /* Set Gamma */
    lcd_wr_data(0x0F);
    lcd_wr_data(0x2A);
    lcd_wr_data(0x28);
    lcd_wr_data(0x08);
    lcd_wr_data(0x0E);
    lcd_wr_data(0x08);
    lcd_wr_data(0x54);
    lcd_wr_data(0XA9);
    lcd_wr_data(0x43);
    lcd_wr_data(0x0A);
    lcd_wr_data(0x0F);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_regno(0XE1);    /* Set Gamma */
    lcd_wr_data(0x00);
    lcd_wr_data(0x15);
    lcd_wr_data(0x17);
    lcd_wr_data(0x07);
    lcd_wr_data(0x11);
    lcd_wr_data(0x06);
    lcd_wr_data(0x2B);
    lcd_wr_data(0x56);
    lcd_wr_data(0x3C);
    lcd_wr_data(0x05);
    lcd_wr_data(0x10);
    lcd_wr_data(0x0F);
    lcd_wr_data(0x3F);
    lcd_wr_data(0x3F);
    lcd_wr_data(0x0F);
    lcd_wr_regno(0x2B);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x01);
    lcd_wr_data(0x3f);
    lcd_wr_regno(0x2A);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0xef);
    lcd_wr_regno(0x11); /* Exit Sleep */
    delay_ms(120);
    lcd_wr_regno(0x29); /* display on */
 }
 

/**
 * @brief       NT35310寄存器初始化代码 
 * @param       无
 * @retval      无
 */
void lcd_ex_nt35310_reginit(void)
{
    lcd_wr_regno(0xED);
    lcd_wr_data(0x01);
    lcd_wr_data(0xFE);

    lcd_wr_regno(0xEE);
    lcd_wr_data(0xDE);
    lcd_wr_data(0x21);

    lcd_wr_regno(0xF1);
    lcd_wr_data(0x01);
    lcd_wr_regno(0xDF);
    lcd_wr_data(0x10);

    /* VCOMvoltage */
    lcd_wr_regno(0xC4);
    lcd_wr_data(0x8F);  /* 5f */

    lcd_wr_regno(0xC6);
    lcd_wr_data(0x00);
    lcd_wr_data(0xE2);
    lcd_wr_data(0xE2);
    lcd_wr_data(0xE2);
    lcd_wr_regno(0xBF);
    lcd_wr_data(0xAA);

    lcd_wr_regno(0xB0);
    lcd_wr_data(0x0D);
    lcd_wr_data(0x00);
    lcd_wr_data(0x0D);
    lcd_wr_data(0x00);
    lcd_wr_data(0x11);
    lcd_wr_data(0x00);
    lcd_wr_data(0x19);
    lcd_wr_data(0x00);
    lcd_wr_data(0x21);
    lcd_wr_data(0x00);
    lcd_wr_data(0x2D);
    lcd_wr_data(0x00);
    lcd_wr_data(0x3D);
    lcd_wr_data(0x00);
    lcd_wr_data(0x5D);
    lcd_wr_data(0x00);
    lcd_wr_data(0x5D);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xB1);
    lcd_wr_data(0x80);
    lcd_wr_data(0x00);
    lcd_wr_data(0x8B);
    lcd_wr_data(0x00);
    lcd_wr_data(0x96);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xB2);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x02);
    lcd_wr_data(0x00);
    lcd_wr_data(0x03);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xB3);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xB4);
    lcd_wr_data(0x8B);
    lcd_wr_data(0x00);
    lcd_wr_data(0x96);
    lcd_wr_data(0x00);
    lcd_wr_data(0xA1);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xB5);
    lcd_wr_data(0x02);
    lcd_wr_data(0x00);
    lcd_wr_data(0x03);
    lcd_wr_data(0x00);
    lcd_wr_data(0x04);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xB6);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xB7);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x3F);
    lcd_wr_data(0x00);
    lcd_wr_data(0x5E);
    lcd_wr_data(0x00);
    lcd_wr_data(0x64);
    lcd_wr_data(0x00);
    lcd_wr_data(0x8C);
    lcd_wr_data(0x00);
    lcd_wr_data(0xAC);
    lcd_wr_data(0x00);
    lcd_wr_data(0xDC);
    lcd_wr_data(0x00);
    lcd_wr_data(0x70);
    lcd_wr_data(0x00);
    lcd_wr_data(0x90);
    lcd_wr_data(0x00);
    lcd_wr_data(0xEB);
    lcd_wr_data(0x00);
    lcd_wr_data(0xDC);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xB8);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xBA);
    lcd_wr_data(0x24);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xC1);
    lcd_wr_data(0x20);
    lcd_wr_data(0x00);
    lcd_wr_data(0x54);
    lcd_wr_data(0x00);
    lcd_wr_data(0xFF);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xC2);
    lcd_wr_data(0x0A);
    lcd_wr_data(0x00);
    lcd_wr_data(0x04);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xC3);
    lcd_wr_data(0x3C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x3A);
    lcd_wr_data(0x00);
    lcd_wr_data(0x39);
    lcd_wr_data(0x00);
    lcd_wr_data(0x37);
    lcd_wr_data(0x00);
    lcd_wr_data(0x3C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x36);
    lcd_wr_data(0x00);
    lcd_wr_data(0x32);
    lcd_wr_data(0x00);
    lcd_wr_data(0x2F);
    lcd_wr_data(0x00);
    lcd_wr_data(0x2C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x29);
    lcd_wr_data(0x00);
    lcd_wr_data(0x26);
    lcd_wr_data(0x00);
    lcd_wr_data(0x24);
    lcd_wr_data(0x00);
    lcd_wr_data(0x24);
    lcd_wr_data(0x00);
    lcd_wr_data(0x23);
    lcd_wr_data(0x00);
    lcd_wr_data(0x3C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x36);
    lcd_wr_data(0x00);
    lcd_wr_data(0x32);
    lcd_wr_data(0x00);
    lcd_wr_data(0x2F);
    lcd_wr_data(0x00);
    lcd_wr_data(0x2C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x29);
    lcd_wr_data(0x00);
    lcd_wr_data(0x26);
    lcd_wr_data(0x00);
    lcd_wr_data(0x24);
    lcd_wr_data(0x00);
    lcd_wr_data(0x24);
    lcd_wr_data(0x00);
    lcd_wr_data(0x23);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xC4);
    lcd_wr_data(0x62);
    lcd_wr_data(0x00);
    lcd_wr_data(0x05);
    lcd_wr_data(0x00);
    lcd_wr_data(0x84);
    lcd_wr_data(0x00);
    lcd_wr_data(0xF0);
    lcd_wr_data(0x00);
    lcd_wr_data(0x18);
    lcd_wr_data(0x00);
    lcd_wr_data(0xA4);
    lcd_wr_data(0x00);
    lcd_wr_data(0x18);
    lcd_wr_data(0x00);
    lcd_wr_data(0x50);
    lcd_wr_data(0x00);
    lcd_wr_data(0x0C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x17);
    lcd_wr_data(0x00);
    lcd_wr_data(0x95);
    lcd_wr_data(0x00);
    lcd_wr_data(0xF3);
    lcd_wr_data(0x00);
    lcd_wr_data(0xE6);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xC5);
    lcd_wr_data(0x32);
    lcd_wr_data(0x00);
    lcd_wr_data(0x44);
    lcd_wr_data(0x00);
    lcd_wr_data(0x65);
    lcd_wr_data(0x00);
    lcd_wr_data(0x76);
    lcd_wr_data(0x00);
    lcd_wr_data(0x88);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xC6);
    lcd_wr_data(0x20);
    lcd_wr_data(0x00);
    lcd_wr_data(0x17);
    lcd_wr_data(0x00);
    lcd_wr_data(0x01);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xC7);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xC8);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xC9);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xE0);
    lcd_wr_data(0x16);
    lcd_wr_data(0x00);
    lcd_wr_data(0x1C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x21);
    lcd_wr_data(0x00);
    lcd_wr_data(0x36);
    lcd_wr_data(0x00);
    lcd_wr_data(0x46);
    lcd_wr_data(0x00);
    lcd_wr_data(0x52);
    lcd_wr_data(0x00);
    lcd_wr_data(0x64);
    lcd_wr_data(0x00);
    lcd_wr_data(0x7A);
    lcd_wr_data(0x00);
    lcd_wr_data(0x8B);
    lcd_wr_data(0x00);
    lcd_wr_data(0x99);
    lcd_wr_data(0x00);
    lcd_wr_data(0xA8);
    lcd_wr_data(0x00);
    lcd_wr_data(0xB9);
    lcd_wr_data(0x00);
    lcd_wr_data(0xC4);
    lcd_wr_data(0x00);
    lcd_wr_data(0xCA);
    lcd_wr_data(0x00);
    lcd_wr_data(0xD2);
    lcd_wr_data(0x00);
    lcd_wr_data(0xD9);
    lcd_wr_data(0x00);
    lcd_wr_data(0xE0);
    lcd_wr_data(0x00);
    lcd_wr_data(0xF3);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xE1);
    lcd_wr_data(0x16);
    lcd_wr_data(0x00);
    lcd_wr_data(0x1C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x22);
    lcd_wr_data(0x00);
    lcd_wr_data(0x36);
    lcd_wr_data(0x00);
    lcd_wr_data(0x45);
    lcd_wr_data(0x00);
    lcd_wr_data(0x52);
    lcd_wr_data(0x00);
    lcd_wr_data(0x64);
    lcd_wr_data(0x00);
    lcd_wr_data(0x7A);
    lcd_wr_data(0x00);
    lcd_wr_data(0x8B);
    lcd_wr_data(0x00);
    lcd_wr_data(0x99);
    lcd_wr_data(0x00);
    lcd_wr_data(0xA8);
    lcd_wr_data(0x00);
    lcd_wr_data(0xB9);
    lcd_wr_data(0x00);
    lcd_wr_data(0xC4);
    lcd_wr_data(0x00);
    lcd_wr_data(0xCA);
    lcd_wr_data(0x00);
    lcd_wr_data(0xD2);
    lcd_wr_data(0x00);
    lcd_wr_data(0xD8);
    lcd_wr_data(0x00);
    lcd_wr_data(0xE0);
    lcd_wr_data(0x00);
    lcd_wr_data(0xF3);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xE2);
    lcd_wr_data(0x05);
    lcd_wr_data(0x00);
    lcd_wr_data(0x0B);
    lcd_wr_data(0x00);
    lcd_wr_data(0x1B);
    lcd_wr_data(0x00);
    lcd_wr_data(0x34);
    lcd_wr_data(0x00);
    lcd_wr_data(0x44);
    lcd_wr_data(0x00);
    lcd_wr_data(0x4F);
    lcd_wr_data(0x00);
    lcd_wr_data(0x61);
    lcd_wr_data(0x00);
    lcd_wr_data(0x79);
    lcd_wr_data(0x00);
    lcd_wr_data(0x88);
    lcd_wr_data(0x00);
    lcd_wr_data(0x97);
    lcd_wr_data(0x00);
    lcd_wr_data(0xA6);
    lcd_wr_data(0x00);
    lcd_wr_data(0xB7);
    lcd_wr_data(0x00);
    lcd_wr_data(0xC2);
    lcd_wr_data(0x00);
    lcd_wr_data(0xC7);
    lcd_wr_data(0x00);
    lcd_wr_data(0xD1);
    lcd_wr_data(0x00);
    lcd_wr_data(0xD6);
    lcd_wr_data(0x00);
    lcd_wr_data(0xDD);
    lcd_wr_data(0x00);
    lcd_wr_data(0xF3);
    lcd_wr_data(0x00);
    lcd_wr_regno(0xE3);
    lcd_wr_data(0x05);
    lcd_wr_data(0x00);
    lcd_wr_data(0xA);
    lcd_wr_data(0x00);
    lcd_wr_data(0x1C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x33);
    lcd_wr_data(0x00);
    lcd_wr_data(0x44);
    lcd_wr_data(0x00);
    lcd_wr_data(0x50);
    lcd_wr_data(0x00);
    lcd_wr_data(0x62);
    lcd_wr_data(0x00);
    lcd_wr_data(0x78);
    lcd_wr_data(0x00);
    lcd_wr_data(0x88);
    lcd_wr_data(0x00);
    lcd_wr_data(0x97);
    lcd_wr_data(0x00);
    lcd_wr_data(0xA6);
    lcd_wr_data(0x00);
    lcd_wr_data(0xB7);
    lcd_wr_data(0x00);
    lcd_wr_data(0xC2);
    lcd_wr_data(0x00);
    lcd_wr_data(0xC7);
    lcd_wr_data(0x00);
    lcd_wr_data(0xD1);
    lcd_wr_data(0x00);
    lcd_wr_data(0xD5);
    lcd_wr_data(0x00);
    lcd_wr_data(0xDD);
    lcd_wr_data(0x00);
    lcd_wr_data(0xF3);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xE4);
    lcd_wr_data(0x01);
    lcd_wr_data(0x00);
    lcd_wr_data(0x01);
    lcd_wr_data(0x00);
    lcd_wr_data(0x02);
    lcd_wr_data(0x00);
    lcd_wr_data(0x2A);
    lcd_wr_data(0x00);
    lcd_wr_data(0x3C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x4B);
    lcd_wr_data(0x00);
    lcd_wr_data(0x5D);
    lcd_wr_data(0x00);
    lcd_wr_data(0x74);
    lcd_wr_data(0x00);
    lcd_wr_data(0x84);
    lcd_wr_data(0x00);
    lcd_wr_data(0x93);
    lcd_wr_data(0x00);
    lcd_wr_data(0xA2);
    lcd_wr_data(0x00);
    lcd_wr_data(0xB3);
    lcd_wr_data(0x00);
    lcd_wr_data(0xBE);
    lcd_wr_data(0x00);
    lcd_wr_data(0xC4);
    lcd_wr_data(0x00);
    lcd_wr_data(0xCD);
    lcd_wr_data(0x00);
    lcd_wr_data(0xD3);
    lcd_wr_data(0x00);
    lcd_wr_data(0xDD);
    lcd_wr_data(0x00);
    lcd_wr_data(0xF3);
    lcd_wr_data(0x00);
    lcd_wr_regno(0xE5);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x02);
    lcd_wr_data(0x00);
    lcd_wr_data(0x29);
    lcd_wr_data(0x00);
    lcd_wr_data(0x3C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x4B);
    lcd_wr_data(0x00);
    lcd_wr_data(0x5D);
    lcd_wr_data(0x00);
    lcd_wr_data(0x74);
    lcd_wr_data(0x00);
    lcd_wr_data(0x84);
    lcd_wr_data(0x00);
    lcd_wr_data(0x93);
    lcd_wr_data(0x00);
    lcd_wr_data(0xA2);
    lcd_wr_data(0x00);
    lcd_wr_data(0xB3);
    lcd_wr_data(0x00);
    lcd_wr_data(0xBE);
    lcd_wr_data(0x00);
    lcd_wr_data(0xC4);
    lcd_wr_data(0x00);
    lcd_wr_data(0xCD);
    lcd_wr_data(0x00);
    lcd_wr_data(0xD3);
    lcd_wr_data(0x00);
    lcd_wr_data(0xDC);
    lcd_wr_data(0x00);
    lcd_wr_data(0xF3);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xE6);
    lcd_wr_data(0x11);
    lcd_wr_data(0x00);
    lcd_wr_data(0x34);
    lcd_wr_data(0x00);
    lcd_wr_data(0x56);
    lcd_wr_data(0x00);
    lcd_wr_data(0x76);
    lcd_wr_data(0x00);
    lcd_wr_data(0x77);
    lcd_wr_data(0x00);
    lcd_wr_data(0x66);
    lcd_wr_data(0x00);
    lcd_wr_data(0x88);
    lcd_wr_data(0x00);
    lcd_wr_data(0x99);
    lcd_wr_data(0x00);
    lcd_wr_data(0xBB);
    lcd_wr_data(0x00);
    lcd_wr_data(0x99);
    lcd_wr_data(0x00);
    lcd_wr_data(0x66);
    lcd_wr_data(0x00);
    lcd_wr_data(0x55);
    lcd_wr_data(0x00);
    lcd_wr_data(0x55);
    lcd_wr_data(0x00);
    lcd_wr_data(0x45);
    lcd_wr_data(0x00);
    lcd_wr_data(0x43);
    lcd_wr_data(0x00);
    lcd_wr_data(0x44);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xE7);
    lcd_wr_data(0x32);
    lcd_wr_data(0x00);
    lcd_wr_data(0x55);
    lcd_wr_data(0x00);
    lcd_wr_data(0x76);
    lcd_wr_data(0x00);
    lcd_wr_data(0x66);
    lcd_wr_data(0x00);
    lcd_wr_data(0x67);
    lcd_wr_data(0x00);
    lcd_wr_data(0x67);
    lcd_wr_data(0x00);
    lcd_wr_data(0x87);
    lcd_wr_data(0x00);
    lcd_wr_data(0x99);
    lcd_wr_data(0x00);
    lcd_wr_data(0xBB);
    lcd_wr_data(0x00);
    lcd_wr_data(0x99);
    lcd_wr_data(0x00);
    lcd_wr_data(0x77);
    lcd_wr_data(0x00);
    lcd_wr_data(0x44);
    lcd_wr_data(0x00);
    lcd_wr_data(0x56);
    lcd_wr_data(0x00);
    lcd_wr_data(0x23);
    lcd_wr_data(0x00);
    lcd_wr_data(0x33);
    lcd_wr_data(0x00);
    lcd_wr_data(0x45);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xE8);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x99);
    lcd_wr_data(0x00);
    lcd_wr_data(0x87);
    lcd_wr_data(0x00);
    lcd_wr_data(0x88);
    lcd_wr_data(0x00);
    lcd_wr_data(0x77);
    lcd_wr_data(0x00);
    lcd_wr_data(0x66);
    lcd_wr_data(0x00);
    lcd_wr_data(0x88);
    lcd_wr_data(0x00);
    lcd_wr_data(0xAA);
    lcd_wr_data(0x00);
    lcd_wr_data(0xBB);
    lcd_wr_data(0x00);
    lcd_wr_data(0x99);
    lcd_wr_data(0x00);
    lcd_wr_data(0x66);
    lcd_wr_data(0x00);
    lcd_wr_data(0x55);
    lcd_wr_data(0x00);
    lcd_wr_data(0x55);
    lcd_wr_data(0x00);
    lcd_wr_data(0x44);
    lcd_wr_data(0x00);
    lcd_wr_data(0x44);
    lcd_wr_data(0x00);
    lcd_wr_data(0x55);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xE9);
    lcd_wr_data(0xAA);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    lcd_wr_regno(0x00);
    lcd_wr_data(0xAA);

    lcd_wr_regno(0xCF);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xF0);
    lcd_wr_data(0x00);
    lcd_wr_data(0x50);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xF3);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xF9);
    lcd_wr_data(0x06);
    lcd_wr_data(0x10);
    lcd_wr_data(0x29);
    lcd_wr_data(0x00);

    lcd_wr_regno(0x3A);
    lcd_wr_data(0x55);  /* 66 */

    lcd_wr_regno(0x11);
    delay_ms(100);
    lcd_wr_regno(0x29);
    lcd_wr_regno(0x35);
    lcd_wr_data(0x00);

    lcd_wr_regno(0x51);
    lcd_wr_data(0xFF);
    lcd_wr_regno(0x53);
    lcd_wr_data(0x2C);
    lcd_wr_regno(0x55);
    lcd_wr_data(0x82);
    lcd_wr_regno(0x2c);
}

/**
 * @brief       NT35510寄存器初始化代码 
 * @param       无
 * @retval      无
 */
void lcd_ex_nt35510_reginit(void)
{
    lcd_write_reg(0xF000, 0x55);
    lcd_write_reg(0xF001, 0xAA);
    lcd_write_reg(0xF002, 0x52);
    lcd_write_reg(0xF003, 0x08);
    lcd_write_reg(0xF004, 0x01);
    /* AVDD Set AVDD 5.2V */
    lcd_write_reg(0xB000, 0x0D);
    lcd_write_reg(0xB001, 0x0D);
    lcd_write_reg(0xB002, 0x0D);
    /* AVDD ratio */
    lcd_write_reg(0xB600, 0x34);
    lcd_write_reg(0xB601, 0x34);
    lcd_write_reg(0xB602, 0x34);
    /* AVEE -5.2V */
    lcd_write_reg(0xB100, 0x0D);
    lcd_write_reg(0xB101, 0x0D);
    lcd_write_reg(0xB102, 0x0D);
    /* AVEE ratio */
    lcd_write_reg(0xB700, 0x34);
    lcd_write_reg(0xB701, 0x34);
    lcd_write_reg(0xB702, 0x34);
    /* VCL -2.5V */
    lcd_write_reg(0xB200, 0x00);
    lcd_write_reg(0xB201, 0x00);
    lcd_write_reg(0xB202, 0x00);
    /* VCL ratio */
    lcd_write_reg(0xB800, 0x24);
    lcd_write_reg(0xB801, 0x24);
    lcd_write_reg(0xB802, 0x24);
    /* VGH 15V (Free pump) */
    lcd_write_reg(0xBF00, 0x01);
    lcd_write_reg(0xB300, 0x0F);
    lcd_write_reg(0xB301, 0x0F);
    lcd_write_reg(0xB302, 0x0F);
    /* VGH ratio */
    lcd_write_reg(0xB900, 0x34);
    lcd_write_reg(0xB901, 0x34);
    lcd_write_reg(0xB902, 0x34);
    /* VGL_REG -10V */
    lcd_write_reg(0xB500, 0x08);
    lcd_write_reg(0xB501, 0x08);
    lcd_write_reg(0xB502, 0x08);
    lcd_write_reg(0xC200, 0x03);
    /* VGLX ratio */
    lcd_write_reg(0xBA00, 0x24);
    lcd_write_reg(0xBA01, 0x24);
    lcd_write_reg(0xBA02, 0x24);
    /* VGMP/VGSP 4.5V/0V */
    lcd_write_reg(0xBC00, 0x00);
    lcd_write_reg(0xBC01, 0x78);
    lcd_write_reg(0xBC02, 0x00);
    /* VGMN/VGSN -4.5V/0V */
    lcd_write_reg(0xBD00, 0x00);
    lcd_write_reg(0xBD01, 0x78);
    lcd_write_reg(0xBD02, 0x00);
    /* VCOM */
    lcd_write_reg(0xBE00, 0x00);
    lcd_write_reg(0xBE01, 0x64);
    /* Gamma Setting */
    lcd_write_reg(0xD100, 0x00);
    lcd_write_reg(0xD101, 0x33);
    lcd_write_reg(0xD102, 0x00);
    lcd_write_reg(0xD103, 0x34);
    lcd_write_reg(0xD104, 0x00);
    lcd_write_reg(0xD105, 0x3A);
    lcd_write_reg(0xD106, 0x00);
    lcd_write_reg(0xD107, 0x4A);
    lcd_write_reg(0xD108, 0x00);
    lcd_write_reg(0xD109, 0x5C);
    lcd_write_reg(0xD10A, 0x00);
    lcd_write_reg(0xD10B, 0x81);
    lcd_write_reg(0xD10C, 0x00);
    lcd_write_reg(0xD10D, 0xA6);
    lcd_write_reg(0xD10E, 0x00);
    lcd_write_reg(0xD10F, 0xE5);
    lcd_write_reg(0xD110, 0x01);
    lcd_write_reg(0xD111, 0x13);
    lcd_write_reg(0xD112, 0x01);
    lcd_write_reg(0xD113, 0x54);
    lcd_write_reg(0xD114, 0x01);
    lcd_write_reg(0xD115, 0x82);
    lcd_write_reg(0xD116, 0x01);
    lcd_write_reg(0xD117, 0xCA);
    lcd_write_reg(0xD118, 0x02);
    lcd_write_reg(0xD119, 0x00);
    lcd_write_reg(0xD11A, 0x02);
    lcd_write_reg(0xD11B, 0x01);
    lcd_write_reg(0xD11C, 0x02);
    lcd_write_reg(0xD11D, 0x34);
    lcd_write_reg(0xD11E, 0x02);
    lcd_write_reg(0xD11F, 0x67);
    lcd_write_reg(0xD120, 0x02);
    lcd_write_reg(0xD121, 0x84);
    lcd_write_reg(0xD122, 0x02);
    lcd_write_reg(0xD123, 0xA4);
    lcd_write_reg(0xD124, 0x02);
    lcd_write_reg(0xD125, 0xB7);
    lcd_write_reg(0xD126, 0x02);
    lcd_write_reg(0xD127, 0xCF);
    lcd_write_reg(0xD128, 0x02);
    lcd_write_reg(0xD129, 0xDE);
    lcd_write_reg(0xD12A, 0x02);
    lcd_write_reg(0xD12B, 0xF2);
    lcd_write_reg(0xD12C, 0x02);
    lcd_write_reg(0xD12D, 0xFE);
    lcd_write_reg(0xD12E, 0x03);
    lcd_write_reg(0xD12F, 0x10);
    lcd_write_reg(0xD130, 0x03);
    lcd_write_reg(0xD131, 0x33);
    lcd_write_reg(0xD132, 0x03);
    lcd_write_reg(0xD133, 0x6D);
    lcd_write_reg(0xD200, 0x00);
    lcd_write_reg(0xD201, 0x33);
    lcd_write_reg(0xD202, 0x00);
    lcd_write_reg(0xD203, 0x34);
    lcd_write_reg(0xD204, 0x00);
    lcd_write_reg(0xD205, 0x3A);
    lcd_write_reg(0xD206, 0x00);
    lcd_write_reg(0xD207, 0x4A);
    lcd_write_reg(0xD208, 0x00);
    lcd_write_reg(0xD209, 0x5C);
    lcd_write_reg(0xD20A, 0x00);

    lcd_write_reg(0xD20B, 0x81);
    lcd_write_reg(0xD20C, 0x00);
    lcd_write_reg(0xD20D, 0xA6);
    lcd_write_reg(0xD20E, 0x00);
    lcd_write_reg(0xD20F, 0xE5);
    lcd_write_reg(0xD210, 0x01);
    lcd_write_reg(0xD211, 0x13);
    lcd_write_reg(0xD212, 0x01);
    lcd_write_reg(0xD213, 0x54);
    lcd_write_reg(0xD214, 0x01);
    lcd_write_reg(0xD215, 0x82);
    lcd_write_reg(0xD216, 0x01);
    lcd_write_reg(0xD217, 0xCA);
    lcd_write_reg(0xD218, 0x02);
    lcd_write_reg(0xD219, 0x00);
    lcd_write_reg(0xD21A, 0x02);
    lcd_write_reg(0xD21B, 0x01);
    lcd_write_reg(0xD21C, 0x02);
    lcd_write_reg(0xD21D, 0x34);
    lcd_write_reg(0xD21E, 0x02);
    lcd_write_reg(0xD21F, 0x67);
    lcd_write_reg(0xD220, 0x02);
    lcd_write_reg(0xD221, 0x84);
    lcd_write_reg(0xD222, 0x02);
    lcd_write_reg(0xD223, 0xA4);
    lcd_write_reg(0xD224, 0x02);
    lcd_write_reg(0xD225, 0xB7);
    lcd_write_reg(0xD226, 0x02);
    lcd_write_reg(0xD227, 0xCF);
    lcd_write_reg(0xD228, 0x02);
    lcd_write_reg(0xD229, 0xDE);
    lcd_write_reg(0xD22A, 0x02);
    lcd_write_reg(0xD22B, 0xF2);
    lcd_write_reg(0xD22C, 0x02);
    lcd_write_reg(0xD22D, 0xFE);
    lcd_write_reg(0xD22E, 0x03);
    lcd_write_reg(0xD22F, 0x10);
    lcd_write_reg(0xD230, 0x03);
    lcd_write_reg(0xD231, 0x33);
    lcd_write_reg(0xD232, 0x03);
    lcd_write_reg(0xD233, 0x6D);
    lcd_write_reg(0xD300, 0x00);
    lcd_write_reg(0xD301, 0x33);
    lcd_write_reg(0xD302, 0x00);
    lcd_write_reg(0xD303, 0x34);
    lcd_write_reg(0xD304, 0x00);
    lcd_write_reg(0xD305, 0x3A);
    lcd_write_reg(0xD306, 0x00);
    lcd_write_reg(0xD307, 0x4A);
    lcd_write_reg(0xD308, 0x00);
    lcd_write_reg(0xD309, 0x5C);
    lcd_write_reg(0xD30A, 0x00);

    lcd_write_reg(0xD30B, 0x81);
    lcd_write_reg(0xD30C, 0x00);
    lcd_write_reg(0xD30D, 0xA6);
    lcd_write_reg(0xD30E, 0x00);
    lcd_write_reg(0xD30F, 0xE5);
    lcd_write_reg(0xD310, 0x01);
    lcd_write_reg(0xD311, 0x13);
    lcd_write_reg(0xD312, 0x01);
    lcd_write_reg(0xD313, 0x54);
    lcd_write_reg(0xD314, 0x01);
    lcd_write_reg(0xD315, 0x82);
    lcd_write_reg(0xD316, 0x01);
    lcd_write_reg(0xD317, 0xCA);
    lcd_write_reg(0xD318, 0x02);
    lcd_write_reg(0xD319, 0x00);
    lcd_write_reg(0xD31A, 0x02);
    lcd_write_reg(0xD31B, 0x01);
    lcd_write_reg(0xD31C, 0x02);
    lcd_write_reg(0xD31D, 0x34);
    lcd_write_reg(0xD31E, 0x02);
    lcd_write_reg(0xD31F, 0x67);
    lcd_write_reg(0xD320, 0x02);
    lcd_write_reg(0xD321, 0x84);
    lcd_write_reg(0xD322, 0x02);
    lcd_write_reg(0xD323, 0xA4);
    lcd_write_reg(0xD324, 0x02);
    lcd_write_reg(0xD325, 0xB7);
    lcd_write_reg(0xD326, 0x02);
    lcd_write_reg(0xD327, 0xCF);
    lcd_write_reg(0xD328, 0x02);
    lcd_write_reg(0xD329, 0xDE);
    lcd_write_reg(0xD32A, 0x02);
    lcd_write_reg(0xD32B, 0xF2);
    lcd_write_reg(0xD32C, 0x02);
    lcd_write_reg(0xD32D, 0xFE);
    lcd_write_reg(0xD32E, 0x03);
    lcd_write_reg(0xD32F, 0x10);
    lcd_write_reg(0xD330, 0x03);
    lcd_write_reg(0xD331, 0x33);
    lcd_write_reg(0xD332, 0x03);
    lcd_write_reg(0xD333, 0x6D);
    lcd_write_reg(0xD400, 0x00);
    lcd_write_reg(0xD401, 0x33);
    lcd_write_reg(0xD402, 0x00);
    lcd_write_reg(0xD403, 0x34);
    lcd_write_reg(0xD404, 0x00);
    lcd_write_reg(0xD405, 0x3A);
    lcd_write_reg(0xD406, 0x00);
    lcd_write_reg(0xD407, 0x4A);
    lcd_write_reg(0xD408, 0x00);
    lcd_write_reg(0xD409, 0x5C);
    lcd_write_reg(0xD40A, 0x00);
    lcd_write_reg(0xD40B, 0x81);

    lcd_write_reg(0xD40C, 0x00);
    lcd_write_reg(0xD40D, 0xA6);
    lcd_write_reg(0xD40E, 0x00);
    lcd_write_reg(0xD40F, 0xE5);
    lcd_write_reg(0xD410, 0x01);
    lcd_write_reg(0xD411, 0x13);
    lcd_write_reg(0xD412, 0x01);
    lcd_write_reg(0xD413, 0x54);
    lcd_write_reg(0xD414, 0x01);
    lcd_write_reg(0xD415, 0x82);
    lcd_write_reg(0xD416, 0x01);
    lcd_write_reg(0xD417, 0xCA);
    lcd_write_reg(0xD418, 0x02);
    lcd_write_reg(0xD419, 0x00);
    lcd_write_reg(0xD41A, 0x02);
    lcd_write_reg(0xD41B, 0x01);
    lcd_write_reg(0xD41C, 0x02);
    lcd_write_reg(0xD41D, 0x34);
    lcd_write_reg(0xD41E, 0x02);
    lcd_write_reg(0xD41F, 0x67);
    lcd_write_reg(0xD420, 0x02);
    lcd_write_reg(0xD421, 0x84);
    lcd_write_reg(0xD422, 0x02);
    lcd_write_reg(0xD423, 0xA4);
    lcd_write_reg(0xD424, 0x02);
    lcd_write_reg(0xD425, 0xB7);
    lcd_write_reg(0xD426, 0x02);
    lcd_write_reg(0xD427, 0xCF);
    lcd_write_reg(0xD428, 0x02);
    lcd_write_reg(0xD429, 0xDE);
    lcd_write_reg(0xD42A, 0x02);
    lcd_write_reg(0xD42B, 0xF2);
    lcd_write_reg(0xD42C, 0x02);
    lcd_write_reg(0xD42D, 0xFE);
    lcd_write_reg(0xD42E, 0x03);
    lcd_write_reg(0xD42F, 0x10);
    lcd_write_reg(0xD430, 0x03);
    lcd_write_reg(0xD431, 0x33);
    lcd_write_reg(0xD432, 0x03);
    lcd_write_reg(0xD433, 0x6D);
    lcd_write_reg(0xD500, 0x00);
    lcd_write_reg(0xD501, 0x33);
    lcd_write_reg(0xD502, 0x00);
    lcd_write_reg(0xD503, 0x34);
    lcd_write_reg(0xD504, 0x00);
    lcd_write_reg(0xD505, 0x3A);
    lcd_write_reg(0xD506, 0x00);
    lcd_write_reg(0xD507, 0x4A);
    lcd_write_reg(0xD508, 0x00);
    lcd_write_reg(0xD509, 0x5C);
    lcd_write_reg(0xD50A, 0x00);
    lcd_write_reg(0xD50B, 0x81);

    lcd_write_reg(0xD50C, 0x00);
    lcd_write_reg(0xD50D, 0xA6);
    lcd_write_reg(0xD50E, 0x00);
    lcd_write_reg(0xD50F, 0xE5);
    lcd_write_reg(0xD510, 0x01);
    lcd_write_reg(0xD511, 0x13);
    lcd_write_reg(0xD512, 0x01);
    lcd_write_reg(0xD513, 0x54);
    lcd_write_reg(0xD514, 0x01);
    lcd_write_reg(0xD515, 0x82);
    lcd_write_reg(0xD516, 0x01);
    lcd_write_reg(0xD517, 0xCA);
    lcd_write_reg(0xD518, 0x02);
    lcd_write_reg(0xD519, 0x00);
    lcd_write_reg(0xD51A, 0x02);
    lcd_write_reg(0xD51B, 0x01);
    lcd_write_reg(0xD51C, 0x02);
    lcd_write_reg(0xD51D, 0x34);
    lcd_write_reg(0xD51E, 0x02);
    lcd_write_reg(0xD51F, 0x67);
    lcd_write_reg(0xD520, 0x02);
    lcd_write_reg(0xD521, 0x84);
    lcd_write_reg(0xD522, 0x02);
    lcd_write_reg(0xD523, 0xA4);
    lcd_write_reg(0xD524, 0x02);
    lcd_write_reg(0xD525, 0xB7);
    lcd_write_reg(0xD526, 0x02);
    lcd_write_reg(0xD527, 0xCF);
    lcd_write_reg(0xD528, 0x02);
    lcd_write_reg(0xD529, 0xDE);
    lcd_write_reg(0xD52A, 0x02);
    lcd_write_reg(0xD52B, 0xF2);
    lcd_write_reg(0xD52C, 0x02);
    lcd_write_reg(0xD52D, 0xFE);
    lcd_write_reg(0xD52E, 0x03);
    lcd_write_reg(0xD52F, 0x10);
    lcd_write_reg(0xD530, 0x03);
    lcd_write_reg(0xD531, 0x33);
    lcd_write_reg(0xD532, 0x03);
    lcd_write_reg(0xD533, 0x6D);
    lcd_write_reg(0xD600, 0x00);
    lcd_write_reg(0xD601, 0x33);
    lcd_write_reg(0xD602, 0x00);
    lcd_write_reg(0xD603, 0x34);
    lcd_write_reg(0xD604, 0x00);
    lcd_write_reg(0xD605, 0x3A);
    lcd_write_reg(0xD606, 0x00);
    lcd_write_reg(0xD607, 0x4A);
    lcd_write_reg(0xD608, 0x00);
    lcd_write_reg(0xD609, 0x5C);
    lcd_write_reg(0xD60A, 0x00);
    lcd_write_reg(0xD60B, 0x81);

    lcd_write_reg(0xD60C, 0x00);
    lcd_write_reg(0xD60D, 0xA6);
    lcd_write_reg(0xD60E, 0x00);
    lcd_write_reg(0xD60F, 0xE5);
    lcd_write_reg(0xD610, 0x01);
    lcd_write_reg(0xD611, 0x13);
    lcd_write_reg(0xD612, 0x01);
    lcd_write_reg(0xD613, 0x54);
    lcd_write_reg(0xD614, 0x01);
    lcd_write_reg(0xD615, 0x82);
    lcd_write_reg(0xD616, 0x01);
    lcd_write_reg(0xD617, 0xCA);
    lcd_write_reg(0xD618, 0x02);
    lcd_write_reg(0xD619, 0x00);
    lcd_write_reg(0xD61A, 0x02);
    lcd_write_reg(0xD61B, 0x01);
    lcd_write_reg(0xD61C, 0x02);
    lcd_write_reg(0xD61D, 0x34);
    lcd_write_reg(0xD61E, 0x02);
    lcd_write_reg(0xD61F, 0x67);
    lcd_write_reg(0xD620, 0x02);
    lcd_write_reg(0xD621, 0x84);
    lcd_write_reg(0xD622, 0x02);
    lcd_write_reg(0xD623, 0xA4);
    lcd_write_reg(0xD624, 0x02);
    lcd_write_reg(0xD625, 0xB7);
    lcd_write_reg(0xD626, 0x02);
    lcd_write_reg(0xD627, 0xCF);
    lcd_write_reg(0xD628, 0x02);
    lcd_write_reg(0xD629, 0xDE);
    lcd_write_reg(0xD62A, 0x02);
    lcd_write_reg(0xD62B, 0xF2);
    lcd_write_reg(0xD62C, 0x02);
    lcd_write_reg(0xD62D, 0xFE);
    lcd_write_reg(0xD62E, 0x03);
    lcd_write_reg(0xD62F, 0x10);
    lcd_write_reg(0xD630, 0x03);
    lcd_write_reg(0xD631, 0x33);
    lcd_write_reg(0xD632, 0x03);
    lcd_write_reg(0xD633, 0x6D);
    /* LV2 Page 0 enable */
    lcd_write_reg(0xF000, 0x55);
    lcd_write_reg(0xF001, 0xAA);
    lcd_write_reg(0xF002, 0x52);
    lcd_write_reg(0xF003, 0x08);
    lcd_write_reg(0xF004, 0x00);
    /* Display control */
    lcd_write_reg(0xB100, 0xCC);
    lcd_write_reg(0xB101, 0x00);
    /* Source hold time */
    lcd_write_reg(0xB600, 0x05);
    /* Gate EQ control */
    lcd_write_reg(0xB700, 0x70);
    lcd_write_reg(0xB701, 0x70);
    /* Source EQ control (Mode 2) */
    lcd_write_reg(0xB800, 0x01);
    lcd_write_reg(0xB801, 0x03);
    lcd_write_reg(0xB802, 0x03);
    lcd_write_reg(0xB803, 0x03);
    /* Inversion mode (2-dot) */
    lcd_write_reg(0xBC00, 0x02);
    lcd_write_reg(0xBC01, 0x00);
    lcd_write_reg(0xBC02, 0x00);
    /* Timing control 4H w/ 4-delay */
    lcd_write_reg(0xC900, 0xD0);
    lcd_write_reg(0xC901, 0x02);
    lcd_write_reg(0xC902, 0x50);
    lcd_write_reg(0xC903, 0x50);
    lcd_write_reg(0xC904, 0x50);
    lcd_write_reg(0x3500, 0x00);
    lcd_write_reg(0x3A00, 0x55); /* 16-bit/pixel */
    lcd_wr_regno(0x1100);
    delay_us(120);
    lcd_wr_regno(0x2900);
}








void lcd_ex_OTM8009_reginit(void)
{
       lcd_write_reg(0xFF00,0x80);
        lcd_write_reg(0xFF01,0x09);
        lcd_write_reg(0xFF02,0x01);
        lcd_write_reg(0xFF80,0x80);
        lcd_write_reg(0xFF81,0x09);
        lcd_write_reg(0xFF03,0x01);  

        lcd_write_reg(0xC0B4,0x10);
        lcd_write_reg(0xC489,0x08);
        lcd_write_reg(0xC0A3,0x00);
        lcd_write_reg(0xC582,0xA3);
        lcd_write_reg(0xC590,0xD6);
        lcd_write_reg(0xC591,0x87);

        lcd_write_reg(0xD800,0x74);
        lcd_write_reg(0xD801,0x72);

        lcd_write_reg(0xD900,0x60);	

        lcd_write_reg(0xE100,0x09);	
        lcd_write_reg(0xE101,0x0C);	
        lcd_write_reg(0xE102,0x12);	
        lcd_write_reg(0xE103,0x0E);	
        lcd_write_reg(0xE104,0x08);	
        lcd_write_reg(0xE105,0x19);	
        lcd_write_reg(0xE106,0x0C);	
        lcd_write_reg(0xE107,0x0B);	
        lcd_write_reg(0xE108,0x01);	
        lcd_write_reg(0xE109,0x05);	
        lcd_write_reg(0xE10A,0x03);	
        lcd_write_reg(0xE10B,0x07);	
        lcd_write_reg(0xE10C,0x0E);	
        lcd_write_reg(0xE10D,0x26);	
        lcd_write_reg(0xE10E,0x23);	
        lcd_write_reg(0xE10F,0x1B); 

        lcd_write_reg(0xE200,0x09);
        lcd_write_reg(0xE201,0x0C);
        lcd_write_reg(0xE202,0x12);
        lcd_write_reg(0xE203,0x0E);
        lcd_write_reg(0xE204,0x08);
        lcd_write_reg(0xE205,0x19);
        lcd_write_reg(0xE206,0x0C);
        lcd_write_reg(0xE207,0x0B);
        lcd_write_reg(0xE208,0x01);
        lcd_write_reg(0xE209,0x05);
        lcd_write_reg(0xE20A,0x03);
        lcd_write_reg(0xE20B,0x07);
        lcd_write_reg(0xE20C,0x0E);
        lcd_write_reg(0xE20D,0x26);
        lcd_write_reg(0xE20E,0x23);
        lcd_write_reg(0xE20F,0x1B);

        lcd_write_reg(0xC181,0x66);
        lcd_write_reg(0xC1A1,0x08);
        lcd_write_reg(0xC481,0x83);
        lcd_write_reg(0xC592,0x01);  
        lcd_write_reg(0xC5B1,0xA9);
        lcd_write_reg(0xCE80,0x85);

        lcd_write_reg(0xCE81,0x03);
        lcd_write_reg(0xCE82,0x00);
        lcd_write_reg(0xCE83,0x84);
        lcd_write_reg(0xCE84,0x03);
        lcd_write_reg(0xCE85,0x00);	                       
        lcd_write_reg(0xCE86,0x83);	                      
        lcd_write_reg(0xCE87,0x03);	                       
        lcd_write_reg(0xCE88,0x00);	                       
        lcd_write_reg(0xCE89,0x82);
        lcd_write_reg(0xCE8A,0x03);
        lcd_write_reg(0xCE8B,0x00);
        lcd_write_reg(0xCEA0,0x38);
        lcd_write_reg(0xCEA1,0x02);
        lcd_write_reg(0xCEA2,0x03);
        lcd_write_reg(0xCEA3,0x21);
        lcd_write_reg(0xCEA4,0x00);
        lcd_write_reg(0xCEA5,0x00);
        lcd_write_reg(0xCEA6,0x00);
        lcd_write_reg(0xCEA7,0x38);
        lcd_write_reg(0xCEA8,0x01);
        lcd_write_reg(0xCEA9,0x03);
        lcd_write_reg(0xCEAA,0x22);
        lcd_write_reg(0xCEAB,0x00);
        lcd_write_reg(0xCEAC,0x00);
        lcd_write_reg(0xCEAD,0x00);
        lcd_write_reg(0xCEB0,0x38);
        lcd_write_reg(0xCEB1,0x00);
        lcd_write_reg(0xCEB2,0x03);
        lcd_write_reg(0xCEB3,0x23);
        lcd_write_reg(0xCEB4,0x00);
        lcd_write_reg(0xCEB5,0x00);
        lcd_write_reg(0xCEB6,0x00);
        lcd_write_reg(0xCEB7,0x30);
        lcd_write_reg(0xCEB8,0x00);
        lcd_write_reg(0xCEB9,0x03);
        lcd_write_reg(0xCEBA,0x24);
        lcd_write_reg(0xCEBB,0x00);
        lcd_write_reg(0xCEBC,0x00);
        lcd_write_reg(0xCEBD,0x00);
        lcd_write_reg(0xCEC0,0x30);
        lcd_write_reg(0xCEC1,0x01);
        lcd_write_reg(0xCEC2,0x03);
        lcd_write_reg(0xCEC3,0x25);
        lcd_write_reg(0xCEC4,0x00);
        lcd_write_reg(0xCEC5,0x00);
        lcd_write_reg(0xCEC6,0x00);
        lcd_write_reg(0xCEC7,0x30);
        lcd_write_reg(0xCEC8,0x02);
        lcd_write_reg(0xCEC9,0x03);
        lcd_write_reg(0xCECA,0x26);
        lcd_write_reg(0xCECB,0x00);
        lcd_write_reg(0xCECC,0x00);
        lcd_write_reg(0xCECD,0x00);
        lcd_write_reg(0xCED0,0x30);
        lcd_write_reg(0xCED1,0x03);
        lcd_write_reg(0xCED2,0x03);
        lcd_write_reg(0xCED3,0x27);
        lcd_write_reg(0xCED4,0x00);
        lcd_write_reg(0xCED5,0x00);
        lcd_write_reg(0xCED6,0x00);
        lcd_write_reg(0xCED7,0x30);
        lcd_write_reg(0xCED8,0x04);
        lcd_write_reg(0xCED9,0x03);
        lcd_write_reg(0xCEDA,0x28);
        lcd_write_reg(0xCEDB,0x00);
        lcd_write_reg(0xCEDC,0x00);
        lcd_write_reg(0xCEDD,0x00);
        lcd_write_reg(0xCFC0,0x00);
        lcd_write_reg(0xCFC1,0x00);
        lcd_write_reg(0xCFC2,0x00);
        lcd_write_reg(0xCFC3,0x00);
        lcd_write_reg(0xCFC4,0x00);
        lcd_write_reg(0xCFC5,0x00);
        lcd_write_reg(0xCFC6,0x00);
        lcd_write_reg(0xCFC7,0x00);
        lcd_write_reg(0xCFC8,0x00);
        lcd_write_reg(0xCFC9,0x00);
        lcd_write_reg(0xCFD0,0x00);
        lcd_write_reg(0xCBC0,0x00);
        lcd_write_reg(0xCBC1,0x00);
        lcd_write_reg(0xCBC2,0x00);
        lcd_write_reg(0xCBC3,0x00);
        lcd_write_reg(0xCBC4,0x04);
        lcd_write_reg(0xCBC5,0x04);
        lcd_write_reg(0xCBC6,0x04);
        lcd_write_reg(0xCBC7,0x04);
        lcd_write_reg(0xCBC8,0x04);
        lcd_write_reg(0xCBC9,0x04);
        lcd_write_reg(0xCBCA,0x00);
        lcd_write_reg(0xCBCB,0x00);
        lcd_write_reg(0xCBCC,0x00);
        lcd_write_reg(0xCBCD,0x00);
        lcd_write_reg(0xCBCE,0x00);
        lcd_write_reg(0xCBD0,0x00);
        lcd_write_reg(0xCBD1,0x00);
        lcd_write_reg(0xCBD2,0x00);
        lcd_write_reg(0xCBD3,0x00);
        lcd_write_reg(0xCBD4,0x00);
        lcd_write_reg(0xCBD5,0x00);
        lcd_write_reg(0xCBD6,0x00);
        lcd_write_reg(0xCBD7,0x00);
        lcd_write_reg(0xCBD8,0x00);
        lcd_write_reg(0xCBD9,0x04);
        lcd_write_reg(0xCBDA,0x04);
        lcd_write_reg(0xCBDB,0x04);
        lcd_write_reg(0xCBDC,0x04);
        lcd_write_reg(0xCBDD,0x04);
        lcd_write_reg(0xCBDE,0x04);
        lcd_write_reg(0xCBE0,0x00);
        lcd_write_reg(0xCBE1,0x00);
        lcd_write_reg(0xCBE2,0x00);
        lcd_write_reg(0xCBE3,0x00);
        lcd_write_reg(0xCBE4,0x00);
        lcd_write_reg(0xCBE5,0x00);
        lcd_write_reg(0xCBE6,0x00);
        lcd_write_reg(0xCBE7,0x00);
        lcd_write_reg(0xCBE8,0x00);
        lcd_write_reg(0xCBE9,0x00);
        lcd_write_reg(0xCC80,0x00);
        lcd_write_reg(0xCC81,0x00);
        lcd_write_reg(0xCC82,0x00);
        lcd_write_reg(0xCC83,0x00);
        lcd_write_reg(0xCC84,0x0C);
        lcd_write_reg(0xCC85,0x0A);
        lcd_write_reg(0xCC86,0x10);
        lcd_write_reg(0xCC87,0x0E);
        lcd_write_reg(0xCC88,0x03);
        lcd_write_reg(0xCC89,0x04);
        lcd_write_reg(0xCC90,0x00);
        lcd_write_reg(0xCC91,0x00);
        lcd_write_reg(0xCC92,0x00);
        lcd_write_reg(0xCC93,0x00);
        lcd_write_reg(0xCC94,0x00);
        lcd_write_reg(0xCC95,0x00);
        lcd_write_reg(0xCC96,0x00);
        lcd_write_reg(0xCC97,0x00);
        lcd_write_reg(0xCC98,0x00);
        lcd_write_reg(0xCC99,0x00);
        lcd_write_reg(0xCC9A,0x00);
        lcd_write_reg(0xCC9B,0x00);
        lcd_write_reg(0xCC9C,0x00);
        lcd_write_reg(0xCC9D,0x00);
        lcd_write_reg(0xCC9E,0x0B);
        lcd_write_reg(0xCCA0,0x09);
        lcd_write_reg(0xCCA1,0x0F);
        lcd_write_reg(0xCCA2,0x0D);
        lcd_write_reg(0xCCA3,0x01);
        lcd_write_reg(0xCCA4,0x02);
        lcd_write_reg(0xCCA5,0x00);
        lcd_write_reg(0xCCA6,0x00);
        lcd_write_reg(0xCCA7,0x00);
        lcd_write_reg(0xCCA8,0x00);
        lcd_write_reg(0xCCA9,0x00);
        lcd_write_reg(0xCCAA,0x00);
        lcd_write_reg(0xCCAB,0x00);
        lcd_write_reg(0xCCAC,0x00);
        lcd_write_reg(0xCCAD,0x00);
        lcd_write_reg(0xCCAE,0x00);	
        lcd_write_reg(0xCCB0,0x00);
        lcd_write_reg(0xCCB1,0x00);
        lcd_write_reg(0xCCB2,0x00);
        lcd_write_reg(0xCCB3,0x00);
        lcd_write_reg(0xCCB4,0x0D);
        lcd_write_reg(0xCCB5,0x0F);
        lcd_write_reg(0xCCB6,0x09);
        lcd_write_reg(0xCCB7,0x0B);
        lcd_write_reg(0xCCB8,0x02);
        lcd_write_reg(0xCCB9,0x01);
        lcd_write_reg(0xCCC0,0x00);
        lcd_write_reg(0xCCC1,0x00);
        lcd_write_reg(0xCCC2,0x00);
        lcd_write_reg(0xCCC3,0x00);
        lcd_write_reg(0xCCC4,0x00);
        lcd_write_reg(0xCCC5,0x00);
        lcd_write_reg(0xCCC6,0x00);
        lcd_write_reg(0xCCC7,0x00);
        lcd_write_reg(0xCCC8,0x00);
        lcd_write_reg(0xCCC9,0x00);
        lcd_write_reg(0xCCCA,0x00);
        lcd_write_reg(0xCCCB,0x00);
        lcd_write_reg(0xCCCC,0x00);
        lcd_write_reg(0xCCCD,0x00);
        lcd_write_reg(0xCCCE,0x0E);
        lcd_write_reg(0xCCD0,0x10);
        lcd_write_reg(0xCCD1,0x0A);
        lcd_write_reg(0xCCD2,0x0C);
        lcd_write_reg(0xCCD3,0x04);
        lcd_write_reg(0xCCD4,0x03);
        lcd_write_reg(0xCCD5,0x00);
        lcd_write_reg(0xCCD6,0x00);
        lcd_write_reg(0xCCD7,0x00);
        lcd_write_reg(0xCCD8,0x00);
        lcd_write_reg(0xCCD9,0x00);
        lcd_write_reg(0xCCDA,0x00);
        lcd_write_reg(0xCCDB,0x00);
        lcd_write_reg(0xCCDC,0x00);
        lcd_write_reg(0xCCDD,0x00);
        lcd_write_reg(0xCCDE,0x00);

        //lcd_write_reg(0xB391,0x20);
        //lcd_write_reg(0xB392,0x20);//BGR

        lcd_write_reg(0xFF00,0xFF); 
        lcd_write_reg(0xFF01,0xFF); 
        lcd_write_reg(0xFF02,0xFF); 

        lcd_write_reg(0x3600,0xD0);// DisplAy DirECtion 180
        lcd_write_reg(0x3500,0x00);// TE( FmArk ) SignAl On
        lcd_write_reg(0x4400,0x01);
        lcd_write_reg(0x4401,0xFF);// TE( FmArk ) SignAl Output Position

        lcd_write_reg(0x3600,0x08);// DisplAy DirECtion 0
        lcd_write_reg(0x3500,0x00);// TE( FmArk ) SignAl On
        lcd_write_reg(0x4400,0x01);
        lcd_write_reg(0x4401,0x22);// TE( FmArk ) SignAl Output Position

        lcd_write_reg(0x5100,0xFF);// BACklight LEvEl Control
        lcd_write_reg(0x5300,0x2C);// BACklight On
        lcd_write_reg(0x5500,0x00);// CABC FunCtion OFF

        lcd_write_reg(0x3A00,0x55);	
        lcd_wr_regno(0x1100);
        delay_us(120);
        lcd_wr_regno(0x2900);

}


void lcd_ex_RM68120_reginit(void)
{
 			lcd_write_reg(0x1100,0x00);//Sleep out
			delay_ms(120);//delay_ms 120ms	
			/////Start Initial Sequence /////
			lcd_write_reg(0xF000,0x55); //page 1
			lcd_write_reg(0xF001,0xAA);
			lcd_write_reg(0xF002,0x52);
			lcd_write_reg(0xF003,0x08);
			lcd_write_reg(0xF004,0x01);

			lcd_write_reg(0xD100,0x00);//Gamma setting Red
			lcd_write_reg(0xD101,0x00);
			lcd_write_reg(0xD102,0x22);
			lcd_write_reg(0xD103,0x55);
			lcd_write_reg(0xD104,0x78);
			lcd_write_reg(0xD105,0x40);
			lcd_write_reg(0xD106,0x93);
			lcd_write_reg(0xD107,0xBF);
			lcd_write_reg(0xD108,0xE0);
			lcd_write_reg(0xD109,0x10);
			lcd_write_reg(0xD10A,0x55);
			lcd_write_reg(0xD10B,0x33);
			lcd_write_reg(0xD10C,0x4F);
			lcd_write_reg(0xD10D,0x66);
			lcd_write_reg(0xD10E,0x7A);
			lcd_write_reg(0xD10F,0x55);
			lcd_write_reg(0xD110,0x8C);
			lcd_write_reg(0xD111,0x9C);
			lcd_write_reg(0xD112,0xA9);
			lcd_write_reg(0xD113,0xB6);
			lcd_write_reg(0xD114,0x55);
			lcd_write_reg(0xD115,0xC2);
			lcd_write_reg(0xD116,0xCE);
			lcd_write_reg(0xD117,0xD8);
			lcd_write_reg(0xD118,0xE2);
			lcd_write_reg(0xD119,0x55);
			lcd_write_reg(0xD11A,0xEC);
			lcd_write_reg(0xD11B,0xED);
			lcd_write_reg(0xD11C,0xF6);
			lcd_write_reg(0xD11D,0xFF);
			lcd_write_reg(0xD11E,0xAA);
			lcd_write_reg(0xD11F,0x07);
			lcd_write_reg(0xD120,0x0F);
			lcd_write_reg(0xD121,0x17);
			lcd_write_reg(0xD122,0x20);
			lcd_write_reg(0xD123,0xAA);
			lcd_write_reg(0xD124,0x28);
			lcd_write_reg(0xD125,0x30);
			lcd_write_reg(0xD126,0x3A);
			lcd_write_reg(0xD127,0x44);
			lcd_write_reg(0xD128,0xAA);
			lcd_write_reg(0xD129,0x52);
			lcd_write_reg(0xD12A,0x66);
			lcd_write_reg(0xD12B,0x86);
			lcd_write_reg(0xD12C,0xC5);
			lcd_write_reg(0xD12D,0xFF);
			lcd_write_reg(0xD12E,0x00);
			lcd_write_reg(0xD12F,0x51);
			lcd_write_reg(0xD130,0x8D);
			lcd_write_reg(0xD131,0xC4);
			lcd_write_reg(0xD132,0x0F);
			lcd_write_reg(0xD133,0xE0);
			lcd_write_reg(0xD134,0xFF);

			lcd_write_reg(0xD200,0x00);//Gamma setting Green
			lcd_write_reg(0xD201,0x00);
			lcd_write_reg(0xD202,0x22);
			lcd_write_reg(0xD203,0x55);
			lcd_write_reg(0xD204,0x78);
			lcd_write_reg(0xD205,0x40);
			lcd_write_reg(0xD206,0x93);
			lcd_write_reg(0xD207,0xBF);
			lcd_write_reg(0xD208,0xE0);
			lcd_write_reg(0xD209,0x10);
			lcd_write_reg(0xD20A,0x55);
			lcd_write_reg(0xD20B,0x33);
			lcd_write_reg(0xD20C,0x4F);
			lcd_write_reg(0xD20D,0x66);
			lcd_write_reg(0xD20E,0x7A);
			lcd_write_reg(0xD20F,0x55);
			lcd_write_reg(0xD210,0x8C);
			lcd_write_reg(0xD211,0x9C);
			lcd_write_reg(0xD212,0xA9);
			lcd_write_reg(0xD213,0xB6);
			lcd_write_reg(0xD214,0x55);
			lcd_write_reg(0xD215,0xC2);
			lcd_write_reg(0xD216,0xCE);
			lcd_write_reg(0xD217,0xD8);
			lcd_write_reg(0xD218,0xE2);
			lcd_write_reg(0xD219,0x55);
			lcd_write_reg(0xD21A,0xEC);
			lcd_write_reg(0xD21B,0xED);
			lcd_write_reg(0xD21C,0xF6);
			lcd_write_reg(0xD21D,0xFF);
			lcd_write_reg(0xD21E,0xAA);
			lcd_write_reg(0xD21F,0x07);
			lcd_write_reg(0xD220,0x0F);
			lcd_write_reg(0xD221,0x17);
			lcd_write_reg(0xD222,0x20);
			lcd_write_reg(0xD223,0xAA);
			lcd_write_reg(0xD224,0x28);
			lcd_write_reg(0xD225,0x30);
			lcd_write_reg(0xD226,0x3A);
			lcd_write_reg(0xD227,0x44);
			lcd_write_reg(0xD228,0xAA);
			lcd_write_reg(0xD229,0x52);
			lcd_write_reg(0xD22A,0x66);
			lcd_write_reg(0xD22B,0x86);
			lcd_write_reg(0xD22C,0xC5);
			lcd_write_reg(0xD22D,0xFF);
			lcd_write_reg(0xD22E,0x00);
			lcd_write_reg(0xD22F,0x51);
			lcd_write_reg(0xD230,0x8D);
			lcd_write_reg(0xD231,0xC4);
			lcd_write_reg(0xD232,0x0F);
			lcd_write_reg(0xD233,0xE0);
			lcd_write_reg(0xD234,0xFF);

			lcd_write_reg(0xD300,0x00);//Gamma setting Blue
			lcd_write_reg(0xD301,0x00);
			lcd_write_reg(0xD302,0x22);
			lcd_write_reg(0xD303,0x55);
			lcd_write_reg(0xD304,0x78);
			lcd_write_reg(0xD305,0x40);
			lcd_write_reg(0xD306,0x93);
			lcd_write_reg(0xD307,0xBF);
			lcd_write_reg(0xD308,0xE0);
			lcd_write_reg(0xD309,0x10);
			lcd_write_reg(0xD30A,0x55);
			lcd_write_reg(0xD30B,0x33);
			lcd_write_reg(0xD30C,0x4F);
			lcd_write_reg(0xD30D,0x66);
			lcd_write_reg(0xD30E,0x7A);
			lcd_write_reg(0xD30F,0x55);
			lcd_write_reg(0xD310,0x8C);
			lcd_write_reg(0xD311,0x9C);
			lcd_write_reg(0xD312,0xA9);
			lcd_write_reg(0xD313,0xB6);
			lcd_write_reg(0xD314,0x55);
			lcd_write_reg(0xD315,0xC2);
			lcd_write_reg(0xD316,0xCE);
			lcd_write_reg(0xD317,0xD8);
			lcd_write_reg(0xD318,0xE2);
			lcd_write_reg(0xD319,0x55);
			lcd_write_reg(0xD31A,0xEC);
			lcd_write_reg(0xD31B,0xED);
			lcd_write_reg(0xD31C,0xF6);
			lcd_write_reg(0xD31D,0xFF);
			lcd_write_reg(0xD31E,0xAA);
			lcd_write_reg(0xD31F,0x07);
			lcd_write_reg(0xD320,0x0F);
			lcd_write_reg(0xD321,0x17);
			lcd_write_reg(0xD322,0x20);
			lcd_write_reg(0xD323,0xAA);
			lcd_write_reg(0xD324,0x28);
			lcd_write_reg(0xD325,0x30);
			lcd_write_reg(0xD326,0x3A);
			lcd_write_reg(0xD327,0x44);
			lcd_write_reg(0xD328,0xAA);
			lcd_write_reg(0xD329,0x52);
			lcd_write_reg(0xD32A,0x66);
			lcd_write_reg(0xD32B,0x86);
			lcd_write_reg(0xD32C,0xC5);
			lcd_write_reg(0xD32D,0xFF);
			lcd_write_reg(0xD32E,0x00);
			lcd_write_reg(0xD32F,0x51);
			lcd_write_reg(0xD330,0x8D);
			lcd_write_reg(0xD331,0xC4);
			lcd_write_reg(0xD332,0x0F);
			lcd_write_reg(0xD333,0xE0);
			lcd_write_reg(0xD334,0xFF);

			lcd_write_reg(0xD400,0x00);//Gamma setting Red
			lcd_write_reg(0xD401,0x00);
			lcd_write_reg(0xD402,0x22);
			lcd_write_reg(0xD403,0x55);
			lcd_write_reg(0xD404,0x78);
			lcd_write_reg(0xD405,0x40);
			lcd_write_reg(0xD406,0x93);
			lcd_write_reg(0xD407,0xBF);
			lcd_write_reg(0xD408,0xE0);
			lcd_write_reg(0xD409,0x10);
			lcd_write_reg(0xD40A,0x55);
			lcd_write_reg(0xD40B,0x33);
			lcd_write_reg(0xD40C,0x4F);
			lcd_write_reg(0xD40D,0x66);
			lcd_write_reg(0xD40E,0x7A);
			lcd_write_reg(0xD40F,0x55);
			lcd_write_reg(0xD410,0x8C);
			lcd_write_reg(0xD411,0x9C);
			lcd_write_reg(0xD412,0xA9);
			lcd_write_reg(0xD413,0xB6);
			lcd_write_reg(0xD414,0x55);
			lcd_write_reg(0xD415,0xC2);
			lcd_write_reg(0xD416,0xCE);
			lcd_write_reg(0xD417,0xD8);
			lcd_write_reg(0xD418,0xE2);
			lcd_write_reg(0xD419,0x55);
			lcd_write_reg(0xD41A,0xEC);
			lcd_write_reg(0xD41B,0xED);
			lcd_write_reg(0xD41C,0xF6);
			lcd_write_reg(0xD41D,0xFF);
			lcd_write_reg(0xD41E,0xAA);
			lcd_write_reg(0xD41F,0x07);
			lcd_write_reg(0xD420,0x0F);
			lcd_write_reg(0xD421,0x17);
			lcd_write_reg(0xD422,0x20);
			lcd_write_reg(0xD423,0xAA);
			lcd_write_reg(0xD424,0x28);
			lcd_write_reg(0xD425,0x30);
			lcd_write_reg(0xD426,0x3A);
			lcd_write_reg(0xD427,0x44);
			lcd_write_reg(0xD428,0xAA);
			lcd_write_reg(0xD429,0x52);
			lcd_write_reg(0xD42A,0x66);
			lcd_write_reg(0xD42B,0x86);
			lcd_write_reg(0xD42C,0xC5);
			lcd_write_reg(0xD42D,0xFF);
			lcd_write_reg(0xD42E,0x00);
			lcd_write_reg(0xD42F,0x51);
			lcd_write_reg(0xD430,0x8D);
			lcd_write_reg(0xD431,0xC4);
			lcd_write_reg(0xD432,0x0F);
			lcd_write_reg(0xD433,0xE0);
			lcd_write_reg(0xD434,0xFF);

			lcd_write_reg(0xD500,0x00);//Gamma setting Green
			lcd_write_reg(0xD501,0x00);
			lcd_write_reg(0xD502,0x22);
			lcd_write_reg(0xD503,0x55);
			lcd_write_reg(0xD504,0x78);
			lcd_write_reg(0xD505,0x40);
			lcd_write_reg(0xD506,0x93);
			lcd_write_reg(0xD507,0xBF);
			lcd_write_reg(0xD508,0xE0);
			lcd_write_reg(0xD509,0x10);
			lcd_write_reg(0xD50A,0x55);
			lcd_write_reg(0xD50B,0x33);
			lcd_write_reg(0xD50C,0x4F);
			lcd_write_reg(0xD50D,0x66);
			lcd_write_reg(0xD50E,0x7A);
			lcd_write_reg(0xD50F,0x55);
			lcd_write_reg(0xD510,0x8C);
			lcd_write_reg(0xD511,0x9C);
			lcd_write_reg(0xD512,0xA9);
			lcd_write_reg(0xD513,0xB6);
			lcd_write_reg(0xD514,0x55);
			lcd_write_reg(0xD515,0xC2);
			lcd_write_reg(0xD516,0xCE);
			lcd_write_reg(0xD517,0xD8);
			lcd_write_reg(0xD518,0xE2);
			lcd_write_reg(0xD519,0x55);
			lcd_write_reg(0xD51A,0xEC);
			lcd_write_reg(0xD51B,0xED);
			lcd_write_reg(0xD51C,0xF6);
			lcd_write_reg(0xD51D,0xFF);
			lcd_write_reg(0xD51E,0xAA);
			lcd_write_reg(0xD51F,0x07);
			lcd_write_reg(0xD520,0x0F);
			lcd_write_reg(0xD521,0x17);
			lcd_write_reg(0xD522,0x20);
			lcd_write_reg(0xD523,0xAA);
			lcd_write_reg(0xD524,0x28);
			lcd_write_reg(0xD525,0x30);
			lcd_write_reg(0xD526,0x3A);
			lcd_write_reg(0xD527,0x44);
			lcd_write_reg(0xD528,0xAA);
			lcd_write_reg(0xD529,0x52);
			lcd_write_reg(0xD52A,0x66);
			lcd_write_reg(0xD52B,0x86);
			lcd_write_reg(0xD52C,0xC5);
			lcd_write_reg(0xD52D,0xFF);
			lcd_write_reg(0xD52E,0x00);
			lcd_write_reg(0xD52F,0x51);
			lcd_write_reg(0xD530,0x8D);
			lcd_write_reg(0xD531,0xC4);
			lcd_write_reg(0xD532,0x0F);
			lcd_write_reg(0xD533,0xE0);
			lcd_write_reg(0xD534,0xFF);

			lcd_write_reg(0xD600,0x00);//Gamma setting Blue
			lcd_write_reg(0xD601,0x00);
			lcd_write_reg(0xD602,0x22);
			lcd_write_reg(0xD603,0x55);
			lcd_write_reg(0xD604,0x78);
			lcd_write_reg(0xD605,0x40);
			lcd_write_reg(0xD606,0x93);
			lcd_write_reg(0xD607,0xBF);
			lcd_write_reg(0xD608,0xE0);
			lcd_write_reg(0xD609,0x10);
			lcd_write_reg(0xD60A,0x55);
			lcd_write_reg(0xD60B,0x33);
			lcd_write_reg(0xD60C,0x4F);
			lcd_write_reg(0xD60D,0x66);
			lcd_write_reg(0xD60E,0x7A);
			lcd_write_reg(0xD60F,0x55);
			lcd_write_reg(0xD610,0x8C);
			lcd_write_reg(0xD611,0x9C);
			lcd_write_reg(0xD612,0xA9);
			lcd_write_reg(0xD613,0xB6);
			lcd_write_reg(0xD614,0x55);
			lcd_write_reg(0xD615,0xC2);
			lcd_write_reg(0xD616,0xCE);
			lcd_write_reg(0xD617,0xD8);
			lcd_write_reg(0xD618,0xE2);
			lcd_write_reg(0xD619,0x55);
			lcd_write_reg(0xD61A,0xEC);
			lcd_write_reg(0xD61B,0xED);
			lcd_write_reg(0xD61C,0xF6);
			lcd_write_reg(0xD61D,0xFF);
			lcd_write_reg(0xD61E,0xAA);
			lcd_write_reg(0xD61F,0x07);
			lcd_write_reg(0xD620,0x0F);
			lcd_write_reg(0xD621,0x17);
			lcd_write_reg(0xD622,0x20);
			lcd_write_reg(0xD623,0xAA);
			lcd_write_reg(0xD624,0x28);
			lcd_write_reg(0xD625,0x30);
			lcd_write_reg(0xD626,0x3A);
			lcd_write_reg(0xD627,0x44);
			lcd_write_reg(0xD628,0xAA);
			lcd_write_reg(0xD629,0x52);
			lcd_write_reg(0xD62A,0x66);
			lcd_write_reg(0xD62B,0x86);
			lcd_write_reg(0xD62C,0xC5);
			lcd_write_reg(0xD62D,0xFF);
			lcd_write_reg(0xD62E,0x00);
			lcd_write_reg(0xD62F,0x51);
			lcd_write_reg(0xD630,0x8D);
			lcd_write_reg(0xD631,0xC4);
			lcd_write_reg(0xD632,0x0F);
			lcd_write_reg(0xD633,0xE0);
			lcd_write_reg(0xD634,0xFF);

			lcd_write_reg(0xB000,0x00);//AVDD
			lcd_write_reg(0xB001,0x00);
			lcd_write_reg(0xB002,0x00);

			lcd_write_reg(0xB100,0x05);//AVEE
			lcd_write_reg(0xB101,0x05);
			lcd_write_reg(0xB102,0x05);

			lcd_write_reg(0xB600,0x44);//AVDD Boosting
			lcd_write_reg(0xB601,0x44);
			lcd_write_reg(0xB602,0x44);

			lcd_write_reg(0xB700,0x34);//AVEE Boosting
			lcd_write_reg(0xB701,0x34);
			lcd_write_reg(0xB702,0x34);

			lcd_write_reg(0xB900,0x34);//VGH
			lcd_write_reg(0xB901,0x34);
			lcd_write_reg(0xB902,0x34);

			lcd_write_reg(0xBA00,0x14);//VGL
			lcd_write_reg(0xBA01,0x14);
			lcd_write_reg(0xBA02,0x14);

			lcd_write_reg(0xBC00,0x00);
			lcd_write_reg(0xBC01,0xB8);//VGMP

			lcd_write_reg(0xBD00,0x00);
			lcd_write_reg(0xBD01,0xB8);//VGMN

			lcd_write_reg(0xBE00,0x00);//VCOM
			lcd_write_reg(0xBE01,0x58);//VCOM

			lcd_write_reg(0xF000,0x55);//Enable Page 0
			lcd_write_reg(0xF001,0xAA);
			lcd_write_reg(0xF002,0x52);
			lcd_write_reg(0xF003,0x08);
			lcd_write_reg(0xF004,0x00);

			lcd_write_reg(0xB400,0x10);//Color Enhancement Enable

			lcd_write_reg(0xB600,0x02);//Source Output Control

			lcd_write_reg(0xB000,0x00);//Control Signal Polarity	 RGB mode1/mode2 select no enable mode

			lcd_write_reg(0xB100,0xf8);//RAM Keep
			lcd_write_reg(0xB101,0x00);//Normal Scan
			delay_ms(10);//delay_ms 10ms
			lcd_write_reg(0xB700,0x22);//Gate EQ Control
			lcd_write_reg(0xB701,0x22);

			lcd_write_reg(0xC800,0x01);//Display Timing Control
			lcd_write_reg(0xC801,0x00);
			lcd_write_reg(0xC802,0x54);
			lcd_write_reg(0xC803,0x38);
			lcd_write_reg(0xC804,0x54);
			lcd_write_reg(0xC805,0x38);
			lcd_write_reg(0xC806,0x54);
			lcd_write_reg(0xC807,0x38);
			lcd_write_reg(0xC808,0x54);
			lcd_write_reg(0xC809,0x38);
			lcd_write_reg(0xC80A,0x8C);
			lcd_write_reg(0xC80B,0x2A);
			lcd_write_reg(0xC80C,0x2A);
			lcd_write_reg(0xC80D,0x8C);
			lcd_write_reg(0xC80E,0x8C);
			lcd_write_reg(0xC80F,0x2A);
			lcd_write_reg(0xC810,0x2A);

			lcd_write_reg(0xB800,0x01);//Source EQ Control
			lcd_write_reg(0xB801,0x03);
			lcd_write_reg(0xB802,0x03);
			lcd_write_reg(0xB803,0x03);

			lcd_write_reg(0xBC00,0x05);//Z-inversion
			lcd_write_reg(0xBC01,0x05);
			lcd_write_reg(0xBC02,0x05);

			lcd_write_reg(0xD000,0x01);//PWM_ENH_OE=1

			lcd_write_reg(0xBA00,0x01);//PRG=0

			lcd_write_reg(0xBD00,0x01);//Porch Lines
			lcd_write_reg(0xBD01,0x10);//Porch Lines
			lcd_write_reg(0xBD02,0x07);//Porch Lines
			lcd_write_reg(0xBD03,0x07);//Porch Lines

			lcd_write_reg(0xBE00,0x01);//Porch Lines
			lcd_write_reg(0xBE01,0x10);//Porch Lines
			lcd_write_reg(0xBE02,0x07);//Porch Lines
			lcd_write_reg(0xBE03,0x07);//Porch Lines

			lcd_write_reg(0xBF00,0x01);//Porch Lines
			lcd_write_reg(0xBF01,0x10);//Porch Lines
			lcd_write_reg(0xBF02,0x07);//Porch Lines
			lcd_write_reg(0xBF03,0x07);//Porch Lines

			lcd_write_reg(0xF000,0x55);//Enable Page 2
			lcd_write_reg(0xF001,0xAA);
			lcd_write_reg(0xF002,0x52);
			lcd_write_reg(0xF003,0x08);
			lcd_write_reg(0xF004,0x02);

			lcd_write_reg(0xC300,0x00);
			lcd_write_reg(0xC301,0xA9);

			lcd_write_reg(0xFE00,0x00);
			lcd_write_reg(0xFE01,0x94);

			lcd_write_reg(0x3500,0x00);//TE Enable

			lcd_write_reg(0x3600,0x08); ///0x08

			lcd_write_reg(0x3A00,0x55);//Color Depth

            lcd_wr_regno(0x1100);
            delay_us(120);
            lcd_wr_regno(0x2900);


}



/**
 * @brief       SSD1963寄存器初始化代码 
 * @param       无
 * @retval      无
 */


void lcd_ex_ssd1963_reginit(void)
{
    lcd_wr_regno(0xE2); /* Set PLL with OSC = 10MHz (hardware),	Multiplier N = 35, 250MHz < VCO < 800MHz = OSC*(N+1), VCO = 300MHz */
    lcd_wr_data(0x1D);  /* 参数1 */
    lcd_wr_data(0x02);  /* 参数2 Divider M = 2, PLL = 300/(M+1) = 100MHz */
    lcd_wr_data(0x04);  /* 参数3 Validate M and N values */
    delay_us(100);
    lcd_wr_regno(0xE0); /*  Start PLL command */
    lcd_wr_data(0x01);  /*  enable PLL */
    delay_ms(10);
    lcd_wr_regno(0xE0); /*  Start PLL command again */
    lcd_wr_data(0x03);  /*  now, use PLL output as system clock */
    delay_ms(12);
    lcd_wr_regno(0x01); /* 软复位 */
    delay_ms(10);

    lcd_wr_regno(0xE6); /* 设置像素频率,33Mhz */
    lcd_wr_data(0x2F);
    lcd_wr_data(0xFF);
    lcd_wr_data(0xFF);

    lcd_wr_regno(0xB0); /* 设置LCD模式 */
    lcd_wr_data(0x20);  /* 24位模式 */
    lcd_wr_data(0x00);  /* TFT 模式 */

    lcd_wr_data((SSD_HOR_RESOLUTION - 1) >> 8); /* 设置LCD水平像素 */
    lcd_wr_data(SSD_HOR_RESOLUTION - 1);
    lcd_wr_data((SSD_VER_RESOLUTION - 1) >> 8); /* 设置LCD垂直像素 */
    lcd_wr_data(SSD_VER_RESOLUTION - 1);
    lcd_wr_data(0x00);  /* RGB序列 */

    lcd_wr_regno(0xB4); /* Set horizontal period */
    lcd_wr_data((SSD_HT - 1) >> 8);
    lcd_wr_data(SSD_HT - 1);
    lcd_wr_data(SSD_HPS >> 8);
    lcd_wr_data(SSD_HPS);
    lcd_wr_data(SSD_HOR_PULSE_WIDTH - 1);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_regno(0xB6); /* Set vertical perio */
    lcd_wr_data((SSD_VT - 1) >> 8);
    lcd_wr_data(SSD_VT - 1);
    lcd_wr_data(SSD_VPS >> 8);
    lcd_wr_data(SSD_VPS);
    lcd_wr_data(SSD_VER_FRONT_PORCH - 1);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    lcd_wr_regno(0xF0); /* 设置SSD1963与CPU接口为16bit */
    lcd_wr_data(0x03);  /* 16-bit(565 format) data for 16bpp */

    lcd_wr_regno(0x29); /* 开启显示 */
    /* 设置PWM输出  背光通过占空比可调 */
    lcd_wr_regno(0xD0); /* 设置自动白平衡DBC */
    lcd_wr_data(0x00);  /* disable */

    lcd_wr_regno(0xBE); /* 配置PWM输出 */
    lcd_wr_data(0x05);  /* 1设置PWM频率 */
    lcd_wr_data(0xFE);  /* 2设置PWM占空比 */
    lcd_wr_data(0x01);  /* 3设置C */
    lcd_wr_data(0x00);  /* 4设置D */
    lcd_wr_data(0x00);  /* 5设置E */
    lcd_wr_data(0x00);  /* 6设置F */

    lcd_wr_regno(0xB8); /* 设置GPIO配置 */
    lcd_wr_data(0x03);  /* 2个IO口设置成输出 */
    lcd_wr_data(0x01);  /* GPIO使用正常的IO功能 */
    lcd_wr_regno(0xBA);
    lcd_wr_data(0X01);  /* GPIO[1:0]=01,控制LCD方向 */
}


















