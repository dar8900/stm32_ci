#include "rcc_common.h"

volatile uint32_t Tick1Ms = 0;

void hmt_RccSysTickHandler()
{
	if(Tick1Ms < UINT32_MAX){
        Tick1Ms++;
    } else {
        Tick1Ms = 0;
    }
}