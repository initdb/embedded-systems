#include "Arduino.h"

int an_in = 2;

void setup() {
    Serial1.begin(9600);
}

void loop() {
    int val = analogRead(A2);
    double voltage = val * 5.0 / 1024.0;

    Serial1.print(val);
    Serial1.print(", ");
    Serial1.println(voltage);
}
