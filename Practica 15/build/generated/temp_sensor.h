
// C:/Users/medel/Documents/Microcontroladores/Practica 15/build/generated/temp_sensor.h generated from C:/Users/medel/Documents/Microcontroladores/Practica 15/temp_sensor.gatt for BTstack
// it needs to be regenerated when the .gatt file is updated. 

// To generate C:/Users/medel/Documents/Microcontroladores/Practica 15/build/generated/temp_sensor.h:
// C:/Program Files/Raspberry Pi/Pico SDK v1.5.1/pico-sdk/lib/btstack/tool/compile_gatt.py C:/Users/medel/Documents/Microcontroladores/Practica 15/temp_sensor.gatt C:/Users/medel/Documents/Microcontroladores/Practica 15/build/generated/temp_sensor.h

// att db format version 1

// binary attribute representation:
// - size in bytes (16), flags(16), handle (16), uuid (16/128), value(...)

#include <stdint.h>

// Reference: https://en.cppreference.com/w/cpp/feature_test
#if __cplusplus >= 200704L
constexpr
#endif
const uint8_t profile_data[] =
{
    // ATT DB Version
    1,

    // 0x0001 PRIMARY_SERVICE-GAP_SERVICE
    0x0a, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x28, 0x00, 0x18, 
    // 0x0002 CHARACTERISTIC-GAP_DEVICE_NAME - READ
    0x0d, 0x00, 0x02, 0x00, 0x02, 0x00, 0x03, 0x28, 0x02, 0x03, 0x00, 0x00, 0x2a, 
    // 0x0003 VALUE CHARACTERISTIC-GAP_DEVICE_NAME - READ -'picov_temp'
    // READ_ANYBODY
    0x12, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x2a, 0x70, 0x69, 0x63, 0x6f, 0x76, 0x5f, 0x74, 0x65, 0x6d, 0x70, 
    // 0x0004 PRIMARY_SERVICE-GATT_SERVICE
    0x0a, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0x28, 0x01, 0x18, 
    // 0x0005 CHARACTERISTIC-GATT_DATABASE_HASH - READ
    0x0d, 0x00, 0x02, 0x00, 0x05, 0x00, 0x03, 0x28, 0x02, 0x06, 0x00, 0x2a, 0x2b, 
    // 0x0006 VALUE CHARACTERISTIC-GATT_DATABASE_HASH - READ -''
    // READ_ANYBODY
    0x18, 0x00, 0x02, 0x00, 0x06, 0x00, 0x2a, 0x2b, 0x1b, 0x6d, 0x9b, 0x96, 0x2f, 0xae, 0xe0, 0xe5, 0xc7, 0x08, 0x09, 0x42, 0xdf, 0x92, 0x46, 0x38, 
    // 0x0007 PRIMARY_SERVICE-org.bluetooth.service.environmental_sensing
    0x0a, 0x00, 0x02, 0x00, 0x07, 0x00, 0x00, 0x28, 0x1a, 0x18, 
    // 0x0008 CHARACTERISTIC-org.bluetooth.characteristic.temperature - 
    0x0d, 0x00, 0x02, 0x00, 0x08, 0x00, 0x03, 0x28, 0x00, 0x09, 0x00, 0x6e, 0x2a, 
    // 0x0009 VALUE CHARACTERISTIC-org.bluetooth.characteristic.temperature -  -''
    // 
    0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x6e, 0x2a, 
    // END
    0x00, 0x00, 
}; // total size 71 bytes 


//
// list service handle ranges
//
#define ATT_SERVICE_GAP_SERVICE_START_HANDLE 0x0001
#define ATT_SERVICE_GAP_SERVICE_END_HANDLE 0x0003
#define ATT_SERVICE_GAP_SERVICE_01_START_HANDLE 0x0001
#define ATT_SERVICE_GAP_SERVICE_01_END_HANDLE 0x0003
#define ATT_SERVICE_GATT_SERVICE_START_HANDLE 0x0004
#define ATT_SERVICE_GATT_SERVICE_END_HANDLE 0x0006
#define ATT_SERVICE_GATT_SERVICE_01_START_HANDLE 0x0004
#define ATT_SERVICE_GATT_SERVICE_01_END_HANDLE 0x0006
#define ATT_SERVICE_org.bluetooth.service.environmental_sensing_START_HANDLE 0x0007
#define ATT_SERVICE_org.bluetooth.service.environmental_sensing_END_HANDLE 0x0009
#define ATT_SERVICE_org.bluetooth.service.environmental_sensing_01_START_HANDLE 0x0007
#define ATT_SERVICE_org.bluetooth.service.environmental_sensing_01_END_HANDLE 0x0009

//
// list mapping between characteristics and handles
//
#define ATT_CHARACTERISTIC_GAP_DEVICE_NAME_01_VALUE_HANDLE 0x0003
#define ATT_CHARACTERISTIC_GATT_DATABASE_HASH_01_VALUE_HANDLE 0x0006
#define ATT_CHARACTERISTIC_org.bluetooth.characteristic.temperature_01_VALUE_HANDLE 0x0009
