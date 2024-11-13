#include <stdlib.h>
#include <stdint.h>
#include "FinalProjectFunctions.h"

uint16_t SPIConvertData(uint16_t Data){
    // stores the Digital data sent to the DAC via SPI
    uint16_t DigiPacket = 0x9000 | (Data << 2);  
    return DigiPacket;
}

void delayUS(uint32_t usec){
  for(uint32_t i=0;i<usec;i++){
    __delay_us(1); /* some kind of provided software delay */  
  }
}

void writeLCD(uint8_t bitfield){
  /*****************
   ASSUMING:
   PORTC 7-4 -> LCD D 7-4
   PORTC 2 -> LCD E 
   PORTC 1 -> LCD RW 
   PORTC 0 -> LCD RS 
  ******************/	
  PORTB = (bitfield & 0xF0) >> 4;
  PORTC = (bitfield & 0x07) << 5;
}