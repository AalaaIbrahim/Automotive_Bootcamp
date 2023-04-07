#include "../../Services/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"


/*================= Global Variables ==================*/

ST_LED LED1 = {DIO_PORT_A, DIO_PIN_1, LED_Enabled};
ST_LED LED2 = {DIO_PORT_A, DIO_PIN_2, LED_Enabled};
ST_LED LED3 = {DIO_PORT_A, DIO_PIN_3, LED_Enabled};
ST_LED LED4 = {DIO_PORT_A, DIO_PIN_4, LED_Enabled};

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

/**
 * Toggles the given given led
 */
EN_LEDErrorState_t LED_Toggle(ST_LED* Copy_Led)
{
	if(Copy_Led != NULL)
	{
		DIO_TogglePin(Copy_Led->port, Copy_Led->pin);
	}
	else
	{
		return LED_NOK;
	}
	return LED_OK;
}
