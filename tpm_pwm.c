/*
 * Proj 7
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * CSE 325
 */
#include "tpm_pwm.h"

void tpm_pwm_init()
{
	TPM0_SC = 0;
	TPM0_SC |=  1 << 7;
	TPM0_SC &= ~(1 << 5);
	TPM0_CNT = 0;
	TPM0_MOD = 20000 - 1;
	tpm_0_duty();
	tpm_50_duty();
	TPM0_CONF = 0;
	TPM0_C0SC = 0b00100100;
	TPM0_CONF = 0;
	TPM0_SC |= 0b01 << 3;
}

void tpm_100_duty()
{
	TPM0_C0SC = 0b00101000;
	TPM0_C0V = ((TPM0_MOD + 1) * 100) / 100;
}

void tpm_50_duty()
{
	TPM0_C0SC = 0b00101000;
	TPM0_C0V = ((TPM0_MOD + 1) * 50) / 100;
}

void tpm_0_duty()
{
	TPM0_C0SC = 0b00000000;
}
