#define F_CPU 1000000UL

#include "../Services/STD_TYPES.h"

#include "../SYSTEM/PORTS/PORTS_interface.h"
#include "../SYSTEM/INT/int.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/SW/SW_interface.h"

#include "App.h"

/*================= Global Variables ==================*/

ST_Blink_t Global_BlinkModes[] = {{100, 900},
{200, 800},
{300, 700},
{500, 500},
{800, 200}};

uint8_t button0Press=0, BlinkMode = 0;
extern ST_LED LED1, LED2, LED3, LED4;
extern ST_Switch button0, button1;

void Button0_Callback(void);
void Button1_Callback(void);

void TIM_Callback(void);
/*=============== Function Prototypes =================*/
void App3_Init(void)
{
	PORT_voidInit();
	SW_EXTIMode(&button0, SW_FallingEdge, &Button0_Callback);
	SW_EXTIMode(&button1, SW_FallingEdge, &Button1_Callback);
	sei();
}

void App3(void)
{
	switch(button0Press)
	{
		case 1:
		LED_BlinkPort(LED_PORT, PORTA_LED1, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
		break;
		
		case 2:
		LED_BlinkPort(LED_PORT, PORTA_LED12, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
		break;
		
		case 3:
		LED_BlinkPort(LED_PORT, PORTA_LED123, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
		break;
		
		case 4:
		LED_BlinkPort(LED_PORT, PORTA_LED_PINS, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
		break;
		
		case 5:
		LED_BlinkPort(LED_PORT, PORTA_LED234, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
		break;
		case 6:
		LED_BlinkPort(LED_PORT, PORTA_LED34, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
		break;
		case 7:
		LED_BlinkPort(LED_PORT, PORTA_LED4, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
		break;
		case 8:
		LED_setLEDPortState(LED_PORT, PORTA_LED_PINS, LED_OFF);
		button0Press = 0;
		break;
	}

}

void Button0_Callback(void)
{
	button0Press++;
}

void Button1_Callback(void)
{
	BlinkMode++;
	if(BlinkMode>4) BlinkMode = 0;
}

