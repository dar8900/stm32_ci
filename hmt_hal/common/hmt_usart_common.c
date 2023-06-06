#include "hmt_common.h"
#include "hmt_usart_common.h"
#include "usart_manager.h"


#define USART_MAX_BUFFER_LEN	1024

typedef struct usart_data
{
	uint8_t txBuffer[USART_MAX_BUFFER_LEN];
	uint8_t rxBuffer[USART_MAX_BUFFER_LEN];
	uint16_t txMsgLen;
	uint16_t rxMsgLen;
	uint16_t txMsgCnt;
	uint16_t rxMsgCnt;
	bool txOnGoing;
	bool msgRcv;
}usart_data_s;


static usart_data_s UsartData;


bool hmt_UsartSendMsg(USART_TypeDef *UsartX, uint8_t *Data, uint16_t MsgLen)
{
	bool SentStarted = false;
	/* TODO Init TX buffers and counters; init the it transmission */

	if(!Data || MsgLen >= USART_MAX_BUFFER_LEN){
		return false;
	}

	if(!UsartData.txOnGoing)
	{
		UsartData.txMsgCnt = 0;
		UsartData.txMsgLen = MsgLen;
		memset(UsartData.txBuffer, 0x00, USART_MAX_BUFFER_LEN);
		memcpy(UsartData.txBuffer, Data, MsgLen);
		UsartData.txOnGoing = true;
		/* Start USART transmission : Will initiate TXE interrupt after DR register is empty */
		LL_USART_TransmitData8(UsartX, UsartData.txBuffer[UsartData.txMsgCnt++]);
		LL_USART_EnableIT_TXE(UsartX); 
		SentStarted = true;
	}
	return SentStarted;
}

void hmt_UsartTxEmptyCB(USART_TypeDef *UsartX)
{
	if(!UsartData.txOnGoing){
		return;
	}
	if (UsartData.txMsgCnt == (UsartData.txMsgLen - 1))
	{
		/* Disable TXE interrupt */
		LL_USART_DisableIT_TXE(UsartX);
		/* Enable TC interrupt */
		LL_USART_EnableIT_TC(UsartX);
	}
	/* Fill DR with a new char */
	LL_USART_TransmitData8(UsartX, UsartData.txBuffer[UsartData.txMsgCnt++]);
}

void hmt_UsartTcCB(USART_TypeDef *UsartX)
{
	if(!UsartData.txOnGoing){
		return;
	}	
	if(UsartData.txMsgCnt == UsartData.txMsgLen)
	{
		UsartData.txMsgCnt = 0;
		UsartData.txOnGoing = false;
		memset(UsartData.txBuffer, 0x00, USART_MAX_BUFFER_LEN);
		/* Disable TC interrupt */
		LL_USART_DisableIT_TC(UsartX);
	}
}


bool hmt_UsartReceiveMsg(USART_TypeDef *UsartX, uint8_t *Data, uint16_t MsgLen)
{
	bool MessageReceived = false;
	if(!Data || MsgLen >= USART_MAX_BUFFER_LEN){
		return false;
	}

	if(UsartData.rxMsgLen == 0){
		UsartData.rxMsgLen = MsgLen;
	}

	if(UsartData.rxMsgCnt == MsgLen && UsartData.msgRcv)
	{
		memcpy(Data, UsartData.rxBuffer, MsgLen);
		UsartData.msgRcv = false;
		UsartData.rxMsgCnt = 0;
		UsartData.rxMsgLen = 0;
		memset(UsartData.rxBuffer, 0x00, USART_MAX_BUFFER_LEN);
		MessageReceived = true;
	}

	return MessageReceived;
}

void hmt_UsartRxCB(USART_TypeDef *UsartX)
{
	UsartData.msgRcv = true;
	/* Read Received character. RXNE flag is cleared by reading of DR register */
	if(UsartData.rxMsgCnt < UsartData.rxMsgLen){
		UsartData.rxBuffer[UsartData.rxMsgCnt++] = LL_USART_ReceiveData8(UsartX);
	}
}
