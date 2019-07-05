#include <Arduino.h>

const uint8_t ledPin = 24;
bool led_state = false;

void setup() {
    pinMode(ledPin, OUTPUT);
    // just in case, set it to 0x00
    TCCR4A = 0x00;
    TCCR4B = 0x00;

    // set prescaler to 1024
    TCCR4B |= (1 << CS42) | (0 << CS41) | (1 << CS40);

    // activate timer interrupt
    TIMSK4 |= (1 << ICIE4) | (1 << TOIE4);

    sei();
}

void loop() {
    // do nothing
}

ISR(TIMER4_OVF_vect) {
    // toggle led
    if(led_state) {
        led_state = false;
    } else {
        led_state = true;
    }

    digitalWrite(ledPin, led_state);
}