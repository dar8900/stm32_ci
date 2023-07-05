#include "main.h"

unsigned char *TestMsg = "\r\nMessaggio ricevuto\r\n";

char ByteRcv[14]; // = "abcdefghilmno";

int main(void)
{
    simple_timer_t ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
#ifdef USE_USART    
    hmt_UsartInit(USART_USED, 115200);
#endif
    hmt_SimpleTimerStart(&ToggleTimer, 500);
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, 0))
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, 0))
        {
            hmt_GpioTogglePin(DEBUG_LED);
            // hmt_UsartSendMsg(USART_USED, TestMsg, strlen(TestMsg));
        }

        usart_rx_ret_code code = hmt_UsartReceiveMsg(USART_USED, &ByteRcv, 13, 0);
        if(code == USART_RX_MSG_RCV){
            hmt_UsartSendMsg(USART_USED, TestMsg, strlen(TestMsg)); 
            while(!hmt_UsartSendMsg(USART_USED, ByteRcv, strlen(ByteRcv))){}
        }
    }

    return 0;
    
}
