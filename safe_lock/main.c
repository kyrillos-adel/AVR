#include "avr/io.h"
#include "util/delay.h"

void main(void)
{
	DDRA |= 0b00000101;
	DDRC = 0;
	PORTC = 0xff;

	while(1)
	{
		while(PINC == 0b11010110){
			PORTA |= 0b00000100;
			PORTA &= 0b11111110;
		}

		PORTA |= 0b00000001;
		PORTA &= 0b11111011;
	}
}
