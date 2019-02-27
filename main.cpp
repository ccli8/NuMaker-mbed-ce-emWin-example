#include "mbed.h"

#include "GUI.h"
#include "WM.h"
#include "FRAMEWIN.h"

#include "M48XTouchPanel.h"
#include "tslib.h"
//
// Enable emWin touch feature after calibration
//
volatile int g_enable_Touch;
//
// For touch sampling timer
//
Ticker s_ticker_emWinloop;
//
// emWin timer count
//
extern GUI_TIMER_TIME OS_TimeMS;
//
// Tick loop for emWin and touch
//
void task_emWinloop(void)
{
    OS_TimeMS++;
#if GUI_SUPPORT_TOUCH
    if ( OS_TimeMS % 10 == 0 )
    {
        if ( g_enable_Touch == 1 )
        {
            GUI_TOUCH_Exec();
        }
    }
#endif
}
//
// Extern emWin GUI layout
//
extern WM_HWIN CreateFramewin(void);
//
// emWin MainTask to create a GUI layout
//
void MainTask(void)
{
    WM_HWIN hWin;
    char     acVersion[40] = "Framewin: Version of emWin: ";

    printf("Main Task -> \n");

    strcat(acVersion, GUI_GetVersionString());
    hWin = CreateFramewin();
    FRAMEWIN_SetText(hWin, acVersion);
    while (1)
    {
        GUI_Delay(500);
    }
}
//
// Main
//
int main(void)
{
    //
    // Before touch calibration
    //
    g_enable_Touch = 0;
    //
    // Attach Mbed tick
    //
    s_ticker_emWinloop.attach(&task_emWinloop, 0.001);

#if GUI_SUPPORT_TOUCH
    //
    // Init emWin and touch calibration
    //
    GUI_Init();
    Init_TouchPanel();
    ts_calibrate(__DEMO_TS_WIDTH__, __DEMO_TS_HEIGHT__);
#endif
    //
    // After touch calibration
    //
    g_enable_Touch = 1;
    //
    // Create GUI layout
    //
    MainTask();

    while(1);
}
