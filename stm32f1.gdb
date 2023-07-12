#BKP
define f1_bkp_reg
    print /x *(0x40006C00 + 0x4 + (0x4 * $arg0))
end

#ADC
set $ADC_1 = 0x40012400
set $ADC_2 = 0x40012800
set $ADC_3 = 0x40013C00

set $ADC_OFF_SR = 0x00
set $ADC_OFF_CRy = 0x04
set $ADC_OFF_SMPRy = 0x0C
set $ADC_OFF_HTR = 0x24
set $ADC_OFF_LTR = 0x28
set $ADC_OFF_SQR1 = 0x2C
set $ADC_OFF_SQR2 = 0x30
set $ADC_OFF_SQR3 = 0x34
set $ADC_OFF_DR = 0x4C

define f1_ADCx_SR
    if $arg0 >= 1 && $arg0 <= 3
        set $baseaddr = $ADC_$arg0 + $ADC_OFF_SR
        printf "ADC%d SR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_ADCx_SR
Print SR register of ADCx
Usage: f1_ADCx_SR <adc number>
end

define f1_ADCx_CRy
    if $arg0 >= 1 && $arg0 <= 3
        if $arg1 >= 1 && $arg1 <= 2
            set $baseaddr = $ADC_$arg0 + $ADC_OFF_CRy + (0x04 * ($arg1 - 1))
            printf "ADC%d CR%d:\t", $arg0, $arg1
            x/wx $baseaddr
        else
            printf "Wrong <CR number> argument\n"
            help f1_ADCx_CRy
        end
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_CRy
    end
end
document f1_ADCx_CRy
Print CRy register of ADCx
Usage: f1_ADCx_CRy <adc number> <CR number>
end

define f1_ADCx_CFGR
    if $arg0 >= 1 && $arg0 <= 3
        set $baseaddr = $ADC_$arg0 + $ADC_OFF_CFGR
        printf "ADC%d CFGR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_CFGR
    end
end
document f1_ADCx_CFGR
Print CFGR register of ADCx
Usage: f1_ADCx_CFGR <adc number>
end
define f1_ADCx_SMPR1
    if $arg0 >= 1 && $arg0 <= 3
        set $baseaddr = $ADC_$arg0 + $ADC_OFF_SMPR1
        printf "ADC%d SMPR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_SMPR1
    end
end
document f1_ADCx_SMPR1
Print SMPR1 register of ADCx
Usage: f1_ADCx_SMPR1 <adc number>
end

define f1_ADCx_SMPR2
    if $arg0 >= 1 && $arg0 <= 3
        set $baseaddr = $ADC_$arg0 + $ADC_OFF_SMPR2
        printf "ADC%d SMPR2:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_SMPR2
    end
end
document f1_ADCx_SMPR2
Print SMPR2 register of ADCx
Usage: f1_ADCx_SMPR2 <adc number>
end

define f1_ADCx_TR1
    if $arg0 >= 1 && $arg0 <= 3
        set $baseaddr = $ADC_$arg0 + $ADC_OFF_TR1
        printf "ADC%d TR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_TR1
    end
end
document f1_ADCx_TR1
Print TR1 register of ADCx
Usage: f1_ADCx_TR1 <adc number>
end

define f1_ADCx_TR2
    if $arg0 >= 1 && $arg0 <= 3
        set $baseaddr = $ADC_$arg0 + $ADC_OFF_TR2
        printf "ADC%d TR2:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_TR2
    end
end
document f1_ADCx_TR2
Print TR2 register of ADCx
Usage: f1_ADCx_TR2 <adc number>
end

define f1_ADCx_TR3
    if $arg0 >= 1 && $arg0 <= 3
        set $baseaddr = $ADC_$arg0 + $ADC_OFF_TR3
        printf "ADC%d TR3:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_TR3
    end
end
document f1_ADCx_TR3
Print TR3 register of ADCx
Usage: f1_ADCx_TR3 <adc number>
end


define f1_ADCx_SQR1
    if $arg0 >= 1 && $arg0 <= 3
        set $baseaddr = $ADC_$arg0 + $ADC_OFF_SQR1
        printf "ADC%d SQR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_SQR1
    end
end
document f1_ADCx_SQR1
Print SQR1 register of ADCx
Usage: f1_ADCx_SQR1 <adc number>
end

define f1_ADCx_SQR2
    if $arg0 >= 1 && $arg0 <= 3
        set $baseaddr = $ADC_$arg0 + $ADC_OFF_SQR2
        printf "ADC%d SQR2:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_SQR2
    end
end
document f1_ADCx_SQR2
Print SQR2 register of ADCx
Usage: f1_ADCx_SQR2 <adc number>
end

