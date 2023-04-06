#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"

/**
 * enables displaying output on given led 
*/
EN_LEDErrorState_t SW_u8EnableLED(ST_LED* Copy_LED)
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
EN_LEDErrorState_t SW_u8DisableLED(ST_LED* Copy_LED)
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
EN_LEDErrorState_t LED_setState(ST_LED* Copy_pLed, EN_LEDState Copy_LEDState)
{
	if(Copy_pLed != NULL && (Copy_pLed->state != LED_Disabled))
	{
		DIO_u8SetPinVal(Copy_pLed->port, Copy_pLed->pin, Copy_LEDState);
	}
	else
	{
		return LED_NOK;
	}
	return LED_OK;
}

/**
 * Toggles the given given led 
 */
EN_LEDErrorState_t LED_Toggle(ST_LED* Copy_Led)
{
	if(Copy_Led != NULL)
	{
		DIO_u8TogglePin(Copy_Led->port, Copy_Led->pin);
	}
	else
	{
		return LED_NOK;
	}
	return LED_OK;
}
