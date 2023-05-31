cmake_minimum_required(VERSION 3.16)
# set(CMAKE_TOOLCHAIN_FILE "/home/deo/Documenti/STM32/stm32-cmake/cmake/stm32_gcc.cmake")

set(EXECUTABLE_NAME "simple_blinky")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(stm32-blinky C ASM)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

add_compile_definitions("USE_FULL_LL_DRIVER")

string(TOLOWER ${STM32_FAMILY} STM32_FAMILY_LOWER)

# Find all device specific drivers:
find_package(CMSIS COMPONENTS STM32${STM32_FAMILY} REQUIRED)
find_package(HAL COMPONENTS STM32${STM32_FAMILY} REQUIRED)


include_directories(
    hmt_hal/common
    hmt_hal/rcc/${STM32_FAMILY_LOWER}
    hmt_hal/gpio
    src
    inc
)

add_subdirectory(hmt_hal)

set(SOURCES
    src/stm32${STM32_FAMILY_LOWER}xx_it.c
    inc/stm32${STM32_FAMILY_LOWER}xx_it.h
    inc/stm32${STM32_FAMILY_LOWER}xx_hal_conf.h
    src/main.c
)

add_executable("${EXECUTABLE_NAME}" "${SOURCES}")

target_link_libraries("${EXECUTABLE_NAME}" PUBLIC
    STM32::Nano
    common_func
    rcc_manager
    gpio_manager
)

set(INCLUEDES_DIRECTORY
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/hmt_hal"
    "${PROJECT_SOURCE_DIR}/hmt_hal/gpio"  
)


stm32_print_size_of_target("${EXECUTABLE_NAME}")

stm32_generate_hex_file("${EXECUTABLE_NAME}")

