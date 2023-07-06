#include "timer_test.h"
#include "hmt_simple_timer.h"

#ifdef USE_PWM

void PwmTestInit()
{
	hmt_PWM_Init(PWM_TIMER_USED, PWM_TIMER_CHANNEL);
	hmt_PWM_SetDutyCycle(PWM_TIMER_USED, PWM_TIMER_CHANNEL, 50);
}

void PwmTestRun()
{

}


#endif /* USE_PWM */

#ifdef USE_INPUT_CAPTURE


void IcTestInit()
{
	hmt_IC_Init(IC_TIMER_USED, IC_TIMER_CHANNEL);
}

void IcTestRun()
{
	simple_timer_t IcTestTimer;
	uint32_t Frq = 0, FrqFiltered = 0;
	hmt_SimpleTimerStart(&IcTestTimer, 500);
	while(1)
	{
		if(hmt_SimpleTimerElapsed(&IcTestTimer, true, 0))
		{
			Frq = hmt_IC_GetFrq();
			FrqFiltered = hmt_IC_GetFrqFiltered();
		}
	}
}

#endif /* USE_INPUT_CAPTURE */