define f1_ADCx_SQR3
    if $arg0 >= 1 && $arg0 <= 3
        set $baseaddr = $ADC_$arg0 + $ADC_OFF_SQR3
        printf "ADC%d SQR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_SQR3
    end
end
document f1_ADCx_SQR3
Print SQR3 register of ADCx
Usage: f1_ADCx_SQR3 <adc number>
end

define f1_ADCx_DR
    if $arg0 >= 1 && $arg0 <= 3
        set $baseaddr = $ADC_$arg0 + $ADC_OFF_DR
        printf "ADC%d DR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_ADCx_DR
    end
end
document f1_ADCx_DR
Print DR register of ADCx
Usage: f1_ADCx_DR <adc number>
end

define f1_ADCx_registers
    if $arg0 >= 1 && $arg0 <= 3
        f1_ADCx_SR $arg0
        f1_ADCx_CRy $arg0 1
        f1_ADCx_CRy $arg0 2
        f1_ADCx_SQR1 $arg0
        f1_ADCx_SQR2 $arg0
        f1_ADCx_SQR3 $arg0
        f1_ADCx_DR $arg0
    else
        printf "Wrong <usart number> argument\n"
        help f1_ADCx_registers
    end
end
document f1_ADCx_registers
Print ADCx registers
Usage: f1_ADCx_registers <adc number>
end


#USART
set $USART_1 = 0x40013800
set $USART_2 = 0x40004400
set $USART_3 = 0x40004800
set $USART_4 = 0x40004C00
set $USART_5 = 0x40005000

set $USART_OFF_SR = 0x00
set $USART_OFF_DR = 0x04
set $USART_OFF_BRR = 0x08
set $USART_OFF_CR1 = 0x0C
set $USART_OFF_CR2 = 0x10
set $USART_OFF_CR3 = 0x14
set $USART_OFF_GTPR = 0x18


define f1_USARTx_SR
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $USART_$arg0 + $USART_OFF_SR
        printf "USART%d SR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_USARTx_SR
    end
end
document f1_USARTx_SR
Print SR register of USARTx
Usage: f1_USARTx_SR <usart number>
end

define f1_USARTx_DR
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $USART_$arg0 + $USART_OFF_DR
        printf "USART%d DR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_USARTx_DR
    end
end
document f1_USARTx_DR
Print DR register of USARTx
Usage: f1_USARTx_DR <usart number>
end

define f1_USARTx_BRR
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $USART_$arg0 + $USART_OFF_BRR
        printf "USART%d BRR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_USARTx_BRR
    end
end
document f1_USARTx_BRR
Print BRR register of USARTx
Usage: f1_USARTx_BRR <usart number>
end

define f1_USARTx_CR1
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $USART_$arg0 + $USART_OFF_CR1
        printf "USART%d CR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_USARTx_CR1
    end
end
document f1_USARTx_CR1
Print CR1 register of USARTx
Usage: f1_USARTx_CR1 <usart number>
end

define f1_USARTx_CR2
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $USART_$arg0 + $USART_OFF_CR2
        printf "USART%d CR2:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_USARTx_CR2
    end
end
document f1_USARTx_CR2
Print CR2 register of USARTx
Usage: f1_USARTx_CR2 <usart number>
end

define f1_USARTx_CR3
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $USART_$arg0 + $USART_OFF_CR3
        printf "USART%d CR3:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_USARTx_CR3
    end
end
document f1_USARTx_CR3
Print CR3 register of USARTx
Usage: f1_USARTx_CR3 <usart number>
end

define f1_USARTx_GTPR
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $USART_$arg0 + $USART_OFF_GTPR
        printf "USART%d GTPR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <adc number> argument\n"
        help f1_USARTx_GTPR
    end
end
document f1_USARTx_GTPR
Print GTPR register of USARTx
Usage: f1_USARTx_GTPR <usart number>
end

define f1_USARTx_registers
    if $arg0 >= 1 && $arg0 <= 5
        f1_USARTx_SR $arg0
        f1_USARTx_DR $arg0
        f1_USARTx_BRR $arg0
        f1_USARTx_CR1 $arg0
        f1_USARTx_CR2 $arg0
        f1_USARTx_CR3 $arg0
        f1_USARTx_GTPR $arg0
    else
        printf "Wrong <usart number> argument\n"
        help f1_USARTx_registers
    end
end
document f1_USARTx_registers
Print USARTx registers
Usage: f1_USARTx_registers <tim number>
end


#SYSTICK
define f1_systick_ctl
    print /x *(0xE000E010)
end

