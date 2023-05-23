cmake_minimum_required(VERSION 3.16)
# set(CMAKE_TOOLCHAIN_FILE "/home/deo/Documenti/STM32/stm32-cmake/cmake/stm32_gcc.cmake")

set(EXECUTABLE_NAME "simple_blinky")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(stm32-blinky C ASM)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

set(HAL_COMP_LIST RCC GPIO CORTEX)
set(CMSIS_COMP_LIST "")

# set(STM32_CUBE_F1_PATH "/home/deo/Documenti/STM32/STM32CubeF1")
list(APPEND CMSIS_COMP_LIST STM32F1)
list(APPEND HAL_COMP_LIST STM32F1)


find_package(CMSIS COMPONENTS "${CMSIS_COMP_LIST}" REQUIRED)
find_package(HAL COMPONENTS "${HAL_COMP_LIST}" REQUIRED)

# Find all device specific drivers:
#find_package(HAL COMPONENTS STM32L0 STM32F1 STM32F4 REQUIRED)
# Find drivers for all families:
#find_package(HAL COMPONENTS RCC GPIO CORTEX REQUIRED)
# Find LL driver:
# find_package(HAL COMPONENTS LL_GPIO REQUIRED)
# Find everything:
# find_package(HAL REQUIRED)

include_directories(
    src
    inc
)

add_subdirectory(hmt_hal)


set(SOURCES
    src/stm32f1xx_it.c
    src/main.c
)

add_executable("${EXECUTABLE_NAME}" "${SOURCES}" "${HEADERS}")

target_link_libraries("${EXECUTABLE_NAME}" PUBLIC
    HAL::STM32::${STM32_FAMILY}::RCC
    HAL::STM32::${STM32_FAMILY}::GPIO
    HAL::STM32::${STM32_FAMILY}::CORTEX
    CMSIS::STM32::${STM32_TYPE}
    STM32::Nano
    gpio_manager
)

set(INCLUEDES_DIRECTORY
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/hmt_hal"
    "${PROJECT_SOURCE_DIR}/hmt_hal/gpio"  
)

target_include_directories("${EXECUTABLE_NAME}" PUBLIC
    "${INCLUEDES_DIRECTORY}"
)

stm32_print_size_of_target("${EXECUTABLE_NAME}")

