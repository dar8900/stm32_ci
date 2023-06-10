
set(LIBRARY_NAME "common_func")

string(TOLOWER ${STM32_FAMILY} STM32_FAMILY_LOWER)

include_directories(
    ../../inc
    ../rcc
    ../usart/${STM32_FAMILY_LOWER}
)



add_library("${LIBRARY_NAME}" 
    hmt_common.c
    hmt_simple_timer.c
    ../rcc/rcc_common.c
    ../usart/usart_common.c
)

target_link_libraries("${LIBRARY_NAME}" PUBLIC
    HAL::STM32::${STM32_FAMILY}::GPIO
    CMSIS::STM32::${STM32_TYPE}
    usart_manager_${STM32_FAMILY}
)