int counter = 0;

void setup() {
    Serial1.begin(9600);
    pinMode(22, INPUT);
    Serial1.println("Hello");
}

void loop() {
    if (digitalRead(22) == HIGH)
        counter++;

    Serial1.println("Zaehlerstand: ");
    Serial1.println(counter);
    delay(3000);
}