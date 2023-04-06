
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/PORT/PORT_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LED/LED_interface.h"
#include "HAL/SW/SW_interface.h"

uint8_t buttonState, buttonPress=0;

ST_Switch button = {DIO_PORT_A, DIO_PIN_0, SW_PullUp, SW_Enabled};
ST_LED LED1 = {DIO_PORT_A, DIO_PIN_1, LED_Enabled};
ST_LED LED2 = {DIO_PORT_A, DIO_PIN_2, LED_Enabled};
ST_LED LED3 = {DIO_PORT_A, DIO_PIN_3, LED_Enabled};
ST_LED LED4 = {DIO_PORT_A, DIO_PIN_4, LED_Enabled};

void App_Init(void)
{
	PORT_voidInit();
}


uint8_t App(void)
{
	SW_u8ReadSwitch(&button, &buttonState);

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
	
	return OK;
}


