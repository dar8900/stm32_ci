cmake_minimum_required(VERSION 3.16)
# set(CMAKE_TOOLCHAIN_FILE "/home/deo/Documenti/STM32/stm32-cmake/cmake/stm32_gcc.cmake")

find_package (Git)
if (NOT GIT_FOUND)
    message(FATAL_ERROR "Git repo not found")
endif (NOT GIT_FOUND)

execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD 
    OUTPUT_VARIABLE BRANCH_NAME
)

string(STRIP ${BRANCH_NAME} BRANCH_NAME)

message("Actual branch is ${BRANCH_NAME}")


set(EXECUTABLE_NAME "stm32_ci_${BRANCH_NAME}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(stm32-ci-${BRANCH_NAME} C ASM)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

add_compile_definitions("USE_FULL_LL_DRIVER")

# add_compile_definitions("USE_DYNAMIC_MEM")

string(TOLOWER ${STM32_FAMILY} STM32_FAMILY_LOWER)

# Find all device specific drivers:
find_package(CMSIS COMPONENTS STM32${STM32_FAMILY} REQUIRED)
find_package(HAL COMPONENTS STM32${STM32_FAMILY} REQUIRED)


include_directories(
    hmt_hal/common
    hmt_hal/rcc
    hmt_hal/rcc/${STM32_FAMILY_LOWER}
    hmt_hal/gpio
    hmt_hal/gpio/${STM32_FAMILY_LOWER}
    hmt_hal/usart
    hmt_hal/usart/${STM32_FAMILY_LOWER}
    hmt_hal/i2c
    hmt_hal/i2c/${STM32_FAMILY_LOWER}    
    hmt_hal/spi
    hmt_hal/spi/${STM32_FAMILY_LOWER}
    hmt_hal/adc
    hmt_hal/adc/${STM32_FAMILY_LOWER}
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

# if you want to use malloc or dynamic memory allocation
# then switch to STM32::Nano -> STM32::NoSys

target_link_libraries("${EXECUTABLE_NAME}" PUBLIC
    STM32::Nano
    common_func
    rcc_manager_${STM32_FAMILY}
    gpio_manager_${STM32_FAMILY}
    usart_manager_${STM32_FAMILY}
    i2c_manager_${STM32_FAMILY}
    spi_manager_${STM32_FAMILY}
    adc_manager_${STM32_FAMILY}
)



stm32_print_size_of_target("${EXECUTABLE_NAME}")

stm32_generate_hex_file("${EXECUTABLE_NAME}")

