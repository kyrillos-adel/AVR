#include "avr/io.h"
#include "util/delay.h"
#include "animations.h"

void flasher(void)
{
	LED_PORT = 0xff;
	_delay_ms(500);
	LED_PORT = 0;
	_delay_ms(500);
}

void shiftLeft(void)
{
	LED_PORT = 0;
	for(int i=0; i<8; i++){
		LED_PORT = (1<<i);
		_delay_ms(250);
	}
}

void shiftRight(void)
{
	LED_PORT = 0;
	for(int i=0; i<8; i++){
		LED_PORT = (0b10000000>>i);
		_delay_ms(250);
	}
}

void converging(void)
{
	LED_PORT = 0;
	for(int i=0; i<8; i++){
		LED_PORT = (1<<i) | (1<<(7-i));
		_delay_ms(300);
	}
}

void diverging(void)
{
	LED_PORT = 0;
	for(int i=4; i<8; i++){
		LED_PORT = (1<<i) | (1<<(7-i));
		_delay_ms(300);
	}
}

void snake(void)
{
	LED_PORT = 0;
	for(int i=0; i<8; i++){
		LED_PORT |= (1<<i);
		_delay_ms(300);
	}
}

void convDiv(void)
{
	converging();
	diverging();
}

void pingPong()
{
	LED_PORT = 0;
	for(int i=0 ; i<8 ; i++){
		LED_PORT = (1<<i);
		_delay_ms(50);
	}
	for(int i=7 ; i>=0 ; i--){
		LED_PORT = (1<<i);
		_delay_ms(50);
	}
}
