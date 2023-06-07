#include "spi_manager.h"

#ifdef USE_SPI

void hmt_SPIInit(SPI_TypeDef *SPIx)
{
	LL_SPI_InitTypeDef SPI_InitStruct = {0};

	SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
	SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
	SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
	SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
	SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
	SPI_InitStruct.NSS = LL_SPI_NSS_SOFT;
	SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV4;
	SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
	SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
	SPI_InitStruct.CRCPoly = 10;
	LL_SPI_Init(SPIx, &SPI_InitStruct);
}

void hmt_SPI_IT_Handler(SPI_TypeDef *SPIx)
{
		/* Check RXNE flag value in ISR register */
	if(LL_SPI_IsActiveFlag_RXNE(SPI2))
	{
		/* Call function Slave Reception Callback */
		hmt_SPIRxCB();
	}
	/* Check RXNE flag value in ISR register */
	else if(LL_SPI_IsActiveFlag_TXE(SPI2))
	{
		/* Call function Slave Reception Callback */
		hmt_SPITxCB();
	}
	/* Check STOP flag value in ISR register */
	else if(LL_SPI_IsActiveFlag_OVR(SPI2))
	{
		/* Call Error function */
		// SPI2_TransferError_Callback();
	}
}
































#endif /* USE_SPI */
