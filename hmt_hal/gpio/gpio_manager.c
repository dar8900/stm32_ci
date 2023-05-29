#include "gpio_manager.h"




static gpio_value ValueToDigital(uint32_t Val)
{
    gpio_value NewVal = LOW;
    if(Val == 0){
        NewVal = LOW;
     } else {
        NewVal = HIGH;
     }
    return NewVal;
}

bool hmt_GpioInit(const gpio_def *Gpio)
{

    LL_GPIO_InitTypeDef InitStruct = {0};
    InitStruct.Pin = Gpio->pin;
    InitStruct.Mode = Gpio->mode;
    InitStruct.Speed = Gpio->speed;
    InitStruct.OutputType = Gpio->outputType;
    InitStruct.Pull = Gpio->pull;

    if(Gpio->port == GPIOA){
        __HAL_RCC_GPIOA_CLK_ENABLE();
    } else if (Gpio->port == GPIOB){
        __HAL_RCC_GPIOB_CLK_ENABLE();
    } else if (Gpio->port == GPIOC){
        __HAL_RCC_GPIOC_CLK_ENABLE();
    } else if (Gpio->port == GPIOD){
        __HAL_RCC_GPIOD_CLK_ENABLE();
    } else if (Gpio->port == GPIOE){
        __HAL_RCC_GPIOE_CLK_ENABLE();
    } 
#ifdef GPIOF
    else if (Gpio->port == GPIOF){
        __HAL_RCC_GPIOF_CLK_ENABLE();
    } 
#endif
#ifdef GPIOG
    else if (Gpio->port == GPIOG){
        __HAL_RCC_GPIOG_CLK_ENABLE();
    } 
#endif    
#ifdef GPIOH    
    else if (Gpio->port == GPIOH){
        __HAL_RCC_GPIOH_CLK_ENABLE();
    }
#endif

    LL_GPIO_Init(Gpio->port, &InitStruct);
    
}

bool hmt_GpioTogglePin(gpio_def *Gpio)
{
    bool Toggled = false;
    uint32_t TmpVal = 0;
    Gpio->oldVal = LL_GPIO_IsOutputPinSet(Gpio->port, Gpio->pin) == 1 ? HIGH : LOW;
    LL_GPIO_TogglePin(Gpio->port, Gpio->pin);
    TmpVal = LL_GPIO_IsOutputPinSet(Gpio->port, Gpio->pin);
    Toggled = ValueToDigital(TmpVal) != Gpio->oldVal ? true : false;
    Gpio->actualVal = ValueToDigital(TmpVal);
    return Toggled;
}

bool hmt_GpioWritePin(gpio_def *Gpio, gpio_value NewVal)
{
    bool Writed = false;
    if(LL_GPIO_GetPinMode(Gpio->port, Gpio->pin) != LL_GPIO_MODE_OUTPUT){
        return false;
    }
    Gpio->oldVal = LL_GPIO_IsOutputPinSet(Gpio->port, Gpio->pin) == 1 ? HIGH : LOW;
    if(NewVal == HIGH){
        if(Gpio->active_level == HIGH){
            LL_GPIO_SetOutputPin(Gpio->port, Gpio->pin);
        } else {
            LL_GPIO_ResetOutputPin(Gpio->port, Gpio->pin);
        }
        Writed = true;
    } 
    else {
        if(Gpio->active_level == HIGH){
            LL_GPIO_ResetOutputPin(Gpio->port, Gpio->pin);
        } else {
            LL_GPIO_SetOutputPin(Gpio->port, Gpio->pin);
        }        
        Writed = true;
    }
    Gpio->actualVal = Writed ? NewVal : Gpio->oldVal;
    return Writed;
}

bool hmt_GpioReadPin(gpio_def *Gpio)
{
    bool Readed = true;
    if(LL_GPIO_GetPinMode(Gpio->port, Gpio->pin) != LL_GPIO_MODE_INPUT){
        return false;
    }
    Gpio->oldVal = Gpio->actualVal;
    Gpio->actualVal = LL_GPIO_IsInputPinSet(Gpio->port, Gpio->pin) == 1 ? HIGH : LOW;
    if(Gpio->active_level == LOW){
       Gpio->actualVal = Gpio->actualVal == HIGH ? LOW : HIGH;
    }
    return Readed;
}