define f1_systick_load
    print /x *(0xE000E014)
end

define f1_systick_value
    print /x *(0xE000E018)
end

define f1_scb_icsr
    print /x *(0xE000ED04)
end

define f1_scb_hfsr
    print /x *(0xE000ED2C)
end

#RCC
set $RCC = 0x40021000

set $RCC_OFF_CR         = 0x00
set $RCC_OFF_CFGR       = 0x04
set $RCC_OFF_CIR        = 0x08
set $RCC_OFF_APB2RSTR   = 0x0C
set $RCC_OFF_APB1RSTR   = 0x10
set $RCC_OFF_AHBENR     = 0x14
set $RCC_OFF_APB2ENR    = 0x18
set $RCC_OFF_APB1ENR    = 0x1C
set $RCC_OFF_BDCR       = 0x20
set $RCC_OFF_CSR        = 0x24

define f1_RCC_CR
    set $baseaddr = $RCC + $RCC_OFF_CR
    printf "RCC CR: \t"
    x/wx $baseaddr
end
document f1_RCC_CR
Print CR register of RCC
Usage: f1_RCC_CR
end

define f1_RCC_CFGR
    set $baseaddr = $RCC + $RCC_OFF_CFGR
    printf "RCC CFGR:\t"
    x/wx $baseaddr
end
document f1_RCC_CFGR
Print CFGR register of RCC
Usage: f1_RCC_CFGR
end

define f1_RCC_CIR
    set $baseaddr = $RCC + $RCC_OFF_CIR
    printf "RCC CIR:\t"
    x/wx $baseaddr
end
document f1_RCC_CIR
Print CIR register of RCC
Usage: f1_RCC_CIR
end

define f1_RCC_APB2RSTR
    set $baseaddr = $RCC + $RCC_OFF_APB2RSTR
    printf "RCC APB2RSTR:\t"
    x/wx $baseaddr
end
document f1_RCC_APB2RSTR
Print APB2RSTR register of RCC
Usage: f1_RCC_APB2RSTR
end

define f1_RCC_APB1RSTR
    set $baseaddr = $RCC + $RCC_OFF_APB1RSTR
    printf "RCC APB1RSTR:\t"
    x/wx $baseaddr
end
document f1_RCC_APB1RSTR
Print APB1RSTR register of RCC
Usage: f1_RCC_APB1RSTR
end

define f1_RCC_AHBENR
    set $baseaddr = $RCC + $RCC_OFF_AHBENR
    printf "RCC AHBENR:\t"
    x/wx $baseaddr
end
document f1_RCC_AHBENR
Print AHBENR register of RCC
Usage: f1_RCC_AHBENR
end

define f1_RCC_APB2ENR
    set $baseaddr = $RCC + $RCC_OFF_APB2ENR
    printf "RCC APB2ENR:\t"
    x/wx $baseaddr
end
document f1_RCC_APB2ENR
Print APB2ENR register of RCC
Usage: f1_RCC_APB2ENR
end

define f1_RCC_APB1ENR
    set $baseaddr = $RCC + $RCC_OFF_APB1ENR
    printf "RCC APB1ENR:\t"
    x/wx $baseaddr
end
document f1_RCC_APB1ENR
Print APB1ENR register of RCC
Usage: f1_RCC_APB1ENR
end

define f1_RCC_BDCR
    set $baseaddr = $RCC + $RCC_OFF_BDCR
    printf "RCC BDCR:\t"
    x/wx $baseaddr
end
document f1_RCC_BDCR
Print BDCR register of RCC
Usage: f1_RCC_BDCR
end

define f1_RCC_CSR
    set $baseaddr = $RCC + $RCC_OFF_CSR
    printf "RCC CSR:\t"
    x/wx $baseaddr
end
document f1_RCC_CSR
Print CSR register of RCC
Usage: f1_RCC_CSR
end

define f1_RCC_registers
    f1_RCC_CR      
    f1_RCC_CFGR    
    f1_RCC_CIR     
    f1_RCC_APB2RSTR
    f1_RCC_APB1RSTR
    f1_RCC_AHBENR  
    f1_RCC_APB2ENR 
    f1_RCC_APB1ENR 
    f1_RCC_BDCR    
    f1_RCC_CSR     
end
document f1_RCC_registers
Print RCC registers
Usage: f1_RCC_registers
end

