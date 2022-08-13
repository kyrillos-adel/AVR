/*
 * LCD_int.h
 *
 *  Created on: Sep 23, 2021
 *      Author: Kero Adel
 */

#include "../../Libs/stdtypes.h"

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_


u8 LCD_u8sendData(u8 copy_u8data);
u8 LCD_u8sendCommand(u8 copy_u8command);

void LCD_vidWriteMyName(void);

void LCD_vidInit(void);

void LCD_vidSendNumber(s32 copy_u8Number);

void LCD_vidSendString(const u8* copy_pcString);
void LCD_vidGoToXY(u8 copy_u8XPos, u8 copy_u8YPos);

void LCD_vidWriteSpecialCharecter(u8 *copy_u8pPattern, u8 copy_u8BlockNo, u8 copy_u8XPos, u8 copy_u8YPos);

void LCD_vidClearDisplay(void);

void LCD_vidReturnHome(void);

void LCD_vidShiftRight(void);

void LCD_vidShiftLeft(void);

void LCD_vidGlitchString(const u8* copy_pcString);

void LCD_vidSinWaveString(const u8* copy_pcString);

void LCD_vidSendNumberBottomRight(s32 copy_u8Number);

void LCD_vidShiftRightCursor(void);

void LCD_vidShiftLeftCursor(void);

#endif /* HAL_LCD_LCD_INT_H_ */
