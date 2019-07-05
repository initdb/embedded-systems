#include "Arduino.h"

int anIn = 2;

void setup() {
    Serial1.begin(9600);

    // enable ADC
    ADCSRA |= (1<<ADEN);

    // set prescaler 128
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);

    // ADC 2
    ADMUX |= (1<<MUX1);

    // external rev voltage 5V
    ADMUX |= (1<<REFS0);
}

void loop() {
    ADCSRA |= (1<<ADSC);

    while(ADCSRA & (1<<ADSC));

    uint8_t valL = ADCL;
    uint8_t valH = ADCH;
    uint16_t in = (valH<<8) | valL;
    
    Serial1.print("raw: ");
    Serial1.print(in);
    Serial1.print(" ,voltage: ");
    float voltage = in * 5.0 / 1024.0;
    Serial1.println(voltage);
    delay(500);
}
