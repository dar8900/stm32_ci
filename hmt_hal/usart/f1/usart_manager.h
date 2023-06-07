#ifndef HMT_USART_MANAGER_H
#define HMT_USART_MANAGER_H
#include "hmt_common.h"
#include "hmt_usart_common.h"

void hmt_UsartInit(USART_TypeDef *UsartX);
void hmt_Usart_IT_Handler(USART_TypeDef *UsartX);

#endif