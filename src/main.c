#include "main.h"

static void CiTestInit()
{
#ifdef USE_USART
    UsartTestInit();
#endif

#ifdef USE_SPI
    SpiTestInit();
#endif

#ifdef USE_I2C
    I2cTestInit();
#endif

#ifdef USE_ADC
    AdcTestInit();
#endif

#ifdef USE_PWM
    PwmTestInit();
#endif

#ifdef USE_INPUT_CAPTURE
    IcTestInit();
#endif

#ifdef USE_FLASH_STORAGE
    FlashTestInit();
#endif
}

static void CiTestRun()
{
#ifdef USE_USART
    UsartTestRun();
#endif

#ifdef USE_SPI
    SpiTestRun();
#endif

#ifdef USE_I2C
    I2cTestRun();
#endif

#ifdef USE_ADC
    AdcTestRun();
#endif

#ifdef USE_PWM
    PwmTestRun();
#endif

#ifdef USE_INPUT_CAPTURE
    IcTestRun();
#endif

#ifdef USE_FLASH_STORAGE
    FlashTestRun();
#endif
}

int main(void)
{
    simple_timer_t ToggleTimer;
    simple_timer_t *ptrToggleTimer = &ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
    CiTestInit();
    hmt_SimpleTimerStart(ptrToggleTimer, 250);
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(ptrToggleTimer, true, 0))
        {
            hmt_GpioTogglePin(DEBUG_LED);
        }
        CiTestRun();
    }

    return 0;
    
}
