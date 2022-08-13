/*
 * Interrupts_regs.h
 *
 *  Created on: Oct 13, 2021
 *      Author: Kero Adel
 */

#ifndef EXT_INTERRUPTS_EXT_INTERRUPTS_REGS_H_
#define EXT_INTERRUPTS_EXT_INTERRUPTS_REGS_H_

#define MCUCR			(*((volatile u8*)0x55))
#define MCUCSR			(*((volatile u8*)0x54))
#define GICR			(*((volatile u8*)0x5B))
#define GIFR			(*((volatile u8*)0x5A))
#define SREG			(*((volatile u8*)0x5F))

#define ISC_INT0_0			PIN_0
#define ISC_INT0_1			PIN_1
#define ISC_INT1_0			PIN_2
#define ISC_INT1_1			PIN_3

#define ISC_INT2			PIN_6

#endif /* EXT_INTERRUPTS_EXT_INTERRUPTS_REGS_H_ */
