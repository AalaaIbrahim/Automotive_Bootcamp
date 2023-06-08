
#ifndef TIM_PRIVATE_H_
#define TIM_PRIVATE_H_

#define TIM0_MAX_TICKS				256

#define TIM0_MAX_PRSCLR_1_DELAY		5000
#define TIM0_MAX_PRSCLR_8_DELAY		25000
#define TIM0_MAX_PRSCLR_64_DELAY	125000
#define TIM0_MAX_PRSCLR_256_DELAY	500000
		

#define TIM0_MODE_MASK				0xB7
#define TIM0_NORMAL					0
#define TIM0_PWM					0x40
#define TIM0_CTC					0x08
#define TIM0_FAST_PWM				0x48


#define TIM0_CLK_MASK				0xF8

#define TIM0_PRSCLR_1				1
#define TIM0_PRSCLR_8				8
#define TIM0_PRSCLR_64				64
#define TIM0_PRSCLR_256				256
#define TIM0_PRSCLR_1024			1024

#endif 