# Getting started sample with emWin simple demo on Mbed OS

This is an example to utilize emWin library to demonstrate interactive feature.

### CLI for NuMaker-PFM-M487
Target board "NUMAKER_PFM_M487" with GCC_ARM toolchain.
1. mbed target "NUMAKER_PFM_M487"
2. mbed toolchain "GCC_ARM"
3. mbed config -G GCC_ARM_PATH "C:\Program Files (x86)\GNU Tools ARM Embedded\6 2017-q1-update\bin"
4. mbed compile

Target board "NUMAKER_PFM_M487" with ARM toolchain.
1. mbed target "NUMAKER_PFM_M487"
2. mbed toolchain "ARM"
3. mbed config -G ARMC6_PATH "C:\Keil_v5\ARM\ARMCLANG\bin"
4. mbed compile

Please note that the toolchain path in step 3 may be different from your environment.

### CLI for NuMaker-IoT-M467
Target board "NUMAKER_IOT_M467" with GCC_ARM toolchain.
1. mbed target "NUMAKER_IOT_M467"
2. mbed toolchain "GCC_ARM"
3. mbed config -G GCC_ARM_PATH "C:\Program Files (x86)\GNU Tools ARM Embedded\6 2017-q1-update\bin"
4. mbed compile

Target board "NUMAKER_IOT_M467" with ARM toolchain.
1. mbed target "NUMAKER_IOT_M467"
2. mbed toolchain "ARM"
3. mbed config -G ARMC6_PATH "C:\Keil_v5\ARM\ARMCLANG\bin"
4. mbed compile

Please note that the toolchain path in step 3 may be different from your environment.

### Burn Code & Execute
1. Connect the board NuMaker-PFM-XXX / NuMaker-IoT-XXX with your PC by USB cable, then there will be one "NuMicro MCU" disk.
2. Copy the built binary file into this disk.
3. Press reset button to execute, user could test emWin simple demo.

### Demo condition, document and link
This demo utilizes LCD and touch to display and touch operation.

LCD: ILI9341 MPU-type RGB56 QVGA LCD with resistive touch panel.

Please go to [Nuvoton website](https://www.nuvoton.com/) and search "emWin" for more details!

The link of emWin quick start guide "M480 emWin Quick Start Guide.pdf" can be found at \emWin\Doc\

[The link of SEGGER emWin official forum](https://forum.segger.com/index.php/Board/12-emWin-related/)

The links of Nuvoton HMI/GUI official forum:
[NuForum](http://forum.nuvoton.com/viewforum.php?f=31)
[牛卧堂](http://nuvoton-mcu.com/forum.php?mod=forumdisplay&fid=86)

### How to utilize emWin tool "GUIBuilder" in Windows?
Please refer to the chapter 4 "EMWIN GUIBUILDER" of "M480 emWin Quick Start Guide.pdf" for more details.

### PIN
M487 TFT pin:
-------------
LCD_RS   PH_3
LCD_REST PB_6
LCD_BL   PB_7

M487 TOUCH pin:
---------------
LCD_XR PB_9
LCD_YU PB_8
LCD_XL PH_4
LCD_YD PH_5
ADC_X  PB_8
ADC_Y  PB_9

M487 EBI pin:
-------------
EBI_nRD  PE_5
EBI_nWR  PE_4
EBI_nCS0 PD_14
EBI_AD15 PH_11
EBI_AD14 PH_10
EBI_AD13 PH_9
EBI_AD12 PH_8
EBI_AD11 PE_0
EBI_AD10 PE_1
EBI_AD9  PE_15
EBI_AD8  PE_14
EBI_AD7  PD_9
EBI_AD6  PD_8
EBI_AD5  PG_14
EBI_AD4  PG_13
EBI_AD3  PG_12
EBI_AD2  PG_11
EBI_AD1  PG_10
EBI_AD0  PG_9

M467 TFT pin:
-------------
LCM_DC  PB_2
LCM_LED PB_5

M467 TOUCH pin:
---------------
LCD_XR PB_9
LCD_YU PB_6
LCD_XL PB_7
LCD_YD PB_8
ADC_X  PB_6
ADC_Y  PB_9

M467 SPI pin:
-------------
SPI2_MOSI PA_8
SPI2_MISO PA_9
SPI2_SCLK PA_10
SPI2_SS   PA_11
