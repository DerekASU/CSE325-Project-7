/*
 * Proj 7
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * CSE 325
 */
#ifndef GPIO_H_
#define GPIO_H_
#include "global.h"


void set_pin_low(char, int);
void set_pin_high(char, int);
void uc_gpio_config_A_output(int n);
void uc_gpio_config_A_input(int n);
void uc_gpio_config_B_output(int n);
void uc_gpio_config_B_input(int n);
void uc_gpio_config_C_output(int n);
void uc_gpio_config_C_input(int n);
void uc_gpio_config_D_output(int n);
void uc_gpio_config_D_input(int n);
void uc_gpio_config_E_output(int n);
void uc_gpio_config_E_input(int n);

#endif /* GPIO_H_ */
