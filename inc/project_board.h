#ifndef PROJECT_BOARD
#define PROJECT_BOARD

#include "hmt_common.h"

// #define USE_HSI
#define USE_HSE

// #define USE_USART
#ifdef USE_USART
	#define USART_USED			USART1
#endif

#define USE_SPI
#ifdef USE_SPI
	#define SPI_USED			SPI1
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

/* SPI 1 */
/* MOSI */
#define PA_7_MODE		ALTERNATE
#define PA_7_SPEED		SPEED_HIGH
#define PA_7_OUTPUT		PUSH_PULL
#define PA_7_PULL_TYPE	NO_PULL
/* MISO */
#define PA_6_MODE		INPUT
#define PA_6_SPEED		SPEED_HIGH
#define PA_6_PULL_TYPE	PULL_UP
/* SLK */
#define PA_5_MODE		ALTERNATE
#define PA_5_SPEED		SPEED_HIGH
#define PA_5_OUTPUT		PUSH_PULL
#define PA_5_PULL_TYPE	NO_PULL


#define PC_13_MODE		OUTPUT
#define PC_13_SPEED		SPEED_HIGH
#define PC_13_OUTPUT	PUSH_PULL
#define PC_13_PULL_TYPE	NO_PULL

#define DEBUG_LED		PC_13_ID

#endif
