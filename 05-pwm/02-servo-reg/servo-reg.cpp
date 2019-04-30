#include "Arduino.h"

void setup() {
    // set PH5 as output
    DDRH |= (1 << DDH5);

    // set to zero to be sure
    TCCR4A = 0x00;
    TCCR4B = 0x00;

    // set prescaler to 8
    TCCR4B |= (1 << CS41);

    // set PWM 8-Bit mode
    TCCR4A |= (1 << WGM41);
    TCCR4B |= (1 << WGM43) | (1 << WGM42);

    // compare output mode: non-inverted mode
    // clear on match, set at bottom.
    TCCR4A |= (1 << COM4C1);

    // set TOP value
    ICR4 = 40000;

    // set CMP value
    OCR4C = 1088;
}

void loop() {
    delay(3000);
    OCR4C = 4800;
    delay(3000);
    OCR4C = 1080;
}