#TIM:
# TODO: This is valid for TIM2..5; other timer's registers could be different.
set $TIM_1  = 0x40012C00
set $TIM_2  = 0x40000000
set $TIM_3  = 0x40000400
set $TIM_4  = 0x40000800
set $TIM_5  = 0x40000C00
set $TIM_6  = 0x40001000
set $TIM_7  = 0x40001400
set $TIM_8  = 0x40013400
set $TIM_9  = 0x40014C00
set $TIM_10 = 0x40015000
set $TIM_11 = 0x40015800
set $TIM_12 = 0x40001800
set $TIM_13 = 0x40001C00
set $TIM_14 = 0x40002000

set $TIM_OFF_CR1    = 0x00
set $TIM_OFF_CR2    = 0x04
set $TIM_OFF_SMCR   = 0x08
set $TIM_OFF_DIER   = 0x0C
set $TIM_OFF_SR     = 0x10
set $TIM_OFF_EGT    = 0x14
set $TIM_OFF_CCMR1  = 0x18
set $TIM_OFF_CCMR2  = 0x1C
set $TIM_OFF_CCER   = 0x20
set $TIM_OFF_CNT    = 0x24
set $TIM_OFF_PSC    = 0x28
set $TIM_OFF_ARR    = 0x2C
set $TIM_OFF_CCRy   = 0x34
set $TIM_OFF_DCR    = 0x48
set $TIM_OFF_DMAR   = 0x4C

define f1_TIMx_CR1
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_CR1
        printf "TIM%d CR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_CR1
Print CR1 register of TIMx
Usage: f1_TIMx_CR1 <tim number>
end

define f1_TIMx_CR2
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_CR2
        printf "TIM%d CR2:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_CR2
Print CR2 register of TIMx
Usage: f1_TIMx_CR2 <tim number>
end

define f1_TIMx_SMCR
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_SMCR
        printf "TIM%d SMCR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_SMCR
Print SMCR register of TIMx
Usage: f1_TIMx_SMCR <tim number>
end

define f1_TIMx_DIER
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_DIER
        printf "TIM%d DIER:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_DIER
Print DIER register of TIMx
Usage: f1_TIMx_DIER <tim number>
end

define f1_TIMx_SR
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_SR
        printf "TIM%d SR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_SR
Print SR register of TIMx
Usage: f1_TIMx_SR <tim number>
end

define f1_TIMx_EGT
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_EGT
        printf "TIM%d EGT:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_EGT
Print EGT register of TIMx
Usage: f1_TIMx_EGT <tim number>
end

define f1_TIMx_CCMR1
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_CCMR1
        printf "TIM%d CCMR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_CCMR1
Print CCMR1 register of TIMx
Usage: f1_TIMx_CCMR1 <tim number>
end

define f1_TIMx_CCMR2
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_CCMR2
        printf "TIM%d CCMR2:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_CCMR2
Print CCMR2 register of TIMx
Usage: f1_TIMx_CCMR2 <tim number>
end

define f1_TIMx_CCER
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_CCER
        printf "TIM%d CCER:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_CCER
Print CCER register of TIMx
Usage: f1_TIMx_CCER <tim number>
end

define f1_TIMx_CNT
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_CNT
        printf "TIM%d CNT:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_CNT
Print CNT register of TIMx
Usage: f1_TIMx_CNT <tim number>
end

define f1_TIMx_PSC
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_PSC
        printf "TIM%d PSC:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_PSC
Print PSC register of TIMx
Usage: f1_TIMx_PSC <tim number>
end

define f1_TIMx_ARR
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_ARR
        printf "TIM%d ARR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_ARR
Print ARR register of TIMx
Usage: f1_TIMx_ARR <tim number>
end

define f1_TIMx_CCRy
    if $arg0 >= 1 && $arg0 <= 5
        if $arg1 >= 1 && $arg1 <= 4
            set $baseaddr = $TIM_$arg0 + $TIM_OFF_CCRy + (0x04 * ($arg1 - 1))
            printf "TIM%d CCR%d:\t", $arg0, $arg1
            x/wx $baseaddr
        else
            printf "Wrong <CCRy number> argument\n"
            help f1_TIMx_CCRy
        end
    else
        printf "Wrong <tim number> argument\n"
        help f1_TIMx_CCRy
    end
end
document f1_TIMx_CCRy
Print CCRy register of TIMx
Usage: f1_TIMx_CCRy <tim number> <CCRy number>
end

define f1_TIMx_DCR
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_DCR
        printf "TIM%d DCR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_DCR
Print DCR register of TIMx
Usage: f1_TIMx_DCR <tim number>
end

define f1_TIMx_DMAR
    if $arg0 >= 1 && $arg0 <= 5
        set $baseaddr = $TIM_$arg0 + $TIM_OFF_DMAR
        printf "TIM%d DMAR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <tim number> argument\n"
        help f1_ADCx_SR
    end
