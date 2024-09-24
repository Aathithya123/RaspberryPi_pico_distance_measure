#include <stdio.h>
#include "pico/stdlib.h"

#define TRIG_PIN 4  // GPIO pin connected to the Trig pin of the ultrasonic sensor
#define ECHO_PIN 5  // GPIO pin connected to the Echo pin of the ultrasonic sensor

// Function to measure distance using the ultrasonic sensor
float measure_distance(void) {
    // Trigger the ultrasonic sensor
    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);

    // Wait for the echo response
    while (gpio_get(ECHO_PIN) == 0);  // Wait for the echo to go high
    absolute_time_t start_time = get_absolute_time();  // Start time of echo
    
    while (gpio_get(ECHO_PIN) == 1);  // Wait for the echo to go low
    absolute_time_t end_time = get_absolute_time();  // End time of echo

    // Calculate the duration in microseconds
    int64_t duration = absolute_time_diff_us(start_time, end_time);

    // Speed of sound is ~343 meters/second (or 0.0343 cm/us)
    // Distance = (duration / 2) * speed of sound
    float distance_cm = (duration / 2.0) * 0.0343;

    return distance_cm;
}

int main(void) {
    // Initialize stdio and GPIO
    stdio_init_all();
    gpio_init(TRIG_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_init(ECHO_PIN);
    gpio_set_dir(ECHO_PIN, GPIO_IN);

    // Main loop to measure distance
    while (1) {
        float distance = measure_distance();
        printf("Distance: %.2f cm\n", distance);
        sleep_ms(500);
    }
}
