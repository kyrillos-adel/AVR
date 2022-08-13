/*
 * main.c
 *
 *  Created on: Nov 19, 2021
 *      Author: Kero Adel
 */
#include "Libs/stdtypes.h"
#include "avr/io.h"
#include "MCAL/DIO/DIO_int.h"
#include "SPI_Init.h"
#include "util/delay.h"

void main(void){
	u8 data;

	DIO_u8setPinDir(PORT_A, PIN0, OUTPUT);

	DIO_u8setPinDir(PORT_B, PIN4, OUTPUT);
	DIO_u8setPinDir(PORT_B, PIN5, OUTPUT);
	DIO_u8setPinDir(PORT_B, PIN7, OUTPUT);

	DIO_u8setPinVal(PORT_B, PIN4, LOW);

	SPI_vidmasterInit();

	while(1){
		data = SPI_u8tranceiver(1);

		if(data == 55){
			DIO_u8setPinVal(PORT_A, PIN0, HIGH);
		}

		else{
			DIO_u8setPinVal(PORT_A, PIN0, LOW);
		}

		_delay_ms(1000);
		data = SPI_u8tranceiver(0);

		if(data == 55){
			DIO_u8setPinVal(PORT_A, PIN0, HIGH);
		}

		else{
			DIO_u8setPinVal(PORT_A, PIN0, LOW);
		}
		_delay_ms(1000);

	}
}

