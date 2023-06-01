#ifndef HMT_RCC_MANAGER_H
#define HMT_RCC_MANAGER_H
#include "hmt_common.h"




void hmt_RccInit();

/* I2C RCC */
void hmt_Rcc_I2C_Enable(I2C_TypeDef *i2c_periph);

/* SPI RCC */
void hmt_Rcc_SPI_Enable(SPI_TypeDef *spi_periph);

/* USART RCC */
void hmt_Rcc_USART_Enable(USART_TypeDef *usart_periph);

/* ADC RCC */
void hmt_Rcc_ADC_Enable(ADC_TypeDef *adc_periph);

/* DMA RCC */
void hmt_Rcc_DMA_Enable(DMA_TypeDef *dma_periph);

#endif /* HMT_RCC_MANAGER_H */