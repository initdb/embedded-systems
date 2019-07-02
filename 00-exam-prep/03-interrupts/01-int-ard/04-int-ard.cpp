#include "Arduino.h"

volatile int counter = 0;
volatile float current_time = 0.0;

#define BOUNCING_THRESHOLD 150

void isr();

void setup()
{
    Serial1.begin(9600);
    /*pinMode(21, INPUT);
    attachInterrupt(digitalPinToInterrupt(21), isr, RISING);
    sei();*/
    EIMSK |= (1 << INT0);
    EICRA |= (1<<ISC01) | (1<<ISC00);
    SREG |= (1 << SREG_I);
}

void loop()
{
    Serial1.println("Zählerstand: ");
    Serial1.println(counter);
    delay(1000);
}

void isr() {
    if(millis() - current_time > BOUNCING_THRESHOLD) {
        counter++;
    }
    current_time = millis();
}

ISR (INT0_vect) {
    if(millis() - current_time > BOUNCING_THRESHOLD) {
        counter++;
    }
    current_time = millis();
}