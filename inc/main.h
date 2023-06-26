#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

#include "hmt_common.h"
#include "hmt_simple_timer.h"
#include "rcc_manager.h"
#include "gpio_manager.h"

#ifdef USE_USART
#include "usart_manager.h"
#endif

#ifdef USE_SPI
#include "spi_common.h"
#endif

#endif