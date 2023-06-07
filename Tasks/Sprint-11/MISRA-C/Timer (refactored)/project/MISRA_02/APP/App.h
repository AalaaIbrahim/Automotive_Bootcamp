#ifndef APP_APP_H_
#define APP_APP_H_

#include "std_types.h"

typedef struct
{
	uint16_t_ ON_TIME;
	uint16_t_ OFF_TIME;
}ST_Blink_t;

#define LED_PORT				LED_PORT_A
#define PORTA_LED_PINS			0b00011110
#define PORTA_LED123			0b00001110
#define PORTA_LED12 			0b00000110
#define PORTA_LED1  			0b00000010
#define PORTA_LED234			0b00011100
#define PORTA_LED34 			0b00011000
#define PORTA_LED4  			0b00010000


void APP_init(void);
void APP_start(void);


#endif