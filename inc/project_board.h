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

/*
#define    P<port>_<pin>_MODE    		NOT_USED
#define    P<port>_<pin>_SPEED    		SPEED_HIGH
#define    P<port>_<pin>_OUTPUT    		PUSH_PULL
#define    P<port>_<pin>_PULL_TYPE  	NO_PULL
#define    P<port>_<pin>_AF_TYPE   		NO_PULL
#define    P<port>_<pin>_ACTIVE_LEVEL   NO_PULL
#define    P<port>_<pin>_START_LEVEL   	NO_PULL
*/

#endif
