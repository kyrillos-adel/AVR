#include "avr/io.h"
#include "util/delay.h"
#include "sevenDisplayer.h"

void main(void)
{
	sevenSegInit();

	PORTA |= 0b00000001;

	int counter = 0;

	while(1)
	{
		if((PINA & 0b00000001)==0){
			_delay_ms(5);
			while((PINA & 0b00000001)==0){
				displayShort(counter);
			}
			counter ++;
		}

		if(counter>99)
			counter = 0;

		displayShort(counter);
	}
}
