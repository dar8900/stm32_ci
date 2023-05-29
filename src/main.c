#include "main.h"


int main(void)
{
    gpio_def LedPin = {.port = GPIOA, .pin = IO_PIN_5, .mode = OUTPUT, .pull = PUSH_PULL};
    hmt_RccInit();
    hmt_GpioInit(&LedPin);
    for (;;)
    {
        hmt_GpioTogglePin(&LedPin);
        hmt_Delay(1000);
    }

    return 0;
}
