/**************************************************************************//**
 * @file     ILI9341.c
 * @version  V1.00
 * @brief    Display controller configuration.
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#include <stddef.h>
#include <stdio.h>

#include "GUI.h"
#include "GUIDRV_FlexColor.h"

#include "NuMicro.h"

#include "mbed.h"

#ifdef __DEMO_320x240__
#include "TouchPanel.h"

#include "lcm.h"

SPI spi(PA_8, PA_9, PA_10); // mosi, miso, sclk
DigitalOut GPIO_SPI_SS(PA_11);

DigitalOut GPIO_LCM_DC(PB_2);
DigitalOut ILI9341_LED(PB_5);

#define SPI_PANEL_PORT	SPI2
#define SPI_PANEL_FREQ	40000000

/*********************************************************************
*
*       _Read1
*/
U8 _Read1(void)
{
    /* FIXME if panel supports read back feature */
    return 0;
}

/*********************************************************************
*
*       _ReadM1
*/
void _ReadM1(U8 * pData, int NumItems)
{
    /* FIXME if panel supports read back feature */
}

/*********************************************************************
*
*       _Write0
*/
void _Write0(U8 Cmd)
{
	GPIO_LCM_DC = 0;
    GPIO_SPI_SS = 0;

    spi.write(Cmd);

    GPIO_SPI_SS = 1;
}

/*********************************************************************
*
*       _Write1
*/
void _Write1(U8 Data)
{
	GPIO_LCM_DC = 1;
    GPIO_SPI_SS = 0;

    spi.write(Data);

    GPIO_SPI_SS = 1;
}

/*********************************************************************
*
*       _WriteM1
*/
void _WriteM1(U8 * pData, int NumItems)
{
	GPIO_LCM_DC = 1;
    GPIO_SPI_SS = 0;

    while(NumItems--)
    {
        //spi.write(*pData++);
#if 1
		SPI_WRITE_TX(SPI_PANEL_PORT, *pData++);
        while(SPI_IS_BUSY(SPI_PANEL_PORT));
#endif
    }

    GPIO_SPI_SS = 1;
}

static void _Open_SPI(void)
{
    spi.format(8, 0);
    spi.frequency(SPI_PANEL_FREQ);
}

/*********************************************************************
*
*       _InitController
*
* Purpose:
*   Initializes the display controller
*/
void _InitController(void)
{
    static uint8_t s_InitOnce = 0;

    if(s_InitOnce == 0)
        s_InitOnce = 1;
    else
        return;

    _Open_SPI();

	//Because the Reset signal of Arduino's SPI LCD is pulled together with the Reset signal of M467HJ, the Reset signal cannot be controlled.
    // Reset signal = GPIO_LCM_RST

    GPIO_LCM_DC = 0;
//    GPIO_LCM_RST = 0;
    ILI9341_LED = 0;

    GPIO_LCM_DC = 1;
//    GPIO_LCM_RST = 0;
//    CLK_SysTickDelay(20000);
//    GPIO_LCM_RST = 1;
//    CLK_SysTickDelay(40000);
    //************* Start Initial Sequence **********//

    _Write0(0xCF);
    _Write1(0x00);
    _Write1(0xD9);
    _Write1(0X30);

    _Write0(0xED);
    _Write1(0x64);
    _Write1(0x03);
    _Write1(0X12);
    _Write1(0X81);

    _Write0(0xE8);
    _Write1(0x85);
    _Write1(0x10);
    _Write1(0x78);

    _Write0(0xCB);
    _Write1(0x39);
    _Write1(0x2C);
    _Write1(0x00);
    _Write1(0x34);
    _Write1(0x02);

    _Write0(0xF7);
    _Write1(0x20);

    _Write0(0xEA);
    _Write1(0x00);
    _Write1(0x00);

    _Write0(0xC0);    //Power control
    _Write1(0x21);   //VRH[5:0]

    _Write0(0xC1);    //Power control
    _Write1(0x12);   //SAP[2:0];BT[3:0]

    _Write0(0xC5);    //VCM control
    _Write1(0x32);
    _Write1(0x3C);

    _Write0(0xC7);    //VCM control2
    _Write1(0XC1);

    _Write0(0x36);    // Memory Access Control
    _Write1(0xe8);

    _Write0(0x3A);
    _Write1(0x55);

    _Write0(0xB1);
    _Write1(0x00);
    _Write1(0x18);

    _Write0(0xB6);    // Display Function Control
    _Write1(0x0A);
    _Write1(0xA2);

    _Write0(0xF2);    // 3Gamma Function Disable
    _Write1(0x00);

    _Write0(0x26);    //Gamma curve selected
    _Write1(0x01);

    _Write0(0xE0);    //Set Gamma
    _Write1(0x0F);
    _Write1(0x20);
    _Write1(0x1E);
    _Write1(0x09);
    _Write1(0x12);
    _Write1(0x0B);
    _Write1(0x50);
    _Write1(0XBA);
    _Write1(0x44);
    _Write1(0x09);
    _Write1(0x14);
    _Write1(0x05);
    _Write1(0x23);
    _Write1(0x21);
    _Write1(0x00);

    _Write0(0XE1);    //Set Gamma
    _Write1(0x00);
    _Write1(0x19);
    _Write1(0x19);
    _Write1(0x00);
    _Write1(0x12);
    _Write1(0x07);
    _Write1(0x2D);
    _Write1(0x28);
    _Write1(0x3F);
    _Write1(0x02);
    _Write1(0x0A);
    _Write1(0x08);
    _Write1(0x25);
    _Write1(0x2D);
    _Write1(0x0F);

    _Write0(0x11);    //Exit Sleep
    GUI_X_Delay(120);
    _Write0(0x29);    //Display on

    ILI9341_LED = 1;
}
#endif
