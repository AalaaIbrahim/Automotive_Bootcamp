#define F_CPU 1000000UL 
#include <util/delay.h>

#include "../Services/STD_TYPES.h"

#include "../MCAL/PORTS/PORTS_interface.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/SW/SW_interface.h"

/*================= Global Variables ==================*/

uint8_t buttonState, buttonPress=0;
extern ST_LED LED1, LED2, LED3, LED4;
extern ST_Switch button;

/*=============== Function Prototypes =================*/
void App_Init(void)
{
	PORT_voidInit();
}

void App(void)
{
	SW_ReadSwitch(&button, &buttonState);

	if(buttonState == SW_Pressed)
	{
		buttonPress++;
		switch(buttonPress)
		{
			case 1:
			LED_setState(&LED1, LED_ON);
			break;
			case 2:
			LED_setState(&LED2, LED_ON);
			break;
			case 3:
			LED_setState(&LED3, LED_ON);
			break;
			case 4:
			LED_setState(&LED4, LED_ON);
			break;
			case 5:
			LED_setState(&LED1, LED_OFF);
			break;
			case 6:
			LED_setState(&LED2, LED_OFF);
			break;
			case 7:
			LED_setState(&LED3, LED_OFF);
			break;
			case 8:
			LED_setState(&LED4, LED_OFF);
			buttonPress = 0;
			break;
		}
		_delay_ms(300);
	}	
}