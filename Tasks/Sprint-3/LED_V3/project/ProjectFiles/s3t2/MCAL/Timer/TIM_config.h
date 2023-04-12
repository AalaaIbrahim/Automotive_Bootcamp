/*
 * TIM_config.h
 *
 * Created: 4/10/2023 4:55:31 PM
 *  Author: ME
 */ 


#ifndef TIM_CONFIG_H_
#define TIM_CONFIG_H_



/*
 * Options:
 * 			TIM0_NORMAL
 * 			TIM0_PWM
 * 			TIM0_CTC
 * 			TIM0_FAST_PWM
 */
#define TIM0_MODE						TIM0_NORMAL

/* Timer Compare Output Mode in Non-PWM Mode
 * Options:
 * 			DISCONNECTED
 * 			TOGGLE_PIN
 * 			CLEAR_PIN
 * 			SET_PIN
 */
#define TIM1_COMPARE_OUTPUT_MODE        OC1A_NONINVERTING

/*
 * Options:
 * 			TIM_NO_CLOCK
 * 			TIM_DIV_BY_1
 * 			TIM_DIV_BY_8
 * 			TIM_DIV_BY_64
 * 			TIM_DIV_BY_256
 * 			TIM_DIV_BY_1024
 * 			TIM_EXTERNAL_FALLING_EDGE
 * 			TIM_EXTERNAL_RISING_EDGE
 */
#define TIM0_CLOCK_SELECT				TIM_DIV_BY_1024



/*
 * Options:
 * 			TIM1_NORMAL
 * 			TIM1_PWM_PHASE_CORRECT_8BIT
 * 			TIM1_PWM_PHASE_CORRECT_9BIT
 * 			TIM1_PWM_PHASE_CORRECT_10BIT
 * 			TIM1_CTC_OCR1A_TOP
 * 			TIM1_FAST_PWM_8BIT
 * 			TIM1_FAST_PWM_9BIT
 * 			TIM1_FAST_PWM_10BIT
 * 			TIM1_PWM_PHASE_FREQ_CORRECT_ICR1_TOP
 * 			TIM1_PWM_PHASE_FREQ_CORRECT_OCR1A_TOP
 * 			TIM1_PWM_PHASE_CORRECT_ICR1_TOP
 * 			TIM1_PWM_PHASE_CORRECT_OCR1A_TOP
 * 			TIM1_CTC_ICR1_TOP
 * 			TIM1_FAST_PWM_ICR1_TOP
 * 			TIM1_FAST_PWM_OCR1A_TOP
 */
#define TIM1_MODE						TIM1_NORMAL

/*
 * Compare Output Options when timer 1 is in Non-PWM Mode:
 * Options:
 * 			OC1A_DISCONNECTED
 * 			OC1A_TOGGLE_PIN
 * 			OC1A_NONINVERTING
 * 			OC1A_INVERTING
 */
#define TIM1_COMPARE_OUTPUT_MODE        OC1A_NONINVERTING

/*
 * Options:
 * 			TIM_NO_CLOCK
 * 			TIM_DIV_BY_1
 * 			TIM_DIV_BY_8
 * 			TIM_DIV_BY_64
 * 			TIM_DIV_BY_256
 * 			TIM_DIV_BY_1024
 * 			TIM_EXTERNAL_FALLING_EDGE
 * 			TIM_EXTERNAL_RISING_EDGE
 */
#define TIM1_CLOCK_SELECT				TIM_DIV_BY_8

/*
 * Options:
 * 			ENABLE
 * 			DISABLE
 */
#define INPUT_CAPTURE_INTERRUPT			ENABLE

/*
 * Options:
 * 			ICU_RISING_EDGE
 * 			ICU_FALLING_EDGE
 */
#define INPUT_CAPTURE_TRIGGER_INITIAL	ICU_RISING_EDGE



#endif /* TIM_CONFIG_H_ */