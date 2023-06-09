#include "spi_common.h"
#include "hmt_simple_timer.h"

#ifdef USE_SPI

#define SPI_TX_BUFFER_LEN		1024
#define SPI_RX_BUFFER_LEN		  64


typedef struct spi_msg_var
{
	uint8_t txBuffer[SPI_TX_BUFFER_LEN];
	uint8_t rxBuffer[SPI_RX_BUFFER_LEN];
	uint32_t txDataLen;
	uint32_t txDataCnt;
	uint32_t rxDataLen;
	uint32_t rxDataCnt;
	bool txOngoing;
	bool txComplete;
	simple_timer_t txTimer;
	simple_timer_t rxTimer;
}spi_msg_var_s;


static spi_msg_var_s SpiData;

static void ClearTx(spi_msg_var_s *SpiVar)
{
	if(!SpiVar){
		return;
	}
	memset(SpiVar->txBuffer, 0x00, SPI_TX_BUFFER_LEN);
	SpiVar->txDataCnt = 0;
	SpiVar->txDataLen = 0;
	SpiVar->txOngoing = false;
	SpiVar->txComplete = false;
}

static void ClearRx(spi_msg_var_s *SpiVar)
{
	if(!SpiVar){
		return;
	}
	memset(SpiVar->rxBuffer, 0x00, SPI_RX_BUFFER_LEN);
	SpiVar->rxDataCnt = 0;
	SpiData.rxDataLen = 0;
}

void hmt_SPI_Rx_CB(SPI_TypeDef *SPIx)
{
  	/* Read character in Data register.
 	RXNE flag is cleared by reading data in DR register */
	if(SpiData.rxDataCnt < SPI_RX_BUFFER_LEN){
  		SpiData.rxBuffer[SpiData.rxDataCnt++] = LL_SPI_ReceiveData8(SPIx);
	}
}


void hmt_SPI_Tx_CB(SPI_TypeDef *SPIx)
{
	if(SpiData.txDataCnt < SpiData.txDataLen)
	{
		/* Write character in Data register.
		TXE flag is cleared by reading data in DR register */
		LL_SPI_TransmitData8(SPIx, SpiData.txBuffer[SpiData.txDataCnt++]);
	}
	else
	{
		SpiData.txComplete = true;
		LL_SPI_DisableIT_TXE(SPIx);
	}
}


spi_tx_ret_v hmt_SPIMasterTransmit(SPI_TypeDef *SPIx, uint8_t *Data, uint32_t DataLen, uint32_t Timeout)
{
	spi_rx_ret_v TxRet = SPI_TX_IDLE;

	if(!Data || DataLen > SPI_TX_BUFFER_LEN){
		return SPI_TX_ERROR;
	}

	if(!hmt_SimpleTimerOngoing(&SpiData.txTimer) && Timeout != 0){
		hmt_SimpleTimerStart(&SpiData.txTimer, Timeout);
	}

	if(!SpiData.txOngoing)
	{
		ClearTx(&SpiData);
		memcpy(SpiData.txBuffer, Data, DataLen);
		SpiData.txDataLen = DataLen;
		SpiData.txOngoing = true;
		/* Enable TXE   Interrupt */
		LL_SPI_EnableIT_TXE(SPIx);
	}

	if(hmt_SimpleTimerOngoing(&SpiData.txTimer) && hmt_SimpleTimerElapsed(&SpiData.txTimer, false, 0)){
		ClearTx(&SpiData);
		TxRet = SPI_TX_TIMEOUT;
	} else {
		TxRet = SPI_TX_IDLE;
	}

	if(SpiData.txComplete){
		SpiData.txOngoing = false;
		TxRet = SPI_TX_SENT;
		hmt_SimpleTimerStop(&SpiData.txTimer);
	}

	return TxRet;
}


spi_rx_ret_v hmt_SPIMasterReceive(SPI_TypeDef *SPIx, uint8_t *Data, uint32_t DataLen, uint32_t Timeout)
{
	spi_rx_ret_v RxRet = SPI_RX_IDLE;

	if(!Data || DataLen > SPI_RX_BUFFER_LEN){
		return SPI_RX_ERROR;
	}

	if(!hmt_SimpleTimerOngoing(&SpiData.rxTimer) && Timeout != 0){
		hmt_SimpleTimerStart(&SpiData.rxTimer, Timeout);
	}

	SpiData.rxDataLen = DataLen;

	if(SpiData.rxDataCnt < DataLen){
		if(hmt_SimpleTimerOngoing(&SpiData.rxTimer) && hmt_SimpleTimerElapsed(&SpiData.rxTimer, false, 0)){
			ClearRx(&SpiData);
			RxRet = SPI_RX_TIMEOUT; 
		} else {
			RxRet = SPI_RX_IDLE;
		}
	} else {
		memcpy(Data, SpiData.rxBuffer, DataLen);
		ClearRx(&SpiData);
		RxRet = SPI_RX_RECEIVED;
		hmt_SimpleTimerStop(&SpiData.rxTimer);
	}
	return RxRet;
}

// void WaitAndCheckEndOfTransfer(void)
// {
//   /* 1 - Wait end of transmission */
//   while (ubTransmitIndex != ubNbDataToTransmit)
//   {
//   }
//   /* Disable TXE Interrupt */
//   LL_SPI_DisableIT_TXE(SPI2);

//   /* 2 - Wait end of reception */
//   while (ubNbDataToReceive > ubReceiveIndex)
//   {
//   }
//   /* Disable RXNE Interrupt */
//   LL_SPI_DisableIT_RXNE(SPI2);

//   /* 3 - Compare Transmit data to receive data */
//   if(Buffercmp8((uint8_t*)aTxBuffer, (uint8_t*)aRxBuffer, ubNbDataToTransmit))
//   {
//     /* Processing Error */
//     LED_Blinking(LED_BLINK_ERROR);
//   }
//   else
//   {
//     /* Turn On Led if data are well received */
//     LED_On();
//   }
// }








#endif /* USE_SPI */