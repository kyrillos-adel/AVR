/*
 * main.c
 *
 *  Created on: Sep 24, 2021
 *      Author: Kero Adel
 */

#include "util/delay.h"
#include "../Libs/stdtypes.h"
#include "../HAL/KeyPad/KeyPad_int.h"
#include "../MCAL/DIO/DIO_int.h"


void main(void)
{
	KeyPad_vidInit();
	DIO_u8setPortDir(PORT_C, 0xff);

	while(1)
	{

		DIO_u8setPortVal(PORT_C, KeyPad_u8Pressed());

		_delay_ms(500);
	}
}
