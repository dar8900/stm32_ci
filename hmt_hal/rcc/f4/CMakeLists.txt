set(LIBRARY_NAME "rcc_manager")

include_directories(
    ../../../inc
    ../../common
)

string(TOLOWER ${STM32_FAMILY} STM32_FAMILY_LOWER)

add_library("${LIBRARY_NAME}"
	rcc_manager.c
)


target_link_libraries("${LIBRARY_NAME}" PUBLIC
    HAL::STM32::${STM32_FAMILY}::LL_RCC
    HAL::STM32::${STM32_FAMILY}::LL_UTILS
    HAL::STM32::${STM32_FAMILY}::RCC
    HAL::STM32::${STM32_FAMILY}::CORTEX
    CMSIS::STM32::${STM32_TYPE}
)