
set(LIBRARY_NAME "spi_manager_${STM32_FAMILY}")

include_directories(
    ../../inc
    ../../common
	../rcc
)

add_library("${LIBRARY_NAME}"
    ../spi_common.c
    spi_manager.c
)

target_link_libraries("${LIBRARY_NAME}" PUBLIC
    HAL::STM32::${STM32_FAMILY}::LL_SPI
    HAL::STM32::${STM32_FAMILY}::SPI
    CMSIS::STM32::${STM32_TYPE}
	rcc_manager_${STM32_FAMILY}
)