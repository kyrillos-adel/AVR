/*
 * KeyPad_int.h
 *
 *  Created on: Sep 24, 2021
 *      Author: Kero Adel
 */

#include "../../Libs/stdtypes.h"

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_

void KeyPad_vidInit(void);

u8 KeyPad_u8Pressed(void);

u8 KeyPad_u8IsPressed(u8 copy_u8ID);

const u8* KeyPad_u8cpGetAll(void);

#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
