/*
 * I2C_1.c
 *
 * Created: 1/16/2020 3:58:13 PM
 * Author : Hamza
 */ 

#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>

void i2c_init()
{
	TWBR = 0x62;
	TWCR = (1<<TWEN);
	TWSR = 0x00;
}

void i2c_start()
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while(!(TWCR & (1<<TWINT)));
}

void i2c_write(char x)
{
	TWDR = x;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR &(1<<TWINT)));
}

char i2c_read()
{
	TWCR = (1<<TWEN) |(1<<TWINT);
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
}


int main(void)
{
    /* Replace with your application code */
	DDRA = 0xFF;
	i2c_init();
	i2c_start();
	i2c_write(0x40);
    while (1) 
    {
		i2c_write(0xFF);
		_delay_ms(3000);
		i2c_write(0x00);
		_delay_ms(3000);
    }
}

