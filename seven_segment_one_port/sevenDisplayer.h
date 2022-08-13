
#ifndef SEVENDISPLAYER_H_
#define SEVENDISPLAYER_H_

#define S_SEGMENT_DDR DDRC
#define S_SEGMENT_GND DDRA
#define GND_PORT PORTA
#define S_SEGMENT_PORT PORTC

void sevenSegInit(void);
void display(int number, int period);
void displaySec(int number);
void displayShort(int number);

#endif /* SEVENDISPLAYER_H_ */
