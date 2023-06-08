#include "std_types.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"

#include "SW_interface.h"

/*=============== Function Prototypes =================*/

en_sw_Error_t SW_init(ST_Switch* Copy_pSW_tSwitch)
{
	en_sw_Error_t Local_ErrorState = SW_OK;

	if(Copy_pSW_tSwitch != NULL)
	{

		DIO_SetPinDir(Copy_pSW_tSwitch->Port, Copy_pSW_tSwitch->Pin, DIO_PIN_IN);
		
		if(Copy_pSW_tSwitch->PullType == SW_INTERNAL_PULLUP)
		{
			DIO_SetPinVal(Copy_pSW_tSwitch->Port, Copy_pSW_tSwitch->Pin, DIO_PIN_HIGH);

		}
		
		/* Set the button state */
		Copy_pSW_tSwitch->State = SW_Enabled;
	}
	else
	{
		Local_ErrorState = SW_ERROR;
	}

	return Local_ErrorState;
}



en_sw_Error_t SW_ReadSwitch(ST_Switch* Copy_pSW_tSwitch, uint8_t_* Copy_pu8SwitchState)
{
	en_sw_Error_t Local_ErrorState = SW_OK;
	uint8_t_ Local_SwitchValue;

	if((Copy_pSW_tSwitch != NULL) && (Copy_pu8SwitchState != NULL) && (Copy_pSW_tSwitch->State != SW_Disabled))
	{
		DIO_GetPinVal(Copy_pSW_tSwitch->Port, Copy_pSW_tSwitch->Pin, &Local_SwitchValue);

		if(Copy_pSW_tSwitch->PullType == SW_INTERNAL_PULLUP || Copy_pSW_tSwitch->PullType == SW_EXTERNAL_PULLUP)
		{
			*Copy_pu8SwitchState = !Local_SwitchValue;
		}
		else if(Copy_pSW_tSwitch->PullType == SW_PullDown)
		{
			*Copy_pu8SwitchState = Local_SwitchValue;
		}
		else
		{
			Local_ErrorState = SW_ERROR;
		}
	}
	else
	{
		Local_ErrorState = SW_ERROR;
	}

	return Local_ErrorState;
}

en_sw_Error_t SW_EXTIMode(ST_Switch* Copy_pSW_tSwitch, en_sw_Interrupt_t Copy_IntEvent, void (*Copy_pvCallbackFn)(void))
{
	en_sw_Error_t Local_ErrorState = SW_OK;
	EN_EXTI_t Local_EXTIpin;
	
	/* Get the EXTI pin */
	if(Copy_pSW_tSwitch->Port == (en_sw_port_t)DIO_PORT_D)
	{
		if(Copy_pSW_tSwitch->Pin == (en_sw_pin_t)DIO_PIN_2)
		Local_EXTIpin = EXTI0;
		else if(Copy_pSW_tSwitch->Pin == (en_sw_pin_t)DIO_PIN_3)
		Local_EXTIpin = EXTI1;
		else Local_ErrorState = SW_ERROR;
	}
	else if(Copy_pSW_tSwitch->Port == (en_sw_port_t)DIO_PORT_D && Copy_pSW_tSwitch->Pin == (en_sw_pin_t)DIO_PIN_2)
	{
		Local_EXTIpin = EXTI2;
	}
	else
	{
		Local_ErrorState = SW_ERROR;
	}
	
	if (SW_OK == Local_ErrorState)
	{
		EXTI_Init(Local_EXTIpin, Copy_IntEvent);
		EXTI_Enable(Local_EXTIpin);
		EXTI_SetCallback(Local_EXTIpin, Copy_pvCallbackFn);
	}	
	
	return Local_ErrorState;
}