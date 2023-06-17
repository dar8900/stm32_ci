#include "main.h"
#include "spi_common.h"

char *TestMSg = "Hello from stm32f103 with SPI\n";

int main(void)
{
    simple_timer_t ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
    hmt_SimpleTimerStart(&ToggleTimer, 500);
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, 0))
        {
            hmt_GpioTogglePin(DEBUG_LED);
            hmt_SPIMasterTransmit(SPI1, TestMSg, strlen(TestMSg), 0);
        }
    }

    return 0;
    
}
