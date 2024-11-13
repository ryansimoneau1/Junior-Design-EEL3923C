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
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/adcc.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <builtins.h>
#include <math.h>
#include <float.h>
#include "ANY_LCD.h"

// LCD Required Functions
void delayUS(uint32_t usec);
void writeLCD(uint8_t bitfield);

uint16_t sine[100] = 
{2,4,6,8,10,12,14,16,18,20,
22,24,27,29,31,33,35,37,39,41,
43,45,47,49,51,53,55,57,59,61,
63,65,67,69,71,73,75,78,80,82,
84,86,88,90,92,94,96,98,100,102,
100,98,96,94,92,90,88,86,84,82,
80,78,75,73,71,69,67,65,63,61,
59,57,55,53,51,49,47,45,43,41,
39,37,35,33,31,29,27,24,22,20,
18,16,14,12,10,8,6,4,2,0};

uint16_t zeros[100] = 
{0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0};

//uint16_t zeros[100] = 
//{25,25,25,25,25,25,25,25,25,25,
//25,25,25,25,25,25,25,25,25,25,
//25,25,25,25,25,25,25,25,25,25,
//25,25,25,25,25,25,25,25,25,25,
//25,25,25,25,25,25,25,25,25,25,
//25,25,25,25,25,25,25,25,25,25,
//25,25,25,25,25,25,25,25,25,25,
//25,25,25,25,25,25,25,25,25,25,
//25,25,25,25,25,25,25,25,25,25,
//25,25,25,25,25,25,25,25,25,25};

// Calculation Flag
bool CalcFlag = 1;

// ISR Flags
uint8_t PBFlag   = 0;
uint8_t Tim3Flag = 0;
uint8_t Tim1Flag = 0;

// Push Button Variables
int16_t TempLimit = 25;
int16_t HumLimit = 70;

//ADC Control
bool TempOrHum = 0;
uint16_t TempData = 0; // 0 is temp, 1 is humidity
uint16_t HumData = 0;

// LCD Output
char LCDout[32];
uint8_t Waveselect = 1;

// Calculation Variables
float VDDinv = 0.000977517;
uint16_t TempC = 0;
uint16_t HumRH = 0;

// DAC Variables
uint16_t SPIOutData = 0;
uint8_t SPIOutDataLower = 0;
uint8_t SPIOutDataUpper = 0;
uint8_t wavecount = 0;

uint8_t TempBeepFlag = 0;
uint8_t HumBeepFlag  = 0;
uint8_t BothBeepFlag = 0;
uint8_t BeepCount = 0;

void main(void)
{
    SYSTEM_Initialize();
    SSP1CON1bits.SSPEN = 1;

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    // initialize the LCD
    any_lcd_t lcd;
    lcd.delay_us  = &delayUS; /* provide pointers to necessary functions */
    lcd.lcd_write = &writeLCD;
    LCD_Init(lcd); //will initialize lcd "logically" ie send the correct commands for 4 bit mode

    while (1)
    {
        // Push Buttons
        if(PBFlag == 1){
            PBFlag = 0;
            if(!TD_GetValue()){
                TempLimit -= 5;
                if(TempLimit < 20){
                    TempLimit = 120;
                }
            }
            if(!TI_GetValue()){
                TempLimit += 5;
                if(TempLimit > 120){
                    TempLimit = 20;
                }
            }
            if(!HD_GetValue()){
                HumLimit -= 5;
                if(HumLimit < 0){
                    HumLimit = 100;
                }
            }
            if(!HI_GetValue()){
                HumLimit += 5;
                if(HumLimit > 100){
                    HumLimit = 0;
                }
            }
        }
        
        // LCD Refresh
        if(Tim1Flag == 1){
            Tim1Flag = 0;
            CalcFlag = 1;
            
            sprintf(LCDout,"T:%3d%cC  RH:%3d%c                        TL:%3d%cCRHL:%3d%c", TempC, 0xDF, HumRH,0x25, TempLimit, 0xDF, HumLimit, 0x25);
            LCD_WriteString(LCDout,lcd);
            LCD_WriteCMD(LCD_RETURN,lcd);
        }

        // Calculate Temperature and Humidity. Also set up LCD output
        if(CalcFlag == 1){
            CalcFlag = 0;
            
            TempData = ADCC_GetSingleConversion(TempVal);
            ADCC_GetSingleConversion(channel_VSS);
            HumData = ADCC_GetSingleConversion(RHVal);
            
            TempC = (uint16_t)(206.25*(float)TempData*VDDinv - 60.625);
            HumRH = (uint16_t)(125*(float)HumData*VDDinv - 12.5);
        }
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
uint16_t SPIConvertData(uint16_t Data){
    // stores the Digital data sent to the DAC via SPI
    uint16_t DigiPacket = 0x9000 | (Data << 2);  
    return DigiPacket;
}







        // Temperature and Humidity Value sampling
//        if(ADCFlag == 1){
//            ADCFlag = 0;
//            // Temperature Read
//            if(!TempOrHum){
//                TempData = ADCC_GetConversionResult();
//                // Change ADC input
//                TempOrHum = 1;
//                ADCON0bits.ADON = 0;
//                delayUS(1E3);
//                ADCC_StartConversion(RHVal);
//            }
//            if(TempOrHum){
//                HumData = ADCC_GetConversionResult();                
//                // Change ADC input
//                TempOrHum = 0;
//                ADCON0bits.ADON = 0;
//                delayUS(1E3);
//                ADCC_StartConversion(TempVal);
//            }
//        }