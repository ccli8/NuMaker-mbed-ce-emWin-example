
#include "NuMicro.h"

#include "GUI.h"
#include "TouchPanel.h"

#include "mbed.h"

int Init_TouchPanel(void)
{
    return 1;
}

/*-----------------------------------------------*/
// Get X Position from Touch Panel (ADC input)
//
/*-----------------------------------------------*/
uint16_t Get_TP_X(void)
{
    uint16_t    x_adc_in;

    DigitalOut dout_xr(DOUT_XR);
    DigitalIn din_yd(DIN_YD);
    DigitalOut dout_xl(DOUT_XL);
    dout_xr = 1;
    dout_xl = 0;
    AnalogIn ain(AIN_X);
    ThisThread::sleep_for(1);
    x_adc_in = ain.read_u16();

    return x_adc_in;
}


/*-----------------------------------------------*/
// Get Y Position from Touch Panel (ADC input)
//
/*-----------------------------------------------*/
uint16_t Get_TP_Y(void)
{
    uint16_t    y_adc_in;

    DigitalOut dout_yu(DOUT_YU);
    DigitalOut dout_yd(DOUT_YD);
    DigitalIn din_xl(DIN_XL);
    dout_yu = 1;
    dout_yd = 0;
    AnalogIn ain(AIN_Y);
    ThisThread::sleep_for(1);
    y_adc_in = ain.read_u16();

    return y_adc_in;
}

int Read_TouchPanel(int *x, int *y)
{
    *x = Get_TP_X() >> ADC_SAMPLE_SHIFT;
    *y = Get_TP_Y() >> ADC_SAMPLE_SHIFT;

    if ( (*x >= ADC_SAMPLE_THRESHOLD) || (*y >= ADC_SAMPLE_THRESHOLD) )
        return 0;   //Pen up;
    else
        return 1;
}

int Uninit_TouchPanel(void)
{
    return 1;
}

int Check_TouchPanel(void)
{
    return 0;
}

