#ifndef APP3_APP_H_
#define APP3_APP_H_

typedef struct  
{
	u_int_16 ON_TIME;
	u_int_16 OFF_TIME;
}ST_Blink_t;

#define PORTA_LED_PINS			0b01010101
#define PORTA_LED123			0b00010101
#define PORTA_LED12 			0b00000101
#define PORTA_LED1  			0b00000001
#define PORTA_LED234			0b01010100
#define PORTA_LED34 			0b01010000
#define PORTA_LED4  			0b01000000

void App3_Init(void);
void App3(void);


#endif