/*
 * Buzzer_int.h
 *
 *  Created on: Sep 30, 2021
 *      Author: Kero Adel
 */
#include "../../Libs/stdtypes.h"
#ifndef HAL_BUZZER_BUZZER_INT_H_
#define HAL_BUZZER_BUZZER_INT_H_

void Buzzer_vidInit();

void Buzzer_vidTurnOn(u8 copy_u8Period);

void Buzzer_vidAlarm(u8 copy_u8Period, u8 copy_u8OnOffPeriod);



#endif /* HAL_BUZZER_BUZZER_INT_H_ */
