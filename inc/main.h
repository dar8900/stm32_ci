#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#if defined STM32L0
    #include <stm32l0xx_hal.h>

    // STM32L0538-Discovery green led - PB4
    #define LED_PORT                GPIOB
    #define LED_PIN                 GPIO_PIN_4
    #define LED_PORT_CLK_ENABLE     __HAL_RCC_GPIOB_CLK_ENABLE
#elif defined STM32F1
    #include <stm32f1xx_hal.h>

    // STM32VL-Discovery green led - PC9
    #define LED_PORT                GPIOC
    #define LED_PIN                 GPIO_PIN_13
    #define LED_PORT_CLK_ENABLE     __HAL_RCC_GPIOC_CLK_ENABLE
#elif defined STM32F4
    #include <stm32f4xx_hal.h>

    // STM32F4-Discovery green led - PD12
    #define LED_PORT                GPIOD
    #define LED_PIN                 GPIO_PIN_12
    #define LED_PORT_CLK_ENABLE     __HAL_RCC_GPIOD_CLK_ENABLE
#endif

#endif