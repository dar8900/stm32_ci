#ifndef PROJECT_BOARD
#define PROJECT_BOARD

#define HCLK					72000000

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

// #define USE_ADC
#ifdef USE_ADC
	#define ADC_USED			ADC1
	#define DMA_USED			DMA1
	#define ADC_CHAN_NUM		1 /* MAX 16 WITHOUT TEMP SENSOR OTHERWISE 15 */
	#define ADC_SAMPLES			50
	#define DMA_ADC_CHANNEL		LL_DMA_CHANNEL_1
	#define TEMP_SENSOR			1
#endif

#define USE_PWM	
#ifdef USE_PWM
	#define TIMER_USED			TIM2
	#define TIMER_CHANNEL		LL_TIM_CHANNEL_CH1
	#define TIMER_CNT_CLK		1000000
	#define PWM_FRQ_DFLT		1000
#endif

#define USE_INPUT_CAPTURE
#ifdef USE_INPUT_CAPTURE

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


/* TIM2 CH1 PWM */
#define PA_0_MODE		ALTERNATE


#define PC_13_MODE		OUTPUT
#define PC_13_SPEED		SPEED_HIGH
#define PC_13_OUTPUT	PUSH_PULL
#define PC_13_PULL_TYPE	NO_PULL

/* GPIO custom name ids */
#define PWM_PIN			PA_0_ID
#define DEBUG_LED		PC_13_ID

#endif
