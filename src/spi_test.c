#include "spi_test.h"

#ifdef USE_SPI


void SpiTestInit()
{
	hmt_SPI_Init(SPI_USED);
}


void SpiTestRun()
{
	char *Msg = "Hello from stm32f013 with spi test\r\n";
	hmt_SPIMasterTransmit(SPI_USED, Msg, strlen(Msg), 0);
}

#endif /* USE_SPI */