#define F_CPU 8000000UL 
#include <util/delay.h>

#include "std_types.h"

#include "LED_interface.h"
#include "SW_interface.h"

/*================= Global Variables ==================*/

uint8_t_ buttonState, buttonPress=0;

ST_LED LED1 = {LED_PORT_A, LED_PIN_1, LED_Enabled};
ST_LED LED2 = {LED_PORT_A, LED_PIN_2, LED_Enabled};
ST_LED LED3 = {LED_PORT_A, LED_PIN_3, LED_Enabled};
ST_LED LED4 = {LED_PORT_A, LED_PIN_4, LED_Enabled};
	
ST_Switch button = {SW_PORT_A, SW_PIN_0, SW_PullDown, SW_Enabled};

/*=============== Function Prototypes =================*/
void APP_init(void)
{
	LED_init(&LED1);
	LED_init(&LED2);
	LED_init(&LED3);
	LED_init(&LED4);
	
	SW_init(&button);
}

void APP_start(void)
{
	SW_ReadSwitch(&button, &buttonState);

	if(buttonState == SW_Pressed)
	{
		buttonPress++;
		switch(buttonPress)
		{
			case 1:
			{
				LED_setState(&LED1, LED_ON);
				break;
			}			
			case 2:
			{
				LED_setState(&LED2, LED_ON);
				break;
			}			
			case 3:
			{
				LED_setState(&LED3, LED_ON);
				break;
			}			
			case 4:
			{
				LED_setState(&LED4, LED_ON);
				break;
			}			
			case 5:
			{
				LED_setState(&LED1, LED_OFF);
				break;
			}			
			case 6:
			{
				LED_setState(&LED2, LED_OFF);
				break;
			}			
			case 7:
			{
				LED_setState(&LED3, LED_OFF);
				break;
			}			
			case 8:
			{
				LED_setState(&LED4, LED_OFF);
				buttonPress = 0;
				break;
			}
			default:
			{
				/* Turnoff all LEDs */
				LED_setState(&LED1, LED_OFF);
				LED_setState(&LED2, LED_OFF);
				LED_setState(&LED3, LED_OFF);
				LED_setState(&LED4, LED_OFF);
				buttonPress = 0;
				break;				
			}
			
		}
		//for(int i=0; i<70000; i++);
		_delay_ms(300);
	}	
}