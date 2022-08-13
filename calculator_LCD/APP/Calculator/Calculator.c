/*
 * Calculator.c
 *
 *  Created on: Sep 28, 2021
 *      Author: Kero Adel
 */

#include "../../Libs/stdtypes.h"



s32 Calculator_s32Sum(s32 copy_s32Num1, s32 copy_s32Num2)
{
	return (copy_s32Num1 + copy_s32Num2);
}

s32 Calculator_s32Sub(s32 copy_s32Minuend, s32 copy_s32Subtrahend)
{
	return (copy_s32Minuend - copy_s32Subtrahend);
}

s32 Calculator_s32Mul(s32 copy_s32Num1, s32 copy_s32Num2)
{
	return (copy_s32Num1 * copy_s32Num2);
}

s32 Calculator_s32Div(s32 copy_s32Divident, s32 copy_s32Divisor)
{
	if(copy_s32Divisor != 0)
	{
		return (copy_s32Divident / copy_s32Divisor);
	}

	else
	{
		return -1;
	}
}
