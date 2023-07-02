#include "main.h"
#include "spi_manager.h"
#include "spi_common.h"


int main(void)
{
    simple_timer_t ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
    hmt_SPIInit(SPI_USED);
    hmt_SimpleTimerStart(&ToggleTimer, 2000);
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, 0))
        {
            hmt_GpioTogglePin(DEBUG_LED);
            hmt_SPIMasterTransmit(SPI_USED, "Hi from stm32f103\r\n", strlen("Hi from stm32f103\r\n"), 0);
        }
    }

    return 0;
    
}
