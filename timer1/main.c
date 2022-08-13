/*
 * main.c
 *
 *  Created on: Oct 29, 2021
 *      Author: Kero Adel
 */

#include "avr/io.h"
#include "avr/interrupt.h"
#include "Libs/bitmath.h"

ISR(__vector_10){

//	static u8 OVF_counts = 0;
//	OVF_counts++;

	static u8 CTC_counts = 0;
	CTC_counts++;

	if(CTC_counts == 40){
		/*Set preload*/
//		TCNT0 = 124;

		/*Action*/
		TOGGLE_BIT(PORTA, PA0);

		/*Reset overflow counter*/
		CTC_counts = 0;
	}
}


void main(void){

	/*Port A as output*/
	DDRA = 0xff;

	/*Timer overflow interrupt enable*/
//	TIMSK |= (1<<0);

	OCR0 = 195;

	/*CTC interrupt enable*/
	TIMSK |= (1<<1);

	/*Global interrupt enable*/
	SREG |= (1<<7);

	/*TCCR0 copy*/
	u8 register_copy = TCCR0;

	/*Preload*/
//	TCNT0 = 238;

	/*Timer mode*/
	register_copy |= (1<<6);
	register_copy &= ~(1<<3);

	/*Clear clock source/prescaler*/
	register_copy &= ~(0b111<<0);

	/*Select clock source/prescaler*/
	register_copy |= (0b101<<0);

	TCCR0 = register_copy;

	while(1);
}
