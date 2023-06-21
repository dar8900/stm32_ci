#include "main.h"
#include "i2c_common.h"


int main(void)
{
    simple_timer_t ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
    hmt_SimpleTimerStart(&ToggleTimer, 50);
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, 0))
        {
            hmt_GpioTogglePin(DEBUG_LED);
            // hmt_I2C_MasterTransmitter(I2C1);
        }
    }

    return 0;
    
}
