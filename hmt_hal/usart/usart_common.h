#ifndef HMT_USART_COMMON_H
#define HMT_USART_COMMON_H
#include  "hmt_common.h"


void hmt_UsartTxEmptyCB(USART_TypeDef *UsartX);
void hmt_UsartTcCB(USART_TypeDef *UsartX);
void hmt_UsartRxCB(USART_TypeDef *UsartX);







#endif