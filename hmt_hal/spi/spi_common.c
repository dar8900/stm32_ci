#include "spi_common.h"

#ifdef USE_SPI

#define SPI_TX_BUFFER_LEN		1024
#define SPI_RX_BUFFER_LEN		  64


typedef struct spi_msg_var
{
	uint8_t txBuffer
}spi_msg_var_s;


void hmt_SPIRxCB(SPI_TypeDef *SPIx)
{

}


void hmt_SPITxCB(SPI_TypeDef *SPIx)
{

}












#endif /* USE_SPI */