end
document f1_TIMx_DMAR
Print DMAR register of TIMx
Usage: f1_TIMx_DMAR <tim number>
end

define f1_TIMx_registers
    if $arg0 >= 1 && $arg0 <= 5
        f1_TIMx_CR1 $arg0
        f1_TIMx_CR2 $arg0
        f1_TIMx_SMCR $arg0
        f1_TIMx_DIER $arg0
        f1_TIMx_SR $arg0
        f1_TIMx_EGT $arg0
        f1_TIMx_CCMR1 $arg0
        f1_TIMx_CCMR2 $arg0
        f1_TIMx_CCER $arg0
        f1_TIMx_CNT $arg0
        f1_TIMx_PSC $arg0
        f1_TIMx_ARR $arg0
        f1_TIMx_CCRy $arg0 1
        f1_TIMx_CCRy $arg0 2
        f1_TIMx_CCRy $arg0 3
        f1_TIMx_CCRy $arg0 4
        f1_TIMx_DCR $arg0
        f1_TIMx_DMAR $arg0
    else
        printf "Wrong <tim number> argument\n"
        help f1_TIMx_registers
    end
end
document f1_TIMx_registers
Print TIMx registers
Usage: f1_TIMx_registers <tim number>
end

#GPIOA
set $GPIO_1 = 0x40010800
#GPIOB
set $GPIO_2 = 0x40010C00
#GPIOC
set $GPIO_3 = 0x40011000
#GPIOD
set $GPIO_4 = 0x40011400
#GPIOE
set $GPIO_5 = 0x40011800
#GPIOF
set $GPIO_6 = 0x40011C00
#GPIOG
set $GPIO_7 = 0x40012000

set $GPIO_OFF_CRL = 0x00
set $GPIO_OFF_CRH = 0x04
set $GPIO_OFF_IDR = 0x08

define f1_GPIOx_CRL
    if $arg0 >= 1 && $arg0 <= 7
        set $baseaddr = $GPIO_$arg0 + $GPIO_OFF_CRL
        printf "GPIO%d CRL:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <gpio number> argument\n"
        help f1_GPIOx_CRL
    end
end
document f1_GPIOx_CRL
Print CRL register of GPIOx
Usage: f1_GPIOx_CRL <gpio number>
end

define f1_GPIOx_CRH
    if $arg0 >= 1 && $arg0 <= 7
        set $baseaddr = $GPIO_$arg0 + $GPIO_OFF_CRH
        printf "GPIO%d CRH:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <gpio number> argument\n"
        help f1_GPIOx_CRH
    end
end
document f1_GPIOx_CRH
Print CRH register of GPIOx
Usage: f1_GPIOx_CRH <gpio number>
end

define f1_GPIOx_IDR
    if $arg0 >= 1 && $arg0 <= 7
        set $baseaddr = $GPIO_$arg0 + $GPIO_OFF_IDR
        printf "GPIO%d IDR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <gpio number> argument\n"
        help f1_GPIOx_IDR
    end
end
document f1_GPIOx_IDR
Print IDR register of GPIOx
Usage: f1_GPIOx_IDR <gpio number>
end

#AFIO
set $AFIO = 0x40010000

set $AFIO_OFF_EVCR      = 0x00
set $AFIO_OFF_MAPR      = 0x04
set $AFIO_OFF_EXTICRy   = 0x08
set $AFIO_OFF_MAPR2     = 0x1C

define f1_AFIO_EVCR
    set $baseaddr = $AFIO + $AFIO_OFF_EVCR
    printf "AFIO EVCR:\t"
    x/wx $baseaddr
end
document f1_AFIO_EVCR
Print EVCR register of AFIO
Usage: f1_AFIO_EVCR
end

define f1_AFIO_MAPR
    set $baseaddr = $AFIO + $AFIO_OFF_MAPR
    printf "AFIO MAPR:\t"
    x/wx $baseaddr
end
document f1_AFIO_MAPR
Print MAPR register of AFIO
Usage: f1_AFIO_MAPR
end

define f1_AFIO_EXTICRy
    if $arg0 >= 1 && $arg0 <= 4
        set $baseaddr = $AFIO + $AFIO_OFF_EXTICRy + (0x04 * ($arg0 - 1))
        printf "AFIO EXTICR%d:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <EXTICRy number> argument\n"
        help f1_AFIO_EXTICRy
    end
end
document f1_AFIO_EXTICRy
Print EXTICRy register of AFIO
Usage: f1_AFIO_EXTICRy <exticr number>
end

define f1_AFIO_MAPR2
    set $baseaddr = $AFIO + $AFIO_OFF_MAPR2
    printf "AFIO MAPR2:\t"
    x/wx $baseaddr
