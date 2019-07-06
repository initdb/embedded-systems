#include "Arduino.h"
#include <avr/wdt.h>

#define BOUNCING_THRESHOLD 150

volatile uint32_t current_time = 0;

void WDT_Prescaler_Change(void)
{
    cli();
    wdt_reset();
    /* Start timed equence */
    WDTCSR |= (1<<WDCE) | (1<<WDE);
    /* Set new prescaler(time-out) value = 4s */
    WDTCSR = (1<<WDE) | (1<<WDP3);
    sei();
}

void setup() {
    Serial1.begin(9600);
    Serial1.println("System restart");
    // TODO: set watchdog interval to 4s and start watchdog timer
    WDT_Prescaler_Change();
    DDRD &= ~(1 << DDD0);   // configure pin PD0 as input
    PORTD |= (1 << PORTD0); // pull up (manual p68)
    // TODO: configure and enable external interrupt on pin PD0 / INT0
    EICRA |= (1<<ISC01) | (1<<ISC00); // rising edge
    EIMSK |= (1<<INT0); // enable int0
}

void loop() {} // empty

ISR (INT0_vect) {
    if(millis() - current_time > BOUNCING_THRESHOLD) {
        // TODO: reset watchdog within ISR, “debounce” button (Taster entprellen)
        wdt_reset();
        Serial1.println("ResetWDT");
    }
    current_time = millis();
}