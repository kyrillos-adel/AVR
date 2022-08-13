/*
 * main.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Kero Adel
 */
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../Libs/stdtypes.h"
#include "util/delay.h"

void main (void)
{
	u16 digital;
	f32 analog_mv;
	u32 temp;

	LCD_vidInit();
	ADC_vidADCInit();

	while(1)
	{
		LCD_vidClearDisplay();
		digital = ADC_u8ADCRead(0);
		analog_mv = digital * 4.88;
		temp = analog_mv /10;
		LCD_vidSendString("Temp=");
		LCD_vidSendNumber(temp);
		LCD_vidSendString("C");
		_delay_ms(800);
	}
}