end
document f1_AFIO_MAPR2
Print MAPR2 register of AFIO
Usage: f1_AFIO_MAPR2
end

define f1_AFIO_registers
    f1_AFIO_EVCR
    f1_AFIO_MAPR
    f1_AFIO_MAPR2
    f1_AFIO_EXTICRy 1
    f1_AFIO_EXTICRy 2
    f1_AFIO_EXTICRy 3
    f1_AFIO_EXTICRy 4
end
document f1_AFIO_registers
Print AFIO registers
Usage: f1_AFIO_registers
end


#I2C
set $I2C_1 = 0x40005400
set $I2C_2 = 0x40005800

set $I2C_OFF_CR1 = 0x00
set $I2C_OFF_CR2 = 0x04
set $I2C_OFF_OAR1 = 0x08
set $I2C_OFF_OAR2 = 0x0C
set $I2C_OFF_SR1 = 0x14
set $I2C_OFF_SR2 = 0x18
set $I2C_OFF_CCR = 0x1C
set $I2C_OFF_TRISE = 0x20

define f1_I2Cx_CRx
    if $arg0 >= 1 && $arg0 <= 2
        if $arg1 >= 1 && $arg1 <= 2
            set $baseaddr = $I2C_$arg0 + $I2C_OFF_CRx + (0x04 * ($arg1 - 1))
            printf "I2C%d SR%d:\t", $arg0, $arg1
            x/wx $baseaddr
        else
            printf "Wrong <CRx number> argument\n"
            help f1_I2Cx_CRx
        end
    else
        printf "Wrong <i2c number> argument\n"
        help f1_I2Cx_CRx
    end
end
document f1_I2Cx_CRx
Print CRx register of I2Cx
Usage: f1_I2Cx_CRx <i2c number> <CRx number>
end

define f1_I2Cx_OARx
    if $arg0 >= 1 && $arg0 <= 2
        if $arg1 >= 1 && $arg1 <= 2
            set $baseaddr = $I2C_$arg0 + $I2C_OFF_OARx + (0x04 * ($arg1 - 1))
            printf "I2C%d SR%d:\t", $arg0, $arg1
            x/wx $baseaddr
        else
            printf "Wrong <OARx number> argument\n"
            help f1_I2Cx_OARx
        end
    else
        printf "Wrong <i2c number> argument\n"
        help f1_I2Cx_OARx
    end
end
document f1_I2Cx_OARx
Print OARx register of I2Cx
Usage: f1_I2Cx_OARx <i2c number> <OARx number>
end

define f1_I2Cx_SRx
    if $arg0 >= 1 && $arg0 <= 2
        if $arg1 >= 1 && $arg1 <= 2
            set $baseaddr = $I2C_$arg0 + $I2C_OFF_SRx + (0x04 * ($arg1 - 1))
            printf "I2C%d SR%d:\t", $arg0, $arg1
            x/wx $baseaddr
        else
            printf "Wrong <SRx number> argument\n"
            help f1_I2Cx_SRx
        end
    else
        printf "Wrong <i2c number> argument\n"
        help f1_I2Cx_SRx
    end
end
document f1_I2Cx_SRx
Print SRx register of I2Cx
Usage: f1_I2Cx_SRx <i2c number> <SRx number>
end

define f1_I2Cx_CCR
    if $arg0 >= 1 && $arg0 <= 2
        set $baseaddr = $I2C_$arg0 + $I2C_OFF_CCR
        printf "I2C%d CCR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <i2c number> argument\n"
        help f1_I2Cx_CCR
    end
end
document f1_I2Cx_CCR
Print CCR register of I2Cx
Usage: f1_I2Cx_CCR <i2c number>
end

define f1_I2Cx_TRISE
    if $arg0 >= 1 && $arg0 <= 2
        set $baseaddr = $I2C_$arg0 + $I2C_OFF_TRISE
        printf "I2C%d TRISE:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <i2c number> argument\n"
        help f1_I2Cx_TRISE
    end
end
document f1_I2Cx_TRISE
Print TRISE register of I2Cx
Usage: f1_I2Cx_TRISE <i2c number>
end

define f1_I2Cx_registers
    if $arg0 >= 1 && $arg0 <= 2
        f1_I2Cx_CRx $arg0 1
        f1_I2Cx_CRx $arg0 2
        f1_I2Cx_OARx $arg0 1
        f1_I2Cx_OARx $arg0 2
        f1_I2Cx_SRx $arg0 1
        f1_I2Cx_SRx $arg0 2
        f1_I2Cx_CCR $arg0
        f1_I2Cx_TRISE $arg0
    else
        printf "Wrong <i2c number> argument\n"
        help f1_I2Cx_registers
    end
