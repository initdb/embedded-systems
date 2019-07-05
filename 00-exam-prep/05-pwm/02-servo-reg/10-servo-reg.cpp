#include "Arduino.h"

void setup() {
    DDRH |= (1 << DDH5);

    // set to zero to be sure
    TCCR4A = 0x00;
    TCCR4B = 0x00;

    // set prescaler to 8
    TCCR4B |= (1 << CS41);

    // fast pwm
    TCCR4A |= (1<<WGM41);
    TCCR4B |= (1<<WGM43) | (1<<WGM42);

    // non inverting mode
    TCCR4A |= (1<<COM4C1);

    //top
    ICR4 = 40000;

    // duty cycle
    OCR4C = 1024;
}

void loop() {
    delay(3000);
    OCR4C = 5000;
    delay(3000);
    OCR4C = 1024;
}