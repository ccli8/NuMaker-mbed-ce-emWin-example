# Getting started sample with emWin simple demo on Mbed OS

This is an example to utilize emWin library to demonstrate interactive feature.

### CLI
Target board "NUMAKER_PFM_M487" with GCC_ARM toolchain.
1. mbed target "NUMAKER_PFM_M487"
2. mbed toolchain "GCC_ARM"
3. mbed config -G GCC_ARM_PATH "C:\Program Files (x86)\GNU Tools ARM Embedded\5.4 2016q2\bin"
4. mbed compile

Target board "NUMAKER_PFM_M487" with ARM toolchain.
1. mbed target "NUMAKER_PFM_M487"
2. mbed toolchain "ARM"
3. mbed config -G ARM_PATH "C:\Keil_v5\ARM\ARMCC"
4. mbed compile

Please note that the toolchain path in step 3 may be different from your environment.

### Burn Code & Execute
1. Connect the board NuMaker-PFM-XXX with your PC by USB cable, then there will be one "MBED" disk.
2. Copy the built binary file into "MBED" disk on you PC.
3. Press reset button to execute, user could test emWin simple demo.

### Demo condition, document and link
This demo utilizes LCD and touch to display and touch operation.

LCD: ILI9341 MPU-type RGB56 QVGA LCD with resistive touch panel.

Please refer to the emWin related documents in [OpenNuvoton](https://github.com/OpenNuvoton/M480BSP) for more details!

The link of BSP for emWin quick start guide ["M480 emWin Quick Start Guide.pdf"](https://github.com/OpenNuvoton/M480BSP)

The link of emWin official user manual ["UM03001_emWin5.pdf"](https://github.com/OpenNuvoton/M480BSP/tree/master/ThirdParty/emWin/Doc)

[The link of SEGGER emWin official forum](https://forum.segger.com/index.php/Board/12-emWin-related/)

The links of Nuvoton HMI/GUI official forum:
[NuForum](http://forum.nuvoton.com/viewforum.php?f=31)
[牛卧堂](http://nuvoton-mcu.com/forum.php?mod=forumdisplay&fid=86)

### How to utilize emWin tool "GUIBuilder" in Windows OS?
The link of emWin official Windows tool ["GUIBuilder"](https://github.com/OpenNuvoton/M480BSP/tree/master/ThirdParty/emWin/Tool)

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
