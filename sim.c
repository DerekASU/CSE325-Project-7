/*
 * Proj 7
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * CSE 325
 */
#include "sim.h"

void sim_init() 
{
    SIM_SCGC5 |= 0b11111 << 9;
	SIM_SCGC4 |= 1 << 23;
	SIM_SCGC6 |= 1 << 24;
	SIM_SOPT2 |= (1<< 25) | (1 <<24);
	MCG_C2  |= 1 << 0;
	MCG_SC |= 0b010 << 1;
}
