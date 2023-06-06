#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

typedef struct
{
	uint8_t_ port;
	uint8_t_ pin;
	uint8_t_ state;
}ST_LED;

typedef enum
{
	LED_Disabled,
	LED_Enabled
}en_States_t;

typedef enum
{
	LED_PORT_A,
	LED_PORT_B,
	LED_PORT_C,
	LED_PORT_D
}en_led_port_t;

typedef enum
{
	LED_PIN_0,
	LED_PIN_1,
	LED_PIN_2,
	LED_PIN_3,
	LED_PIN_4,
	LED_PIN_5,
	LED_PIN_6,
	LED_PIN_7
}en_led_pin_t;

typedef enum
{
	LED_OFF,
	LED_ON
}en_LEDState;

typedef enum
{
	LED_OK,
	LED_NOK
}en_LEDErrorState_t;

/**
 * enables displaying output on given led
*/
en_LEDErrorState_t LED_init(ST_LED* Copy_LED);

/**
 * Set the state of the given led to On/Off
 */
en_LEDErrorState_t LED_setState(ST_LED* Copy_LED, en_LEDState Copy_LEDState);

/**
 * Toggles the given given led
 */

en_LEDErrorState_t LED_Toggle(ST_LED* Copy_Led);


#endif
