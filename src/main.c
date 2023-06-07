#include "main.h"


int main(void)
{
    simple_timer ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
#ifdef USE_USART    
    hmt_UsartInit(USART_USED);
#endif
    hmt_SimpleTimerStart(&ToggleTimer, 50);
    uint32_t NewTimeout = 50;
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, NewTimeout))
        {
            hmt_GpioTogglePin(PA_5_ID);
            if(NewTimeout < 500)
                NewTimeout += 2;
            else
                NewTimeout = 50;
            hmt_UsartSendMsg(USART_USED, "Hello world!", strlen("Hello world!"));
        }
    }

    return 0;
}
