#include "main.h"


int main(void)
{
    simple_timer ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
    hmt_SimpleTimerStart(&ToggleTimer, 500);
    uint32_t PrevTick = Tick1Ms;
    for (;;)
    {
        // if(hmt_SimpleTimerElapsed(&ToggleTimer, true, 0)){
        //     hmt_GpioTogglePin(PA_5_ID);
        // }
        // hmt_GpioTogglePin(PA_5_ID);
        // hmt_Delay(150);
        if(PrevTick != Tick1Ms){
            hmt_GpioTogglePin(PA_5_ID);
            PrevTick = Tick1Ms;
        }
    }

    return 0;
}
