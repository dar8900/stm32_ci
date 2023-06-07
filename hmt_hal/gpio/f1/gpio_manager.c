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


void hmt_GpioInit()
{
    for(int i = 0; i < MAX_GPIO; i++)
    {
        gpio_def ActualGpio = GpioDefsTab[i];
        if(ActualGpio.mode == NOT_USED){
            continue;
        }
        LL_GPIO_InitTypeDef InitStruct = {0};
        InitStruct.Pin = ActualGpio.pin;
        InitStruct.Mode = ActualGpio.mode;
        InitStruct.Speed = ActualGpio.speed;
        InitStruct.OutputType = ActualGpio.outputType;
        InitStruct.Pull = ActualGpio.pull;


        if(ActualGpio.port == GPIOA && __HAL_RCC_GPIOA_IS_CLK_DISABLED()){
            __HAL_RCC_GPIOA_CLK_ENABLE();
        } else if (ActualGpio.port == GPIOB  && __HAL_RCC_GPIOB_IS_CLK_DISABLED()){
            __HAL_RCC_GPIOB_CLK_ENABLE();
        } else if (ActualGpio.port == GPIOC  && __HAL_RCC_GPIOC_IS_CLK_DISABLED()){
            __HAL_RCC_GPIOC_CLK_ENABLE();
        } else if (ActualGpio.port == GPIOD  && __HAL_RCC_GPIOD_IS_CLK_DISABLED()){
            __HAL_RCC_GPIOD_CLK_ENABLE();
        } else if (ActualGpio.port == GPIOE  && __HAL_RCC_GPIOE_IS_CLK_DISABLED()){
            __HAL_RCC_GPIOE_CLK_ENABLE();
        } 
    #ifdef GPIOF
        else if (ActualGpio.port == GPIOF  && __HAL_RCC_GPIOF_IS_CLK_DISABLED()){
            __HAL_RCC_GPIOF_CLK_ENABLE();
        } 
    #endif
    #ifdef GPIOG
        else if (ActualGpio.port == GPIOG  && __HAL_RCC_GPIOG_IS_CLK_DISABLED()){
            __HAL_RCC_GPIOG_CLK_ENABLE();
        } 
    #endif    
    #ifdef GPIOH    
        else if (ActualGpio.port == GPIOH  && __HAL_RCC_GPIOH_IS_CLK_DISABLED()){
            __HAL_RCC_GPIOH_CLK_ENABLE();
        }
    #endif

        LL_GPIO_Init(ActualGpio.port, &InitStruct);

        GpioValTab[i].activeLevel = ActualGpio.activeLevel;
        GpioValTab[i].actualVal = ActualGpio.startVal;
        GpioValTab[i].oldVal = ActualGpio.startVal;
        if(ActualGpio.mode == OUTPUT)
        {
            if(GpioValTab[i].activeLevel == LOW)
            {
                if(GpioValTab[i].actualVal == HIGH){
                    LL_GPIO_ResetOutputPin(ActualGpio.port, ActualGpio.pin);
                } else {
                    LL_GPIO_SetOutputPin(ActualGpio.port, ActualGpio.pin);
                }
            } 
            else 
            {
                if(GpioValTab[i].actualVal == HIGH){
                    LL_GPIO_SetOutputPin(ActualGpio.port, ActualGpio.pin);
                } else {
                    LL_GPIO_ResetOutputPin(ActualGpio.port, ActualGpio.pin);
                }                
            }
        }
    }
    
}

bool hmt_GpioTogglePin(uint16_t GpioId)
{
    bool Toggled = false;
    uint32_t TmpVal = 0;
    if(GpioId >= MAX_GPIO){
        return false;
    }
    if(GpioDefsTab[GpioId].mode != OUTPUT){
        return false;
    }    
    GpioValTab[GpioId].oldVal = LL_GPIO_IsOutputPinSet(GpioDefsTab[GpioId].port, GpioDefsTab[GpioId].pin) == 1 ? HIGH : LOW;
    LL_GPIO_TogglePin(GpioDefsTab[GpioId].port, GpioDefsTab[GpioId].pin);
    TmpVal = LL_GPIO_IsOutputPinSet(GpioDefsTab[GpioId].port, GpioDefsTab[GpioId].pin);
    Toggled = ValueToDigital(TmpVal) != GpioValTab[GpioId].oldVal ? true : false;
    GpioValTab[GpioId].actualVal = ValueToDigital(TmpVal);
    return Toggled;
}

bool hmt_GpioWritePin(uint16_t GpioId, gpio_value NewVal)
{
    bool Writed = false;
    if(GpioId >= MAX_GPIO){
        return false;
    }    
    if(GpioDefsTab[GpioId].mode != OUTPUT){
        return false;
    }
    GpioValTab[GpioId].oldVal = LL_GPIO_IsOutputPinSet(GpioDefsTab[GpioId].port, GpioDefsTab[GpioId].pin) == 1 ? HIGH : LOW;
    if(NewVal == HIGH){
        if(GpioValTab[GpioId].activeLevel == HIGH){
            LL_GPIO_SetOutputPin(GpioDefsTab[GpioId].port, GpioDefsTab[GpioId].pin);
        } else {
            LL_GPIO_ResetOutputPin(GpioDefsTab[GpioId].port, GpioDefsTab[GpioId].pin);
        }
        Writed = true;
    } 
    else {
        if(GpioValTab[GpioId].activeLevel == HIGH){
            LL_GPIO_ResetOutputPin(GpioDefsTab[GpioId].port, GpioDefsTab[GpioId].pin);
        } else {
            LL_GPIO_SetOutputPin(GpioDefsTab[GpioId].port, GpioDefsTab[GpioId].pin);
        }        
        Writed = true;
    }
    GpioValTab[GpioId].actualVal = Writed ? NewVal : GpioValTab[GpioId].oldVal;
    return Writed;
}

bool hmt_GpioReadPin(uint16_t GpioId)
{
    bool Readed = true;
    if(GpioId >= MAX_GPIO){
        return false;
    }    
    if(GpioDefsTab[GpioId].mode != INPUT){
        return false;
    }
    GpioValTab[GpioId].oldVal = GpioValTab[GpioId].actualVal;
    GpioValTab[GpioId].actualVal = LL_GPIO_IsInputPinSet(GpioDefsTab[GpioId].port, GpioDefsTab[GpioId].pin) == 1 ? HIGH : LOW;
    if(GpioValTab[GpioId].activeLevel == LOW){
       GpioValTab[GpioId].actualVal = GpioValTab[GpioId].actualVal == HIGH ? LOW : HIGH;
    }
    return Readed;
}