#include "std_types.h"
#include "bit_math.h"
#include "int.h"

#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_private.h"

/* Initialize all EXTI Callback functions with NULL */
void (*EXTI_CallbackFn[3])(void) = {NULL};

EN_EXTIErrorState_t EXTI_Init(EN_EXTI_t Copy_Int, EN_EXTISenseMode_t Copy_Mode)
{
	EN_EXTIErrorState_t Local_u8ErrorState = EXTI_OK;	
	bool_t_ temp_exi_mode_check = (Copy_Mode<=EXTI_RisingEdge) && !(Copy_Mode<EXTI_FallingEdge && Copy_Int==EXTI2);
	
	if(TRUE == temp_exi_mode_check)
	{
		switch(Copy_Int)
		{
			case EXTI0: MCUCR &= EXTI0_SENSE_MODE_MASK;
						MCUCR |= Copy_Mode;
						break;
						
			case EXTI1: MCUCR &= EXTI1_SENSE_MODE_MASK;
						MCUCR |= Copy_Mode<<2;
						break;
						
			case EXTI2: CLR_BIT(MCUCSR, 6);
						MCUCSR |= Copy_Mode<<6;
						break;	
						
			default: Local_u8ErrorState = EXTI_NOK;						
		}
	}
	else
	{
		Local_u8ErrorState = EXTI_NOK;
	}
		
	return Local_u8ErrorState;
}

EN_EXTIErrorState_t EXTI_Enable(EN_EXTI_t Copy_Int)
{
	uint8_t_ Local_u8ErrorState = EXTI_OK;
	
	/* Set Specific Interrupt Enable bit */
	switch(Copy_Int)
	{
		case EXTI0: SET_BIT(GICR, GICR_INT0); break;
		case EXTI1: SET_BIT(GICR, GICR_INT1); break;
		case EXTI2: SET_BIT(GICR, GICR_INT2); break;
		default: Local_u8ErrorState = EXTI_NOK;
	}
	
	return Local_u8ErrorState;
}

EN_EXTIErrorState_t EXTI_Disable(EN_EXTI_t Copy_Int)
{
	uint8_t_ Local_u8ErrorState = EXTI_OK;
	
	/* Clear Specific Interrupt Enable bit */
	switch(Copy_Int)
	{
		case EXTI0: CLR_BIT(GICR, GICR_INT0); break;
		case EXTI1: CLR_BIT(GICR, GICR_INT1); break;
		case EXTI2: CLR_BIT(GICR, GICR_INT2); break;
		default: Local_u8ErrorState = EXTI_NOK;
	}
	
	return Local_u8ErrorState;
}


EN_EXTIErrorState_t EXTI_SetCallback(EN_EXTI_t Copy_Int, void (*Copy_pCallbackFn)(void))
{
	uint8_t_ Local_ErrorStatus = EXTI_OK;
	bool_t_ temp_argument_check = (Copy_Int<=EXTI2) && Copy_pCallbackFn != NULL;
	
	if(TRUE == temp_argument_check)
	{
		EXTI_CallbackFn[Copy_Int] = Copy_pCallbackFn;
	}
	else
	{
		Local_ErrorStatus = EXTI_NOK;
	}
	
	return Local_ErrorStatus;
}

ISR(EXT_INT_0)
{
	if(EXTI_CallbackFn[EXTI0] != NULL)
	{
		EXTI_CallbackFn[EXTI0]();
	}
	else
	{
		/* Do Nothing */
	}
}

ISR(EXT_INT_1)
{
	if(EXTI_CallbackFn[EXTI1] != NULL)
	{
		EXTI_CallbackFn[EXTI1]();
	}
	else
	{
		/* Do Nothing */
	}
}

ISR(EXT_INT_2)
{
	if(EXTI_CallbackFn[EXTI2] != NULL)
	{
		EXTI_CallbackFn[EXTI2]();
	}
	else
	{
		/* Do Nothing */
	}
}