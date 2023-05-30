
set(LIBRARY_NAME "common_func")

include_directories(
    ../../inc
)

string(TOLOWER ${STM32_FAMILY} STM32_FAMILY_LOWER)

add_library("${LIBRARY_NAME}" 
    hmt_common.c
    hmt_simple_timer.c
)

target_link_libraries("${LIBRARY_NAME}" PUBLIC
    HAL::STM32::${STM32_FAMILY}::GPIO
    CMSIS::STM32::${STM32_TYPE}
)