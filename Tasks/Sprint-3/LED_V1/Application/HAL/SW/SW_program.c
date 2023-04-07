#include "../../Services/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SW_interface.h"

/*================= Global Variables ==================*/

ST_Switch button = {DIO_PORT_A, DIO_PIN_0, SW_PullUp, SW_Enabled};

/*=============== Function Prototypes =================*/

uint8_t SW_EnableSwitch(ST_Switch* Copy_pSW_tSwitch)
{
	uint8_t Local_ErrorState = OK;

	if(Copy_pSW_tSwitch != NULL)
	{
		Copy_pSW_tSwitch->State = SW_Enabled;
	}
	else
	{
		Local_ErrorState = NOK;
	}

	return Local_ErrorState;
}

uint8_t SW_DisableSwitch(ST_Switch* Copy_pSW_tSwitch)
{
	uint8_t Local_ErrorState = OK;

	if(Copy_pSW_tSwitch != NULL)
	{
		Copy_pSW_tSwitch->State = SW_Disabled;
	}
	else
	{
		Local_ErrorState = NOK;
	}

	return Local_ErrorState;
}

uint8_t SW_ReadSwitch(ST_Switch* Copy_pSW_tSwitch, uint8_t* Copy_pu8SwitchState)
{
	uint8_t Local_ErrorState = OK;
	uint8_t Local_SwitchValue;

	if((Copy_pSW_tSwitch != NULL) && (Copy_pu8SwitchState != NULL) && (Copy_pSW_tSwitch->State != SW_Disabled))
	{
		DIO_GetPinVal(Copy_pSW_tSwitch->Port, Copy_pSW_tSwitch->Pin, &Local_SwitchValue);

		if(Copy_pSW_tSwitch->PullType == SW_PullUp)
		{
			*Copy_pu8SwitchState = !Local_SwitchValue;
		}
		else if(Copy_pSW_tSwitch->PullType == SW_PullDown)
		{
			*Copy_pu8SwitchState = Local_SwitchValue;
		}
		else
		{
			Local_ErrorState = NOK;
		}
	}
	else
	{
		Local_ErrorState = NOK;
	}

	return Local_ErrorState;
}
