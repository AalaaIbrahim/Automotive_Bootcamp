

#include "std_types.h"
#include "bit_math.h"

#include "DIO_register.h"
#include "DIO_interface.h"


/**
 * @def function to configure a single DIO pin as input/output
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @param Copy_Dir desired direction (input or output) to set the pin to
 * @return error status
 */
en_DIO_errorState_t DIO_SetPinDir(en_port_t Copy_Port, en_pin_t Copy_Pin, en_pinDirection_t Copy_Dir)
{
	en_DIO_errorState_t Local_u8ErrorStatus = DIO_OK;

	if((Copy_Pin >= 0) && (Copy_Pin < DIO_PIN_TOTAL))
	{
		if(Copy_Dir == DIO_PIN_IN)
		{
			switch (Copy_Port)
			{
				case DIO_PORT_A: DDRA &= ~(1<<Copy_Pin); break;
				case DIO_PORT_B: DDRB &= ~(1<<Copy_Pin); break;
				case DIO_PORT_C: DDRC &= ~(1<<Copy_Pin); break;
				case DIO_PORT_D: DDRD &= ~(1<<Copy_Pin); break;
				default : Local_u8ErrorStatus = DIO_INVALID_PORT;
			}
		}
		else if(Copy_Dir == DIO_PIN_OUT)
		{
			switch (Copy_Port)
			{
				case DIO_PORT_A: DDRA |= (1<<Copy_Pin); break;
				case DIO_PORT_B: DDRB |= (1<<Copy_Pin); break;
				case DIO_PORT_C: DDRC |= (1<<Copy_Pin); break;
				case DIO_PORT_D: DDRD |= (1<<Copy_Pin); break;
				default : Local_u8ErrorStatus = DIO_INVALID_PORT;
			}
		}
		else 
		{
			Local_u8ErrorStatus = DIO_ERROR;
		}
	}
	else Local_u8ErrorStatus = DIO_INVALID_PIN;

	return Local_u8ErrorStatus;	
}

/**
 * @def function to configure the direction of an entire DIO port
 * @param Copy_Port the desired port
 * @param Copy_Dir  desired direction (0-255) to set the entire port to
 * @return error status
 */
en_DIO_errorState_t DIO_SetPortDir(en_port_t Copy_Port, uint8_t_ Copy_Dir)
{
	en_DIO_errorState_t Local_u8ErrorStatus = DIO_OK;

	switch (Copy_Port)
	{
		case DIO_PORT_A: DDRA = Copy_Dir; break;
		case DIO_PORT_B: DDRB = Copy_Dir; break;
		case DIO_PORT_C: DDRC = Copy_Dir; break;
		case DIO_PORT_D: DDRD = Copy_Dir; break;
		default : Local_u8ErrorStatus = DIO_INVALID_PORT;
	}

	return Local_u8ErrorStatus;	
}

/**
 * @def function to configure a single DIO pin as input/output
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @return error status
 */
en_DIO_errorState_t DIO_SetPinVal(en_port_t Copy_Port, en_pin_t Copy_Pin, uint8_t_ Copy_Value)
{
	en_DIO_errorState_t Local_u8ErrorStatus = DIO_OK;

	if(Copy_Pin >= 0 && Copy_Pin < DIO_PIN_TOTAL)
	{
		if(Copy_Value == DIO_PIN_LOW)
		{
			switch (Copy_Port)
			{
			case DIO_PORT_A: PORTA &= ~(1<<Copy_Pin); break;
			case DIO_PORT_B: PORTB &= ~(1<<Copy_Pin); break;
			case DIO_PORT_C: PORTC &= ~(1<<Copy_Pin); break;
			case DIO_PORT_D: PORTD &= ~(1<<Copy_Pin); break;
			default : Local_u8ErrorStatus = DIO_INVALID_PORT;
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
			default : Local_u8ErrorStatus = DIO_INVALID_PORT;
			}
		}
		else Local_u8ErrorStatus = DIO_ERROR;
	}
	else Local_u8ErrorStatus = DIO_INVALID_PORT;

	return Local_u8ErrorStatus;
}

/**
 * @def function to configure a single DIO pin as input/output
 * @param Copy_Port the port of the required pin
 * @param Copy_Value the desired value to set the entire port to
 * @return error status
 */
en_DIO_errorState_t DIO_SetPortVal(en_port_t Copy_Port, uint8_t_ Copy_Value)
{
	en_DIO_errorState_t Local_u8ErrorStatus = OK;

	switch (Copy_Port)
	{
	case DIO_PORT_A: PORTA = Copy_Value; break;
	case DIO_PORT_B: PORTB = Copy_Value; break;
	case DIO_PORT_C: PORTC = Copy_Value; break;
	case DIO_PORT_D: PORTD = Copy_Value; break;
	default : Local_u8ErrorStatus = DIO_INVALID_PORT;
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
en_DIO_errorState_t DIO_GetPinVal(en_port_t Copy_Port, en_pin_t Copy_Pin, uint8_t_* Copy_pu8Val)
{
	en_DIO_errorState_t Local_u8ErrorStatus = OK;

	if((Copy_pu8Val != NULL) && (Copy_Pin >= 0 && Copy_Pin < DIO_PIN_TOTAL))
	{
		switch (Copy_Port)
		{
		case DIO_PORT_A: *Copy_pu8Val = GET_BIT(PINA,Copy_Pin); break;
		case DIO_PORT_B: *Copy_pu8Val = GET_BIT(PINB,Copy_Pin); break;
		case DIO_PORT_C: *Copy_pu8Val = GET_BIT(PINC,Copy_Pin); break;
		case DIO_PORT_D: *Copy_pu8Val = GET_BIT(PIND,Copy_Pin); break;
		default : Local_u8ErrorStatus = DIO_INVALID_PORT;
		}
	}
	else Local_u8ErrorStatus = DIO_INVALID_PIN;

	return Local_u8ErrorStatus;
}

/**
 * @def function to toggle the value of a single DIO pin (from high or low and vice versa)
 * @param Copy_Port the port of the required pin
 * @param Copy_Pin the pin number in the given port
 * @return error status
 */
en_DIO_errorState_t DIO_TogglePin(en_port_t Copy_Port, en_pin_t Copy_Pin)
{
	en_DIO_errorState_t Local_u8ErrorStatus = OK;

	if((Copy_Pin >= 0) && (Copy_Pin < DIO_PIN_TOTAL))
	{
		switch (Copy_Port)
		{
		case DIO_PORT_A: GET_BIT(PINA,Copy_Pin)? CLR_BIT(PORTA,Copy_Pin): SET_BIT(PORTA,Copy_Pin); break;
		case DIO_PORT_B: GET_BIT(PINB,Copy_Pin)? CLR_BIT(PORTB,Copy_Pin): SET_BIT(PORTB,Copy_Pin); break;
		case DIO_PORT_C: GET_BIT(PINC,Copy_Pin)? CLR_BIT(PORTC,Copy_Pin): SET_BIT(PORTC,Copy_Pin); break;
		case DIO_PORT_D: GET_BIT(PIND,Copy_Pin)? CLR_BIT(PORTD,Copy_Pin): SET_BIT(PORTD,Copy_Pin); break;
		default : Local_u8ErrorStatus = DIO_INVALID_PORT;
		}
	}
	else Local_u8ErrorStatus = DIO_INVALID_PIN;

	return Local_u8ErrorStatus;
}
