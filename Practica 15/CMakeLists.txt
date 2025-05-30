cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.5.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version
    1.5.0 (or later) required. Your version is ${
        PICO_SDK_VERSION_STRING}")
endif()

project(Practica 15 C CXX ASM)      #Tu carpeta de proyecto no lleva guion
set(PICO_BOARD pico_w)                      #La placa es pico_w no pico-w
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Standalone example that reads from the on board
# temperature sensor and sends notifications via BLE
# Flashes slowly each second to show it’s running
add_executable(picow_ble_temp_sensor
    server.c server_common.c
)

target_link_libraries(picow_ble_temp_sensor
    pico_stdlib
    pico_btstack_ble
    pico_btstack_cyw43
    pico_cyw43_arch_none
    hardware_adc
)

target_include_directories(picow_ble_temp_sensor PRIVATE
    ${CMAKE_CURRENT_LIST_DIR} # For btstack config
)

pico_btstack_make_gatt_header(picow_ble_temp_sensor
    PRIVATE "${CMAKE_CURRENT_LIST_DIR}/temp_sensor.gatt"
)

pico_add_extra_outputs(picow_ble_temp_sensor)

# Flashes twice quickly each second when connected to
# another device and reading it's temperature
add_executable(picow_ble_temp_reader
    client.c
)

target_link_libraries(picow_ble_temp_reader
    pico_stdlib
    pico_btstack_ble
    pico_btstack_cyw43
    pico_cyw43_arch_none
    hardware_adc
)

pico_enable_stdio_usb(picow_ble_temp_reader 1)
pico_enable_stdio_uart(picow_ble_temp_reader 0)

target_include_directories(picow_ble_temp_reader PRIVATE
    ${CMAKE_CURRENT_LIST_DIR} # For btstack config
)

target_compile_definitions(picow_ble_temp_reader PRIVATE
    RUNNING_AS_CLIENT=1
)

pico_add_extra_outputs(picow_ble_temp_reader)
