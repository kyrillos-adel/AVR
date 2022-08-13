/*
 * main.c
 *
 *  Created on: Sep 18, 2021
 *      Author: Mark
 */

#include "lib/DIO_Registers.h"
#include "lib/bitmath.h"
#include "lib/stdtypes.h"
#include "lib/stderrors.h"
#include "DIO_V1/DIO_int.h"
#include "util/delay.h"
#define NULL (u8)0
void main()
{

	//			/*PORTs Test*/
	//	DIO_u8setPortDir(PORT_A,FULL_OUTPUT);
	//			/*PINs Test/*
	//  DIO_u8setPinDir(PORT_A,PIN_0,OUTPUT);

	while(1)
	{

		//		/*PORTs Test*/
		//		DIO_u8setPortVal(PORT_A,FULL_HIGH);
		//		_delay_ms(300);
		//		DIO_u8setPortVal(PORT_A,FULL_LOW);
		//		_delay_ms(300);
		//		/*PINs Test*/
		//		DIO_u8setPinVal(PORT_A,PIN_0,HIGH);
		//		_delay_ms(300);
		//		DIO_u8setPinVal(PORT_A,PIN_0,LOW);
		//		_delay_ms(300);

	}
}

