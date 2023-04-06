
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "../../HAL/SW/SW_interface.h"


uint8_t SW_u8EnableSwitch(ST_Switch* Copy_pSW_tSwitch)
{
	uint8_t Local_u8ErrorStatus = OK;

	if(Copy_pSW_tSwitch != NULL)
	{
		Copy_pSW_tSwitch->State = SW_Enabled;
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}

	return Local_u8ErrorStatus;
}

uint8_t SW_u8DisableSwitch(ST_Switch* Copy_pSW_tSwitch)
{
	uint8_t Local_u8ErrorStatus = OK;

	if(Copy_pSW_tSwitch != NULL)
	{
		Copy_pSW_tSwitch->State = SW_Disabled;
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}

	return Local_u8ErrorStatus;
}

uint8_t SW_u8ReadSwitch(ST_Switch* Copy_pSW_tSwitch, uint8_t* Copy_pu8SwitchState)
{
	uint8_t Local_u8ErrorStatus = OK;
	uint8_t Local_pu8SwitchValue;
	uint32_t Local_u32Counter;

	if((Copy_pSW_tSwitch != NULL) && (Copy_pu8SwitchState != NULL) && (Copy_pSW_tSwitch->State != SW_Disabled))
	{
		DIO_u8GetPinVal(Copy_pSW_tSwitch->Port, Copy_pSW_tSwitch->Pin, &Local_pu8SwitchValue);

		if(Copy_pSW_tSwitch->PullType == SW_PullUp)
		{
			*Copy_pu8SwitchState = !Local_pu8SwitchValue;
		}
		else if(Copy_pSW_tSwitch->PullType == SW_PullDown)
		{
			*Copy_pu8SwitchState = Local_pu8SwitchValue;
		}
		else
		{
			Local_u8ErrorStatus = NOK;
		}

		/* Delay for debouncing */
		//for(Local_u32Counter=0; Local_u32Counter<100000; Local_u32Counter++);

	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}

	return Local_u8ErrorStatus;
}
