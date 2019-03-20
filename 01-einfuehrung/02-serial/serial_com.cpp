#include <Arduino.h>

String input;

void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
    // empty
}

void serialEvent() {
    // check if something is there
    if (Serial.available() > 0) {
        // consume data regardless of input
        input = Serial.readString();

        if (input.length() == 4) {
            Serial.print("valid input: ");
            Serial.println(input);
        } else {
            Serial.print("discarded: ");
            Serial.println(input);
        }
    }
}
