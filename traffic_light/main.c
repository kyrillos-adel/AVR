#include "avr/io.h"
#include "util/delay.h"
#include "sevenDisplayer.h"

void stop(int period)
{
	PORTA &= 0b11111000;
	PORTA |= 0b00000001;

	for(int i=0; i<period; i++){
		display(period-i, 1);
	}
}

void wait(int period)
{
	PORTA &= 0b11111000;
	PORTA |= 0b00000010;

	for(int i=0; i<period; i++){
		display(period-i, 1);
	}
}

void run(int period)
{
	PORTA &= 0b11111000;
	PORTA |= 0b00000100;

	for(int i=0; i<period; i++){
		display(period-i, 1);
	}
}

int main(void)
{
	DDRA |= 0b00000111;
	sevenSegInit();
	while(1)
	{
		stop(10);
		wait(3);
		run(10);
		wait(3);
	}
}


