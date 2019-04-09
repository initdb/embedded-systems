volatile int counter = 0;
volatile float current_time = 0.0;

#define BOUNCING_THRESHOLD 150

void setup() {
    Serial1.begin(9600);
    // configure pin as input
    pinMode(21, INPUT);
    // alternatively:
    // attachInterrupt(digitalPinToInterrupt(21), isr, RISING);
    // configure as active high;
    EICRA |= (1 << ISC00) | (1 << ISC01);
    // configure pin 21 as interrupt
    EIMSK |= (1 << INT0);
    // globally enable interrupts
    // sei();
    SREG |= (1 << SREG_I);
}

void loop() {
    // do nothing ...
    Serial1.println(counter);
    delay(1000);
}

/*
void isr() {
    if(millis() - current_time > BOUNCING_THRESHOLD) {
        counter++;
    }
    current_time = millis();
}
*/

ISR(INT0_vect) {
        if(millis() - current_time > BOUNCING_THRESHOLD) {
            counter++;
        }
        current_time = millis();
}
