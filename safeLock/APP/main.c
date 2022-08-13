/*
 * main.c
 *
 *  Created on: Sep 23, 2021
 *      Author: Kero Adel
 */

#include "../Libs/stdtypes.h"
#include "../MCAL/DIO/DIO_int.h"
#include "util/delay.h"
#include "../HAL/DCMotor/DCMotor_int.h"
#include "../HAL/Buzzer/Buzzer_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "SafeLock/SafeLock_int.h"

void main(void)
{
	SafeLock_vidInit();

	SafeLock_vidLogin();
}
