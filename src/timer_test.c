#include "timer_test.h"
#include "hmt_simple_timer.h"
#include "main.h"
#include <stdio.h>

#ifdef USE_PWM

void PwmTestInit()
{
	hmt_PWM_Init(PWM_TIMER_USED, PWM_TIMER_CHANNEL);
	hmt_PWM_SetDutyCycle(PWM_TIMER_USED, PWM_TIMER_CHANNEL, 25);
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
	uint32_t Frq = 0, FrqFiltered = 0;
	Frq = hmt_IC_GetFrq();
	FrqFiltered = hmt_IC_GetFrqFiltered();
	if(FrqFiltered != 0)
	{
		char Msg[50] = {0};
		snprintf(Msg, 50, "Frq: %d\r\n", Frq);
		hmt_UsartSendMsg(USART_USED, Msg, strlen(Msg));
	}
}

#endif /* USE_INPUT_CAPTURE */