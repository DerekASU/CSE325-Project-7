/*
 * Proj 7
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * CSE 325
 */
#include "port.h"

void port_init()
{	
	PORTA_PCR1 |= PORT_PCR_MUX(0b001);
	PORTA_PCR2 |= PORT_PCR_MUX(0b001);	
	PORTB_PCR3 |= PORT_PCR_MUX(0b001);		
	PORTC_PCR1 |= PORT_PCR_MUX(0b100);	
	PORTC_PCR2 |= PORT_PCR_MUX(0b001);
	PORTC_PCR3 |= PORT_PCR_MUX(0b001);
	PORTC_PCR12 |= PORT_PCR_MUX(0b001);
	PORTD_PCR4 |= PORT_PCR_MUX(0b010);
	PORTE_PCR2 |= PORT_PCR_MUX(0b010);
	PORTE_PCR3 |= PORT_PCR_MUX(0b101);
}

