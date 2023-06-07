#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#define DIO_PORT_LOW	0x0
#define DIO_PORT_HIGH	0xff

typedef enum
{
	DIO_PORT_A,
	DIO_PORT_B,
	DIO_PORT_C,
	DIO_PORT_D
}en_port_t;

typedef enum
{
	DIO_PIN_0,
	DIO_PIN_1,
	DIO_PIN_2,
	DIO_PIN_3,
	DIO_PIN_4,
	DIO_PIN_5,
	DIO_PIN_6,
	DIO_PIN_7,
	DIO_PIN_TOTAL
}en_pin_t;

typedef enum
{
	DIO_PIN_IN,
	DIO_PIN_OUT
}en_pinDirection_t;

typedef enum
{
	DIO_PIN_LOW,
	DIO_PIN_HIGH
}en_pinValue_t;

typedef enum
{
	DIO_OK,
	DIO_INVALID_PORT,
	DIO_INVALID_PIN,
	DIO_ERROR
}en_DIO_errorState_t;


/**
 * @def function to configure a single DIO pin as input/output
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @param Copy_Dir desired direction (input or output) to set the pin to
 * @return error status
 */
en_DIO_errorState_t DIO_SetPinDir(en_port_t Copy_Port, en_pin_t Copy_Pin, en_pinDirection_t Copy_Dir);

/**
 * @def function to configure the direction of an entire DIO port
 * @param Copy_Port the desired port
 * @param Copy_Dir  desired direction (0-255) to set the entire port to
 * @return error status
 */
en_DIO_errorState_t DIO_SetPortDir(en_port_t Copy_Port, uint8_t_ Copy_Dir);

/**
 * @def function to set the value of a single DIO pin as high/low
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @param Copy_Value desired value (high or low) to set the pin to
 * @return error status
 */
en_DIO_errorState_t DIO_SetPinVal(en_port_t Copy_Port, en_pin_t Copy_Pin, en_pinValue_t Copy_Value);

/**
 * @def function to set the value of an entire DIO port
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @param Copy_Value desired value (0 - 255) to set the entire port to
 * @return error status
 */
en_DIO_errorState_t DIO_SetPortVal(en_port_t Copy_Port, uint8_t_ Copy_Value);

/**
 * @def function to get the value of a single DIO pin whether high or low
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @param Copy_pu8Val pointer to a variable to store pin value
 * @return error status
 */
en_DIO_errorState_t DIO_GetPinVal(en_port_t Copy_Port, en_pin_t Copy_Pin, uint8_t_* Copy_pu8Val);

/**
 * @def function to toggle the value of the given pin
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @return error status
 */
en_DIO_errorState_t DIO_TogglePin(en_port_t Copy_Port, en_pin_t Copy_Pin);

/**
 * @def function to set the value of multiple port pins without affecting 
 *		the rest of the pins
 * @param Copy_Port the port of the required pin
 * @param Copy_portMask the desired bits on the port
 * @param Copy_Value the desired value to set the selected pins to
 * @return error status
 */
en_DIO_errorState_t DIO_MaskPortVal(en_port_t Copy_Port, uint8_t_ Copy_portMask, en_pinValue_t Copy_Value);

#endif
