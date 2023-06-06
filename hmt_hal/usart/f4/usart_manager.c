#include "usart_manager.h"
#include "rcc_manager.h"


void hmt_UsartInit(USART_TypeDef *UsartX)
{


	if(UsartX == USART1){
				/* USART1 interrupt Init */
		NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),10, 0));
		NVIC_EnableIRQ(USART1_IRQn);
	} 
	else if (UsartX == USART2){
				/* USART1 interrupt Init */
		NVIC_SetPriority(USART2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),10, 0));
		NVIC_EnableIRQ(USART2_IRQn);
	}
#ifdef USART3
	else if (UsartX == USART3){
				/* USART1 interrupt Init */
		NVIC_SetPriority(USART3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),10, 0));
		NVIC_EnableIRQ(USART3_IRQn);
	}
#endif /* USART 3 */

	LL_USART_InitTypeDef USART_InitStruct = {0};

	USART_InitStruct.BaudRate = 115200;
	USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
	USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
	USART_InitStruct.Parity = LL_USART_PARITY_NONE;
	USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
	USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
	USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
	LL_USART_Init(UsartX, &USART_InitStruct);
	LL_USART_ConfigAsyncMode(UsartX);

	// TODO Enable interrupts

	LL_USART_Enable(UsartX);

	/* Enable RXNE and Error interrupts */
	LL_USART_EnableIT_RXNE(UsartX);
	LL_USART_EnableIT_ERROR(UsartX);
}

void hmt_Usart_IT_Handler(USART_TypeDef *UsartX)
{
	/* Check Tx data */
	if (LL_USART_IsEnabledIT_TXE(UsartX) && LL_USART_IsActiveFlag_TXE(UsartX))
	{
		/* TXE flag will be automatically cleared when writing new data in DR register */

		/* Call function in charge of handling empty DR => will lead to transmission of next character */
		hmt_UsartTxEmptyCB(UsartX);
	}

	/* Check Rx data */
	/* Check RXNE flag value in SR register */
	if (LL_USART_IsActiveFlag_RXNE(UsartX) && LL_USART_IsEnabledIT_RXNE(UsartX))
	{
		/* RXNE flag will be cleared by reading of DR register (done in call) */
		/* Call function in charge of handling Character reception */
		hmt_UsartRxCB(UsartX);
	}

	if (LL_USART_IsEnabledIT_TC(UsartX) && LL_USART_IsActiveFlag_TC(UsartX))
	{
		/* Clear TC flag */
		LL_USART_ClearFlag_TC(UsartX);
		/* Call function in charge of handling end of transmission of sent character
			and prepare next character transmission */
		hmt_UsartTcCB(UsartX);
	}

	if (LL_USART_IsEnabledIT_ERROR(UsartX) && LL_USART_IsActiveFlag_NE(UsartX))
	{
		/* Call Error function */
		// Error_Callback(); // TODO
	}
}

