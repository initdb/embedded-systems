#include <Arduino.h>

const uint8_t ledPin = 24;
volatile bool led_state = false;
volatile uint16_t counter = 0;
const uint16_t max_counter = 122; // 122.95

void setup() {
    pinMode(ledPin, OUTPUT);
    // just in case, set it to 0x00
    TCCR4A = 0x00;
    TCCR4B = 0x00;

    // set prescaler to no prescaler
    TCCR4B |= (0 << CS42) | (0 << CS41) | (1 << CS40);

    // activate timer interrupt
    TIMSK4 |= (1 << ICIE4) | (1 << TOIE4);

    // enable global interrupts
    sei();
}

void loop() {
    // do nothing
}

ISR(TIMER4_OVF_vect) {
    if(counter >= max_counter) {
        // toggle led
        if(led_state) {
            led_state = false;
        } else {
            led_state = true;
        }

        digitalWrite(ledPin, led_state);

        counter = 0; // reset counter
    } else {
        counter++;
    }
}