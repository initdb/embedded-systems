#include "Arduino.h"

int anIn = 2;

void setup() {
    Serial1.begin(9600);
}

void loop() {
    uint16_t in = analogRead(anIn);
    Serial1.print("raw: ");
    Serial1.print(in);
    Serial1.print(" ,voltage: ");
    float voltage = in * 5.0 / 1024.0;
    Serial1.println(voltage);
    delay(500);
}
