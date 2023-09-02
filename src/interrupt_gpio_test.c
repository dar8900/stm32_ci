#include "interrupt_gpio_test.h"
#include "main.h"

#ifdef USE_EXTI
static void GpioITHandler()
{
	hmt_GpioTogglePin(LED_TEST);
}

void InterruptGpioTestInit()
{
	hmt_GpioSetEXTI_IT_Handler(PB_12_ID, GpioITHandler);
}


void InterruptGpioTestRun()
{
	

}


#endif