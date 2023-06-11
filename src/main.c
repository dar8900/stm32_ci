#include "main.h"


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
            hmt_GpioTogglePin(PC_13_ID);
            hmt_GpioTogglePin(PB_3_ID);
            if(NewTimeout < 500)
                NewTimeout += 2;
            else
                NewTimeout = 50;
            hmt_UsartSendMsg(USART_USED, "Hello world!", strlen("Hello world!"));
        }
    }

    return 0;
    
}
