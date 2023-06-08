#include "std_types.h"

#include "DIO_interface.h"
#include "TIM_interface.h"

#include "LED_interface.h"


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
 * Set the state of multiple LEDs on the same port 
 * without affecting the rest of its pins
 */
void LED_mask_led_port(en_led_port_t Copy_port, uint8_t_ Copy_portPins, en_LEDState Copy_LEDsState)
{
	DIO_MaskPortVal(Copy_port, Copy_portPins, Copy_LEDsState);
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

/**
 * Blink led with given on and off time
 */
en_LEDErrorState_t LED_Blink(ST_LED* Copy_Led, uint16_t_ Copy_OnTime, uint16_t_ Copy_OffTime)
{
	en_LEDErrorState_t local_en_led_state = LED_OK;
	
	if(Copy_Led != NULL)
	{
		LED_setState(Copy_Led, LED_ON);
		TIM0_SyncDelay(Copy_OnTime, mSeconds);
		LED_setState(Copy_Led, LED_OFF);
		TIM0_SyncDelay(Copy_OffTime, mSeconds);
	}
	else
	{
		local_en_led_state = LED_NOK;
	}
	
	return local_en_led_state;
}

/**
 * Blink multiple LEDs on a port with given on and off time
 */
void LED_BlinkPort(en_led_port_t Copy_port, uint8_t_ Copy_portPins, uint16_t_ Copy_OnTime, uint16_t_ Copy_OffTime)
{
	LED_mask_led_port(Copy_port, Copy_portPins, LED_ON);
	TIM0_SyncDelay(Copy_OnTime, mSeconds);
	LED_mask_led_port(Copy_port, Copy_portPins, LED_OFF);
	TIM0_SyncDelay(Copy_OffTime, mSeconds);
}

