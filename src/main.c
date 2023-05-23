#include "main.h"


void initGPIO()
{
    GPIO_InitTypeDef GPIO_Config;

    GPIO_Config.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Config.Pull = GPIO_NOPULL;
    GPIO_Config.Speed = GPIO_SPEED_FREQ_HIGH;

    GPIO_Config.Pin = LED_PIN;

    LED_PORT_CLK_ENABLE();
    HAL_GPIO_Init(LED_PORT, &GPIO_Config);
}

int main(void)
{
    HAL_Init();
    initGPIO();
    // 1kHz ticks
    HAL_SYSTICK_Config(SystemCoreClock / 1000);

    for (;;)
        __WFI();

    return 0;
}
