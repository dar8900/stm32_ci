#include "timer_test.h"
#include "hmt_simple_timer.h"
#include "main.h"
#include <stdio.h>

#ifdef USE_PWM

#define FRQ_INCR	10
uint32_t NewFrq = PWM_FRQ_DFLT;

void PwmTestInit()
{
	hmt_PWM_Init(PWM_TIMER_USED, PWM_TIMER_CHANNEL);
	hmt_PWM_SetDutyCycle(PWM_TIMER_USED, PWM_TIMER_CHANNEL, 50);
}

void PwmTestRun()
{
	usart_rx_ret_code RxRet = USART_RX_MSG_IDLE;
	uint8_t MsgReceived[2] = {0};
	char FrqStr[15] = {0};
#ifdef USE_USART	
	RxRet = hmt_UsartReceiveMsg(USART_USED, MsgReceived, 1, 0);
	if(RxRet == USART_RX_MSG_RCV){
		if(strcmp(MsgReceived, "+") == 0){
			if(NewFrq + FRQ_INCR <= 5000){
				NewFrq += FRQ_INCR;
			} else {
				NewFrq = PWM_FRQ_DFLT;
			}			
		} else if(strcmp(MsgReceived, "-") == 0){
			if(NewFrq - FRQ_INCR >= PWM_FRQ_DFLT){
				NewFrq -= FRQ_INCR;	
			} else {
				NewFrq = 5000;
			}
		}
#endif		
		uint32_t PrintFrq = NewFrq;
		hmt_PWM_SetPwmFrq(PWM_TIMER_USED, NewFrq);
		snprintf(FrqStr, 15, "New frq: %d\r\n", PrintFrq);
#ifdef USE_USART		
		hmt_UsartSendMsg(USART_USED, FrqStr, strlen(FrqStr));
#endif
		PrintFrq = hmt_PWM_GetPwmFrq(PWM_TIMER_USED);
		memset(FrqStr, 0x00, 15);
		snprintf(FrqStr, 15, "True frq: %d\r\n", PrintFrq);
#ifdef USE_USART
		hmt_UsartSendMsg(USART_USED, FrqStr, strlen(FrqStr));
#endif		
	}
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
#ifdef USE_USART
		hmt_UsartSendMsg(USART_USED, Msg, strlen(Msg));
#endif
	}
}

#endif /* USE_INPUT_CAPTURE */