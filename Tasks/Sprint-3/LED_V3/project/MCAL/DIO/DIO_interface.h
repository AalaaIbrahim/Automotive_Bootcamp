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
}Port_t;

typedef enum
{
	DIO_PIN_0,
	DIO_PIN_1,
	DIO_PIN_2,
	DIO_PIN_3,
	DIO_PIN_4,
	DIO_PIN_5,
	DIO_PIN_6,
	DIO_PIN_7
}Pin_t;

typedef enum
{
	DIO_PIN_IN,
	DIO_PIN_OUT
}PinDirection_t;

typedef enum
{
	DIO_PIN_LOW,
	DIO_PIN_HIGH
}PinValue_t;

typedef enum
{
	DIO_OK,
	InvalidPort,
	InvalidPin,
	DIO_Error
}EN_DIOErrorState_t;


/**
 * @def function to set the value of a single DIO pin
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @param Copy_Value desired value (high or low) to set the pin to
 * @return error status
 */
EN_DIOErrorState_t DIO_SetPinVal(uint8_t Copy_Port,uint8_t Copy_Pin, uint8_t Copy_Value);

/**
 * @def function to configure the value of an entire port
 * @param Copy_Port the desired port 
 * @param Copy_Value desired 8-bit value to set the port to
 * @return error status
 */
EN_DIOErrorState_t DIO_SetPortVal(uint8_t Copy_Port, uint8_t Copy_Value);

/**
 * @def Set or clear multiple pins on port without affecting the rest of the pins
 * @param Copy_Port the port of the required pin
 * @param Copy_portMask 8-bit value where the desired pins are represented by ones 
 * @param Copy_Value desired value (high or low) to set the pins to
 * @return error status
 */
EN_DIOErrorState_t DIO_MaskPortVal(uint8_t Copy_Port, uint8_t Copy_portMask, uint8_t Copy_Value);


#endif
