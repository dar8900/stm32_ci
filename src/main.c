#include "main.h"
#include "adc_manager.h"
#include "adc_common.h"



int main(void)
{
    simple_timer_t ToggleTimer;
    hmt_RccInit();
    hmt_GpioInit();
    hmt_Adc_Init(ADC_USED, DMA_USED);
    hmt_SimpleTimerStart(&ToggleTimer, 500);
    for (;;)
    {
        if(hmt_SimpleTimerElapsed(&ToggleTimer, true, 0))
        {
            hmt_GpioTogglePin(DEBUG_LED);
        }
        hmt_AdcDataHandle();
    }

    return 0;
    
}
