
set(LIBRARY_NAME "gpio_manager")

include_directories(
    ../../inc

)

add_library("${LIBRARY_NAME}" 
	gpio_defs.c
    gpio_manager.c
)

target_link_libraries("${LIBRARY_NAME}" PUBLIC
    HAL::STM32::${STM32_FAMILY}::LL_GPIO
    HAL::STM32::${STM32_FAMILY}::GPIO
    CMSIS::STM32::${STM32_TYPE}
)