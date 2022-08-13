/*
 * Buzzer_prg.c
 *
 *  Created on: Sep 30, 2021
 *      Author: Kero Adel
 */
#include "../../MCAL/DIO/DIO_int.h"
#include "../../Libs/stdtypes.h"
#include "Buzzer_config.h"
#include "util/delay.h"

void Buzzer_vidInit()
{
	DIO_u8setPinDir(BUZZER_PORT, BUZZER_PIN, OUTPUT);
	DIO_u8setPinVal(BUZZER_PORT, BUZZER_PIN, LOW);
}

void Buzzer_vidTurnOn(u8 copy_u8Period)
{
	DIO_u8setPinVal(BUZZER_PORT, BUZZER_PIN, HIGH);

	_delay_ms(copy_u8Period*1000);

	DIO_u8setPinVal(BUZZER_PORT, BUZZER_PIN, LOW);
}

void Buzzer_vidAlarm(u8 copy_u8Period, u8 copy_u8OnOffPeriodIn_ms)
{
	for(u16 counter=0; counter<((1000*copy_u8Period)/(2*copy_u8OnOffPeriodIn_ms)); counter++)
	{
		DIO_u8setPinVal(BUZZER_PORT, BUZZER_PIN, HIGH);

		_delay_ms(copy_u8OnOffPeriodIn_ms);

		DIO_u8setPinVal(BUZZER_PORT, BUZZER_PIN, LOW);

		_delay_ms(copy_u8OnOffPeriodIn_ms);
	}
}
