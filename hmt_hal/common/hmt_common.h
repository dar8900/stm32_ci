#ifndef HMT_COMMON_H
#define HMT_COMMON_H

#if defined STM32F1
    #include <stm32f1xx_hal.h>
    #include "stm32f1xx_ll_i2c.h"
    #include "stm32f1xx_ll_rcc.h"
    #include "stm32f1xx_ll_bus.h"
    #include "stm32f1xx_ll_system.h"
    #include "stm32f1xx_ll_exti.h"
    #include "stm32f1xx_ll_cortex.h"
    #include "stm32f1xx_ll_utils.h"
    #include "stm32f1xx_ll_pwr.h"
    #include "stm32f1xx_ll_dma.h"
    #include "stm32f1xx_ll_spi.h"
    #include "stm32f1xx_ll_usart.h"
    #include "stm32f1xx_ll_gpio.h"

    #define LL_GPIO_SPEED_FREQ_VERY_HIGH    0xFFFFFFFF
    #define LL_GPIO_PULL_NO                 0xFFFFFFFF
#endif
#if defined STM32F4
    #include <stm32f4xx_hal.h>
    #include "stm32f4xx_ll_i2c.h"
    #include "stm32f4xx_ll_rcc.h"
    #include "stm32f4xx_ll_bus.h"
    #include "stm32f4xx_ll_system.h"
    #include "stm32f4xx_ll_exti.h"
    #include "stm32f4xx_ll_cortex.h"
    #include "stm32f4xx_ll_utils.h"
    #include "stm32f4xx_ll_pwr.h"
    #include "stm32f4xx_ll_dma.h"
    #include "stm32f4xx_ll_spi.h"
    #include "stm32f4xx_ll_usart.h"
    #include "stm32f4xx_ll_gpio.h"
#endif

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct hmt_simple_timer
{
    bool start;
    bool stop;
    uint32_t counter;
    uint32_t timeout;
}simple_timer_t;

typedef enum usart_rx_ret
{
    USART_RX_MSG_RCV = 0,
    USART_RX_MSG_IDLE,
    USART_RX_MSG_ERROR
}usart_rx_ret_code;

typedef enum spi_tx_ret_e
{
    SPI_TX_IDLE = 0,
    SPI_TX_SENT,
    SPI_TX_TIMEOUT,
    SPI_TX_ERROR
}spi_tx_ret_v;
typedef enum spi_rx_ret_e
{
    SPI_RX_IDLE = 0,
    SPI_RX_RECEIVED,
    SPI_RX_TIMEOUT,
    SPI_RX_ERROR
}spi_rx_ret_v;


/**
 * @brief Return ms elapsed
 * 
 * @return uint32_t MsTick
 */
uint32_t hmt_GetMsTick();

/**
 * @brief Delay in blocking mode for specify ms
 * 
 * @param uint32_t DelayMs 
 */
void hmt_Delay(uint32_t DelayMs);


/* USART */
bool hmt_UsartSendMsg(USART_TypeDef *UsartX, uint8_t *Data, uint32_t MsgLen);
usart_rx_ret_code hmt_UsartReceiveMsg(USART_TypeDef *UsartX, uint8_t *Data, uint32_t MsgLen, uint32_t Timeout);




#include "project_board.h"


#endif