#include "main.h"
#include "pwm_manager.h"


int main(void)
{
    simple_timer_t ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
    hmt_PWM_Init(TIMER_USED);
    hmt_PWM_SetDutyCycle(TIMER_USED, 50);
    hmt_SimpleTimerStart(&ToggleTimer, 500);
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, 0))
        {
            hmt_GpioTogglePin(DEBUG_LED);
        }
    }

    return 0;
    
}
