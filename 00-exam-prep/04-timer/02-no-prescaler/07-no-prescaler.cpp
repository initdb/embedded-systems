#include <Arduino.h>

volatile uint16_t counter = 0;

void setup() {
    DDRA |= (1<<DDA2);
    // sicherheitshalber auf 0
    TCCR4A = 0x0;
    TCCR4B = 0x0;

    // no prescaler
    TCCR4B |= (1<<CS42) | (0<<CS41) | (0<<CS40);

    // overflow interrupt enable
    TIMSK4 |= (1<<TOIE4);
}

void loop() {
    // do nothing
}

ISR(TIMER4_OVF_vect) {
    if(counter >= 244) {
        PORTA ^= (1 << PA2);
        counter = 0;
    }
    else {
        counter++;
    }
}