
#include "../../Libs/stdtypes.h"
#include "../..//MCAL/DIO/DIO_int.h"
#include "util/delay.h"

#include "LCD_config.h"
#include "LCD_int.h"

void LCD_vidWriteSpecialCharecter(u8 *copy_u8pPattern, u8 copy_u8BlockNo, u8 copy_u8XPos, u8 copy_u8YPos)
{
	u8 local_u8CGRAMAdress = copy_u8BlockNo * 8, local_u8Counter;

	_delay_ms(1);
	LCD_u8sendCommand(local_u8CGRAMAdress + 64);
	_delay_ms(1);
	for(local_u8Counter=0; local_u8Counter<8; local_u8Counter++)
	{
		LCD_u8sendData(copy_u8pPattern[local_u8Counter]);
		_delay_ms(1);
	}

	LCD_vidGoToXY(copy_u8XPos, copy_u8YPos);
	_delay_ms(1);
	LCD_u8sendData(copy_u8BlockNo);
	_delay_ms(1);
}


u8 LCD_u8sendData(u8 copy_u8command)
{
	DIO_u8setPinVal(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);

	DIO_u8setPinVal(LCD_CTRL_PORT, LCD_RW_PIN, LOW);

	DIO_u8setPortVal(LCD_DATA_PORT, copy_u8command);

	DIO_u8setPinVal(LCD_CTRL_PORT, LCD_E_PIN, HIGH);
	_delay_ms(2);
	DIO_u8setPinVal(LCD_CTRL_PORT, LCD_E_PIN, LOW);

	return 0;
}
u8 LCD_u8sendCommand(u8 copy_u8data)
{
	DIO_u8setPinVal(LCD_CTRL_PORT, LCD_RS_PIN, LOW);

	DIO_u8setPinVal(LCD_CTRL_PORT, LCD_RW_PIN, LOW);

	DIO_u8setPortVal(LCD_DATA_PORT, copy_u8data);

	DIO_u8setPinVal(LCD_CTRL_PORT, LCD_E_PIN, HIGH);
	_delay_ms(2);
	DIO_u8setPinVal(LCD_CTRL_PORT, LCD_E_PIN, LOW);

	return 0;
}

void LCD_vidInit(void)
{
	DIO_u8setPortDir(LCD_DATA_PORT, FULL_OUTPUT);
	DIO_u8setPinDir(LCD_CTRL_PORT, LCD_E_PIN, OUTPUT);
	DIO_u8setPinDir(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);
	DIO_u8setPinDir(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);

	_delay_ms(40);						//Wait more than 30 ms after power on

	LCD_u8sendCommand(0b00111000);		//Function set cmd: 2 lines, 5x8 font size

	LCD_u8sendCommand(0b00001110);		//Function set cmd: Display enable, disable cursor, disable blinking cursor

	LCD_u8sendCommand(1);				//Function set: clear display


}

void LCD_vidStarterString(const u8* copy_pcString)
{
	u8 counter = 0;
	LCD_vidGoToXY(3, 0);
	while(copy_pcString[counter] != '\0')
	{
		LCD_u8sendData(copy_pcString[counter]);
		counter++;
		_delay_ms(150);
	}
	LCD_vidShiftRight();
	_delay_ms(100);
}

void LCD_vidSendString(const u8* copy_pu8String)
{
	u8 local_u8Counter = 0;
	while(copy_pu8String[local_u8Counter] != '\0')
	{
		LCD_u8sendData(copy_pu8String[local_u8Counter]);
		local_u8Counter++;
	}
}

void LCD_vidCenterString(const u8* copy_pu8String, u8 copy_u8YPos)
{
	u8 local_u8StringCuonter = 0;
	while(copy_pu8String[local_u8StringCuonter] != '\0')
	{
		local_u8StringCuonter++;
	}

	u8 local_u8Offset = (16 - local_u8StringCuonter)/2;

	LCD_vidGoToXY(local_u8Offset, copy_u8YPos);

	LCD_vidSendString(copy_pu8String);
}

void LCD_vidGoToXY(u8 copy_u8XPos, u8 copy_u8YPos)
{
	u8 address;

	if(copy_u8YPos == 0){
		address = copy_u8XPos;
	}

	else if(copy_u8YPos == 1){
		address = copy_u8XPos + 0x40;
	}

	LCD_u8sendCommand(128 + address);

}

void LCD_vidShiftRightCursor(void)
{
	LCD_u8sendCommand(0b00000001);
}

void LCD_vidShiftLeftCursor(void)
{
	LCD_u8sendCommand(0b00000000);
}

