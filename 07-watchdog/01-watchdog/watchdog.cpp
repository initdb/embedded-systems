#include "Arduino.h"
#include <avr/wdt.h>

#define BOUNCING_THRESHOLD 300

volatile float current_time = 0.0;

void WDT_Prescaler_Change(void)
{
    cli();
    wdt_reset();
    /* Start timed equence */
    WDTCSR |= (1<<WDCE) | (1<<WDE);
    /* Set new prescaler(time-out) value = 64K cycles (~4 s) */
    WDTCSR = (1<<WDE) | (1<<WDP3);
    sei();
}

void setup() {
    Serial1.begin(9600);
    Serial1.println("System restart");

    // set watchdog interval to 4s and start watchdog timer
    WDT_Prescaler_Change();

    DDRD &= ~(1 << DDD0); // configure pin PD0 as input
    PORTD |= (1 << PORTD0); // pull up (manual p68)

    // configure and enable external interrupt on pin PD0
    // configure as active high;
    EICRA |= (1 << ISC00) | (1 << ISC01);
    // configure pin 21 as interrupt
    EIMSK |= (1 << INT0);
}

void loop() {} // empty

ISR (INT0_vect) {
    // reset watchdog within ISR, “debounce” button (Taster entprellen)
    if(millis() - current_time > BOUNCING_THRESHOLD) {
        wdt_reset();
        Serial1.println("ResetWDT");
    }
    current_time = millis();
}