#ifndef HAL_SW_SW_INTERFACE_H_
#define HAL_SW_SW_INTERFACE_H_

#define BUTTON_PORT			DIO_PORT_A
#define BUTTON_PIN			DIO_PIN_0

typedef struct
{
	uint8_t Port;
	uint8_t Pin;
	uint8_t PullType;
	uint8_t State;
}ST_Switch;

typedef enum
{
	SW_Disabled,
	SW_Enabled
}EN_SWState_t;

typedef enum
{
	SW_PullUp,
	SW_PullDown,
}SW_Pull_t;

typedef enum
{
	SW_NotPressed,
	SW_Pressed,
}EN_SWValue_t;

typedef enum
{
	SW_LowLevel,
	SW_LogicalChange,
	SW_FallingEdge,
	SW_RisingEdge
}EN_SW_Interrupt_t;

typedef enum
{
	SW_OK,
	SW_ERROR
}EN_SWError_t;

/************************************************************************/
/* Enable reading from given switch                                     */
/************************************************************************/
EN_SWError_t SW_EnableSwitch(ST_Switch* Copy_pSW_tSwitch);

/************************************************************************/
/* Disable reading from given switch                                    */
/************************************************************************/
EN_SWError_t SW_DisableSwitch(ST_Switch* Copy_pSW_tSwitch);

/************************************************************************/
/* Read Switch pin value if not disabled                                */
/************************************************************************/
EN_SWError_t SW_ReadSwitch(ST_Switch* Copy_pSW_tSwitch, uint8_t* Copy_pu8SwitchState);

/************************************************************************/
/* Initialize Switch in EXTI mode			                            */
/************************************************************************/
EN_SWError_t SW_EXTIMode(ST_Switch* Copy_pSW_tSwitch, EN_SW_Interrupt_t Copy_IntEvent, void (*Copy_pvCallbackFn)(void));

#endif
