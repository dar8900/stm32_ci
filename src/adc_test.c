#include "adc_test.h"
#include "hmt_simple_timer.h"
#ifdef USE_ADC

void AdcTestInit()
{
	hmt_Adc_Init(ADC_USED, DMA_USED);
}

void AdcTestRun()
{
	simple_timer_t AdcTestTimer;
	hmt_SimpleTimerStart(&AdcTestTimer, 500);
	uint16_t DataRaw = 0, AdcVoltAvg = 0;
	while(1)
	{	
		if(hmt_SimpleTimerElapsed(&AdcTestTimer, true, 0))
		{
			DataRaw = hmt_AdcGetDataRaw(ADC_CHAN_NUM);
			AdcVoltAvg = hmt_AdcGetAvgVoltage(ADC_CHAN_NUM);
		}
		hmt_AdcDataHandle();
	}
}


#endif /* USE_ADC */