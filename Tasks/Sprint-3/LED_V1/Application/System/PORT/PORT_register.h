/*
 * PORT_reg.h
 *
 *  Created on: Sep 11, 2022
 *      Author: ME
 */

#ifndef MCAL_PORT_PORT_REGISTER_H_
#define MCAL_PORT_PORT_REGISTER_H_

#define DDRA      *((volatile uint8_t*)0x3a)
#define DDRB      *((volatile uint8_t*)0x37)
#define DDRC      *((volatile uint8_t*)0x34)
#define DDRD      *((volatile uint8_t*)0x31)

#define PORTA     *((volatile uint8_t*)0x3b)
#define PORTB     *((volatile uint8_t*)0x38)
#define PORTC     *((volatile uint8_t*)0x35)
#define PORTD     *((volatile uint8_t*)0x32)

#endif /* MCAL_PORT_PORT_REGISTER_H_ */
