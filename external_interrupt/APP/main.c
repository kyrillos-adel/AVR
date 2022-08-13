#include "util/delay.h"
#include "avr/io.h"
#include "avr/interrupt.h"

void main(void)
{
	DDRA |= (1<<0);

	PORTD |= (1<<2);

	MCUCR |= (1<<0);
	MCUCR &= ~(1<<1);

	GICR |= (1<<6);
	SREG |= (1<<7);


	while(1)
	{

	}


}

ISR(INT0_vect)
{
	PORTA ^= (1<<0);
}

