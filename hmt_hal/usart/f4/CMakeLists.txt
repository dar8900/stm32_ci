
set(LIBRARY_NAME "usart_manager_${STM32_FAMILY}")

include_directories(
    ../../../inc
    ../../common
	../../rcc
)

add_library("${LIBRARY_NAME}" 
	usart_manager.c
)

target_link_libraries("${LIBRARY_NAME}" PUBLIC
    HAL::STM32::${STM32_FAMILY}::LL_USART
    HAL::STM32::${STM32_FAMILY}::USART
    CMSIS::STM32::${STM32_TYPE}
	rcc_manager
)