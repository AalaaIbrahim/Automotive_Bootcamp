#ifndef APP_APP_H_
#define APP_APP_H_

#include "std_types.h"

typedef struct
{
	uint16_t_ ON_TIME;
	uint16_t_ OFF_TIME;
}ST_Blink_t;

#define LED_PORT				LED_PORT_A
#define PORTA_LED_PINS			0x1E
#define PORTA_LED123			0x0E
#define PORTA_LED12 			0x06
#define PORTA_LED1  			0x02
#define PORTA_LED234			0x1C
#define PORTA_LED34 			0x18
#define PORTA_LED4  			0x10


void APP_init(void);
void APP_start(void);


#endif