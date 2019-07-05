#include "Arduino.h"

#include <Servo.h>

Servo myservo;

int pos = 0;    // variable to store the servo position

void setup() {
    myservo.attach(8);  // attaches the servo on pin 8 to the servo object
}

void loop() {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
    }

    pos=0;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(350);
    pos=180;
    myservo.write(pos);
    delay(350);
    pos=0;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(350);
}