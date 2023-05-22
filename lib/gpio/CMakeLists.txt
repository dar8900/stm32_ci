
include_directories(
	../../inc
)

add_library(toggle STATIC
	toggle.c
)

target_link_libraries(toggle PUBLIC
    HAL::STM32::${STM32_FAMILY}::GPIO
    CMSIS::STM32::${STM32_TYPE}
)