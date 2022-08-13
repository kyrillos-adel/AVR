/*
 * SPI_Init.h
 *
 *  Created on: Nov 19, 2021
 *      Author: Kero Adel
 */
#include "Libs/stdtypes.h"

#ifndef SPI_INIT_H_
#define SPI_INIT_H_



void SPI_vidmasterInit(void);
void SPI_vidslaveInit(void);

u8 SPI_u8tranceiver(u8 copy_u8data);



#endif /* SPI_INIT_H_ */
