
#ifndef TIM_REGISTER_H_
#define TIM_REGISTER_H_



/******************* Timer 0 ***********************/
#define	 TCNT0					  *((volatile uint8_t_*)0x52)	
#define  TCCR0                    *((volatile uint8_t_*)0x53)		/* Timer/Counter Control Register */
#define  TCCR0_WGM00				6								/* Waveform generation mode bit 0 */
#define  TCCR0_WGM01				3								/* Waveform generation mode bit 1 */
#define  TCCR0_CS02					2								/* prescaler bit 2 */
#define  TCCR0_CS01					1								/* prescaler bit 1 */
#define  TCCR0_CS00					0								/* prescaler bit 0 */

#define  OCR0                     *((volatile uint8_t_*)0x5c)		/* Output compare register */

#define	 TIFR					  *((volatile uint8_t_*)0x58)		/* Timer/Counter Interrupt Flag Register */
#define  TIFR_TOV0					0								/* Timer/Counter0 Overflow Flag */
#define  TIFR_OCF0					1								/* Output Compare Flag 0 */

#define  TIMSK                    *((volatile uint8_t_*)0x59)		/* Timer/Counter Interrupt Mask Register */
#define  TIMSK_TOIE0				0								/* Timer/Counter0 Overflow Interrupt Enable */
#define  TIMSK_OCIE0				1								/* Timer/Counter0 Output Compare Match Interrupt Enable */


#endif /* TIM_REGISTER_H_ */