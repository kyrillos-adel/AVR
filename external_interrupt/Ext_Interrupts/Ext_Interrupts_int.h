/*
 * Ext_Interrupts_int.h
 *
 *  Created on: Oct 21, 2021
 *      Author: Kyrillos Adel
 */


#ifndef EXT_INTERRUPTS_EXT_INTERRUPTS_INT_H_
#define EXT_INTERRUPTS_EXT_INTERRUPTS_INT_H_

#define			INT_ENABLE		0b1
#define 		INT_DISABLE		0b0

#define			INT0_CONTROL	6
#define			INT1_CONTROL	7
#define			INT2_CONTROL	5

#define			INT0_MODE


typedef enum{
	low_level_0_1			=	0b00,
	any_logical_change_0_1	=	0b01,
	falling_edge_0_1		=	0b10,
	rising_edge_0_1			=	0b11
}INT_0_1_Modes;

typedef enum{
	falling_edge		=	0b0,
	rising_edge			=	0b1
}INT_2_Modes;


#define INT_STATUS_CLEAR			0b1
#define INT_2_MODE_CLEAR			0b1
#define INT_0_1_MODE_CLEAR			0b11

void Ext_Interrupts_vidINT0Mode(INT_0_1_Modes copy_modesINT0Mode);
void Ext_Interrupts_vidINT1Mode(INT_0_1_Modes copy_modesINT1Mode);
void Ext_Interrupts_vidINT2Mode(INT_2_Modes copy_modesINT2Mode);

void Ext_Interrupts_vidINTEnable(u8 copy_u8INTNo, u8 copy_u8Status);

void Ext_Interrupts_vidGlobalINTEnable(void);


#endif /* EXT_INTERRUPTS_EXT_INTERRUPTS_INT_H_ */