end
document f1_I2Cx_registers
Print I2Cx registers
Usage: f1_I2Cx_registers <i2c number>
end

#SPI
set $SPI_1 = 0x40013000
set $SPI_2 = 0x40013800
set $SPI_3 = 0x40013C00


set $SPI_OFF_CR1 = 0x00
set $SPI_OFF_CR2 = 0x04
set $SPI_OFF_SR = 0x08
set $SPI_OFF_DR = 0x0C
set $SPI_OFF_CRCPR = 0x10
set $SPI_OFF_RXCRCR = 0x14
set $SPI_OFF_TXCRCR = 0x18
set $SPI_OFF_I2SCFGR = 0x1C
set $SPI_OFF_I2SPR = 0x20


define f1_SPIx_CR1
    if $arg0 >= 0 && $arg0 <= 3
        set $baseaddr = $SPI_$arg0 + $SPI_OFF_CR1
        printf "SPI%d CR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <SPI number> argument\n"
        help f1_SPIx_CR1
    end
end
document f1_SPIx_CR1
Print CR1 register of SPIx
Usage: f1_SPIx_CR1 <SPI number>
end

define f1_SPIx_CR2
    if $arg0 >= 0 && $arg0 <= 3
        set $baseaddr = $SPI_$arg0 + $SPI_OFF_CR2 
        printf "SPI%d CR2:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <SPI number> argument\n"
        help f1_SPIx_CR2
    end
end
document f1_SPIx_CR2
Print CR2 register of SPIx
Usage: f1_SPIx_CR2 <SPI number>
end

define f1_SPIx_SR
    if $arg0 >= 0 && $arg0 <= 3
        set $baseaddr = $SPI_$arg0 + $SPI_OFF_SR 
        printf "SPI%d SR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <SPI number> argument\n"
        help f1_SPIx_SR
    end
end
document f1_SPIx_SR
Print SR register of SPIx
Usage: f1_SPIx_SR <SPI number>
end

define f1_SPIx_DR
    if $arg0 >= 0 && $arg0 <= 3
        set $baseaddr = $SPI_$arg0 + $SPI_OFF_DR 
        printf "SPI%d DR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <SPI number> argument\n"
        help f1_SPIx_DR
    end
end
document f1_SPIx_DR
Print DR register of SPIx
Usage: f1_SPIx_DR <SPI number>
end

define f1_SPIx_CRCPR
    if $arg0 >= 0 && $arg0 <= 3
        set $baseaddr = $SPI_$arg0 + $SPI_OFF_CRCPR 
        printf "SPI%d CRCPR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <SPI number> argument\n"
        help f1_SPIx_CRCPR
    end
end
document f1_SPIx_CRCPR
Print CRCPR register of SPIx
Usage: f1_SPIx_CRCPR <SPI number>
end

define f1_SPIx_RXCRCR
    if $arg0 >= 0 && $arg0 <= 3
        set $baseaddr = $SPI_$arg0 + $SPI_OFF_RXCRCR 
        printf "SPI%d RXCRCR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <SPI number> argument\n"
        help f1_SPIx_RXCRCR
    end
end
document f1_SPIx_RXCRCR
Print RXCRCR register of SPIx
Usage: f1_SPIx_RXCRCR <SPI number>
end

define f1_SPIx_TXCRCR
    if $arg0 >= 0 && $arg0 <= 3
        set $baseaddr = $SPI_$arg0 + $SPI_OFF_TXCRCR 
        printf "SPI%d TXCRCR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <SPI number> argument\n"
        help f1_SPIx_TXCRCR
    end
end
document f1_SPIx_TXCRCR
Print RXCRCR register of SPIx
Usage: f1_SPIx_TXCRCR <SPI number>
end

define f1_SPIx_I2SCFGR
    if $arg0 >= 0 && $arg0 <= 3
        set $baseaddr = $SPI_$arg0 + $SPI_OFF_I2SCFGR 
        printf "SPI%d I2SCFGR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <SPI number> argument\n"
        help f1_SPIx_I2SCFGR
    end
end
document f1_SPIx_I2SCFGR
Print RXCRCR register of SPIx
Usage: f1_SPIx_I2SCFGR <SPI number>
end

define f1_SPIx_I2SPR
    if $arg0 >= 0 && $arg0 <= 3
        set $baseaddr = $SPI_$arg0 + $SPI_OFF_I2SPR 
        printf "SPI%d I2SPR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <SPI number> argument\n"
        help f1_SPIx_I2SPR
    end
