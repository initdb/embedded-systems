#include "Arduino.h"

void setup() {
    /* Set baud rate */
    UBRR1H = 0;     // to be sure set to 0
    UBRR1L = 0x67;  // set BAUD to 9600 see p.223
    /* Enable receiver and transmitter */
    UCSR1B = (1<<TXEN1);
    /* Set frame format: 8data, 1stop bit */
    UCSR1C = (1<<UCSZ11) | (3<<UCSZ10);

}

void uart_putchar(char c) {
    /* Wait for empty transmit buffer */
    while ( !( UCSR1A & (1<<UDRE1)) )
        ;
    /* Put data into buffer, sends the data */
    UDR1 = c;
}

void loop() {
    char text[] = "Pommes!";
    for (int i = 0; i < sizeof(text);i++) {
        uart_putchar(text[i]);
    }
    delay(2000);
}