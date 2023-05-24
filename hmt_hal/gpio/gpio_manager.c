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


bool hmt_togglePin(gpio_def *Gpio)
{
    bool Toggled = false;
    uint32_t odr = READ_REG(Gpio->port->ODR);
    Gpio->oldVal = ValueToDigital(odr);
    LL_GPIO_TogglePin(Gpio->port, Gpio->pinDef.Pin);
    if(READ_REG(Gpio->port->ODR != odr)){
        odr = READ_REG(Gpio->port->ODR);
        Toggled = true;
        Gpio->actualVal = ValueToDigital(odr);
    }
    return Toggled;
}