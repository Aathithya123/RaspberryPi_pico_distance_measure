cmake_minimum_required(VERSION 3.12)

# Import the Pico SDK
include(pico_sdk_import.cmake)

# Define the project name
project(pico-ultrasonic)

# Initialize the Pico SDK
pico_sdk_init()

# Add the executable target with the source file
add_executable(ultrasonic_sensor
    ultrasonic_sensor.c
)

# Link the necessary libraries (Pico standard library)
target_link_libraries(ultrasonic_sensor
    pico_stdlib
)

# Enable USB output (for serial communication)
pico_enable_stdio_usb(ultrasonic_sensor 1)

# Disable UART output (optional)
pico_enable_stdio_uart(ultrasonic_sensor 0)

# Generate the necessary output formats (UF2, etc.)
pico_add_extra_outputs(ultrasonic_sensor)
