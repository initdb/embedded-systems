#include "Arduino.h"

// MASTER
void setup() {
    Serial1.begin(9600);

    DDRB |= (1<<DDB2) | (1<<DDB1);//? | (1<<DDB0);

    SPCR |= (1<<SPE) | (1<<MSTR);
}
// send and receive data
char spi_transceive(char data) {
    PORTB &=~(1<<PB0);
    /* Start transmission */
    SPDR = data;
    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)))
        ;
    PORTB |= (1<<PB0);
    return SPDR;
}

void loop() {
    char text[] = "Hallo Slave!";
    for (int i = 0; i < sizeof(text);i++){
        char received = spi_transceive(text[i]);
        Serial1.print(received);
    }

    delay(1000);
}

// SLAVE
void setup() {
    Serial1.begin(9600);
    DDRB |= (1<<DDB3);
}

// send and receive data
unsigned char spi_transceive(unsigned char data) {
    /* Start transmission */
    SPDR = data;
    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)))
        ;

    return SPDR;
}

void loop() {
    char text[] = "Hallo Master!";
    for (int i = 0; i < sizeof(text);i++){
        char received = spi_transceive(text[i]);
        Serial1.println(received); }
    delay(1000);
}
