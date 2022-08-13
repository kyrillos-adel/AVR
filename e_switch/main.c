/*
 * main.c
 *
 *  Created on: Sep 25, 2021
 *      Author: Kero Adel
 */

#include "util/delay.h"
#include "Libs/stdtypes.h"
#include "MCAL/DIO/DIO_int.h"

void main(void)
{
	DIO_u8setPinDir(PORT_A, PIN_0, OUTPUT);
//	DIO_u8setPinDir(PORT_A, PIN_1, OUTPUT);


	while(1)
	{
		DIO_u8setPinVal(PORT_A, PIN_0, HIGH);
		_delay_ms(2000);
		DIO_u8setPinVal(PORT_A, PIN_0, LOW);
		_delay_ms(2000);


//		DIO_u8setPinVal(PORT_A, PIN_0, HIGH);
//		DIO_u8setPinVal(PORT_A, PIN_1, LOW);
//		_delay_ms(2000);
//
//		DIO_u8setPinVal(PORT_A, PIN_0, LOW);
//		DIO_u8setPinVal(PORT_A, PIN_1, LOW);
//		_delay_ms(2000);
//
//
//		DIO_u8setPinVal(PORT_A, PIN_0, LOW);
//		DIO_u8setPinVal(PORT_A, PIN_1, HIGH);
//		_delay_ms(2000);
//
//
//		DIO_u8setPinVal(PORT_A, PIN_0, LOW);
//		DIO_u8setPinVal(PORT_A, PIN_1, LOW);
//		_delay_ms(2000);
	}
}
