#include <util/delay.h>

int ledPin = 13;                // LED connected to digital pin 13

void setup() {
  // put your setup code here, to run once:
  //pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  DDRB = 0xFF;
  //PORTB = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(ledPin, HIGH);
  PORTB = 0xFF;
  // wait n milliseconds
  //delay(1000);
  _delay_ms(1000);
  //digitalWrite(ledPin, LOW);
  PORTB = 0x00;
  //delay(1000);
  _delay_ms(1000);
}
