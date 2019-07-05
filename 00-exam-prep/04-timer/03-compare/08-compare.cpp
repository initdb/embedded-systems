#include <Arduino.h>

void setup() {
    DDRA |= (1<<DDA2);
    // sicherheitshalber auf 0
    TCCR4A = 0x0;
    TCCR4B = 0x0;

    // ctc mode
    TCCR4B |= (1<<WGM42);

    // 256 prescaler
    TCCR4B |= (1<<CS42) | (0<<CS41) | (0<<CS40);

    // overflow interrupt enable
    TIMSK4 |= (1 << OCIE4A);

    // max
    OCR4A = 62500;
}

void loop() {
    // do nothing
}

ISR(TIMER4_COMPA_vect) {
    PORTA ^= (1 << PA2);
}