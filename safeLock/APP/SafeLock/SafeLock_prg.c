/*
 * SafeLock_prg.c
 *
 *  Created on: Sep 30, 2021
 *      Author: Kero Adel
 */

#include "../../Libs/stdtypes.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "util/delay.h"
#include "../../HAL/DCMotor/DCMotor_int.h"
#include "../../HAL/Buzzer/Buzzer_int.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../../HAL/KeyPad/KeyPad_int.h"
#include "SafeLock_config.h"

u8 local_u8Numbers[4];
s8 local_u8Counter = 0;
u16 local_u16Num1 = 0;
u16 local_u16Num2 = 0;
u8 local_u8TrialsCounter = 0;
u16 Password = 1234;

void SafeLock_vidInit()
{
	LCD_vidInit();
	KeyPad_vidInit();
	Buzzer_vidInit();
	DCMotor_vidInit();
	DIO_u8setPinDir(LED_PORT, RED_LED, OUTPUT);
	DIO_u8setPinDir(LED_PORT, GREEN_LED, OUTPUT);
	DIO_u8setPinVal(LED_PORT, RED_LED, HIGH);
	DIO_u8setPinVal(LED_PORT, GREEN_LED, LOW);
}

void SafeLock_vidChangePassword(void)
{
	while((KeyPad_u8Pressed()!='=')&&(local_u8Counter<4))
	{
		if((KeyPad_u8Pressed()>=0)&&(KeyPad_u8Pressed()<10))
		{
			LCD_u8sendData('*');
			local_u8Numbers[local_u8Counter] = KeyPad_u8Pressed();
			local_u8Counter++;
		}

		else
			continue;
	}

	while(KeyPad_u8Pressed() != '=');

	if(KeyPad_u8Pressed() == '=')
	{
		for(u16 iterate=1; local_u8Counter>0; local_u8Counter--, iterate*=10)
		{
			local_u16Num1 += local_u8Numbers[local_u8Counter-1] * iterate;
			local_u8Numbers[local_u8Counter-1] = 0;
		}

		LCD_vidClearDisplay();
		LCD_vidCenterString("ReEnter new pass", 0);
		LCD_vidGoToXY(6, 1);

		while((KeyPad_u8Pressed()!='=')&&(local_u8Counter<4))
		{
			if((KeyPad_u8Pressed()>=0)&&(KeyPad_u8Pressed()<10))
			{
				LCD_u8sendData('*');
				local_u8Numbers[local_u8Counter] = KeyPad_u8Pressed();
				local_u8Counter++;
			}

			else
				continue;
		}

		for(u16 iterate=1; local_u8Counter>0; local_u8Counter--, iterate*=10)
		{
			local_u16Num2 += local_u8Numbers[local_u8Counter-1] * iterate;
			local_u8Numbers[local_u8Counter-1] = 0;
		}
	}

	if(local_u16Num1==local_u16Num2)
	{
		LCD_vidCenterString("Password's changed!");
		_delay_ms(1000);
	}
}

void SafeLock_vidOpenSystem(void)
{
	LCD_vidClearDisplay();
	LCD_vidCenterString("WELCOME", 0);
	DIO_u8setPinVal(LED_PORT, RED_LED, LOW);
	DIO_u8setPinVal(LED_PORT, GREEN_LED, HIGH);
	DCMotor_vidTurnRight(2);
}

void SafeLock_vidCloseSystem(void)
{
	LCD_vidClearDisplay();
	LCD_vidCenterString("Closing system!", 0);
	DIO_u8setPinVal(LED_PORT, RED_LED, HIGH);
	DIO_u8setPinVal(LED_PORT, GREEN_LED, LOW);
	DCMotor_vidTurnLeft(2);
}

void SafeLock_vidLogin()
{
	while(1)
	{
		LCD_vidClearDisplay();

		LCD_vidCenterString("Enter Password!", 0);

		LCD_vidGoToXY(6, 1);

		while((KeyPad_u8Pressed()!='=')&&(local_u8Counter<4))
		{
			if((KeyPad_u8Pressed()>=0)&&(KeyPad_u8Pressed()<10))
			{
				LCD_u8sendData('*');
				local_u8Numbers[local_u8Counter] = KeyPad_u8Pressed();
				local_u8Counter++;
			}

			else
				continue;
		}

		while(KeyPad_u8Pressed() != '=');

		if(KeyPad_u8Pressed() == '=')
		{
			for(u16 iterate=1; local_u8Counter>0; local_u8Counter--, iterate*=10)
			{
				local_u16Num1 += local_u8Numbers[local_u8Counter-1] * iterate;
				local_u8Numbers[local_u8Counter-1] = 0;
			}
		}


		if(local_u16Num1 == Password)
		{
			SafeLock_vidOpenSystem();
			while((KeyPad_u8Pressed() != 'c')||(KeyPad_u8Pressed() != '/'));


			if(KeyPad_u8Pressed() == '/')
			{
				SafeLock_vidChangePassword();
			}

			else if(KeyPad_u8Pressed() == 'c')
			{
				SafeLock_vidCloseSystem();
				continue;
			}
		}

		else if(local_u16Num1 != Password)
		{
			if(local_u8TrialsCounter<3)
			{
			LCD_vidGlitchString("Wrong password!");
			_delay_ms(1000);
			LCD_vidCenterString("Try again");
			local_u8TrialsCounter++;
			}

			else
			{
				LCD_vidGlitchString("Too much trials!");
				_delay_ms(2000);
				LCD_vidGlitchString("System Locked!");
				while(1);
			}
		}
	}
}
