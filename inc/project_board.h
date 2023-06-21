#ifndef PROJECT_BOARD
#define PROJECT_BOARD

#include "hmt_common.h"

// #define USE_HSI
#define USE_HSE

// #define USE_USART
#ifdef USE_USART
	#define USART_USED			USART1
#endif

// #define USE_SPI
#ifdef USE_SPI
	#define SPI_USED			SPI1
#endif

// #define USE_I2C
#ifdef USE_I2C
	#define I2C_USED			I2C1
#endif

#define USE_ADC
#ifdef USE_ADC
	#define ADC_USED			ADC1
	#define DMA_USED			DMA1
	#define ADC_CHAN_NUM		1 /* MAX 16 */
	#define ADC_BUFF_SIZE		50
	#define DMA_ADC_CHANNEL		LL_DMA_CHANNEL_1
#endif

/*
#define    P<port>_<pin>_MODE    		NOT_USED
#define    P<port>_<pin>_SPEED    		SPEED_HIGH
#define    P<port>_<pin>_OUTPUT    		PUSH_PULL
#define    P<port>_<pin>_PULL_TYPE  	NO_PULL
#define    P<port>_<pin>_AF_TYPE   		NO_PULL
#define    P<port>_<pin>_ACTIVE_LEVEL   HIGH
#define    P<port>_<pin>_START_LEVEL   	LOW
*/

#define PC_13_MODE		OUTPUT
#define PC_13_SPEED		SPEED_HIGH
#define PC_13_OUTPUT	PUSH_PULL
#define PC_13_PULL_TYPE	NO_PULL

#define DEBUG_LED		PC_13_ID

#endif
