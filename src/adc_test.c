#include "adc_test.h"
#include "hmt_simple_timer.h"
#ifdef USE_ADC

void AdcTestInit()
{
	hmt_AdcInit(ADC_USED, DMA_USED);
}

void AdcTestRun()
{
	uint16_t DataRaw = 0, AdcVoltAvg = 0;
	DataRaw = hmt_AdcGetDataRaw(ADC_CHAN_NUM);
	AdcVoltAvg = hmt_AdcGetAvgVoltage(ADC_CHAN_NUM);
	hmt_AdcDataHandle();
}


#endif /* USE_ADC */