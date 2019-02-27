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

Please note that the toolchain path in step 3 may different from your environment.

### Burn Code & Execute
1. Connect the board NuMaker-PFM-XXX with your PC by USB cable, then there will be one "MBED" disk.
2. Copy the built binary file into "MBED" disk on you PC.
3. Press reset button to execute, user could test Audio Codec.

### Demo condition, document and link
ILI9341 MPU-type RGB56 QVGA LCD with resistive touch panel.

Please reference the emWin related documents for further details, the path is in "\NuMaker-mbed-emWin-example\emWin\Doc"

Quick start guide:  M480 emWin Quick Start Guide.pdf
Official user manual: UM03001_emWin5.pdf

SEGGER emWin official forum link:
https://forum.segger.com/index.php/Board/12-emWin-related/

Nuvoton HMI/GUI official forum link:
http://forum.nuvoton.com/viewforum.php?f=31&sid=94265886594b34c7cd812d3f74c44fec
http://nuvoton-mcu.com/forum.php?mod=forumdisplay&fid=86

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
