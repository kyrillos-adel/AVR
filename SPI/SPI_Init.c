#include "Libs/stdtypes.h"
#include "avr/io.h"


void SPI_vidmasterInit(void){

	/*
	 * 1.Master
	 * 2.CLK
	 * 3.Polarity and check
	 * 4.Enable SPI
	 * */

	SPCR |= (1<<MSTR) | (1<<SPE) | (1<<CPHA) | (1<<SPR0) | (1<<SPR1);

}
void SPI_vidslaveInit(void){
	SPCR |= (1<<SPE) | (1<<CPHA) | (1<<SPR0);
}

u8 SPI_u8tranceiver(u8 copy_u8data){
	SPDR = copy_u8data;

	while(SPSR & (1<<SPIF) == 0);

	return SPDR;
}
