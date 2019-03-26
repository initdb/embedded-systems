int count = 0;

void setup() {
    Serial1.begin(9600);
    pinMode(22, INPUT);
}
void loop() {
    if (digitalRead(22)) {

        while (!digitalRead(22)) {
        }
        count++;

        delay(100);
    }
    Serial1.println(count);
}