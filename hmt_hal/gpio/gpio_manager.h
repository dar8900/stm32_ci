#ifndef GPIO_MANAGER_H
#define GPIO_MANAGER_H

#include "gpio_defs.h"

bool hmt_GpioInit(const gpio_def *Gpio);
bool hmt_GpioWritePin(gpio_def *Gpio, gpio_value NewVal);
bool hmt_GpioReadPin(gpio_def *Gpio);
bool hmt_GpioTogglePin(gpio_def *Gpio);

#endif