#include "rcc_manager.h"

#define SYSYEM_CLOCK(mhz)		(mhz * 1000000)

void hmt_RccInit()
{	
	__HAL_RCC_SYSCFG_CLK_ENABLE();
	__HAL_RCC_PWR_CLK_ENABLE();
		/* System interrupt init*/
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	/* SysTick_IRQn interrupt configuration */
	NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));

	LL_FLASH_SetLatency(LL_FLASH_LATENCY_3);
	while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_3)
	{
	}
	LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
	LL_RCC_HSE_Enable();

	/* Wait till HSE is ready */
	while(LL_RCC_HSE_IsReady() != 1)
	{

	}
	LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_12, 96, LL_RCC_PLLP_DIV_2);
	LL_RCC_PLL_Enable();

	/* Wait till PLL is ready */
	while(LL_RCC_PLL_IsReady() != 1)
	{

	}
	while (LL_PWR_IsActiveFlag_VOS() == 0)
	{
	}
	LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
	LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
	LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
	LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

	/* Wait till System clock is ready */
	while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
	{

	}
	LL_Init1msTick(SYSYEM_CLOCK(100));
	LL_SetSystemCoreClock(SYSYEM_CLOCK(100));
	LL_RCC_SetTIMPrescaler(LL_RCC_TIM_PRESCALER_TWICE);
	LL_SYSTICK_EnableIT();

}

/* I2C RCC */
void hmt_Rcc_I2C_Enable(I2C_TypeDef *i2c_periph)
{
	if(i2c_periph == I2C1){
		__HAL_RCC_I2C1_CLK_ENABLE();
	} 
	else if (i2c_periph == I2C2){
		__HAL_RCC_I2C2_CLK_ENABLE();
	}
#ifdef I2C3 
	else if (i2c_periph == I2C3) {
		__HAL_RCC_I2C3_CLK_ENABLE();
	}
#endif	
}

/* SPI RCC */
void hmt_Rcc_SPI_Enable(SPI_TypeDef *spi_periph)
{
	if(spi_periph == SPI1){
		__HAL_RCC_SPI1_CLK_ENABLE();
	} 
	else if (spi_periph == SPI2){
		__HAL_RCC_SPI2_CLK_ENABLE();
	}
#ifdef SPI3 
	else if (spi_periph == SPI3) {
		__HAL_RCC_SPI3_CLK_ENABLE();
	}
#endif	
}

/* USART RCC */
void hmt_Rcc_USART_Enable(USART_TypeDef *usart_periph)
{
	if(usart_periph == USART1){
		__HAL_RCC_USART1_CLK_ENABLE();
	} 
	else if (usart_periph == USART2){
		__HAL_RCC_USART2_CLK_ENABLE();
	}
#ifdef USART3
	else if (usart_periph == USART3) {
		__HAL_RCC_USART3_CLK_ENABLE();
	}
#endif		
}

/* ADC RCC */
void hmt_Rcc_ADC_Enable(ADC_TypeDef *adc_periph)
{
	if(adc_periph == ADC1){
		__HAL_RCC_ADC1_CLK_ENABLE();
	}
#ifdef ADC2
	else if(adc_periph == ADC2){
		__HAL_RCC_ADC2_CLK_ENABLE();
	}
#endif
}

/* DMA RCC */
void hmt_Rcc_DMA_Enable(DMA_TypeDef *dma_periph)
{
	if(dma_periph == DMA1){
		__HAL_RCC_DMA1_CLK_DISABLE();
	}
#ifdef DMA2
	else if(dma_periph == DMA2){
		__HAL_RCC_DMA2_CLK_DISABLE();
	}
#endif
#ifdef DMA3
	else if(dma_periph == DMA3){
		__HAL_RCC_DMA3_CLK_DISABLE();
	}
#endif
}