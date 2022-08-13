/*
 * LCDKeyPadCalc.c
 *
 *  Created on: Sep 28, 2021
 *      Author: Kero Adel
 */

#include "../../HAL/KeyPad/KeyPad_int.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../../Libs/stdtypes.h"
#include "../Calculator/Calculator.h"
#include <util/delay.h>
#include <math.h>

void LCDKeyPadCalc_vidInit(void)
{
	LCD_vidInit();
	KeyPad_vidInit();
	u8 local_u8KeyPressed;
	u8 local_u8Numbers[6];
	s8 local_u8Counter = 0;
	s32 local_s32Num1 = 0;
	s32 local_s32Num2 = 0;
	u8 local_u8Operation = 0;
	u8 local_u8ScreenCounter = 0;
	s32 local_s32Result = 0;

	while(1)
	{
		local_u8KeyPressed = KeyPad_u8Pressed();

		if((local_u8KeyPressed>=0)&&(local_u8KeyPressed<10))
		{
			LCD_vidSendNumber(local_u8KeyPressed);
			local_u8Numbers[local_u8Counter] = local_u8KeyPressed;
			local_u8Counter++;
			local_u8ScreenCounter++;
		}

		else if(local_u8KeyPressed == '=')
		{
			local_u8ScreenCounter++;

			LCD_u8sendData(local_u8KeyPressed);

			for(u16 iterate=1; local_u8Counter>0; local_u8Counter--, iterate*=10)
			{
				local_s32Num2 += local_u8Numbers[local_u8Counter-1] * iterate;
				local_u8Numbers[local_u8Counter-1] = 0;
			}
			local_u8Counter = 0;
			switch (local_u8Operation)
			{
			case '+':
				local_s32Result = Calculator_s32Sum(local_s32Num1, local_s32Num2);
				if((local_s32Result/pow(10, 15-local_u8ScreenCounter))!=local_s32Result)
				{
					LCD_vidClearDisplay();
					LCD_vidGlitchString("Out of space!");
					break;
				}
				else
				{
					LCD_vidSendNumber(local_s32Result);
				}
				break;
			case '-':
				local_s32Result = Calculator_s32Sub(local_s32Num1, local_s32Num2);
				if((local_s32Result/pow(10, 15-local_u8ScreenCounter))!=local_s32Result)
				{
					LCD_vidClearDisplay();
					LCD_vidGlitchString("Out of space!");
					break;
				}
				else
				{
					LCD_vidSendNumber(local_s32Result);
				}
				break;
			case '*':
				local_s32Result = Calculator_s32Mul(local_s32Num1, local_s32Num2);
				if((local_s32Result/pow(10, 15-local_u8ScreenCounter))!=local_s32Result)
				{
					LCD_vidClearDisplay();
					LCD_vidGlitchString("Out of space!");
					break;
				}
				else
				{
					LCD_vidSendNumber(local_s32Result);
				}
				break;
			case '/':
				local_s32Result = Calculator_s32Div(local_s32Num1, local_s32Num2);
				if(local_s32Result==-1)
				{
					LCD_vidGoToXY(0, 1);
					LCD_vidSendString("Syntax error");
					break;
				}
				else
				{
					if((local_s32Result/pow(10, 15-local_u8ScreenCounter))!=local_s32Result)
					{
						LCD_vidClearDisplay();
						LCD_vidGlitchString("Out of space!");
						break;
					}
					else
					{
						LCD_vidSendNumber(local_s32Result);
					}
				}
				break;
			}
		}

		else if((local_u8KeyPressed == '+')||(local_u8KeyPressed == '-')||(local_u8KeyPressed == '*')||(local_u8KeyPressed == '/'))
		{
			LCD_u8sendData(local_u8KeyPressed);
			local_u8Operation = local_u8KeyPressed;
			local_u8ScreenCounter++;

			for(u16 iterate=1; local_u8Counter>0; local_u8Counter--, iterate*=10)
			{
				local_s32Num1 += local_u8Numbers[local_u8Counter-1] * iterate;
				local_u8Numbers[local_u8Counter-1] = 0;
			}
			local_u8Counter = 0;
		}

		else if(local_u8KeyPressed == 'c')
		{
			break;
		}

	}
}


