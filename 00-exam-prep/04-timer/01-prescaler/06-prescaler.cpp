#include <Arduino.h>

void setup() {
    DDRA |= (1<<DDA2);
    // sicherheitshalber auf 0
    TCCR4A = 0x0;
    TCCR4B = 0x0;

    // no prescaler
    TCCR4B |= (1<<CS41) | (0<<CS40);

    // overflow interrupt enable
    TIMSK4 |= (1<<TOIE4);
}

void loop() {
    // do nothing
}

ISR(TIMER4_OVF_vect) {
    PORTA ^= (1<<PA2);
}