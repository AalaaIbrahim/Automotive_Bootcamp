/*
 * TIM_program.c
 *
 * Created: 4/10/2023 1:44:33 PM
 *  Author: ME
 */ 
#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATH.h"

#include "TIM_register.h"
#include "TIM_private.h"
#include "TIM_config.h"
#include "TIM_interface.h"

u_int_16 prescalers[] = {1,8,64,265,1024};

void TIM_voidInit()
{
	/* Clear the timer mode bit */
	TCCR0 &= TIMER0_MODE_MASK;
	/* Set the bits to the configured value */
	TCCR0 |= TIM0_MODE;
}

EN_TIMErrorState_t TIM_Start(uint8_t Copy_prescaler)
{
	EN_TIMErrorState_t Local_ErrorState = TIM_OK;
	
	if(Copy_prescaler > TIM_NO_CLOCK && Copy_prescaler <= TIM_EXTERNAL_RISING_EDGE)
	{
		/* Clear the prescaler bits */
		TCCR0 &= TIM0_CLK_MASK;
		/* Set prescaler value */
		TCCR0 |= Copy_prescaler;		
	}
	else
	{
		Local_ErrorState = TIM_NOK;
	}
	
	return Local_ErrorState;
}

void TIM_Stop()
{
	/* Clear the prescaler bits */
	TCCR0 &= TIM0_CLK_MASK;
}

void TIM_SetValue(uint8_t Copy_Value)
{
	TCNT0 = Copy_Value;
}

EN_TIMErrorState_t TIM_Delay(uint32_t Copy_delayTime, en_timeUnits_t Copy_timeUnit)
{
	uint8_t Local_prescaler, Local_TotalOverFlows, Local_OverFlowCounter=0;
	u_int_16 Local_TotalTicks;
	float Local_TickTime;
	
	/* Get Value in micro seconds */
	if(Copy_timeUnit == Seconds) Copy_delayTime *= 1000000;
	else if(Copy_timeUnit == mSeconds) Copy_delayTime *= 1000;
	//else if(C)
	
	/* Get prescaler */
	if(Copy_delayTime>=300000)
	{
		Local_prescaler = TIM_DIV_BY_1024;
	}
	else if(Copy_delayTime<=5000)
	{
		Local_prescaler = TIM_DIV_BY_1;
	}
	else
	{
		Local_prescaler = TIM_DIV_BY_64;
	}
	
	Local_TickTime = prescalers[Local_prescaler-1]; //CPU Prescaler 
	Local_TotalTicks = (u_int_16)(Copy_delayTime/Local_TickTime);
	Local_TotalOverFlows = Local_TotalTicks/TIM0_MAX_TICKS;
	
	TIM_SetValue(TIM0_MAX_TICKS-(Local_TotalTicks%TIM0_MAX_TICKS));
	
	TIM_Start(Local_prescaler);
	while(Local_OverFlowCounter <= Local_TotalOverFlows)
	{
		/* Wait until the overflow flag is raised */
		while(!GET_BIT(TIFR, TIFR_TOV0));
		
		/* Clear the overflow flag */
		SET_BIT(TIFR, TIFR_TOV0);
		
		Local_OverFlowCounter++;		
	}
	
	TIM_Stop();
}

EN_TIMErrorState_t TIM_SetCallback(void (*Copy_pvCallbackFn)(void));