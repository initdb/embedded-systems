#include "Arduino.h"

int microPin = 24;
int ledPin = 21;

// states
typedef enum {
    WAIT_FOR_CLAP_ONE,
    ONE_CLAP_DETECTED,
    WAIT_FOR_CLAP_TWO
} state_t;

// events
typedef enum {
    NO_EVENT,
    MICRO_PIN_HIGH,
    TIMER100_EXPIRED,
    TIMER300_EXPIRED
} event_t;

// global variables
state_t state;       // current state
unsigned long timer100 = 0;    // timestamp for 100 ms timer, 0 means inactive
unsigned long timer300 = 0;    // timerstamp for 300 ms timer, 0 means inactive

// transition functions
void stay() {
}
void enterOneClapDetected() {
    state = ONE_CLAP_DETECTED;
    timer100 = millis();  // start timer for 100 ms
}
void enterWaitForClapTwo() {
    state = WAIT_FOR_CLAP_TWO;
    timer300 = millis(); // start timer for 300 ms
}
void enterWaitForClapOneTimer300() {
    state = WAIT_FOR_CLAP_ONE;
}
void enterWaitForClapOneMicroPin() {
    state = WAIT_FOR_CLAP_ONE;
    digitalWrite(ledPin, !digitalRead(ledPin)); // toggle LED
}


// TODO:  transition table
// state_t
void (*state_table[3][4]) (void) = {
    //                      NO_EVENT    MICRO_PIN_HIGH                  TIMER100_EXPIRED        TIMER300_EXPIRED
    /*WAIT_FOR_CLAP_ONE*/{  stay,       enterOneClapDetected,           stay,                   stay                        },
    /*ONE_CLAP_DETECTED*/{  stay,       stay,                           enterWaitForClapTwo,    stay                        },
    /*WAIT_FOR_CLAP_TWO*/{  stay,       enterWaitForClapOneMicroPin,    stay,                   enterWaitForClapOneTimer300 }
};

void setup() {
    pinMode(microPin, INPUT);
    pinMode(ledPin, OUTPUT);
    state = WAIT_FOR_CLAP_ONE;   // initial state
}

void loop() {
    event_t event = NO_EVENT;
    if (digitalRead(microPin) == HIGH) {
        event = MICRO_PIN_HIGH;
    }
    else if (timer100 && millis() - timer100 > 100)
    {
        // timer valid and 100 ms expired
        event = TIMER100_EXPIRED;
        timer100 = 0;
        // reset timer;
    } else if (timer300 && millis() - timer300 > 300) {
        event = TIMER300_EXPIRED;
        timer300 = 0;
    }
    // use transition table to switch state
    state_table[state][event]();
}










