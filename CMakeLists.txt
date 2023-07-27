cmake_minimum_required(VERSION 3.16)
# set(CMAKE_TOOLCHAIN_FILE "/home/deo/Documenti/STM32/stm32-cmake/cmake/stm32_gcc.cmake")

function(check_folder_exists FOLDER_PATH)
    file(GLOB FOLDER_CONTENTS ${FOLDER_PATH}/*)
    if(FOLDER_CONTENTS)
        set(FOLDER_EXISTS TRUE PARENT_SCOPE)
    else()
        set(FOLDER_EXISTS FALSE PARENT_SCOPE)
    endif()
endfunction()


function(add_custom_linker CUSTOM_LD_FILE)
    set(OUTPUT_LD_FILE "${CMAKE_CURRENT_BINARY_DIR}/${CUSTOM_LD_FILE}")
    add_custom_command(OUTPUT "${OUTPUT_LD_FILE}"
        COMMAND ${CMAKE_COMMAND}
            -DFLASH_ORIGIN="${FLASH_ORIGIN}"
            -DRAM_ORIGIN="${RAM_ORIGIN}"
            -DCCRAM_ORIGIN="${CCRAM_ORIGIN}"
            -DRAM_SHARE_ORIGIN="${RAM_SHARE_ORIGIN}"
            -DFLASH_SIZE="${FLASH_SIZE}"
            -DRAM_SIZE="${RAM_SIZE}"
            -DCCRAM_SIZE="${CCRAM_SIZE}"
            -DRAM_SHARE_SIZE="${RAM_SHARE_SIZE}"
            -DSTACK_SIZE="${STACK_SIZE}"
            -DHEAP_SIZE="${HEAP_SIZE}"
            -DLINKER_SCRIPT="${OUTPUT_LD_FILE}"
            -P "${STM32_CMAKE_DIR}/stm32/linker_ld.cmake"
    )
    add_custom_target(CUSTOM_LD_BL DEPENDS "${OUTPUT_LD_FILE}")
    add_dependencies(CMSIS::STM32::${STM32_TYPE} CUSTOM_LD_BL)
    stm32_add_linker_script(${PROJECT_NAME} PRIVATE "${OUTPUT_LD_FILE}")
endfunction()


find_package (Git)
if (NOT GIT_FOUND)
    message(FATAL_ERROR "Git repo not found")
endif (NOT GIT_FOUND)

execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD 
    OUTPUT_VARIABLE BRANCH_NAME
)

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

check_folder_exists("./hmt_hal")
if(NOT ${FOLDER_EXISTS})
    message(FATAL_ERROR "La cartella \"hmtl_hal\" non esiste.")
endif()

check_folder_exists("./boards_stm32")
if(NOT ${FOLDER_EXISTS})
    message(FATAL_ERROR "La cartella \"boards_stm32\" non esiste.")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


###############################      START PROJECT CMAKE      ###############################

set(PROJECT_NAME "${PROJECT_PREFIX}_${BRANCH_NAME}")

project(${PROJECT_NAME} C ASM)

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

add_compile_definitions("USE_FULL_LL_DRIVER")

# add_compile_definitions("USE_DYNAMIC_MEM")

string(TOLOWER ${STM32_FAMILY} STM32_FAMILY_LOWER)

# Find all device specific drivers:
find_package(CMSIS COMPONENTS STM32${STM32_FAMILY} REQUIRED)
find_package(HAL COMPONENTS STM32${STM32_FAMILY} REQUIRED)

stm32_get_chip_info(STM32${STM32_DEVICE} TYPE STM32_TYPE)

set(INCLUDE_FILES 
    ${CMAKE_SOURCE_DIR}/hmt_hal/common
    ${CMAKE_SOURCE_DIR}/hmt_hal/rcc
    ${CMAKE_SOURCE_DIR}/hmt_hal/rcc/${STM32_FAMILY_LOWER}
    ${CMAKE_SOURCE_DIR}/hmt_hal/gpio
    ${CMAKE_SOURCE_DIR}/hmt_hal/gpio/${STM32_FAMILY_LOWER}
    ${CMAKE_SOURCE_DIR}/hmt_hal/usart
    ${CMAKE_SOURCE_DIR}/hmt_hal/usart/${STM32_FAMILY_LOWER}
    ${CMAKE_SOURCE_DIR}/hmt_hal/i2c
    ${CMAKE_SOURCE_DIR}/hmt_hal/i2c/${STM32_FAMILY_LOWER}    
    ${CMAKE_SOURCE_DIR}/hmt_hal/spi
    ${CMAKE_SOURCE_DIR}/hmt_hal/spi/${STM32_FAMILY_LOWER}
    ${CMAKE_SOURCE_DIR}/hmt_hal/adc
    ${CMAKE_SOURCE_DIR}/hmt_hal/adc/${STM32_FAMILY_LOWER}
    ${CMAKE_SOURCE_DIR}/hmt_hal/pwm
    ${CMAKE_SOURCE_DIR}/hmt_hal/pwm/${STM32_FAMILY_LOWER}
    ${CMAKE_SOURCE_DIR}/hmt_hal/input_capture
    ${CMAKE_SOURCE_DIR}/hmt_hal/input_capture/${STM32_FAMILY_LOWER}
    ${CMAKE_SOURCE_DIR}/hmt_hal/flash
    ${CMAKE_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/boards_stm32/${PROJECT_BOARD}
)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/stm32${STM32_FAMILY_LOWER}xx_it.c
    ${CMAKE_SOURCE_DIR}/src/adc_test.c
    ${CMAKE_SOURCE_DIR}/src/i2c_test.c
    ${CMAKE_SOURCE_DIR}/src/interrupt_gpio_test.c
    ${CMAKE_SOURCE_DIR}/src/spi_test.c
    ${CMAKE_SOURCE_DIR}/src/timer_test.c
    ${CMAKE_SOURCE_DIR}/src/usart_test.c
    ${CMAKE_SOURCE_DIR}/src/flash_test.c
    ${CMAKE_SOURCE_DIR}/src/main.c
)

set(PROJECT_TARGET_LIB 
    CMSIS::STM32::${STM32_TYPE}
    STM32::Nano
    common_func
    rcc_manager_${STM32_FAMILY}
    gpio_manager_${STM32_FAMILY}
    usart_manager_${STM32_FAMILY}
    i2c_manager_${STM32_FAMILY}
    spi_manager_${STM32_FAMILY}
    adc_manager_${STM32_FAMILY}
    pwm_manager_${STM32_FAMILY} 
    ic_manager_${STM32_FAMILY}
    flash_manager_${STM32_FAMILY}
)

include_directories(
    "${INCLUDE_FILES}"
)


add_subdirectory(${CMAKE_SOURCE_DIR}/hmt_hal)

add_executable("${PROJECT_NAME}" "${SOURCES}")

# if you want to use malloc or dynamic memory allocation
# then switch to STM32::Nano -> STM32::NoSys

target_link_libraries("${PROJECT_NAME}" 
    "${PROJECT_TARGET_LIB}"
)


if (EXISTS "${CMAKE_SOURCE_DIR}/boards_stm32/${PROJECT_BOARD}/Ld_variables.cmake")
    include("${CMAKE_SOURCE_DIR}/boards_stm32/${PROJECT_BOARD}/Ld_variables.cmake")
    add_custom_linker(${PROJECT_NAME}_FLASH.ld)
else()
    message(WARNING "Using default ld file")
endif()

stm32_print_size_of_target("${PROJECT_NAME}")

stm32_generate_hex_file("${PROJECT_NAME}")

