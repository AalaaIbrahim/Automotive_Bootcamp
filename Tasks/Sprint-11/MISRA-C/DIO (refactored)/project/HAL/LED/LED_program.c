#include "std_types.h"

#include "DIO_interface.h"

#include "LED_interface.h"


/*================= Global Variables ==================*/



/*=============== Function Prototypes =================*/
/**
 * enables displaying output on given led
*/
en_LEDErrorState_t LED_init(ST_LED* Copy_LED)
{
	en_LEDErrorState_t local_en_led_state = LED_OK;
	
	if(Copy_LED != NULL)
	{
		DIO_SetPinDir(Copy_LED->port, Copy_LED->pin, DIO_PIN_OUT);
	}
	else local_en_led_state = LED_NOK;

	return local_en_led_state;
}

/**
 * Set the state of the given led to On/Off
 */
en_LEDErrorState_t LED_setState(ST_LED* Copy_Led, en_LEDState Copy_LEDState)
{
	en_LEDErrorState_t local_en_led_state = LED_OK;
	
	if(Copy_Led != NULL && (Copy_Led->state != LED_Disabled))
	{
		DIO_SetPinVal(Copy_Led->port, Copy_Led->pin, Copy_LEDState);
	}
	else
	{
		local_en_led_state = LED_NOK;
	}
	return local_en_led_state;
}

/**
 * Toggles the given given led
 */
en_LEDErrorState_t LED_Toggle(ST_LED* Copy_Led)
{
	en_LEDErrorState_t local_en_led_state = LED_OK;
	
	if(Copy_Led != NULL)
	{
		DIO_TogglePin(Copy_Led->port, Copy_Led->pin);
	}
	else
	{
		local_en_led_state = LED_NOK;
	}
	return local_en_led_state;
}
