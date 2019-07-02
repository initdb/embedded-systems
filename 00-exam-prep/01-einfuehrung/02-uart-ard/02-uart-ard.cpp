#include "Arduino.h"

void setup()
{
    Serial1.begin(9600);
    Serial1.println("enter 4 chars");
}

void loop()
{
    String input;

    if(Serial1.available()) {
        input = Serial1.readStringUntil('\r');
        if (input.length() == 4) {
            Serial1.print("valid: ");
            Serial1.println(input);
        } else {
            Serial1.print("discarded due to length: ");
            Serial1.println(input.length());
        }
    }
}
