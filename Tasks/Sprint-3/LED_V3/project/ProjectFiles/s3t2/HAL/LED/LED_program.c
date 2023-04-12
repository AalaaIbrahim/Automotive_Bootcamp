#include "../../Services/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/Timer/TIM_interface.h"

#include "LED_interface.h"


/*================= Global Variables ==================*/

ST_LED LED1 = {DIO_PORT_A, DIO_PIN_0, LED_Enabled};
ST_LED LED2 = {DIO_PORT_A, DIO_PIN_2, LED_Enabled};
ST_LED LED3 = {DIO_PORT_A, DIO_PIN_4, LED_Enabled};
ST_LED LED4 = {DIO_PORT_A, DIO_PIN_6, LED_Enabled};

/*=============== Function Prototypes =================*/
/**
 * enables displaying output on given led
*/
EN_LEDErrorState_t LED_EnableLED(ST_LED* Copy_LED)
{
	if(Copy_LED != NULL)
	{
		Copy_LED->state = LED_Enabled;
	}
	else return LED_NOK;

	return LED_OK;
}

/**
 * Disables displaying output on given led
 */
EN_LEDErrorState_t LED_DisableLED(ST_LED* Copy_LED)
{
	if(Copy_LED != NULL)
	{
		Copy_LED->state = LED_Disabled;
	}
	else return LED_NOK;

	return LED_OK;
}

/**
 * Set the state of the given led to On/Off
 */
EN_LEDErrorState_t LED_setState(ST_LED* Copy_Led, EN_LEDState Copy_LEDState)
{
	if(Copy_Led != NULL && (Copy_Led->state != LED_Disabled))
	{
		DIO_SetPinVal(Copy_Led->port, Copy_Led->pin, Copy_LEDState);
	}
	else
	{
		return LED_NOK;
	}
	return LED_OK;
}

void LED_setLEDPortState(uint8_t Copy_port, uint8_t Copy_portPins, EN_LEDState Copy_LEDsState)
{
	DIO_MaskPortVal(Copy_port, Copy_portPins, Copy_LEDsState);
}

/**
 * Blink led with given on and off time
 */
EN_LEDErrorState_t LED_Blink(ST_LED* Copy_Led, u_int_16 Copy_OnTime, u_int_16 Copy_OffTime)
{
	if(Copy_Led != NULL)
	{
		LED_setState(Copy_Led, LED_ON);
		TIM0_SyncDelay(Copy_OnTime, mSeconds);
		LED_setState(Copy_Led, LED_OFF);
		TIM0_SyncDelay(Copy_OffTime, mSeconds);
	}
	else
	{
		return LED_NOK;
	}
	
	return LED_OK;
}

/**
 * Blink multiple LEDs on a port with given on and off time
 */
void LED_BlinkPort(uint8_t Copy_port, uint8_t Copy_portPins, u_int_16 Copy_OnTime, u_int_16 Copy_OffTime)
{
	LED_setLEDPortState(Copy_port, Copy_portPins, LED_ON);
	TIM0_SyncDelay(Copy_OnTime, mSeconds);
	LED_setLEDPortState(Copy_port, Copy_portPins, LED_OFF);
	TIM0_SyncDelay(Copy_OffTime, mSeconds);
}
