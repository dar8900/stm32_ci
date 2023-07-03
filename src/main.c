#include "main.h"

int main(void)
{
    simple_timer_t ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
    hmt_SimpleTimerStart(&ToggleTimer, 50);
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, 0))
        {
            hmt_GpioTogglePin(DEBUG_LED);
            
        }
    }

    return 0;
    
}
