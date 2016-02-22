/*
 * Proj 7
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * CSE 325
 */
#include "gpio.h"

void uc_gpio_config_A_output(int n) //function to configure the specific gpio ports for output.
{
	PTA_BASE_PTR->PDDR |= (1 << n);
}
void uc_gpio_config_A_input(int n) //function to configure the specific gpio ports for input
{
	PTA_BASE_PTR->PDDR &= ~(1 << n);
}

void uc_gpio_config_B_output(int n) //function to configure the specific gpio ports for output.
{
	PTB_BASE_PTR->PDDR |= (1 << n);
}
void uc_gpio_config_B_input(int n) //function to configure the specific gpio ports for input.
{
	PTB_BASE_PTR->PDDR &= ~(1 << n);
}

void uc_gpio_config_C_output(int n) //function to configure the specific gpio ports for output.
{
	PTC_BASE_PTR->PDDR |= (1 << n);
}
void uc_gpio_config_C_input(int n) //function to configure the specific gpio ports for input.
{
	PTC_BASE_PTR->PDDR &= ~(1 << n);
}

void uc_gpio_config_D_output(int n) //function to configure the specific gpio ports for output.
{
	PTD_BASE_PTR->PDDR |= (1 << n);
}
void uc_gpio_config_D_input(int n) //function to configure the specific gpio ports for input.
{
	PTD_BASE_PTR->PDDR &= ~(1 << n);
}

void uc_gpio_config_E_output(int n) //function to configure the specific gpio ports for output.
{
	PTE_BASE_PTR->PDDR |= (1 << n);
}
void uc_gpio_config_E_input(int n) //function to configure the specific gpio ports for input.
{
	PTE_BASE_PTR->PDDR &= ~(1 << n);
}

void set_pin_low(char port, int n)
{
	if (port == 'a')
		GPIOA_PDOR &= ~(1 << n);
	else if (port == 'b')
		GPIOB_PDOR &= ~(1 << n);
	else if (port == 'c')
		GPIOC_PDOR &= ~(1 << n);
	else if (port == 'd')
		GPIOD_PDOR &= ~(1 << n);
	else if (port == 'e')
		GPIOA_PDOR &= ~(1 << n);
}

void set_pin_high(char port, int n)
{
	if (port == 'a')
		GPIOA_PDOR |= 1 << n;
	else if (port == 'b')
		GPIOB_PDOR |= 1 << n;
	else if (port == 'c')
		GPIOC_PDOR |= 1 << n;
	else if (port == 'd')
		GPIOD_PDOR |= 1 << n;
	else if (port == 'e')
		GPIOE_PDOR |= 1 << n;
	
}
