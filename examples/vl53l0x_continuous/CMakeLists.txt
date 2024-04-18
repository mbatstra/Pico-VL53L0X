add_executable(VL53L0X_continuous
        vl53l0x_continuous.cpp
        )


target_link_libraries(VL53L0X_continuous pico_stdlib hardware_i2c)

target_include_directories(VL53L0X_continuous PRIVATE ../../src)
target_link_libraries(VL53L0X_continuous VL53L0X_API)

pico_add_extra_outputs(VL53L0X_continuous)

pico_enable_stdio_usb(VL53L0X_continuous 1)
pico_enable_stdio_uart(VL53L0X_continuous 0)
