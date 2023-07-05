#include "main.h"

void CiTestInit()
{
#ifdef USE_USART
    
#endif

#ifdef USE_SPI
#endif

#ifdef USE_I2C
#endif

#ifdef USE_ADC
#endif

#ifdef USE_PWM
#endif

#ifdef USE_INPUT_CAPTURE
#endif
}

int main(void)
{
    simple_timer_t ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
    for (;;)
    {

    }

    return 0;
    
}
