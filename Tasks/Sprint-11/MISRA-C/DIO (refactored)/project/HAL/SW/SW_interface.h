#ifndef HAL_SW_SW_INTERFACE_H_
#define HAL_SW_SW_INTERFACE_H_

typedef enum
{
	SW_PORT_A,
	SW_PORT_B,
	SW_PORT_C,
	SW_PORT_D
}en_sw_port_t;

typedef enum
{
	SW_PIN_0,
	SW_PIN_1,
	SW_PIN_2,
	SW_PIN_3,
	SW_PIN_4,
	SW_PIN_5,
	SW_PIN_6,
	SW_PIN_7
}en_sw_pin_t;

typedef enum
{
	SW_Disabled,
	SW_Enabled
}en_sw_state_t;

typedef enum
{
	SW_INTERNAL_PULLUP,
	SW_EXTERNAL_PULLUP,
	SW_PullDown
}en_sw_Pull_t;

typedef enum
{
	SW_NotPressed,
	SW_Pressed,
}EN_SWValue_t;


typedef struct
{
	en_sw_port_t Port;
	en_sw_pin_t Pin;
	en_sw_Pull_t PullType;
	en_sw_state_t State;
}ST_Switch;


uint8_t_ SW_init(ST_Switch* Copy_pSW_tSwitch);
uint8_t_ SW_ReadSwitch(ST_Switch* Copy_pSW_tSwitch, uint8_t_* Copy_pu8SwitchState);

#endif
