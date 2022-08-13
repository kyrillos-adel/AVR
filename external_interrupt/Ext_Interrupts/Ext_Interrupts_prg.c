/*
 * Ext_Interrupts_prg.c
 *
 *  Created on: Oct 21, 2021
 *      Author: Kyrillos Adel
 */

#include "Ext_Interrupts_int.h"
#include "Ext_Interrupts_regs.h"

void Ext_Interrupts_vidGlobalINTEnable(u8 copy_u8Enable)
{
	/*Copy SREG to a local variable*/
	u8 local_u8CopyReg = SREG;

	/*Modify the local variable*/
	local_u8CopyReg &= ~(1<<7);
	local_u8CopyReg |= (copy_u8Enable<<7);

	/*Copy the local variable to SREG*/
	SREG = local_u8CopyReg;
}

void Ext_Interrupts_vidINTEnable(u8 copy_u8INTNo, u8 copy_u8Status)
{
	/*Copy GICR to a local variable*/
	u8 local_u8RegCopy = GICR;

	/*Modify the local variable*/
	local_u8RegCopy &= ~(INT_STATUS_CLEAR<<copy_u8INTNo);
	local_u8RegCopy |= (copy_u8Status<<copy_u8INTNo);

	/*Copy the local variable to GICR*/
	GICR = local_u8RegCopy;
}


void Ext_Interrupts_vidINT0Mode(INT_0_1_Modes copy_modesINT0Mode)
{
	/*Copy MCUCR to a local variable*/
	u8 local_u8RegCopy = MCUCR;

	/*Modify the local variable*/
	local_u8RegCopy &= ~(INT_0_1_MODE_CLEAR<<0);
	local_u8RegCopy |= (copy_modesINT0Mode<<0);

	/*Copy the local variable to MCUCR*/
	MCUCR = local_u8RegCopy;
}

void Ext_Interrupts_vidINT1Mode(INT_0_1_Modes copy_modesINT1Mode)
{
	/*Copy MCUCR to a local variable*/
	u8 local_u8RegCopy = MCUCR;

	/*Modify the local variable*/
	local_u8RegCopy &= ~(INT_0_1_MODE_CLEAR<<2);
	local_u8RegCopy |= (copy_modesINT1Mode<<2);

	/*Copy the local variable to MCUCR*/
	MCUCR = local_u8RegCopy;
}

void Ext_Interrupts_vidINT2Mode(INT_2_Modes copy_modesINT2Mode)
{
	/*Copy MCUCSR to a local variable*/
	u8 local_u8RegCopy = MCUCSR;

	/*Modify the local variable*/
	local_u8RegCopy &= ~(INT_2_MODE_CLEAR<<6);
	local_u8RegCopy |= (copy_modesINT2Mode<<6);

	/*Copy the local variable to MCUCSR*/
	MCUCSR = local_u8RegCopy;
}

