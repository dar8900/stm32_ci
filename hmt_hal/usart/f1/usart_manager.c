#include "usart_manager.h"
#include "rcc_manager.h"


void hmt_UsartInit(USART_TypeDef *UsartX)
{
	if(UsartX == USART1){
				/* USART1 interrupt Init */
		NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),10, 0));
		NVIC_EnableIRQ(USART1_IRQn);
		LL_GPIO_AF_EnableRemap_USART1();
	} 
	else if (UsartX == USART2){
				/* USART1 interrupt Init */
		NVIC_SetPriority(USART2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),10, 0));
		NVIC_EnableIRQ(USART2_IRQn);
		LL_GPIO_AF_EnableRemap_USART2();
	}
#ifdef USART3
	else if (UsartX == USART3){
				/* USART1 interrupt Init */
		NVIC_SetPriority(USART3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),10, 0));
		NVIC_EnableIRQ(USART3_IRQn);
		LL_GPIO_AF_EnableRemap_USART3();
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
}