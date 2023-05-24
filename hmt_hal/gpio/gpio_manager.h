#ifndef GPIO_MANAGER_H
#define GPIO_MANAGER_H

#include "hmt_common.h"

typedef enum gpio_value
{
    LOW = GPIO_PIN_RESET,
    HIGH = GPIO_PIN_SET
}gpio_value;
// typedef enum
// {
//     PORT_A = GPIOA,
//     PORT_B = GPIOB,
//     PORT_C = GPIOC,
//     PORT_D = GPIOD,
//     PORT_E = GPIOE,
// #ifdef GPIOF
//     PORT_F = GPIOF,
// #endif
// #ifdef GPIOG
//     PORT_G = GPIOG,
// #endif    
// #ifdef GPIOH
//     PORT_H = GPIOH    
// #endif
// }gpio_port;

typedef enum gpio_pin
{
    IO_PIN_0  =  LL_GPIO_PIN_0,
    IO_PIN1   =  LL_GPIO_PIN_1,
    IO_PIN2   =  LL_GPIO_PIN_2,
    IO_PIN3   =  LL_GPIO_PIN_3,
    IO_PIN4   =  LL_GPIO_PIN_4,
    IO_PIN5   =  LL_GPIO_PIN_5,
    IO_PIN6   =  LL_GPIO_PIN_6,
    IO_PIN7   =  LL_GPIO_PIN_7,
    IO_PIN8   =  LL_GPIO_PIN_8,
    IO_PIN9   =  LL_GPIO_PIN_9,
    IO_PIN10  =  LL_GPIO_PIN_10,
    IO_PIN11  =  LL_GPIO_PIN_11,
    IO_PIN12  =  LL_GPIO_PIN_12,
    IO_PIN13  =  LL_GPIO_PIN_13,
    IO_PIN14  =  LL_GPIO_PIN_14,
    IO_PIN15  =  LL_GPIO_PIN_15,
    IO_MAX_PIN = 17
}gpio_pin;

typedef struct 
{
    GPIO_TypeDef            *port;
    LL_GPIO_InitTypeDef      pinDef;
    gpio_value              actualVal;
    gpio_value              oldVal;
}gpio_def;



bool hmt_togglePin(gpio_def *Gpio);

#endif