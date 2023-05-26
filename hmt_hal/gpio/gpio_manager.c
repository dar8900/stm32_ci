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

bool hmt_InitGpio(gpio_def *Gpio)
{
    // LL_GPIO_Init(Gpio->port, &Gpio->pinDef);
    
}

bool hmt_TogglePin(gpio_def *Gpio)
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

bool hmt_WritePin(gpio_def *Gpio, gpio_value NewVal)
{
    bool Writed = false;
    if(LL_GPIO_GetPinMode(Gpio->port, Gpio->pin) != LL_GPIO_MODE_OUTPUT){
        return false;
    }
    Gpio->oldVal = LL_GPIO_IsOutputPinSet(Gpio->port, Gpio->pin) == 1 ? HIGH : LOW;
    if(NewVal == HIGH){
        LL_GPIO_SetOutputPin(Gpio->port, Gpio->pin);
        Writed = true;
    } else if(NewVal == LOW) {
        LL_GPIO_ResetOutputPin(Gpio->port, Gpio->pin);
        Writed = true;
    }
    Gpio->actualVal = Writed ? NewVal : Gpio->oldVal;
    return Writed;
}

bool hmt_ReadPin(gpio_def *Gpio)
{
    bool Readed = true;
    if(LL_GPIO_GetPinMode(Gpio->port, Gpio->pin) != LL_GPIO_MODE_INPUT){
        return false;
    }
    Gpio->oldVal = Gpio->actualVal;
    Gpio->actualVal = LL_GPIO_IsInputPinSet(Gpio->port, Gpio->pin) == 1 ? HIGH : LOW;
    return Readed;
}