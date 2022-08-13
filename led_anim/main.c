#include "avr/io.h"
#include "util/delay.h"
#include "animations.h"

void main(void)
{
	DDRA = 0xff;
	DDRC &= 0b11111000;
	PORTC |= 0b00000111;
	int switcher = (PINC & 0b00000111);
	while(1)
	{
		switcher = (PINC & 0b00000111);

		switch (switcher) {
			case 0: flasher();
				break;

			case 1: shiftLeft();
				break;

			case 2: shiftRight();
				break;

			case 3: converging();
				break;

			case 4: diverging();
				break;

			case 5: pingPong();
				break;

			case 6: snake();
				break;

			case 7: convDiv();
				break;

			default:
				break;
		}
	}
}
