#include "usart_test.h"


#ifdef USE_USART

void UsartTestInit()
{
	hmt_Usart_Init(USART_USED, USART_BAUD);
}

void UsartTestRun()
{
	char *Msg = "Hi from stm32f103 usart test\r\n";
	uint8_t CharReceived = 0;
	hmt_UsartSendMsg(USART_USED, Msg, strlen(Msg));
	usart_rx_ret_code RxRet = USART_RX_MSG_IDLE;
	do{
		RxRet = hmt_UsartReceiveByte(USART_USED, &CharReceived, 10000);
	}while(RxRet == USART_RX_MSG_IDLE);
	if(RxRet != USART_RX_MSG_RCV){
		hmt_UsartSendMsg(USART_USED, "Error during the receive\r\n", strlen("Error during the receive\r\n"));
	}
}


#endif /* USE_USART */