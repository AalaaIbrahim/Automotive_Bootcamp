#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#define LED_PORT			0

typedef struct
{
	uint8_t port;
	uint8_t pin;
	uint8_t state;
}ST_LED;

typedef enum
{
	LED_Disabled,
	LED_Enabled
}EN_States_t;

typedef enum
{
	LED_OFF,
	LED_ON
}EN_LEDState;

typedef enum
{
	LED_OK,
	LED_NOK
}EN_LEDErrorState_t;

/**
 * enables displaying output on given led
*/
EN_LEDErrorState_t LED_EnableLED(ST_LED* Copy_LED);

/**
 * Disables displaying output on given led
 */
EN_LEDErrorState_t LED_DisableLED(ST_LED* Copy_LED);

/**
 * Set the state of the given led to On/Off
 */
EN_LEDErrorState_t LED_setState(ST_LED* Copy_LED, EN_LEDState Copy_LEDState);

EN_LEDErrorState_t LED_setLEDPortState(uint8_t Copy_port, uint8_t Copy_portValue, EN_LEDState Copy_LEDsState);

/**
 * Toggles the given given led
 */
EN_LEDErrorState_t LED_Toggle(ST_LED* Copy_Led);


/**
 * Toggles the given given led
 */
EN_LEDErrorState_t LED_Blink(ST_LED* Copy_Led, u_int_16 Copy_OnTime, u_int_16 Copy_OffTime);

EN_LEDErrorState_t LED_BlinkPort(uint8_t Copy_port, uint8_t Copy_portPins, u_int_16 Copy_OnTime, u_int_16 Copy_OffTime);

#endif
