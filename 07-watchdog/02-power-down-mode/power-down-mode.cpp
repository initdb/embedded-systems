#include "Arduino.h"
#include <avr/sleep.h>

#define BOUNCING_THRESHOLD 300

volatile float current_time = 0.0;

void setup() {
    Serial1.begin(9600);

    //configure sleep mode -> power down
    SMCR |= (1<<SM1);
    // enable sleep
    SMCR |= (1<<SE);

    // digital pin 21 config
    DDRD &= ~(1 << DDD0); // configure pin PD0 as input
    PORTD |= (1 << PORTD0); // pull up (manual p68)

    // configure and enable external interrupt on pin PD0
    // configure as active high;
    EICRA |= (1 << ISC00) | (1 << ISC01);
    // configure pin 21 as interrupt
    EIMSK |= (1 << INT0);
}

void loop() {
    Serial1.println("system going to sleep...zzz");
    delay(2000);
    sleep_mode();
    Serial1.println("awake :)");
    delay(2000);
}

ISR (INT0_vect) {
    // empty
}