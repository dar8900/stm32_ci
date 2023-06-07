#include "spi_manager.h"
#include "spi_common.h"

#ifdef USE_SPI

void hmt_SPIInit(SPI_TypeDef *SPIx)
{
	LL_SPI_InitTypeDef SPI_InitStruct = {0};

	if(SPIx == SPI1)
	{
		NVIC_SetPriority(SPI1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
		NVIC_EnableIRQ(SPI1_IRQn);
		LL_GPIO_AF_EnableRemap_SPI1();
	} 
#ifdef SPI2
	if(SPIx == SPI2)
	{
		NVIC_SetPriority(SPI2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
		NVIC_EnableIRQ(SPI2_IRQn);
		LL_GPIO_AF_EnableRemap_SPI2();
	}
#endif
#ifdef SPI3
	if(SPIx == SPI3)
	{
		NVIC_SetPriority(SPI3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
		NVIC_EnableIRQ(SPI3_IRQn);
		LL_GPIO_AF_EnableRemap_SPI3();
	}
#endif

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

	/* Configure SPI2 transfer interrupts */
	/* Enable RXNE  Interrupt             */
	LL_SPI_EnableIT_RXNE(SPIx);
	/* Enable TXE   Interrupt             */
	LL_SPI_EnableIT_TXE(SPIx);
	/* Enable Error Interrupt             */
	LL_SPI_EnableIT_ERR(SPIx);
}

void hmt_SPI_IT_Handler(SPI_TypeDef *SPIx)
{
		/* Check RXNE flag value in ISR register */
	if(LL_SPI_IsActiveFlag_RXNE(SPIx))
	{
		/* Call function Slave Reception Callback */
		hmt_SPIRxCB(SPIx);
	}
	/* Check RXNE flag value in ISR register */
	else if(LL_SPI_IsActiveFlag_TXE(SPIx))
	{
		/* Call function Slave Reception Callback */
		hmt_SPITxCB(SPIx);
	}
	/* Check STOP flag value in ISR register */
	else if(LL_SPI_IsActiveFlag_OVR(SPIx))
	{
		/* Call Error function */
		// SPI2_TransferError_Callback();
	}
}
































#endif /* USE_SPI */
