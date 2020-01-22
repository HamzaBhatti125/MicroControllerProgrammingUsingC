/*
 * 103105.c
 *
 * Created: 11/21/2019 11:21:20 AM
 * Author : Student
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <avr/delay.h>
void _LCDClear(void);
void _LCDFuncSet(void);
void _LCD_DispCtrl(void);
void _LCDEntryMod(void);

void _PrintChar(char k);

void change_line(void);

int main(void)
{
	DDRA = 0xFF;
	DDRE = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		_LCDClear();
		_LCDFuncSet();
		_LCD_DispCtrl();
		_LCDEntryMod();
		
		char name[12] = {'u','k','a','s','h','a',' ','h','a','m','z','a'};
		char roll[12] = {'f','a','l','l','-','1','9'};
			for (int j=0; j<13; j++)
			{
				_PrintChar(name[j]);
				_delay_ms(500);
			}
			
			PORTA = 0xC0;
			
			PORTE = 0x00;
			_delay_ms(10);
			PORTE = 0x01;
			_delay_ms(5);
			PORTE = 0x00;
			
			for (int j=0; j<11; j++)
			{
				_PrintChar(roll[j]);
				_delay_ms(500);
			}
	
		    }

}

void _LCDClear(void){
	PORTA = 0x01;
	PORTE = 0x00;
	_delay_ms(10);
	PORTE = 0x01;
	_delay_ms(5);
	PORTE = 0x00;
}
void _LCDFuncSet(void){
	PORTA = 0x3B;
	PORTE = 0x00;
	_delay_ms(10);
	PORTE = 0x01;
	_delay_ms(5);
	PORTE = 0x00;
}
void _LCD_DispCtrl(void){
	PORTA = 0x0F;
	PORTE = 0x00;
	_delay_ms(10);
	PORTE = 0x01;
	_delay_ms(5);
	PORTE = 0x00;
}
void _LCDEntryMod(void){
	PORTA = 0x06;
	PORTE = 0x00;
	_delay_ms(10);
	PORTE = 0x01;
	_delay_ms(5);
	PORTE = 0x00;
}
void _PrintChar(char K){
	PORTA = K;
	PORTE = 0x0D;
	_delay_ms(5);

	PORTE = 0x0C;
}

