/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f1xx_it.c
 * @brief   Interrupt Service Routines.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "hmt_common.h"
#include "rcc_common.h"

#ifdef USE_USART
#include "usart_common.h"
#endif

#ifdef USE_I2C
#include "i2c_common.h"
#endif

#ifdef USE_SPI
#include "spi_common.h"
#endif

#ifdef USE_ADC
#include "adc_common.h"
#endif

#ifdef USE_PWM
#include "pwm_manager.h"
#endif

#ifdef USE_INPUT_CAPTURE
#include "ic_manager.h"
#endif

#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
 * @brief This function handles Non maskable interrupt.
 */
void NMI_Handler(void)
{
    /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

    /* USER CODE END NonMaskableInt_IRQn 0 */
    /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
    while (1)
    {
    }
    /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
 * @brief This function handles Hard fault interrupt.
 */
void HardFault_Handler(void)
{
    /* USER CODE BEGIN HardFault_IRQn 0 */

    /* USER CODE END HardFault_IRQn 0 */
    while (1)
    {
        /* USER CODE BEGIN W1_HardFault_IRQn 0 */
        /* USER CODE END W1_HardFault_IRQn 0 */
    }
}

/**
 * @brief This function handles Memory management fault.
 */
void MemManage_Handler(void)
{
    /* USER CODE BEGIN MemoryManagement_IRQn 0 */

    /* USER CODE END MemoryManagement_IRQn 0 */
    while (1)
    {
        /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
        /* USER CODE END W1_MemoryManagement_IRQn 0 */
    }
}

/**
 * @brief This function handles Prefetch fault, memory access fault.
 */
void BusFault_Handler(void)
{
    /* USER CODE BEGIN BusFault_IRQn 0 */

    /* USER CODE END BusFault_IRQn 0 */
    while (1)
    {
        /* USER CODE BEGIN W1_BusFault_IRQn 0 */
        /* USER CODE END W1_BusFault_IRQn 0 */
    }
}

/**
 * @brief This function handles Undefined instruction or illegal state.
 */
void UsageFault_Handler(void)
{
    /* USER CODE BEGIN UsageFault_IRQn 0 */

    /* USER CODE END UsageFault_IRQn 0 */
    while (1)
    {
        /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
        /* USER CODE END W1_UsageFault_IRQn 0 */
    }
}

/**
 * @brief This function handles System service call via SWI instruction.
 */
void SVC_Handler(void)
{
    /* USER CODE BEGIN SVCall_IRQn 0 */

    /* USER CODE END SVCall_IRQn 0 */
    /* USER CODE BEGIN SVCall_IRQn 1 */

    /* USER CODE END SVCall_IRQn 1 */
}

/**
 * @brief This function handles Debug monitor.
 */
void DebugMon_Handler(void)
{
    /* USER CODE BEGIN DebugMonitor_IRQn 0 */

    /* USER CODE END DebugMonitor_IRQn 0 */
    /* USER CODE BEGIN DebugMonitor_IRQn 1 */

    /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
 * @brief This function handles Pendable request for system service.
 */
void PendSV_Handler(void)
{
    /* USER CODE BEGIN PendSV_IRQn 0 */

    /* USER CODE END PendSV_IRQn 0 */
    /* USER CODE BEGIN PendSV_IRQn 1 */

    /* USER CODE END PendSV_IRQn 1 */
}

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void)
{
    hmt_RccSysTickHandler();
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

#ifdef USE_USART

#ifdef USART1
void USART1_IRQHandler(void)
{
    hmt_Usart_IT_Handler(USART1);
}
#endif

#ifdef USART2
void USART2_IRQHandler(void)
{
    hmt_Usart_IT_Handler(USART2);
}
#endif

#ifdef USART3
void USART3_IRQHandler(void)
{
    hmt_Usart_IT_Handler(USART3);
}
#endif

#endif /* USE_USART */

#ifdef USE_I2C

#ifdef I2C1
void I2C1_EV_IRQHandler(void)
{
    hmt_I2C_IT_Handler(I2C1);
}

void I2C1_ER_IRQHandler(void)
{
    hmt_I2C_ComError_Handler(I2C1);
}
#endif

#ifdef I2C2
void I2C2_EV_IRQHandler(void)
{
    hmt_I2C_IT_Handler(I2C2);
}

void I2C2_ER_IRQHandler(void)
{
    hmt_I2C_ComError_Handler(I2C2);
}
#endif

#ifdef I2C3
void I2C3_EV_IRQHandler(void)
{
    hmt_I2C_IT_Handler(I2C3);
}

void I2C3_ER_IRQHandler(void)
{
    hmt_I2C_ComError_Handler(I2C3);
}
#endif

#endif /* USE_I2C */

#ifdef USE_SPI

#ifdef SPI1
void SPI1_IRQHandler()
{
    hmt_SPI_It_Handler(SPI1);
}
#endif

#ifdef SPI2
void SPI2_IRQHandler()
{
    hmt_SPI_It_Handler(SPI2);
}
#endif

#endif /* USE_SPI */

#ifdef USE_ADC

#ifdef DMA1
void DMA1_Channel1_IRQHandler(void)
{
    hmt_AdcIt_Handler(DMA1);
}
#endif

#endif /* USE_ADC */

#if defined(USE_PWM) || defined(USE_INPUT_CAPTURE)

void TIM2_IRQHandler(void)
{
    hmt_PWM_IT_Handler(TIM2);
    hmt_IC_IT_Handle(TIM2);
}

void TIM3_IRQHandler(void)
{
    hmt_PWM_IT_Handler(TIM3);
    hmt_IC_IT_Handle(TIM3);  
}

void TIM4_IRQHandler(void)
{
    hmt_PWM_IT_Handler(TIM4);
    hmt_IC_IT_Handle(TIM4);
}

#endif

#ifdef USE_EXTI
void EXTI0_IRQHandler()
{
    hmt_EXTI_Handler();
}
void EXTI1_IRQHandler()
{
    hmt_EXTI_Handler();
}
void EXTI2_IRQHandler()
{
    hmt_EXTI_Handler();
}
void EXTI3_IRQHandler()
{
    hmt_EXTI_Handler();
}
void EXTI4_IRQHandler()
{
    hmt_EXTI_Handler();
}
void EXTI9_5_IRQHandler()
{
    hmt_EXTI_Handler();
}
void EXTI15_10_IRQHandler()
{
    hmt_EXTI_Handler();
}
#endif