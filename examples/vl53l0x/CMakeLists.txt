add_executable(VL53L0X
        vl53l0x.cpp
        )


target_link_libraries(VL53L0X pico_stdlib hardware_i2c)

target_include_directories(VL53L0X PRIVATE ../../src)
target_link_libraries(VL53L0X VL53L0X_API)

pico_add_extra_outputs(VL53L0X)

pico_enable_stdio_usb(VL53L0X 1)
pico_enable_stdio_uart(VL53L0X 0)
