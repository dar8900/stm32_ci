#include "toggle.h"
#include <stdint.h>
// #include "../stm32f1xx_hal_conf.h"
#include <stm32f1xx_hal.h>

#define LED_PORT                GPIOC
#define LED_PIN                 GPIO_PIN_13

void TogglePin()
{
	HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
}