#include "../../Services/STD_TYPES.h"

#include "PORTS_config.h"
#include "PORTS_private.h"
#include "PORTS_interface.h"
#include "PORTS_register.h"

void PORT_voidInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;

	PORTA = PORTA_INITIAL;
	PORTB = PORTB_INITIAL;
	PORTC = PORTC_INITIAL;
	PORTD = PORTD_INITIAL;
}
