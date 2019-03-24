void setup() {
    Serial1.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
    // empty
}

void serialEvent1() {
    // check if something is there
    if (Serial1.available() > 0) {
        // consume data regardless of input
        input = Serial1.readString();

        if (input.length() == 4) {
            Serial1.print("valid input: ");
            Serial1.println(input);
        } else {
            Serial1.print("discarded: ");
            Serial1.println(input);
        }
    }
}
