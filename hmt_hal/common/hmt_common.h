#ifndef HMT_COMMON_H
#define HMT_COMMON_H

#if defined STM32F1
    #include <stm32f1xx_hal.h>
    #include <stm32f1xx_ll_gpio.h>
#endif
#if defined STM32F4
    #include <stm32f4xx_hal.h>
    #include <stm32f4xx_ll_gpio.h>
#endif
#include <stdint.h>
#include <stdbool.h>


#endif