#define F_CPU 1000000UL
#include <util/delay.h>

#include "../Services/STD_TYPES.h"

#include "../SYSTEM/PORTS/PORTS_interface.h"
#include "../SYSTEM/INT/int.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/SW/SW_interface.h"

/*================= Global Variables ==================*/

uint8_t buttonPress=0;
extern ST_LED LED1, LED2, LED3, LED4;
extern ST_Switch button0;

void Button0_Callback(void);

/*=============== Function Prototypes =================*/
void App2_Init(void)
{
	/* Initialize I/O ports */
	PORT_voidInit();
	
	/* Initialize button as an external interrupt source */
	SW_EXTIMode(&button0, SW_LowLevel, &Button0_Callback);
	
	/* Enable Global Interrupt */
	sei();
}

void App2(void)
{
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

}

void Button0_Callback(void)
{
	buttonPress++;
}