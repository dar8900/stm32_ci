#ifndef HMT_USART_MANAGER_H
#define HMT_USART_MANAGER_H
#include "hmt_common.h"
#include "usart_common.h"

void hmt_UsartInit(USART_TypeDef *UsartX, uint32_t Baudrate);
void hmt_Usart_IT_Handler(USART_TypeDef *UsartX);

#endif