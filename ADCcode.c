#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
void adc(void);
void read_adc(void);


int main(void)
{
	DDRC=0b00000000; //output of ADC,input to micro controller
	DDRE=0xFF; //PE2=ADDC, PE1=ADDB, PE0=ADDA
	DDRB=0b00110011; // PB5=ALE, PB1=Start, //PB2=clock, PB3=EOC, PB4=OE, PB0=OC0;
	DDRD=0xFF;  // output from controller to LED bank
		TCCR0|=(1<<WGM01)|(1<<COM00)|(1<<CS00);
		//TCNT0=0;
		OCR0=2;
	//Initialization
	//char number=0;
	PORTB=0b00001000;
	
	
    while(1)
    {
     		 
	 
	 adc();   //TODO:: Please write your application code 
    }
}// main


void adc(void)
{
	
	PORTE=0x00; // Line 0 selected
	read_adc();
} //adc

void read_adc(void)
{
	char num=0;
	PORTB=PORTB|0b00100010; //ALE and Start 1
	_delay_ms(100);
	PORTB=PORTB&0b11011101;// ALE and Start 0
	while((PINB&0b00001000)==0b00001000);
	while((PINB&0b00001000)==0b00000000);
	PORTB=PORTB|(0b00010000);
	num=PINC;
	_delay_ms(200);
	PORTB=PORTB&(0b11101111);
	PORTD=num;
}	