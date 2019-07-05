#include <Arduino.h>

const uint8_t ledPin = 24;
volatile bool led_state = false;

void setup() {
    pinMode(ledPin, OUTPUT);
    // just in case, set it to 0x00
    TCCR4A = 0x00;
    TCCR4B = 0x00;

    // init counter value
    TCNT4 = 0;

    // set Clear Timer on Compare Match (CTC)
    TCCR4B |= (1 << WGM42);

    // set prescaler to 256
    TCCR4B |= (1 << CS42) | (0 << CS41) | (0 << CS40);

    // activate timer interrupt
    TIMSK4 |= (1 << ICIE4) | (1 << OCIE4A);

    // enable global interrupts
    sei();

    // configure Output Compare Register 4 A
    OCR4A = 62500;
}

void loop() {
    // do nothing
}

ISR(TIMER4_COMPA_vect) {
    // toggle led
    if(led_state) {
        led_state = false;
    } else {
        led_state = true;
    }

    digitalWrite(ledPin, led_state);
}