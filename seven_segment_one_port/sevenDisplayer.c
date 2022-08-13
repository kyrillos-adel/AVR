#include "seven.h"
#include "avr/io.h"
#include "util/delay.h"
#include "sevenDisplayer.h"

int seven[10] = {num0, num1, num2, num3, num4, num5, num6, num7, num8, num9};

void sevenSegInit(void){
	S_SEGMENT_DDR = 0xff;
	S_SEGMENT_GND |= 0b11000000;
}

void displayShort(int number){

	int ones = number % 10;
	int tens = (number - ones)/10;

	for(int i=0; i<1; i++){
		GND_PORT |= 0b01000000;
		GND_PORT &= 0b01111111;
		S_SEGMENT_PORT = seven[ones];
		_delay_ms(5);
		GND_PORT |= 0b10000000;
		GND_PORT &= 0b10111111;
		S_SEGMENT_PORT = seven[tens];
		_delay_ms(5);
	}

}

void display(int number, int period){

	int ones = number % 10;
	int tens = (number - ones)/10;

	for(int i=0; i<period*100; i++){
		GND_PORT |= 0b01000000;
		GND_PORT &= 0b01111111;
		S_SEGMENT_PORT = seven[ones];
		_delay_ms(5);
		GND_PORT |= 0b10000000;
		GND_PORT &= 0b10111111;
		S_SEGMENT_PORT = seven[tens];
		_delay_ms(5);
	}

}

void displaySec(int number){
	display(number, 1);
}
