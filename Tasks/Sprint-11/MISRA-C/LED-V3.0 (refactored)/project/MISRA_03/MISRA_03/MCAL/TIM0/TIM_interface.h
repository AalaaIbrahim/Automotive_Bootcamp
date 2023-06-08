
#ifndef TIM_INTERFACE_H_
#define TIM_INTERFACE_H_

#define TIM_CPU_CLK_PRSCLR			8 


typedef enum
{
	uSeconds,
	mSeconds,
	Seconds
}en_timeUnits_t;

typedef enum
{
	TIM_OK,
	TIM_NOK
}EN_TIMErrorState_t;

typedef enum
{
	NormalMode,
	PWM_Mode,
	CTC_Mode,
	FastPWM_Mode
}EN_TIMMode_t;

typedef enum
{
	TIM_NO_CLOCK             ,
	TIM_DIV_BY_1             ,
	TIM_DIV_BY_8             ,
	TIM_DIV_BY_64            ,
	TIM_DIV_BY_256           ,
	TIM_DIV_BY_1024          ,
	TIM_EXTERNAL_FALLING_EDGE,
	TIM_EXTERNAL_RISING_EDGE
}EN_TIM_CLK_SELECT_t;

/* Asynchronous Delay Function States */
#define  DELAY_BUSY			0
#define  DELAY_IDLE			1

/*=========================== Function Prototypes ===========================*/

/************************************************************************/
/* Initialize the timer mode								*/
/************************************************************************/
EN_TIMErrorState_t TIM0_voidInit(EN_TIMMode_t Copy_timerMode);

/************************************************************************/
/* Generate delay (busy waiting)	                                    */
/************************************************************************/
void TIM0_SyncDelay(uint32_t_ Copy_delayTime, en_timeUnits_t Copy_timeUnit);


#endif