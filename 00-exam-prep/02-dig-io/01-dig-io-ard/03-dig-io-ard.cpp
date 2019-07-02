#include "Arduino.h"

uint8_t ledPin = 26;
uint8_t butPin = 22;

void setup()
{
    //pinMode(ledPin, OUTPUT);
    DDRA |= (1<<DDA4);
    //pinMode(butPin, INPUT);
    DDRA &= ~(1<<DDA0);
}

void loop()
{
    /*if(digitalRead(butPin) > LOW)
        digitalWrite(ledPin, HIGH);
    else
        digitalWrite(ledPin, LOW);
        */
    if(PINA & (1<<PA0))
        PORTA |= (1<<PA4);
    else
        PORTA &= ~(1<<PA4);
}
