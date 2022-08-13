/*
 * main.c
 *
 *  Created on: Oct 15, 2021
 *      Author: Kero Adel
 */
#include "ADC_int.h"
#include "../MCAL/DIO/DIO_int.h"

void main(void)
{
	u16 digital;
	ADC_vidADCInit();
	DIO_u8setPinDir(PORT_D, PIN_5, OUTPUT);

	while(1)
	{
		digital = ADC_u8ADCRead(0);

//		digital >>= 2;

		if(digital >= 512)
		{
			DIO_u8setPinVal(PORT_D, PIN_5, HIGH);

		}

		else
		{
			DIO_u8setPinVal(PORT_D, PIN_5, LOW);
		}

	}
}
