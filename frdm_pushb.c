/*
 * Proj 7
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * CSE 325
 */
#include "frdm_pushb.h"

void pushb_init()
{
	
		uc_gpio_config_C_input(3);
		uc_gpio_config_C_input(12);
		PORTC_PCR3 |= 1 << 1;
		PORTC_PCR12 |= 1 << 1;
		PORTC_PCR3 |= 1 << 0;
		PORTC_PCR12 |= 1 << 0;
		PORTC_PCR3 |= PORT_PCR_IRQC(0b1010);
		PORTC_PCR12 |= PORT_PCR_IRQC(0b1010);
}

void port_poll()
{	
	while (1)
	{
		if ((GPIOC_PDIR & 0x00000008) == 0x00000000)
		{
			sw1_press();
			break;
		}
		else if ((GPIOC_PDIR & 0x00001000) == 0x00000000)
		{
			sw3_press();
			break;
		}
	}
}

void sw1_press()
{
	nokia_lcd_clr();
	
	for (int i=32; i<104; i++)
	{
		nokia_lcd_disp_char(i);
	}
}

void sw3_press()
{
	nokia_lcd_clr();
	
	for (int i=104; i<127; i++)
	{
		nokia_lcd_disp_char(i);
	}
}
