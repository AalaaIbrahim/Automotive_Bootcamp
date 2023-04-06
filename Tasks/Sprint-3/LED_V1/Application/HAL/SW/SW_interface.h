
#ifndef HAL_SW_SW_INTERFACE_H_
#define HAL_SW_SW_INTERFACE_H_


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


uint8_t SW_u8EnableSwitch(ST_Switch* Copy_pSW_tSwitch);
uint8_t SW_u8DisableSwitch(ST_Switch* Copy_pSW_tSwitch);
uint8_t SW_u8ReadSwitch(ST_Switch* Copy_pSW_tSwitch, uint8_t* Copy_pu8SwitchState);

#endif
