#include <stdlib.h>
#include <stdint.h>

#ifndef FINALPROJECT_H_   /* Include guard */
#define FINALPROJECT_H_

// Returns the command and data in SPI format
uint16_t SPIConvertData(uint16_t Data);
// LCD Required Functions
void delayUS(uint32_t usec);
void writeLCD(uint8_t bitfield);

#endif // FINALPROJECT_H_