
#include "avr/io.h"
#include "Libs/stdtypes.h"
#include "util/delay.h"

#define ANGLE_0			600
#define ANGLE_180		2600


void main(void){

	u16 Angle_ticks;

	/*Set OC1A pin as output*/
	DDRD = (1<<PD5);

	/*Select timer mode*/
	TCCR1A |= (1<<COM1A1);


	/*Select output compare mode
	 *clear on compare match and set on top
	 */
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM12) | (1<<WGM13);

	/*Inetial Ton ticks*/
	OCR1A = 1000;

	ICR1 = 20000;

	/*Select prescaler*/
	TCCR1B |= (1<<CS11);

	while(1){

		for(Angle_ticks=ANGLE_0; Angle_ticks<ANGLE_180; Angle_ticks+=2000){

			OCR1A = Angle_ticks;
			_delay_ms(500);
		}

		for(Angle_ticks=ANGLE_180; Angle_ticks>ANGLE_0; Angle_ticks-=2000){

			OCR1A = Angle_ticks;
			_delay_ms(500);
		}
	}




}





//void main(void){
//
//	u8 Ton_ticks;
//
//	/*Set OC0 pin as output*/
//	DDRB = (1<<PB3);
//
//	/*Select timer mode*/
//	TCCR0 |= (1<<3) | (1<<6);
//
//
//	/*Select output compare mode
//	 *clear on compare match and set on top
//	 */
//	TCCR0 |= (1<<5);
//
//	/*Inetial Ton ticks*/
//	OCR0 = 0;
//
//	/*Select prescaler*/
//	TCCR0 |= (1<<0);
//
//	while(1){
//
//		for(Ton_ticks=0; Ton_ticks<255; Ton_ticks++){
//
//			OCR0 = Ton_ticks;
//			_delay_ms(25);
//		}
//
//		for(Ton_ticks=255; Ton_ticks>0; Ton_ticks--){
//
//			OCR0 = Ton_ticks;
//			_delay_ms(25);
//		}
//	}
//
//
//
//
//}
