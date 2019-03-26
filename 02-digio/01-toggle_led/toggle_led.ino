#include <util/delay.h> // for _delay_ms()

//int ledPin = 26;        // LED connected to digital pin 13
//int inPin = 22;

void setup() {
    //pinMode(ledPin, OUTPUT);   // sets the digital pin as output
    //pinMode(inPin, INPUT);
    DDRA |= ((0 << DDA0) | (1 << DDA4));
}

void loop() {
    if(PINA & (1 << PINA0))
    {
        //digitalWrite(ledPin, HIGH);
        PORTA |= (1 << PA4);
        delay(5000);
    }
    else
    {
        //digitalWrite(ledPin, LOW);
        PORTA &= ~ (1 << PA4);
    }
}