end
document f1_SPIx_I2SPR
Print RXCRCR register of SPIx
Usage: f1_SPIx_I2SPR <SPI number>
end

define f1_SPIx_registers
    if $arg0 >= 1 && $arg0 <= 3
        f1_SPIx_CR1 $arg0
        f1_SPIx_CR2 $arg0
        f1_SPIx_SR $arg0
        f1_SPIx_SR $arg0
        f1_SPIx_DR $arg0
        f1_SPIx_CRCPR $arg0
        f1_SPIx_RXCRCR $arg0
        f1_SPIx_TXCRCR $arg0
        f1_SPIx_I2SCFGR $arg0
        f1_SPIx_I2SPR $arg0
    else
        printf "Wrong <i2c number> argument\n"
        help f1_SPIx_registers
    end
end
document f1_SPIx_registers
Print SPIx registers
Usage: f1_SPIx_registers <spi number>
end


#DMA
set $DMA_1 = 0x40020000
set $DMA_2 = 0x40024000

set $DMA_OFF_ISR = 0x00
set $DMA_OFF_IFCR = 0x04
set $DMA_OFF_CCR1 = 0x08
set $DMA_OFF_CNDTR1 = 0x0C
set $DMA_OFF_CPAR1 = 0x10
set $DMA_OFF_CMAR1 = 0x14


define f1_DMAx_ISR
    if $arg0 >= 0 && $arg0 <= 2
        set $baseaddr = $DMA_$arg0 + $DMA_OFF_ISR 
        printf "DMA%d ISR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <DMA number> argument\n"
        help f1_DMAx_ISR
    end
end
document f1_DMAx_ISR
Print ISR register of DMAx
Usage: f1_DMAx_ISR <DMA number>
end

define f1_DMAx_IFCR
    if $arg0 >= 0 && $arg0 <= 2
        set $baseaddr = $DMA_$arg0 + $DMA_OFF_IFCR 
        printf "DMA%d IFCR:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <DMA number> argument\n"
        help f1_DMAx_IFCR
    end
end
document f1_DMAx_IFCR
Print IFCR register of DMAx
Usage: f1_DMAx_IFCR <DMA number>
end

define f1_DMAx_CCR1
    if $arg0 >= 0 && $arg0 <= 2
        set $baseaddr = $DMA_$arg0 + $DMA_OFF_CCR1 
        printf "DMA%d CCR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <DMA number> argument\n"
        help f1_DMAx_CCR1
    end
end
document f1_DMAx_CCR1
Print CCR1 register of DMAx
Usage: f1_DMAx_CCR1 <DMA number>
end

define f1_DMAx_CNDTR1
    if $arg0 >= 0 && $arg0 <= 2
        set $baseaddr = $DMA_$arg0 + $DMA_OFF_CNDTR1 
        printf "DMA%d CNDTR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <DMA number> argument\n"
        help f1_DMAx_CNDTR1
    end
end
document f1_DMAx_CNDTR1
Print CNDTR1 register of DMAx
Usage: f1_DMAx_CNDTR1 <DMA number>
end

define f1_DMAx_CPAR1
    if $arg0 >= 0 && $arg0 <= 2
        set $baseaddr = $DMA_$arg0 + $DMA_OFF_CPAR1 
        printf "DMA%d CPAR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <DMA number> argument\n"
        help f1_DMAx_CPAR1
    end
end
document f1_DMAx_CPAR1
Print CPAR1 register of DMAx
Usage: f1_DMAx_CPAR1 <DMA number>
end

define f1_DMAx_CMAR1
    if $arg0 >= 0 && $arg0 <= 2
        set $baseaddr = $DMA_$arg0 + $DMA_OFF_CMAR1 
        printf "DMA%d CMAR1:\t", $arg0
        x/wx $baseaddr
    else
        printf "Wrong <DMA number> argument\n"
        help f1_DMAx_CMAR1
    end
end
document f1_DMAx_CMAR1
Print CMAR1 register of DMAx
Usage: f1_DMAx_CMAR1 <DMA number>
end

define f1_DMAx_registers
    if $arg0 >= 1 && $arg0 <= 2
        f1_DMAx_ISR $arg0
        f1_DMAx_IFCR $arg0
        f1_DMAx_CCR1 $arg0
        f1_DMAx_CNDTR1 $arg0
        f1_DMAx_CPAR1 $arg0
        f1_DMAx_CMAR1 $arg0
    else
        printf "Wrong <dma number> argument\n"
        help f1_DMAx_registers
    end
end
document f1_DMAx_registers
Print DMAx registers
Usage: f1_DMAx_registers <dma number>
end
