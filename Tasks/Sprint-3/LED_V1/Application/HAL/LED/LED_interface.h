#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

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

/**
 * Toggles the given given led
 */

EN_LEDErrorState_t LED_Toggle(ST_LED* Copy_Led);


#endif
