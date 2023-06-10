#include "hmt_common.h"
#include "rcc_common.h"


void hmt_Delay(uint32_t DelayMs)
{
	LL_mDelay(DelayMs);
}

uint32_t hmt_GetMsTick()
{
	return Tick1Ms;
}