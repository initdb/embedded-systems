#include <Arduino.h>

const uint8_t led_pin = 24;
bool led_state = false;

void setup() {
    pinMode(led_pin, OUTPUT);
    // just in case, set it to 0x00
    TCCR4A = 0x00;
    TCCR4B = 0x00;

    // set prescaler
    TCCR4B |= (1 << CS40) | (0 << CS41) | (1 << CS42);

    // activate timer interrupt
    TIMSK4 |= (1 << ICIE4) | (1 << TOIE4);

    sei();
}

void loop() {
    // do nothing
}

ISR(TIMER4_OVF_vect) {
    if(led_state) {
        led_state = false;
    } else {
        led_state = true;
    }

    digitalWrite(led_pin, led_state);
}