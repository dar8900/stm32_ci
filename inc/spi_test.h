#ifndef SPI_TEST_H
#define SPI_TEST_H

#include "hmt_common.h"
#include "spi_manager.h"
#include "spi_common.h"

#ifdef USE_SPI

void SpiTestInit();
void SpiTestRun();

#endif /* USE_SPI */
#endif