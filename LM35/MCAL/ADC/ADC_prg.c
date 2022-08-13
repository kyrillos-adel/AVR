/*
 * ADC_prg.c
 *
 *  Created on: Oct 15, 2021
 *      Author: Kero Adel
 */
#include "ADC_int.h"
#include "ADC_reg.h"
#include "../DIO/DIO_int.h"
#include "../../Libs/bitmath.h"


void ADC_vidADCInit(void)
{
	/*ENABLE*/
	SET_BIT(ADCSRA_REG, 7);

	/*VRef*/
	SET_BIT(ADMUX_REG, 6);
	CLR_BIT(ADMUX_REG, 7);

	/*Res = 10 bit*/
	CLR_BIT(ADMUX_REG, 5);

	/*Single Conv*/
	CLR_BIT(ADCSRA_REG, 5);

	/*Prescalar*/
	SET_BIT(ADCSRA_REG, 0);
	CLR_BIT(ADCSRA_REG, 1);
	SET_BIT(ADCSRA_REG, 2);
}



u16 ADC_u8ADCRead(u8 copy_u8Channel)
{
	u16 local_u16DigitalRead;
	ADMUX_REG &= 0b11100000;
	ADMUX_REG |= copy_u8Channel;

	SET_BIT(ADCSRA_REG, 6);

	while(GET_BIT(ADCSRA_REG, 4)==0);

	SET_BIT(ADCSRA_REG, 4);

	local_u16DigitalRead = ADCL_REG;
	local_u16DigitalRead |= ADCH_REG<<8;

	return local_u16DigitalRead;
}



