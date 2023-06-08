#define F_CPU 8000000UL

#include "std_types.h"
#include "int.h"

#include "LED_interface.h"
#include "SW_interface.h"

#include "App.h"

/*================= Global Variables ==================*/

uint8_t_ buttonState, button0Press=0, BlinkMode = 0;

ST_LED LED1 = {LED_PORT_A, LED_PIN_1, LED_Enabled};
ST_LED LED2 = {LED_PORT_A, LED_PIN_2, LED_Enabled};
ST_LED LED3 = {LED_PORT_A, LED_PIN_3, LED_Enabled};
ST_LED LED4 = {LED_PORT_A, LED_PIN_4, LED_Enabled};

ST_Switch button0 = {SW_PORT_D, SW_PIN_2, SW_PullDown, SW_Enabled};
ST_Switch button1 = {SW_PORT_D, SW_PIN_3, SW_PullDown, SW_Enabled};

ST_Blink_t Global_BlinkModes[] =
{
	{100, 900},
	{200, 800},
	{300, 700},
	{500, 500},
	{800, 200}
};

static void Button0_Callback(void);
static void Button1_Callback(void);

/*=============== Function Implementation =================*/
void APP_init(void)
{
	LED_init(&LED1);
	LED_init(&LED2);
	LED_init(&LED3);
	LED_init(&LED4);
	
	SW_EXTIMode(&button0, SW_RisingEdge, &Button0_Callback);
	SW_EXTIMode(&button1, SW_RisingEdge, &Button1_Callback);
	
	sei();
}



void APP_start(void)
{
	switch(button0Press)
	{
		case 1:
		{
			LED_BlinkPort(LED_PORT, PORTA_LED1, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
			break;
		}
		
		case 2:
		{
			LED_BlinkPort(LED_PORT, PORTA_LED12, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
			break;
		}
		
		case 3:
		{
			LED_BlinkPort(LED_PORT, PORTA_LED123, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
			break;
		}
		
		case 4:
		{
			LED_BlinkPort(LED_PORT, PORTA_LED_PINS, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
			break;
		}
		
		case 5:
		{
			LED_BlinkPort(LED_PORT, PORTA_LED234, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
			break;
		}
		
		case 6:
		{
			LED_BlinkPort(LED_PORT, PORTA_LED34, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
			break;
		}
		
		case 7:
		{
			LED_BlinkPort(LED_PORT, PORTA_LED4, Global_BlinkModes[BlinkMode].ON_TIME, Global_BlinkModes[BlinkMode].OFF_TIME);
			break;
		}
		
		default:
		{
			button0Press = 0;
			LED_mask_led_port(LED_PORT, PORTA_LED_PINS, LED_OFF);
			break;
		}
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

