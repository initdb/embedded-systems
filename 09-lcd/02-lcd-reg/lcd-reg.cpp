#include "Arduino.h"

#define RS 12		// controls RS pin of LCD (digital pin 12)
#define E  11		// controls Enable pin to LCD (digital pin 11)
// Note: Not need to control RW pin: it's set to GND by hardware since we always write and never read

void enablePulse() {
    digitalWrite(E, LOW);
    delayMicroseconds(3);
    digitalWrite(E, HIGH);
    delayMicroseconds(3);		// enable pulse must be > 450 ns, see p49 of HD44780 manual
    digitalWrite(E, LOW);
    delayMicroseconds(200);		// commands need > 37 us to settle
}

// write an instruction, indicated by RS == LOW
void writeInstruction(char instr) {
    digitalWrite(RS, LOW);
    PORTC = instr;
    enablePulse();  // commit command, short pulse on E pin
    PORTC = (instr << 4);
    enablePulse();
}

// write character, indicated by RS == HIGH, automatically moves cursor
void writeData(char data) {
    digitalWrite(RS, HIGH);
    PORTC = data;
    enablePulse(); // commit command, short pulse on E pin
    PORTC = (data << 4);
    enablePulse();
}

void setup()
{
    // set pins to output
    pinMode(RS, OUTPUT);
    pinMode(E, OUTPUT);
    DDRC = 0xF0;				// data pins PC7 to PC4

    // Set RS and E to Low to begin commands
    digitalWrite(RS, LOW);
    digitalWrite(E, LOW);

    // manual HD44780, p46, Figure 24: initialization specification for 4-bit mode
    // wait for more than 15 ms
    delay(30);

    // initialization sequence (Figure 24): sequence (0 0 0 0 1 1), then wait for > 4.1 ms
    PORTC = (0x03 << 4);
    enablePulse();
    delay(5);

    // initialization sequence (Figure 24): sequence (0 0 0 0 1 1), then wait for > 100 us
    PORTC = (0x03 << 4);			// only highest byte
    enablePulse();
    delayMicroseconds(200);


    // initialization sequence: sequence (0 0 0 0 1 1)
    PORTC = (0x03 << 4);   // only highest byte
    enablePulse();
    delayMicroseconds(50);

    //finally, set to 4-bit interface: (0 0 0 0 1 0)
    PORTC = (0x02 << 4);
    enablePulse();

    // Function Set, 4-bit, 2 line mode, 5x8 dots: (0 0 1 0 1 0 0 0)
    writeInstruction((0x0a<<2));


    // Return Home, set cursor to beginning: (0 0 0 0 0 0 1 0)
    writeInstruction(0x02);

    delayMicroseconds(2500);

    // Entry Mode Set, increment cursor, no display shift: (0 0 0 0 0 1 1 0)
    writeInstruction((0x03<<1));

    // clear display: 0x01
    writeInstruction(0x01);
    delayMicroseconds(300);
    delay(50);
}

void loop()
{
    // set cursor to beginning if first line:  command 0x80  (DDRAM address 0x00, see p11 of manual)
    writeInstruction(0x80);
    char line1[] = {"Embedded Systems  "};
    // Write line 1
    for(int8_t i = 0; i < sizeof(line1)-1; i++) {
        writeData(line1[i]);
        delay(50);
    }
    delay(1000);

    // set cursor to beginning of 2nd line line: command 0xC0 (DDRAM address 0x40, see p11 of manual)
    writeInstruction(0xC0);
    char line2[] = {"macht Spass"};
    // TODO: Write line 2
    for(int8_t i = 0; i < sizeof(line2)-1; i++) {
        writeData(line2[i]);
        delay(50);
    }
    delay(3000);
    // clear
    writeInstruction(0x01);
    delay(500);
}
