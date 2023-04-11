#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATH.h"

#include "DIO_register.h"
#include "DIO_interface.h"


/**
 * @def function to configure a single DIO pin as input/output
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @return error status
 */
EN_DIOErrorState_t DIO_SetPinVal(uint8_t Copy_Port,uint8_t Copy_Pin, uint8_t Copy_Value)
{
	uint8_t Local_u8ErrorStatus = OK;

	if(Copy_Pin >= 0 && Copy_Pin <= 7)
	{
		if(Copy_Value == DIO_PIN_LOW)
		{
			switch (Copy_Port)
			{
			case DIO_PORT_A: PORTA &= ~(1<<Copy_Pin); break;
			case DIO_PORT_B: PORTB &= ~(1<<Copy_Pin); break;
			case DIO_PORT_C: PORTC &= ~(1<<Copy_Pin); break;
			case DIO_PORT_D: PORTD &= ~(1<<Copy_Pin); break;
			default : Local_u8ErrorStatus = InvalidPort;
			}
		}
		else if(Copy_Value == DIO_PIN_HIGH)
		{
			switch (Copy_Port)
			{
			case DIO_PORT_A: PORTA |= (1<<Copy_Pin); break;
			case DIO_PORT_B: PORTB |= (1<<Copy_Pin); break;
			case DIO_PORT_C: PORTC |= (1<<Copy_Pin); break;
			case DIO_PORT_D: PORTD |= (1<<Copy_Pin); break;
			default : Local_u8ErrorStatus = InvalidPort;
			}
		}
		else Local_u8ErrorStatus = DIO_Error;
	}
	else Local_u8ErrorStatus = InvalidPin;

	return Local_u8ErrorStatus;
}

/**
 * @def function to configure a single DIO pin as input/output
 * @param Copy_Port the port of the required pin
 * @param Copy_Value the desired value to set the entire port to
 * @return error status
 */
EN_DIOErrorState_t DIO_SetPortVal(uint8_t Copy_Port, uint8_t Copy_Value)
{
	uint8_t Local_u8ErrorStatus = OK;

	switch (Copy_Port)
	{
	case DIO_PORT_A: PORTA = Copy_Value; break;
	case DIO_PORT_B: PORTB = Copy_Value; break;
	case DIO_PORT_C: PORTC = Copy_Value; break;
	case DIO_PORT_D: PORTD = Copy_Value; break;
	default : Local_u8ErrorStatus = InvalidPort;
	}

	return Local_u8ErrorStatus;
}

/**
 * @def function to set the value of multiple port pins without affecting 
 *		the rest of the pins
 * @param Copy_Port the port of the required pin
 * @param Copy_portMask the desired bits on the port
 * @param Copy_Value the desired value to set the entire port to
 * @return error status
 */
EN_DIOErrorState_t DIO_MaskPortVal(uint8_t Copy_Port, uint8_t Copy_portMask, uint8_t Copy_Value)
{
	uint8_t Local_u8ErrorStatus = OK;

	switch (Copy_Port)
	{
	case DIO_PORT_A: PORTA &= ~(Copy_portMask); 
					 if(Copy_Value==DIO_PIN_HIGH) {PORTA |= Copy_portMask;} 
					 break;
					 
	case DIO_PORT_B: PORTB &= ~(Copy_portMask); 
					 if(Copy_Value==DIO_PIN_HIGH) {PORTB |= Copy_portMask;}
					 break;
					 
	case DIO_PORT_C: PORTC &= ~(Copy_portMask); 
					 if(Copy_Value==DIO_PIN_HIGH) {PORTC |= Copy_portMask;}
					 break;
					 
	case DIO_PORT_D: PORTD &= ~(Copy_portMask); 
					 if(Copy_Value==DIO_PIN_HIGH) {PORTD |= Copy_portMask;}
					 break;
	default : Local_u8ErrorStatus = InvalidPort;
	}

	return Local_u8ErrorStatus;
}

/**
 * @def function to get the value of a single DIO pin whether high or low
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @param Copy_pu8Val pointer to a variable to store pin value
 * @return error status
 */
EN_DIOErrorState_t DIO_GetPinVal(uint8_t Copy_Port,uint8_t Copy_Pin, uint8_t* Copy_pu8Val)
{
	uint8_t Local_u8ErrorStatus = OK;

	if((Copy_pu8Val != NULL) && (Copy_Pin >= 0 && Copy_Pin <= 7))
	{
		switch (Copy_Port)
		{
		case DIO_PORT_A: *Copy_pu8Val = GET_BIT(PINA,Copy_Pin); break;
		case DIO_PORT_B: *Copy_pu8Val = GET_BIT(PINB,Copy_Pin); break;
		case DIO_PORT_C: *Copy_pu8Val = GET_BIT(PINC,Copy_Pin); break;
		case DIO_PORT_D: *Copy_pu8Val = GET_BIT(PIND,Copy_Pin); break;
		default : Local_u8ErrorStatus = InvalidPort;
		}
	}
	else Local_u8ErrorStatus = InvalidPin;

	return Local_u8ErrorStatus;
}

/**
 * @def function to toggle the value of a single DIO pin (from high or low and vice versa)
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @return error status
 */
EN_DIOErrorState_t DIO_TogglePin(uint8_t Copy_Port, uint8_t Copy_Pin)
{
	uint8_t Local_u8ErrorStatus = OK;

	if((Copy_Pin >= 0) && (Copy_Pin <= 7))
	{
		switch (Copy_Port)
		{
		case DIO_PORT_A: TOG_BIT(PORTA,Copy_Pin); break;
		case DIO_PORT_B: TOG_BIT(PORTB,Copy_Pin); break;
		case DIO_PORT_C: TOG_BIT(PORTC,Copy_Pin); break;
		case DIO_PORT_D: TOG_BIT(PORTD,Copy_Pin); break;
		default : Local_u8ErrorStatus = InvalidPort;
		}
	}
	else Local_u8ErrorStatus = InvalidPin;

	return Local_u8ErrorStatus;
}
