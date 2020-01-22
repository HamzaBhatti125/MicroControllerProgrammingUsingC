/*
 * Lab10(Receiver).c
 *
 * Created: 1/9/2020 3:25:42 PM
 * Author : student
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


int main(void)
{
	DDRD &= ~(1<<PD0);
	DDRD |= (1<<PD1);
	DDRA = 0xFF;
	DDRC = 0xFF;
	UBRR0H = 0x00;
	UBRR0L = 0x05;
	UCSR0B = (1<<RXEN0);
	UCSR0C = (1<<USBS0) | (3<<UCSZ00);
	unsigned char receiveData;
    /* Replace with your application code */
    while (1) 
    {
		PORTC = 0;
		receiveData = 0;
		while(!(UCSR0A & (1<<RXC0)));
		receiveData = UDR0;
		PORTC = receiveData;
		if(receiveData == 0b11110000){
			PORTA ^= (1<<PA0);
			_delay_ms(1000);
		}
		
    }
}

