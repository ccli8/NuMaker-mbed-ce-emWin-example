# Example for emWin HMI on Nuvoton's Mbed CE enabled boards

This is an example to utilize emWin library to demonstrate interactive feature.

## Supported platforms

Currently, the following Nuvoton Mbed CE enabled boards supports this example.
- [NuMaker-PFM-M487](https://www.nuvoton.com/products/iot-solution/iot-platform/numaker-pfm-m487/)
- [NuMaker-IoT-M467](https://www.nuvoton.com/board/numaker-iot-m467/)

## Support development tools

Use cmake-based build system.
Check out [hello world example](https://github.com/mbed-ce/mbed-ce-hello-world) for getting started.

> **⚠️ Warning**
>
> Legacy development tools below are not supported anymore.
> - [Arm's Mbed Studio](https://os.mbed.com/docs/mbed-os/v6.15/build-tools/mbed-studio.html)
> - [Arm's Mbed CLI 2](https://os.mbed.com/docs/mbed-os/v6.15/build-tools/mbed-cli-2.html)
> - [Arm's Mbed CLI 1](https://os.mbed.com/docs/mbed-os/v6.15/tools/developing-mbed-cli.html)

For [VS Code development](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-VS-Code)
or [OpenOCD as upload method](https://github.com/mbed-ce/mbed-os/wiki/Upload-Methods#openocd),
install below additionally:

-   [NuEclipse](https://github.com/OpenNuvoton/Nuvoton_Tools#numicro-software-development-tools): Nuvoton's fork of Eclipse
-   Nuvoton forked OpenOCD: Shipped with NuEclipse installation package above.
    Checking openocd version `openocd --version`, it should fix to `0.10.022`.

## Hardware requirements

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

### Pin definitions

#### M487 TFT pins

NAME            | PIN
----------------|---------
LCD_RS          | PH_3
LCD_REST        | PB_6
LCD_BL          | PB_7

#### M487 TOUCH pins

NAME            | PIN
----------------|---------
LCD_XR          | PB_9
LCD_YU          | PB_8
LCD_XL          | PH_4
LCD_YD          | PH_5
ADC_X           | PB_8
ADC_Y           | PB_9

#### M487 EBI pins

NAME            | PIN
----------------|---------
EBI_nRD         | PE_5
EBI_nWR         | PE_4
EBI_nCS0        | PD_14
EBI_AD15        | PH_11
EBI_AD14        | PH_10
EBI_AD13        | PH_9
EBI_AD12        | PH_8
EBI_AD11        | PE_0
EBI_AD10        | PE_1
EBI_AD9         | PE_15
EBI_AD8         | PE_14
EBI_AD7         | PD_9
EBI_AD6         | PD_8
EBI_AD5         | PG_14
EBI_AD4         | PG_13
EBI_AD3         | PG_12
EBI_AD2         | PG_11
EBI_AD1         | PG_10
EBI_AD0         | PG_9

#### M467 TFT pins

NAME            | PIN
----------------|---------
LCM_DC          | PB_2
LCM_LED         | PB_5

#### M467 TOUCH pins

NAME            | PIN
----------------|---------
LCD_XR          | PB_9
LCD_YU          | PB_6
LCD_XL          | PB_7
LCD_YD          | PB_8
ADC_X           | PB_6
ADC_Y           | PB_9

#### M467 SPI pins

NAME            | PIN
----------------|---------
SPI2_MOSI       | PA_8
SPI2_MISO       | PA_9
SPI2_SCLK       | PA_10
SPI2_SS         | PA_11

## Developer guide

In the following, we take **NuMaker-PFM-M487** board as an example for Mbed CE support.

1.  Clone the example and navigate into it
    ```
    $ git clone https://github.com/mbed-nuvoton/NuMaker-mbed-ce-emWin-example
    $ cd NuMaker-mbed-ce-emWin-example
    $ git checkout -f master
    ```

1.  Deploy necessary libraries
    ```
    $ git submodule update --init
    ```
    Or for fast install:
    ```
    $ git submodule update --init --filter=blob:none
    ```

1.  Compile with cmake/ninja
    ```
    $ mkdir build; cd build
    $ cmake .. -GNinja -DCMAKE_BUILD_TYPE=Develop -DMBED_TARGET=NUMAKER_PFM_M487
    $ ninja
    $ cd ..
    ```

1.  Flash by drag-n-drop built image `NuMaker-mbed-ce-emWin-example.bin` or `NuMaker-mbed-ce-emWin-example.hex` onto **NuMaker-PFM-M487** board