void LCD_vidSendNumberBottomRight(s32 copy_u8Number)
{
	s8 local_u8Length = 0;
	u8 local_u8Nums[32];
	LCD_vidGoToXY(15, 1);

	if(copy_u8Number==0)
	{
		LCD_u8sendData('0');
		LCD_vidShiftLeftCursor();
	}

	else if(copy_u8Number<0)
	{
		copy_u8Number *= (-1);

		while(copy_u8Number != 0)
		{
			local_u8Nums[local_u8Length] = copy_u8Number % 10;
			copy_u8Number /= 10;
			local_u8Length++;
		}
		for(u8 counter=0; counter<=local_u8Length; counter++)
		{
			LCD_u8sendData(local_u8Nums[counter] + '0');
			LCD_vidShiftLeftCursor();
		}
		LCD_u8sendData('-');
		LCD_vidShiftLeftCursor();
	}

	else
	{
		while(copy_u8Number != 0)
		{
			local_u8Length++;
			local_u8Nums[local_u8Length] = copy_u8Number % 10;
			copy_u8Number /= 10;
		}
		for(u8 counter=0; counter<=local_u8Length; counter++)
		{
			LCD_u8sendData(local_u8Nums[counter] + '0');
			LCD_vidShiftLeftCursor();
		}
	}
}

void LCD_vidSendNumber(s32 copy_u8Number)
{
	s8 local_u8Length = 0;
	u8 local_u8Nums[32];

	if(copy_u8Number==0)
	{
		LCD_u8sendData('0');
	}

	else if(copy_u8Number<0)
	{
		copy_u8Number *= (-1);
		LCD_u8sendData('-');

		while(copy_u8Number != 0)
		{
			local_u8Nums[local_u8Length] = copy_u8Number % 10;
			copy_u8Number /= 10;
			local_u8Length++;
		}
	}

	else
	{
		while(copy_u8Number != 0)
		{
			local_u8Length++;
			local_u8Nums[local_u8Length] = copy_u8Number % 10;
			copy_u8Number /= 10;
		}
	}

	for(; local_u8Length>0; local_u8Length--)
	{
		LCD_u8sendData(local_u8Nums[local_u8Length] + '0');
	}

}

void LCD_vidClearDisplay(void)
{
	LCD_u8sendCommand(0b00000001);
}

void LCD_vidReturnHome(void)
{
	LCD_u8sendCommand(0b00000010);
}

void LCD_vidShiftRight(void)
{
	LCD_u8sendCommand(0b00011100);
}

void LCD_vidShiftLeft(void)
{
	LCD_u8sendCommand(0b00011000);

}

void LCD_vidSinWaveString(const u8* copy_pcString)
{
	u8 local_u8counter = 0;
	u8 local_u8XPos = 2;
	u8 local_u8Iterate = 0;

	while((copy_pcString[local_u8counter] != '\0')&&local_u8Iterate<10)
	{
		if(local_u8counter/2)
		{
			LCD_vidGoToXY(local_u8XPos, 0);
		}

		else
		{
			LCD_vidGoToXY(local_u8XPos, 1);
		}

		LCD_u8sendData(copy_pcString[local_u8counter]);
		local_u8counter++;
		local_u8XPos++;
		_delay_ms(150);
	}
}

void LCD_vidGlitchString(const u8* copy_pcString)
{
	LCD_vidCenterString(copy_pcString, 0);
	_delay_ms(50);
	LCD_vidShiftLeft();
	_delay_ms(50);
	LCD_vidShiftRight();
	_delay_ms(50);
	LCD_vidClearDisplay();
	LCD_vidCenterString(copy_pcString, 1);
	LCD_vidShiftRight();
	_delay_ms(50);
	LCD_vidShiftRight();
	_delay_ms(50);
	LCD_vidClearDisplay();
	LCD_vidCenterString(copy_pcString, 0);
	LCD_vidShiftLeft();
	_delay_ms(50);
	LCD_vidShiftRight();

}

//void LCD_vidWriteMyName(void)
//{
//	u8 kaf[] = {0b00011111,
//			0b00010000,
//			0b00001000,
//			0b00000100,
//			0b00000010,
//			0b00011111,
//			0b00000000,
//			0b00000000};
//
//	LCD_vidWriteSpecialCharecter(kaf, 0, 15, 1);
//
//	u8 kaf2[] = {0b00000000,
//			0b00000000,
//			0b00000000,
//			0b00000001,
//			0b00000001,
//			0b00011111,
//			0b00001010,
//			0b00000000};
//
//	LCD_vidWriteSpecialCharecter(kaf2, 1, 14, 1);
//
//
//	u8 kaf3[] = {0b00000000,
//			0b00000000,
//			0b00000000,
//			0b00000001,
//			0b00000001,
//			0b00000010,
//			0b00011100,
//			0b00000000};
//
//	LCD_vidWriteSpecialCharecter(kaf3, 2, 13, 1);
//
//
//	u8 kaf4[] = {0b00000001,
//			0b00000001,
//			0b00000001,
//			0b00000001,
//			0b00000001,
//			0b00011111,
//			0b00000000,
//			0b00000000};
//
//	LCD_vidWriteSpecialCharecter(kaf4, 3, 12, 1);
//
//
//	u8 kaf5[] = {0b00000000,
//			0b00000000,
//			0b00000000,
//			0b00000000,
//			0b00010101,
//			0b00011111,
//			0b00010000,
//			0b00000000};
//
//	LCD_vidWriteSpecialCharecter(kaf5, 4, 11, 1);
//
//	u8 kaf6[] = {0b00000000,
//			0b00000000,
//			0b00000000,
//			0b00000000,
//			0b00001000,
//			0b00001000,
//			0b00000111,
//			0b00000000};
//
//	LCD_vidWriteSpecialCharecter(kaf6, 5, 10, 1);
//}





