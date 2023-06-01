#ifndef GPIO_MANAGER_H
#define GPIO_MANAGER_H

#include "gpio_defs.h"

void hmt_GpioInit();
bool hmt_GpioWritePin(uint16_t GpioId, gpio_value NewVal);
bool hmt_GpioReadPin(uint16_t GpioId);
bool hmt_GpioTogglePin(uint16_t GpioId);

#endif