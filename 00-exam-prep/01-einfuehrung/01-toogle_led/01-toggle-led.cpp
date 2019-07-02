#include "Arduino.h"

uint8_t pin = 13;

void setup()
{
    //pinMode(pin, OUTPUT);
    DDRB |= (1<<DDB7);
}

void loop()
{
    //digitalWrite(pin, HIGH);
    PORTB |= (1<<PB7);
    delay(1005);
    //digitalWrite(pin, LOW);
    PORTB &= ~(1<<PB7);
    delay(1005);
}
