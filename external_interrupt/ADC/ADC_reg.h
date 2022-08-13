/*
 * ADC_reg.h
 *
 *  Created on: Oct 15, 2021
 *      Author: Kero Adel
 */

#ifndef ADC_ADC_REG_H_
#define ADC_ADC_REG_H_

#define ADMUX_REG				(*((volatile u8*)0x27))
#define ADCSRA_REG				(*((volatile u8*)0x20))
#define SFIOR_REG				(*((volatile u8*)0x50))
#define ADCL_REG				(*((volatile u8*)0x24))
#define ADCH_REG				(*((volatile u8*)0x25))

#endif /* ADC_ADC_REG_H_ */
