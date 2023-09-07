#include "interrupt_gpio_test.h"
#include "main.h"

#ifdef USE_EXTI
static void GpioITHandler()
{
	hmt_GpioTogglePin(LED_TEST);
#ifdef USE_USART
	hmt_UsartSendMsg(USART_USED, (uint8_t *)"EXTI Attivo!\r\n", strlen("EXTI Attivo!\r\n"));
#endif
}

void InterruptGpioTestInit()
{
	hmt_GpioSetEXTI_IT_Handler(EXTI_PIN, GpioITHandler);
	hmt_GpioSetEXTI_IT_Handler(USER_BUTTON, GpioITHandler);
}


void InterruptGpioTestRun()
{
	

}


#endif