/*
 * Proj 7
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * CSE 325
 */
#include "global.h"

#define forever for(;;)

void hw_init();


int main()
{
	hw_init();
	
    forever {
		port_poll();
    }

    // main() should never return, but C requires that main() return an int, so here it is.
    return 0;
}

void hw_init()
{
	// Enable PTB, PTC, PTD and PTE clocks
	sim_init();
	
	// Configures pin functions
	port_init();
	uc_gpio_config_B_output(3);
	uc_gpio_config_C_output(2);
	
	GPIOA_PDOR = 0;
	
	tpm_pwm_init();
	spi1_init();
	nokia_lcd_init();
	pushb_init();
}
