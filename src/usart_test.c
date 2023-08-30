#include "usart_test.h"


#ifdef USE_USART


void UsartTestInit()
{
	hmt_Usart_Init(USART_USED, USART_BAUD);
}

void UsartTestRun()
{
	char Msg[50] = "Mesaggio ricevuto: ";
	uint8_t MsgReceived[4] = {0};
	usart_rx_ret_code RxRet = USART_RX_MSG_IDLE;
	RxRet = hmt_UsartReceiveMsg(USART_USED, MsgReceived, 3, 0);
	if(RxRet == USART_RX_MSG_ERROR){
		hmt_UsartSendMsg(USART_USED, "Error during the receive\r\n", strlen("Error during the receive\r\n"));
	} else if(RxRet == USART_RX_MSG_RCV){
		strcat(Msg, MsgReceived);
		strcat(Msg, "\r\n");
		hmt_UsartSendMsg(USART_USED, Msg, strlen(Msg));
	}
}


#endif /* USE_USART */