#include "hmt_common.h"

volatile uint32_t Tick1Ms = 0;

void hmt_Delay(uint32_t DelayMs)
{
	LL_mDelay(DelayMs);
}