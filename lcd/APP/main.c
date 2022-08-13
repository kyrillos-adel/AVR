/*
 * main.c
 *
 *  Created on: Sep 23, 2021
 *      Author: Kero Adel
 */

#include "../Libs/stdtypes.h"
#include "../MCAL/DIO/DIO_int.h"
#include "util/delay.h"

#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_int.h"

void main(void)
{
	LCD_vidInit();

	LCD_vidSendNumber(25431);

//	LCD_vidSendNumber(0);
//
//	LCD_u8sendData('-');

//	LCD_vidGlitchString("Kyrillos");
}
