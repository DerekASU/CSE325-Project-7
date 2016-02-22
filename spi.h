/*
 * Proj 7
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * CSE 325
 */
#ifndef SPI_H_
#define SPI_H_
#include "global.h"

typedef enum { 
	spi1_mode_cmd = 0, 
	spi1_mode_data = 1 
} spi1_mode_t;

void spi1_init();
void spi1_tx_block(int n, uint8_t block[]);
void spi1_tx_byte(uint8_t byte);
void spi1_tx(uint8_t);

#endif /* SPI_H_ */
