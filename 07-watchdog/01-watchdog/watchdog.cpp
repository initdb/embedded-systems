#include "Arduino.h"
#include <avr/wdt.h>

void setup() {
    Serial1.begin(9600);
    Serial1.println("System restart");

    // TODO: set watchdog interval to 4s and start watchdog timer

    DDRD &= ~(1 << DDD0); // configure pin PD0 as input
    PORTD |= (1 << PORTD0); // pull up (manual p68)

    // TODO: configure and enable external interrupt on pin PD0
}

void loop() {} // empty

ISR (INT0_vect) {
    // TODO: reset watchdog within ISR, “debounce” button (Taster entprellen)
    Serial1.println("ResetWDT");
}