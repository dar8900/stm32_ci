#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

#include "hmt_common.h"
#include "hmt_simple_timer.h"
#include "rcc_manager.h"
#include "gpio_manager.h"

#ifdef USE_USART
#include "usart_test.h"
#endif

#ifdef USE_SPI
#include "spi_test.h"
#endif

#ifdef USE_I2C
#include "i2c_test.h"
#endif

#ifdef USE_ADC
#include "adc_test.h"
#endif

#ifdef USE_PWM
#include "timer_test.h"
#endif

#ifdef USE_INPUT_CAPTURE
#include "timer_test.h"
#endif

#endif