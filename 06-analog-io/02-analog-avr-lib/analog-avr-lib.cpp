#include "Arduino.h"

int an_in = 2;

void setup() {
    Serial1.begin(9600);

    // enable adc
    ADCSRA |= (1 << ADEN);

    // adc prescaler to 128
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

    // single ended ad2
    ADMUX |= (1 << MUX1);

    // referrence voltage
    ADMUX |= (1 << REFS0);
}

void loop() {
    ADCSRA |= (1 << ADSC);

    while(ADCSRA & (1 << ADSC));

    unsigned int valL = ADCL;
    unsigned int valH = ADCH;
    unsigned int val = (valH << 8) | valL;
    double voltage = val * 5.0 / 1024.0;

    Serial1.print(val);
    Serial1.print(", ");
    Serial1.println(voltage);

    delay(100);
}