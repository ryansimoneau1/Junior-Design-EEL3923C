/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F47K40
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/device_config.h"
#include "mcc_generated_files/pin_manager.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <builtins.h>
#include <math.h>
#include "ANY_LCD.h"

int32_t ADCDAT    = 0;
int32_t ADCDATsum = 0;
int32_t ADCDATavg = 0;
float Resistance;
char Measured[7];
float RKnown = 552000;

void delayUS(uint32_t usec);
void writeLCD(uint8_t bitfield);

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    ADCC_StartConversion(0x00);
    
        /****LCD INIT*****/
    any_lcd_t lcd;
    lcd.delay_us  = &delayUS; /* provide pointers to necessary functions */
    lcd.lcd_write = &writeLCD;
    LCD_Init(lcd); //will initialize lcd "logically" ie send the correct commands for 4 bit mode
    
    /* writing a string to the LCD */
    char *str1 = "R: ";
    char *str2 = " Ohms";
    float conversion = 5/(pow(2,10));

    while (1){
        // delay for 2 seconds between updating the lcd
        for(int i = 0; i < 1000; i++){
            ADCDAT = ADCC_GetConversionResult();
            ADCDATsum = ADCDAT + ADCDATsum;
            __delay_us(150);
        }
        ADCDATavg = (int32_t)((float)(ADCDATsum)*0.001);
        ADCDATsum = 0;
        LCD_Reset(lcd);
        Resistance = (float)ADCDATavg*conversion*RKnown/(5 - (float)ADCDATavg*conversion);
        if(Resistance <= 1000){
            Resistance += 470;
        }
        if(Resistance <= 2000 && Resistance > 1000){
            Resistance *= 1.2;
        }
        if(Resistance < 5000 && Resistance > 2500){
            Resistance *= 1.1;
        }
        if(Resistance >= 400000 && Resistance > 5000){
            Resistance *=1.12;
        }
        if((int32_t)Resistance <= 1000000 && (int32_t)Resistance > 1000){
            sprintf(Measured, "%7lu", (int32_t)Resistance);
            LCD_WriteString(str1, lcd);
            LCD_WriteString(Measured, lcd);
            LCD_WriteString(str2, lcd);
        }else{
            LCD_WriteString("OUT OF RANGE", lcd);
        }
        __delay_ms(1500);
    }
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