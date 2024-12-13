#ifndef __TOUCHPANEL_H__
#define __TOUCHPANEL_H__

#define __DEMO_TSFILE_ADDR__    0x00040000 /* SPI flash 256KB address */

#define __DEMO_TS_WIDTH__       320
#define __DEMO_TS_HEIGHT__      240

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define DOUT_XR PB_9
#define DIN_YD  PB_8
#define DOUT_XL PB_7
#define AIN_X   PB_6

#define DOUT_YU PB_6
#define DOUT_YD PB_8
#define DIN_XL  PB_7
#define AIN_Y   PB_9

#define ADC_SAMPLE_SHIFT     4
#define ADC_SAMPLE_THRESHOLD 3600

int Init_TouchPanel(void);
int Read_TouchPanel(int *x, int *y);
int Uninit_TouchPanel(void);
int Check_TouchPanel(void);

int ts_calibrate(int xsize, int ysize);
void ts_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
