#include <util/delay.h> // for _delay_ms()

int ledPin = 13;        // LED connected to digital pin 13

void setup() {
    // pinMode(ledPin, OUTPUT);   // sets the digital pin as output
    // equal to:
    DDRB = 0xFF;
}

void loop() {
    // digitalWrite(ledPin, HIGH);
    // equal to:
    PORTB = 0xFF;

    // wait n milliseconds
    // delay(1000);
    // equal to:
    _delay_ms(1000);

    // digitalWrite(ledPin, LOW);
    // equal to:
    PORTB = 0x00;

    // delay(1000);
    // equal to:
    _delay_ms(1000);
}
