#include "main.h"
#include "pwm_manager.h"
#include "ic_manager.h"


int main(void)
{
    simple_timer_t ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
    hmt_PWM_Init(PWM_TIMER_USED, PWM_TIMER_CHANNEL);
    hmt_PWM_SetDutyCycle(PWM_TIMER_USED, PWM_TIMER_CHANNEL, 50);
    hmt_IC_Init(IC_TIMER_USED, IC_TIMER_CHANNEL);
    hmt_SimpleTimerStart(&ToggleTimer, 1000);
    uint32_t SwitchPwmFrw = PWM_FRQ_DFLT * 2;
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, 0))
        {
            hmt_GpioTogglePin(DEBUG_LED);
            hmt_PWM_SetPwmFrq(PWM_TIMER_USED, SwitchPwmFrw);
            if(SwitchPwmFrw == PWM_FRQ_DFLT){
                SwitchPwmFrw =  PWM_FRQ_DFLT * 2;
            } else {
                SwitchPwmFrw = PWM_FRQ_DFLT;
            }
        }
    }

    return 0;
    
}
