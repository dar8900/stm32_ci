#include "main.h"

static void GpioItHandler()
{
    hmt_GpioTogglePin(DEBUG_LED);
}

int main(void)
{
    simple_timer_t ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
    hmt_GpioSetEXTI_IT_Handler(IT_PIN, GpioItHandler);
    hmt_SimpleTimerStart(&ToggleTimer, 50);
    for (;;)
    {

    }

    return 0;
    
}
