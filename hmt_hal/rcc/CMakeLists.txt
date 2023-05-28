set(LIBRARY_NAME "rcc_manager")

include_directories(
    ../../inc
    ../common
)


add_library("${LIBRARY_NAME}" 
	rcc_manager.c
)


target_link_libraries("${LIBRARY_NAME}" PUBLIC
    HAL::STM32::${STM32_FAMILY}::RCC
    HAL::STM32::${STM32_FAMILY}::CORTEX
    CMSIS::STM32::${STM32_TYPE}
)