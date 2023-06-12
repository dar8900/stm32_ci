#ifndef PROJECT_BOARD
#define PROJECT_BOARD

#include "hmt_common.h"

// #define USE_HSI
#define USE_HSE

#define USE_USART
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
#define    P<port>_<pin>_ACTIVE_LEVEL   HIGH
#define    P<port>_<pin>_START_LEVEL   	LOW
*/

/* USART 1 */
/* TX */
#define PA_9_MODE		ALTERNATE
#define PA_9_SPEED		SPEED_HIGH
#define PA_9_OUTPUT		PUSH_PULL
#define PA_9_PULL_TYPE	NO_PULL

/* RX */
#define PA_10_MODE		INPUT
#define PA_10_PUL_TYPE	PULL_UP
#define PA_10_SPEED		SPEED_HIGH



#define PB_3_MODE		OUTPUT
#define PB_3_SPEED		SPEED_HIGH
#define PB_3_OUTPUT		PUSH_PULL
#define PB_3_PULL_TYPE	NO_PULL

#define PC_13_MODE		OUTPUT
#define PC_13_SPEED		SPEED_HIGH
#define PC_13_OUTPUT	PUSH_PULL
#define PC_13_PULL_TYPE	NO_PULL

#endif
