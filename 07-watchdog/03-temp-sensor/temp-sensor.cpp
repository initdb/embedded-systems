#include "Arduino.h"

void setup() {
    Serial1.begin(9600); // activate serial console
    ADCSRA |= (1 << ADEN); // enable ADC functionality
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    // use /128 prescaler
    ADMUX |= (1 << MUX1); // select ADC2 as input pin
    ADMUX |= (1 << REFS1) | (1 << REFS0); // use reference voltage 2.56V, manual p281
}

void loop() {
    ADCSRA |= (1 << ADSC);
    // trigger ADC conversion
    while (ADCSRA & (1 << ADSC));
    // wait until conversion is finished, see manual p286
    unsigned int read = ADCL + 256 * ADCH;
    // read analog value, first LOW then HIGH
    double result = 2.56 * read / 1024.0;
    Serial1.print(result);
    Serial1.print(" Volt, ");
    double celsius = 0.25 * read - 50;
    Serial1.print(celsius);
    Serial1.println("°C");
}