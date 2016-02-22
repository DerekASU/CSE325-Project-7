//********************************************************************
//		filename: spi.c
//		Project 7
//		Kevin Cabrera, Michael Zarate
//		kevin.cabrera@asu.edu,   michael.zarate@asu.edu
//		CSE325	Embedded Microprocessor Systems
//		Fall 2015
//********************************************************************
#include "spi.h"

void spi1_init()
{
	SPI1_BR = 0b00100001;
	SPI1_C2 &= ~(1 << 7);
	SPI1_C2 &= ~(1 << 5);
	SPI1_C2 &= ~(1 << 2);
	SPI1_C1 &= ~(1 << 7);
	SPI1_C1 &= ~(1 << 5);
	SPI1_C3 &= ~(1 << 2);
	SPI1_C3 &= ~(1 << 1);
	SPI1_C1 |= 1 << 6;
	SPI1_C2 &= ~(1 << 6);
	SPI1_C1 &= ~(1 << 0);
	SPI1_C1 |= 1 << 4;
	SPI1_C2 |= 1 << 4;
	SPI1_C1 |= 1 << 1;
	SPI1_C1 &= ~(1 << 3);
	SPI1_C1 &= ~(1 << 2);
	SPI1_C2 &= ~(1 << 0);
	SPI1_C2 &= ~(1 << 3);
	SPI1_C3 |= 1 << 0;
	SPI1_C1 = 0x52;
}

void spi1_tx(uint8_t data)
{	

	while ((SPI1_S & 0b00000010) == 0b00000010);
	SPI1_DL = data;
}
