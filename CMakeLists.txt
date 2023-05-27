cmake_minimum_required(VERSION 3.16)
# set(CMAKE_TOOLCHAIN_FILE "/home/deo/Documenti/STM32/stm32-cmake/cmake/stm32_gcc.cmake")

set(EXECUTABLE_NAME "simple_blinky")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


project(stm32-blinky C ASM)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

add_compile_definitions("USE_FULL_LL_DRIVER")

# Find all device specific drivers:
find_package(CMSIS COMPONENTS STM32${STM32_FAMILY} REQUIRED)
find_package(HAL COMPONENTS STM32${STM32_FAMILY} REQUIRED)


include_directories(
    hmt_hal/common
    hmt_hal/gpio
    src
    inc
)

add_subdirectory(hmt_hal)

string(TOLOWER ${STM32_FAMILY} STM32_FAMILY_LOWER)

set(SOURCES
    hmt_hal/common/stm32${STM32_FAMILY_LOWER}xx_it.c
    src/main.c
)

add_executable("${EXECUTABLE_NAME}" "${SOURCES}" "${HEADERS}")

target_link_libraries("${EXECUTABLE_NAME}" PUBLIC
    HAL::STM32::${STM32_FAMILY}::RCC
    HAL::STM32::${STM32_FAMILY}::GPIO
    HAL::STM32::${STM32_FAMILY}::CORTEX
    CMSIS::STM32::${STM32_TYPE}
    STM32::Nano
    common_func
    gpio_manager
)

set(INCLUEDES_DIRECTORY
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/hmt_hal"
    "${PROJECT_SOURCE_DIR}/hmt_hal/gpio"  
)

# target_include_directories("${EXECUTABLE_NAME}" PUBLIC
#     "${INCLUEDES_DIRECTORY}"
# )

stm32_print_size_of_target("${EXECUTABLE_NAME}")

