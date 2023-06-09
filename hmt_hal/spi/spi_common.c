#include "spi_common.h"

#ifdef USE_SPI

#define SPI_TX_BUFFER_LEN		1024
#define SPI_RX_BUFFER_LEN		  64


typedef struct spi_msg_var
{
	uint8_t txBuffer[SPI_TX_BUFFER_LEN];
	uint8_t rxBuffer[SPI_RX_BUFFER_LEN];
	uint32_t txDataLen;
	uint32_t rxDataLen;
	uint32_t txDataCnt;
	uint32_t rxDataCnt;
	bool txOngoing;
	bool txComplete;
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

void hmt_SPI_Rx_CB(SPI_TypeDef *SPIx)
{
  /* Read character in Data register.
  RXNE flag is cleared by reading data in DR register */
//   aRxBuffer[ubReceiveIndex++] = LL_SPI_ReceiveData8(SPIx);
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
		SpiData.txOngoing = false;
		SpiData.txComplete = true;
		LL_SPI_DisableIT_TXE(SPIx);
	}
}


bool hmt_SPIMasterTransmit(SPI_TypeDef *SPIx, uint8_t *Data, uint32_t DataLen)
{
	bool DataSent = false;

	if(!Data || DataLen > SPI_TX_BUFFER_LEN){
		return false;
	}

	if(!SpiData.txOngoing)
	{
		ClearTx(&SpiData);
		memcpy(SpiData.txBuffer, Data, DataLen);
		SpiData.txDataLen = DataLen;
		SpiData.txOngoing = true;
		/* Enable TXE   Interrupt */
		LL_SPI_EnableIT_TXE(SPIx);
		DataSent = true;	
	}

	return DataSent;
}

bool hmt_SPI_TxEnd()
{
	bool Complete = SpiData.txComplete;
	if(Complete){
		SpiData.txComplete = false;
	}
	return Complete;
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