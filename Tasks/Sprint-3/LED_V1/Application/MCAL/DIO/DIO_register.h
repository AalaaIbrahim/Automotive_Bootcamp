
#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_

#define PORTA     *((volatile uint8_t*)0x3b)
#define PORTB     *((volatile uint8_t*)0x38)
#define PORTC     *((volatile uint8_t*)0x35)
#define PORTD     *((volatile uint8_t*)0x32)

#define DDRA      *((volatile uint8_t*)0x3a)
#define DDRB      *((volatile uint8_t*)0x37)
#define DDRC      *((volatile uint8_t*)0x34)
#define DDRD      *((volatile uint8_t*)0x31)

#define PINA      *((volatile uint8_t*)0x39)
#define PINB      *((volatile uint8_t*)0x36)
#define PINC      *((volatile uint8_t*)0x33)
#define PIND      *((volatile uint8_t*)0x30)

#endif
