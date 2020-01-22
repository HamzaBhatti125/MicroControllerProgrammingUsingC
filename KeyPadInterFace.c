#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#define  LED PD4

int getKeyPressed(void);

int main(void){
	char digit[20] = {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};
		DDRD = 0xF0;
		DDRA = 0xFF;
		DDRC = 0x00;
		DDRB = (1<<PIND1);
		int key;
		PORTA = digit[10];

	while(1)
	{
		key = getKeyPressed();
		if (key != 16)
		{
			PORTA = digit(key)
		}
	}	
}

int getKeyPressed(void){
	char x;
	PORTB = 0x00;
	int data;
	x = PINC (0x01);
	if (x = ~0x01)
	{
		data = PIND7 (0x0F) ;
		return data;
	}
	return 16;
}