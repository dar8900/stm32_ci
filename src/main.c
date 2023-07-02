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
    hmt_SimpleTimerStart(&ToggleTimer, 50);
    uint32_t SwitchPwmFrw = PWM_FRQ_DFLT * 2;
    hmt_PWM_SetPwmFrq(PWM_TIMER_USED, 5000);
    uint32_t Dc = 0;
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, 0))
        {
            hmt_GpioTogglePin(DEBUG_LED);
            if(Dc < 100){
                Dc++;
            } else {
                Dc = 0;
            }
            hmt_PWM_SetDutyCycle(PWM_TIMER_USED, PWM_TIMER_CHANNEL, Dc);
        }
    }

    return 0;
    
}
