#include <stdio.h>
#include "pico/stdlib.h"

#define TRIG_PIN 4  // GPIO pin connected to the Trig pin of the ultrasonic sensor
#define ECHO_PIN 5  // GPIO pin connected to the Echo pin of the ultrasonic sensor
float measure_distance(void) {
    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);
    while (gpio_get(ECHO_PIN) == 0);  
    absolute_time_t start_time = get_absolute_time();  
    while (gpio_get(ECHO_PIN) == 1);  /
    absolute_time_t end_time = get_absolute_time(); 
    int64_t duration = absolute_time_diff_us(start_time, end_time);
    float distance_cm = (duration / 2.0) * 0.0343;
    return distance_cm;
}

int main(void) {
    stdio_init_all();
    gpio_init(TRIG_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_init(ECHO_PIN);
    gpio_set_dir(ECHO_PIN, GPIO_IN);
    while (1) {
        float distance = measure_distance();
        printf("Distance: %.2f cm\n", distance);
        sleep_ms(500);
    }
}
