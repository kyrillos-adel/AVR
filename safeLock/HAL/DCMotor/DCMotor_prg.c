/*
 * DCMotor_prg.c
 *
 *  Created on: Sep 30, 2021
 *      Author: Kero Adel
 */

#include "../../MCAL/DIO/DIO_int.h"
#include "DCMotor_int.h"
#include "DCMotor_config.h"
#include "../../Libs/stdtypes.h"
#include <util/delay.h>

void DCMotor_vidInit()
{
	DIO_u8setPinDir(DCMOTOR_PORT, DCMOTOR_TURN_LEFT_PIN, OUTPUT);
	DIO_u8setPinDir(DCMOTOR_PORT, DCMOTOR_TURN_RIGHT_PIN, OUTPUT);
	DIO_u8setPinVal(DCMOTOR_PORT, DCMOTOR_TURN_LEFT_PIN, LOW);
	DIO_u8setPinVal(DCMOTOR_PORT, DCMOTOR_TURN_RIGHT_PIN, LOW);
}


void DCMotor_vidTurnRight(u8 copy_u8Period)
{
	DIO_u8setPinVal(DCMOTOR_PORT, DCMOTOR_TURN_LEFT_PIN, LOW);
	DIO_u8setPinVal(DCMOTOR_PORT, DCMOTOR_TURN_RIGHT_PIN, HIGH);

	_delay_ms(copy_u8Period*1000);

	DIO_u8setPinVal(DCMOTOR_PORT, DCMOTOR_TURN_LEFT_PIN, LOW);
	DIO_u8setPinVal(DCMOTOR_PORT, DCMOTOR_TURN_RIGHT_PIN, LOW);
}

void DCMotor_vidTurnLeft(u8 copy_u8Period)
{
	DIO_u8setPinVal(DCMOTOR_PORT, DCMOTOR_TURN_RIGHT_PIN, LOW);
	DIO_u8setPinVal(DCMOTOR_PORT, DCMOTOR_TURN_LEFT_PIN, HIGH);

	_delay_ms(copy_u8Period*1000);

	DIO_u8setPinVal(DCMOTOR_PORT, DCMOTOR_TURN_LEFT_PIN, LOW);
	DIO_u8setPinVal(DCMOTOR_PORT, DCMOTOR_TURN_RIGHT_PIN, LOW);
}
