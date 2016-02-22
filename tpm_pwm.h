/*
 * Proj 7
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * CSE 325
 */
#ifndef TPM_PWM_H_
#define TPM_PWM_H_
#include "global.h"

void tpm_pwm_init();

// Sets the duty cycles to be 100%, 50% or 0%
void tpm_100_duty();
void tpm_50_duty();
void tpm_0_duty();

#endif /* TPM_PWM_H_ */
