#include "hmt_common.h"
#include "hmt_simple_timer.h"
#include "usart_common.h"
// #include "usart_manager.h"

#ifdef USE_USART

#define USART_MAX_TX_BUFFER_LEN				1024
#define USART_MAX_RX_BUFFER_LEN				  64

typedef struct usart_data
{
	uint8_t *txDataPtr;
	uint8_t *rxDataPtr;
	uint8_t txBuffer[USART_MAX_TX_BUFFER_LEN];
	uint8_t rxBuffer[USART_MAX_RX_BUFFER_LEN];
	uint32_t txMsgLen;
	uint32_t rxMsgLen;
	uint32_t txMsgRemanining;
	uint32_t rxMsgRemanining;
	uint32_t txMsgCnt;
	uint32_t rxMsgCnt;
	bool txOnGoing;
	bool msgRcv;
}usart_data_s;


static usart_data_s UsartData;
static simple_timer RxTimer;


/********************************* TX **************************************/

bool hmt_UsartSendMsg(USART_TypeDef *UsartX, uint8_t *Data, uint32_t MsgLen)
{
	bool SentStarted = false;

	/* Init TX buffers and counters; init the it transmission */
	if(!Data){
		return false;
	}

	if(!UsartData.txOnGoing)
	{
		UsartData.txMsgCnt = 0;
		UsartData.txMsgRemanining = 0;
		UsartData.txDataPtr = NULL;
		memset(UsartData.txBuffer, 0x00, USART_MAX_TX_BUFFER_LEN);
#ifdef 	USE_DYNAMIC_MEM	
		if(MsgLen > USART_MAX_TX_BUFFER_LEN){
			UsartData.txMsgRemanining = MsgLen - USART_MAX_TX_BUFFER_LEN;
			UsartData.txMsgLen = USART_MAX_TX_BUFFER_LEN;
			memcpy(UsartData.txBuffer, Data, USART_MAX_TX_BUFFER_LEN);
			UsartData.txDataPtr = malloc(sizeof(uint8_t) * MsgLen);
			memcpy(UsartData.txDataPtr, Data, MsgLen);
		} else {			
			UsartData.txMsgLen = MsgLen;
			memcpy(UsartData.txBuffer, Data, UsartData.txMsgLen);
		}
#else
		UsartData.txMsgLen = MsgLen;
		memcpy(UsartData.txBuffer, Data, UsartData.txMsgLen);
#endif		
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
		/* Disable TC interrupt */
		LL_USART_DisableIT_TC(UsartX);

		__disable_irq();
		memset(UsartData.txBuffer, 0x00, USART_MAX_TX_BUFFER_LEN);
#ifdef 	USE_DYNAMIC_MEM	
		if(UsartData.txMsgRemanining != 0 && UsartData.txDataPtr)
		{
			if(UsartData.txMsgRemanining < USART_MAX_TX_BUFFER_LEN)
			{
				UsartData.txMsgLen = UsartData.txMsgRemanining;
				UsartData.txMsgRemanining = 0;
				memcpy(UsartData.txBuffer, &UsartData.txDataPtr[USART_MAX_TX_BUFFER_LEN], UsartData.txMsgLen);
				free(UsartData.txDataPtr);		
			}
			else
			{
				UsartData.txMsgLen = USART_MAX_TX_BUFFER_LEN;
				UsartData.txMsgRemanining -= USART_MAX_TX_BUFFER_LEN;
				memcpy(UsartData.txBuffer, &UsartData.txDataPtr[USART_MAX_TX_BUFFER_LEN], UsartData.txMsgLen);	
			}
			/* Start USART transmission : Will initiate TXE interrupt after DR register is empty */
			LL_USART_TransmitData8(UsartX, UsartData.txBuffer[UsartData.txMsgCnt++]);
			LL_USART_EnableIT_TXE(UsartX); 			
			UsartData.txOnGoing = true;
		}
#endif		
		__enable_irq();
	}

}


/********************************* RX **************************************/


usart_rx_ret_code hmt_UsartReceiveMsg(USART_TypeDef *UsartX, uint8_t *Data, uint32_t MsgLen, uint32_t Timeout)
{
	usart_rx_ret_code RetCode = USART_RX_MSG_IDLE;
	if(!Data){
		return false;
	}

	if(UsartData.rxMsgLen == 0){
		UsartData.rxDataPtr = NULL;
		UsartData.rxMsgRemanining = 0;
		UsartData.rxMsgCnt = 0;
		memset(UsartData.rxBuffer, 0x00, USART_MAX_RX_BUFFER_LEN);
		if(MsgLen > USART_MAX_RX_BUFFER_LEN)
		{
			UsartData.rxMsgRemanining = MsgLen - USART_MAX_RX_BUFFER_LEN;
			UsartData.rxDataPtr = malloc(sizeof(uint8_t) * MsgLen);
		}
		UsartData.rxMsgLen = MsgLen;
		if(Timeout != 0){
			hmt_SimpleTimerStart(&RxTimer, Timeout);
		}
	}

	if(UsartData.rxMsgCnt == MsgLen && UsartData.msgRcv)
	{
		__disable_irq();
		UsartData.msgRcv = false;
		UsartData.rxMsgCnt = 0;
		UsartData.rxMsgLen = 0;
		if(UsartData.rxMsgRemanining != 0)
		{
			memcpy(Data, UsartData.rxDataPtr, MsgLen);
			free(UsartData.rxDataPtr);
			UsartData.rxMsgRemanining = 0;
		} else {
			memcpy(Data, UsartData.rxBuffer, MsgLen);
		}
		memset(UsartData.rxBuffer, 0x00, USART_MAX_RX_BUFFER_LEN);
		__enable_irq();
		RetCode = USART_RX_MSG_RCV;
	}
	if(Timeout != 0 && hmt_SimpleTimerElapsed(&RxTimer, false, 0))
	{
		__disable_irq();
		UsartData.msgRcv = false;
		UsartData.rxMsgCnt = 0;
		UsartData.rxMsgLen = 0;
		if(UsartData.rxMsgRemanining != 0){
			free(UsartData.rxDataPtr);
			UsartData.rxMsgRemanining = 0;
		}
		memset(UsartData.rxBuffer, 0x00, USART_MAX_RX_BUFFER_LEN);
		memset(Data, 0x00, MsgLen);
		__enable_irq();
		RetCode = USART_RX_MSG_ERROR;
	}

	return RetCode;
}

void hmt_UsartRxCB(USART_TypeDef *UsartX)
{
	UsartData.msgRcv = true;
	/* Read Received character. RXNE flag is cleared by reading of DR register */
	if(UsartData.rxMsgCnt < UsartData.rxMsgLen)
	{
		if(UsartData.rxMsgRemanining != 0){
			UsartData.rxDataPtr[UsartData.rxMsgCnt++] = LL_USART_ReceiveData8(UsartX);
		} else {
			UsartData.rxBuffer[UsartData.rxMsgCnt++] = LL_USART_ReceiveData8(UsartX);
		}
	}
	if(hmt_SimpleTimerOngoing(&RxTimer)){
		hmt_SimpleTimerRestart(&RxTimer, 0);
	}
}

#endif