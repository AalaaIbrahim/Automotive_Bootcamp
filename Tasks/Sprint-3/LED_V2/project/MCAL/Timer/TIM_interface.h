
#ifndef TIM_INTERFACE_H_
#define TIM_INTERFACE_H_


typedef enum
{
	TIM_OK,
	TIM_NOK
}EN_TIMErrorState_t;

/*=========================== Function Prototypes ===========================*/
void TIM_voidInit();
EN_TIMErrorState_t TIM_Start(uint8_t Copy_prescaler);
void TIM_Stop();
void TIM_SetValue(uint8_t Copy_Value);
EN_TIMErrorState_t TIM_Delay(uint32_t Copy_delayTime, en_timeUnits_t Copy_timeUnit);

EN_TIMErrorState_t TIM_SetCallback(void (*Copy_pvCallbackFn)(void));

#endif