
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	EXTI0,
	EXTI1,
	EXTI2
}EN_EXTI_t;

typedef enum
{
	EXTI_LowLevel,
	EXTI_LogicalChange,
	EXTI_FallingEdge,
	EXTI_RisingEdge
}EN_EXTISenseMode_t;

typedef enum
{
	EXTI_OK,
	EXTI_NOK
}EN_EXTIErrorState_t;

/**
 * Initializes given External interrupt with given mode
 */
extern EN_EXTIErrorState_t EXTI_Init(EN_EXTI_t Copy_Int, EN_EXTISenseMode_t Copy_Mode);

/**
 * enables specific interrupt of given EXTI number
 */
extern EN_EXTIErrorState_t EXTI_Enable(EN_EXTI_t Copy_Int);

/**
 * disables specific interrupt of given EXTI number
 */
extern EN_EXTIErrorState_t EXTI_Disable(EN_EXTI_t Copy_Int);

/**
 * Sets given function to be called when given EXTI is triggered
 */
extern EN_EXTIErrorState_t EXTI_SetCallback(EN_EXTI_t Copy_Int, void (*Copy_pCallbackFn)(void));


#endif