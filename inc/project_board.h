#ifndef PROJECT_BOARD
#define PROJECT_BOARD

#include "hmt_common.h"

// #define USE_HSI
#define USE_HSE

// #define USE_USART
#ifdef USE_USART
	#define USART_USED			USART1
#endif

/*
#define    P<port>_<pin>_MODE    	NOT_USED
#define    P<port>_<pin>_SPEED    	SPEED_HIGH
#define    P<port>_<pin>_OUTPUT    	PUSH_PULL
#define    P<port>_<pin>_PULL_TYPE   NO_PULL
*/


#define PA_5_MODE		OUTPUT
#define PA_5_SPEED		SPEED_HIGH
#define PA_5_OUTPUT		PUSH_PULL
#define PA_5_PULL_TYPE	NO_PULL

#define PC_13_MODE		OUTPUT
#define PC_13_SPEED		SPEED_HIGH
#define PC_13_OUTPUT	PUSH_PULL
#define PC_13_PULL_TYPE	NO_PULL

#endif
