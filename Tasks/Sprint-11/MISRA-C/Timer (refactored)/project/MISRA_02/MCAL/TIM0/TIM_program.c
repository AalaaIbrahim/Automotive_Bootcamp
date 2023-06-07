#include "std_types.h"
#include "bit_math.h"

#include "TIM_register.h"
#include "TIM_private.h"
#include "TIM_config.h"
#include "TIM_interface.h"

/* prescaler options */
uint16_t_ prescalers[] = {TIM0_PRSCLR_1, TIM0_PRSCLR_8, TIM0_PRSCLR_64, TIM0_PRSCLR_256, TIM0_PRSCLR_1024};
	

EN_TIMErrorState_t TIM0_voidInit(EN_TIMMode_t Copy_timerMode)
{
	EN_TIMErrorState_t Local_tim0_state = TIM_OK;
	uint8_t_ Local_T0Mode;
	
	switch(Copy_timerMode)
	{
		case NormalMode	 : Local_T0Mode = TIM0_NORMAL	; break;
		case PWM_Mode    : Local_T0Mode = TIM0_PWM	    ; break;
		case CTC_Mode	 : Local_T0Mode = TIM0_CTC		; break;
		case FastPWM_Mode: Local_T0Mode = TIM0_FAST_PWM ; break;
		default: Local_tim0_state = TIM_NOK;
	}
	
	/* Clear the timer0 mode bit */
	TCCR0 &= TIM0_MODE_MASK;
	/* Set the bits to the given value */
	TCCR0 |= Local_T0Mode;
	
	return Local_tim0_state;
}

EN_TIMErrorState_t TIM0_Start(uint8_t_ Copy_prescaler)
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

void TIM0_Stop()
{
	/* Clear the prescaler bits */
	TCCR0 &= TIM0_CLK_MASK;
}

void TIM0_SetValue(uint8_t_ Copy_Value)
{
	TCNT0 = Copy_Value;
}

void TIM0_SyncDelay(uint32_t_ Copy_delayTime, en_timeUnits_t Copy_timeUnit)
{
	uint8_t_ Local_u8_prescaler, Local_TotalOverFlows, Local_OverFlowCounter=0;
	uint16_t_ Local_TotalTicks;
	float Local_TickTime;
	
	/* Get Value in micro seconds */
	if(Copy_timeUnit == Seconds)		{Copy_delayTime *= 1000000;}
	else if(Copy_timeUnit == mSeconds)	{Copy_delayTime *= 1000;}
	else if(Copy_timeUnit == uSeconds)	{/* Do Nothing */}
	
	/* Get prescaler according to delay time */
	if     (Copy_delayTime < TIM0_MAX_PRSCLR_1_DELAY)	{Local_u8_prescaler = TIM_DIV_BY_1;}
	else if(Copy_delayTime < TIM0_MAX_PRSCLR_8_DELAY)	{Local_u8_prescaler = TIM_DIV_BY_8;}
	else if(Copy_delayTime < TIM0_MAX_PRSCLR_64_DELAY)  {Local_u8_prescaler = TIM_DIV_BY_64;}
	else if(Copy_delayTime < TIM0_MAX_PRSCLR_256_DELAY) {Local_u8_prescaler = TIM_DIV_BY_256;}
	else {Local_u8_prescaler = TIM_DIV_BY_1024;}
	
	Local_TickTime = prescalers[Local_u8_prescaler-1]/TIM_CPU_CLK_PRSCLR; //CPU Prescaler
	Local_TotalTicks = (uint16_t_)(Copy_delayTime/Local_TickTime);
	Local_TotalOverFlows = Local_TotalTicks/TIM0_MAX_TICKS;
	
	/* Initialize timer in normal mode */
	TIM0_voidInit(NormalMode);
	
	/* Set timer start value */
	TIM0_SetValue(TIM0_MAX_TICKS-(Local_TotalTicks%TIM0_MAX_TICKS));
	
	/* Start Timer */
	TIM0_Start(Local_u8_prescaler);
	
	while(Local_OverFlowCounter <= Local_TotalOverFlows)
	{
		/* Wait until the overflow flag is raised */
		while(!GET_BIT(TIFR, TIFR_TOV0));
		
		/* Clear the overflow flag */
		SET_BIT(TIFR, TIFR_TOV0);
		
		Local_OverFlowCounter++;
	}
	
	/* Stop the timer after the delay is over */
	TIM0_Stop();
}

