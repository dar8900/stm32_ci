#ifndef PROJECT_BOARD
#define PROJECT_BOARD

// #define USE_HSI
#define USE_HSE

#define HCLK					72000000

// #define USE_USART
#ifdef USE_USART
	#define USART_USED			USART2
#endif

// #define USE_SPI
#ifdef USE_SPI
	#define SPI_USED			SPI1
#endif

// #define USE_I2C
#ifdef USE_I2C
	#define I2C_USED			I2C1
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
// #define PA_9_MODE		ALTERNATE
// #define PA_9_SPEED		SPEED_HIGH
// #define PA_9_OUTPUT		PUSH_PULL
// #define PA_9_PULL_TYPE	NO_PULL

// /* RX */
// #define PA_10_MODE		INPUT
// #define PA_10_PULL_TYPE	PULL_UP
// #define PA_10_SPEED		SPEED_HIGH

/* USART 2 */
/* TX */
#define PA_2_MODE		ALTERNATE
#define PA_2_SPEED		SPEED_HIGH
#define PA_2_OUTPUT		PUSH_PULL
#define PA_2_PULL_TYPE	NO_PULL

/* RX */
#define PA_3_MODE		INPUT
#define PA_3_PULL_TYPE	PULL_UP
#define PA_3_SPEED		SPEED_HIGH

#define PA_5_MODE		OUTPUT
#define PA_5_SPEED		SPEED_HIGH
#define PA_5_OUTPUT		PUSH_PULL
#define PA_5_PULL_TYPE	NO_PULL

#define PC_13_MODE		OUTPUT
#define PC_13_SPEED		SPEED_HIGH
#define PC_13_OUTPUT	PUSH_PULL
#define PC_13_PULL_TYPE	NO_PULL

/* GPIO custom name ids */
#define DEBUG_LED		PC_13_ID


#endif
