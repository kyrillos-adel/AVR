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
#include "LCDKeyPadCalc/LCDKeyPadCalc.h"

void main(void)
{
	LCD_vidInit();

	//LCD_vidSendNumber(12113);

	LCD_vidSendString("Kyrillos");









//	LCD_vidGlitchString("solloryK");
//	_delay_ms(30);
//	LCD_vidClearDisplay();
//	LCD_vidGlitchString("Kyrillos");
//	_delay_ms(1000);
//	LCD_vidClearDisplay();
//	LCD_vidGlitchString("Calculator");
//	_delay_ms(1000);
//	LCD_vidClearDisplay();
//
	while(1)
	{
//		LCDKeyPadCalc_vidInit();
	}
}
