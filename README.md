# RaspberryPi_pico_distance_measure
This project measures distance using an ultrasonic sensor with a Raspberry Pi Pico. The sensor sends a sound wave and calculates the time taken for it to bounce back, using the Trig and Echo pins. A C program computes the distance in centimeters, which is displayed via USB output in a software called putty.

Features:
  Ultrasonic Distance Measurement: The project uses an HC-SR04 ultrasonic sensor to measure distances by calculating the time taken for sound waves to reflect off an object.
  Accurate Timing: The program utilizes the Pico’s absolute_time API to capture the timing of the echo signal, ensuring accurate distance calculation.
  Continuous Measurement: The distance is measured every 500 milliseconds and output to the console using the USB serial connection.
Code Breakdown:
  GPIO Setup: The Trig pin is configured as an output, and the Echo pin is set as an input.
  Distance Calculation: The measure_distance() function triggers the sensor, waits for the echo, and calculates the distance using the speed of sound (343 meters per second).
  CMake Configuration: The CMakeLists.txt file includes the necessary Pico SDK setup and links the standard libraries for the project.
