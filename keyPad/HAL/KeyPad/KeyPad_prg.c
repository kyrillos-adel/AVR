/*
 * KeyPad_prg.c
 *
 *  Created on: Sep 24, 2021
 *      Author: Kero Adel
 */
#include "../../Libs/stdtypes.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "KeyPad_int.h"
#include "KeyPad_config.h"
#include "util/delay.h"

#define NO_KEY_PRESSED 0

u8 KEYPAD_u8KeyPadMap[KEYPAD_ROWS][KEYPAD_COLUMNS] = 	{{1, 2, 3, 4},
														 {5, 6, 7, 8},
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 {9, 10, 11, 12},
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 {13, 14, 15, 16}};


void KeyPad_vidInit(void)
{
	DIO_u8setPinDir(KEYPAD_PORT, KEYPAD_ROW_1, INPUT);
	DIO_u8setPinDir(KEYPAD_PORT, KEYPAD_ROW_2, INPUT);
	DIO_u8setPinDir(KEYPAD_PORT, KEYPAD_ROW_3, INPUT);
	DIO_u8setPinDir(KEYPAD_PORT, KEYPAD_ROW_4, INPUT);

	DIO_u8setPinDir(KEYPAD_PORT, KEYPAD_COLUMN_1, OUTPUT);
	DIO_u8setPinDir(KEYPAD_PORT, KEYPAD_COLUMN_2, OUTPUT);
	DIO_u8setPinDir(KEYPAD_PORT, KEYPAD_COLUMN_3, OUTPUT);
	DIO_u8setPinDir(KEYPAD_PORT, KEYPAD_COLUMN_4, OUTPUT);

	//Enable PULLUP resistors
	DIO_u8setPinVal(KEYPAD_PORT, KEYPAD_ROW_1, HIGH);
	DIO_u8setPinVal(KEYPAD_PORT, KEYPAD_ROW_2, HIGH);
	DIO_u8setPinVal(KEYPAD_PORT, KEYPAD_ROW_3, HIGH);
	DIO_u8setPinVal(KEYPAD_PORT, KEYPAD_ROW_4, HIGH);

	DIO_u8setPinVal(KEYPAD_PORT, KEYPAD_COLUMN_1, HIGH);
	DIO_u8setPinVal(KEYPAD_PORT, KEYPAD_COLUMN_2, HIGH);
	DIO_u8setPinVal(KEYPAD_PORT, KEYPAD_COLUMN_3, HIGH);
	DIO_u8setPinVal(KEYPAD_PORT, KEYPAD_COLUMN_4, HIGH);
}

u8 KeyPad_u8Pressed(void)
{
	u8 local_u8keyPressed = NO_KEY_PRESSED;
	u8 local_u8currentColumn;
	u8 local_u8currentRow;
	u8 local_u8currentRowStatus;

	for(local_u8currentColumn = KEYPAD_COLUMN_START; local_u8currentColumn <= KEYPAD_COLUMN_END; local_u8currentColumn++)
	{
		DIO_u8setPinVal(KEYPAD_PORT, local_u8currentColumn, LOW);

		for(local_u8currentRow = KEYPAD_ROW_START; local_u8currentRow <= KEYPAD_ROW_END; local_u8currentRow++)
		{
			DIO_u8getPinVal(KEYPAD_PORT, local_u8currentRow, &local_u8currentRowStatus);

			if(local_u8currentRowStatus == LOW)
			{
				//local_u8keyPressed = (((local_u8currentRow - KEYPAD_ROW_START) * KEYPAD_COLUMNS) + (local_u8currentColumn - KEYPAD_COLUMN_START));

				local_u8keyPressed = KEYPAD_u8KeyPadMap[local_u8currentRow-KEYPAD_ROW_START][local_u8currentColumn-KEYPAD_COLUMN_START];

				_delay_ms(5);
				while(local_u8currentRowStatus == LOW)
				{
					DIO_u8getPinVal(KEYPAD_PORT, local_u8currentRow, &local_u8currentRowStatus);
				}
				_delay_ms(5);
			}
		}

		DIO_u8setPinVal(KEYPAD_PORT, local_u8currentColumn, HIGH);
	}


	return local_u8keyPressed;
}
