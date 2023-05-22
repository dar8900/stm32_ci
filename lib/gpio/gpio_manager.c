#include <stdint.h>
#if defined STM32F1
    #include <stm32f1xx_hal.h>
#endif
#include "gpio_manager.h"

void TogglePin(GPIO_TypeDef *Port, uint16_t Pin)
{
	HAL_GPIO_TogglePin(Port, Pin);
}