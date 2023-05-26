#ifndef HMT_COMMON_H
#define HMT_COMMON_H

#if defined STM32F1
    #include <stm32f1xx_hal.h>
    #include <stm32f1xx_ll_gpio.h>

    #define LL_GPIO_SPEED_FREQ_VERY_HIGH    0xFFFFFFFF
    #define LL_GPIO_PULL_NO     0xFFFFFFFF
#endif
#if defined STM32F4
    #include <stm32f4xx_hal.h>
    #include <stm32f4xx_ll_gpio.h>
#endif
#include <stdint.h>
#include <stdbool.h>



#endif