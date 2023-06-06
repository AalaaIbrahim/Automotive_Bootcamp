#include "std_types.h"

#include "DIO_interface.h"

#include "SW_interface.h"

/*================= Global Variables ==================*/



/*=============== Function Prototypes =================*/

uint8_t_ SW_init(ST_Switch* Copy_pSW_tSwitch)
{
	uint8_t_ Local_ErrorState = OK;

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
		Local_ErrorState = NOK;
	}

	return Local_ErrorState;
}



uint8_t_ SW_ReadSwitch(ST_Switch* Copy_pSW_tSwitch, uint8_t_* Copy_pu8SwitchState)
{
	uint8_t_ Local_ErrorState = OK;
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
			Local_ErrorState = NOK;
		}
	}
	else
	{
		Local_ErrorState = NOK;
	}

	return Local_ErrorState;
}
