#include "interrupt_gpio_test.h"
#include "main.h"

static void GpioITHandler()
{
	hmt_GpioTogglePin(DEBUG_LED);
}

void InterruptGpioTestInit()
{
	hmt_GpioSetEXTI_IT_Handler(PA_8_ID, GpioITHandler);
}


void InterruptGpioTestRun()
{
	

}
