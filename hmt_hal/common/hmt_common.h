#ifndef HMT_COMMON_H
#define HMT_COMMON_H

#if defined STM32F1
    #include <stm32f1xx_hal.h>
    #include "stm32f1xx_ll_i2c.h"
    #include "stm32f1xx_ll_rcc.h"
    #include "stm32f1xx_ll_bus.h"
    #include "stm32f1xx_ll_system.h"
    #include "stm32f1xx_ll_exti.h"
    #include "stm32f1xx_ll_cortex.h"
    #include "stm32f1xx_ll_utils.h"
    #include "stm32f1xx_ll_pwr.h"
    #include "stm32f1xx_ll_dma.h"
    #include "stm32f1xx_ll_spi.h"
    #include "stm32f1xx_ll_usart.h"
    #include "stm32f1xx_ll_gpio.h"

    #define LL_GPIO_SPEED_FREQ_VERY_HIGH    0xFFFFFFFF
    #define LL_GPIO_PULL_NO                 0xFFFFFFFF
#endif
#if defined STM32F4
    #include <stm32f4xx_hal.h>
    #include "stm32f4xx_ll_i2c.h"
    #include "stm32f4xx_ll_rcc.h"
    #include "stm32f4xx_ll_bus.h"
    #include "stm32f4xx_ll_system.h"
    #include "stm32f4xx_ll_exti.h"
    #include "stm32f4xx_ll_cortex.h"
    #include "stm32f4xx_ll_utils.h"
    #include "stm32f4xx_ll_pwr.h"
    #include "stm32f4xx_ll_dma.h"
    #include "stm32f4xx_ll_spi.h"
    #include "stm32f4xx_ll_usart.h"
    #include "stm32f4xx_ll_gpio.h"
#endif


#include <stdint.h>
#include <stdbool.h>

typedef struct hmt_simple_timer
{
    bool start;
    bool stop;
    uint32_t counter;
    uint32_t timeout;
}simple_timer;


#define P(port)      GPIO##port


typedef enum gpio_mode
{
    NOT_USED = 0,
    INPUT = LL_GPIO_MODE_INPUT,
    OUTPUT = LL_GPIO_MODE_OUTPUT,
    ANALOG = LL_GPIO_MODE_ANALOG,
    ALTERNATE = LL_GPIO_MODE_ALTERNATE
}gpio_mode;

typedef enum gpio_output
{
    PUSH_PULL = LL_GPIO_OUTPUT_PUSHPULL,
    OPEN_DRAIN = LL_GPIO_OUTPUT_OPENDRAIN
}gpio_output;

typedef enum gpio_input
{
    NO_PULL = LL_GPIO_PULL_NO,
    PULL_UP = LL_GPIO_PULL_UP,
    PULL_DOWN = LL_GPIO_PULL_DOWN
}gpio_input;

typedef enum gpio_speed
{
    SPEED_LOW = LL_GPIO_SPEED_FREQ_LOW,       
    SPEED_MED = LL_GPIO_SPEED_FREQ_MEDIUM,    
    SPEED_HIGH = LL_GPIO_SPEED_FREQ_HIGH,      
    SPEED_V_HIGH = LL_GPIO_SPEED_FREQ_VERY_HIGH 
}gpio_speed;

typedef enum gpio_value
{
    LOW = GPIO_PIN_RESET,
    HIGH = GPIO_PIN_SET
}gpio_value;

typedef enum gpio_pin
{
    IO_PIN_0   =  LL_GPIO_PIN_0,
    IO_PIN_1   =  LL_GPIO_PIN_1,
    IO_PIN_2   =  LL_GPIO_PIN_2,
    IO_PIN_3   =  LL_GPIO_PIN_3,
    IO_PIN_4   =  LL_GPIO_PIN_4,
    IO_PIN_5   =  LL_GPIO_PIN_5,
    IO_PIN_6   =  LL_GPIO_PIN_6,
    IO_PIN_7   =  LL_GPIO_PIN_7,
    IO_PIN_8   =  LL_GPIO_PIN_8,
    IO_PIN_9   =  LL_GPIO_PIN_9,
    IO_PIN_10  =  LL_GPIO_PIN_10,
    IO_PIN_11  =  LL_GPIO_PIN_11,
    IO_PIN_12  =  LL_GPIO_PIN_12,
    IO_PIN_13  =  LL_GPIO_PIN_13,
    IO_PIN_14  =  LL_GPIO_PIN_14,
    IO_PIN_15  =  LL_GPIO_PIN_15,
    IO_MAX_PIN = 17
}gpio_pin;

typedef struct 
{
    GPIO_TypeDef            *port;
    uint32_t                pin;         
    uint32_t                mode;        
    uint32_t                speed;       
    uint32_t                outputType;  
    uint32_t                pull;
    uint32_t                alternate;

}gpio_def;

typedef struct 
{
    gpio_value              active_level;                 
    gpio_value              actualVal;
    gpio_value              oldVal;
}gpio_val_s;



extern volatile uint32_t Tick1Ms;

/**
 * @brief Return ms elapsed
 * 
 * @return uint32_t MsTick
 */
uint32_t hmt_GetMsTick();

/**
 * @brief Delay in blocking mode for specify ms
 * 
 * @param uint32_t DelayMs 
 */
void hmt_Delay(uint32_t DelayMs);

#include "project_board.h"


#endif