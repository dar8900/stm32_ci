#include "main.h"

unsigned char *TestMsg = "Hallo world from stm32f103\r\n";

int main(void)
{
    simple_timer_t ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
#ifdef USE_USART    
    hmt_UsartInit(USART_USED, 115200);
#endif
    hmt_SimpleTimerStart(&ToggleTimer, 50);
    uint32_t NewTimeout = 50;
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, NewTimeout))
        {
            hmt_GpioTogglePin(DEBUG_LED);
            if(NewTimeout < 500)
                NewTimeout += 2;
            else
                NewTimeout = 50;
            hmt_UsartSendMsg(USART_USED, TestMsg, strlen(TestMsg));
        }
    }

    return 0;
    
}
