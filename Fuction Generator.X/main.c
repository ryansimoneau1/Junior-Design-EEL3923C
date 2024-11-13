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
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <builtins.h>
#include <math.h>
#include <float.h>

uint16_t sine[100] = {0x200,0x220,0x240,0x25f,0x27f,0x29e,0x2bc,0x2d9,0x2f6,0x312,
0x32c,0x346,0x35e,0x374,0x38a,0x39d,0x3af,0x3c0,0x3ce,0x3db,
0x3e6,0x3ef,0x3f6,0x3fb,0x3fe,0x3ff,0x3fe,0x3fb,0x3f6,0x3ef,
0x3e6,0x3db,0x3ce,0x3c0,0x3af,0x39d,0x38a,0x374,0x35e,0x346,
0x32c,0x312,0x2f6,0x2d9,0x2bc,0x29e,0x27f,0x25f,0x240,0x220,
0x200,0x1df,0x1bf,0x1a0,0x180,0x161,0x143,0x126,0x109,0xed,
0xd3,0xb9,0xa1,0x8b,0x75,0x62,0x50,0x3f,0x31,0x24,
0x19,0x10,0x9,0x4,0x1,0x0,0x1,0x4,0x9,0x10,
0x19,0x24,0x31,0x3f,0x50,0x62,0x75,0x8b,0xa1,0xb9,
0xd3,0xed,0x109,0x126,0x143,0x161,0x180,0x1a0,0x1bf,0x1df};

uint16_t triangle[100] = {0x14,0x29,0x3d,0x52,0x66,0x7b,0x8f,0xa4,0xb8,0xcd,
0xe1,0xf6,0x10a,0x11e,0x133,0x147,0x15c,0x170,0x185,0x199,
0x1ae,0x1c2,0x1d7,0x1eb,0x200,0x214,0x228,0x23d,0x251,0x266,
0x27a,0x28f,0x2a3,0x2b8,0x2cc,0x2e1,0x2f5,0x309,0x31e,0x332,
0x347,0x35b,0x370,0x384,0x399,0x3ad,0x3c2,0x3d6,0x3eb,0x3ff,
0x3eb,0x3d6,0x3c2,0x3ad,0x399,0x384,0x370,0x35b,0x347,0x332,
0x31e,0x309,0x2f5,0x2e1,0x2cc,0x2b8,0x2a3,0x28f,0x27a,0x266,
0x251,0x23d,0x228,0x214,0x200,0x1eb,0x1d7,0x1c2,0x1ae,0x199,
0x185,0x170,0x15c,0x147,0x133,0x11e,0x10a,0xf6,0xe1,0xcd,
0xb8,0xa4,0x8f,0x7b,0x66,0x52,0x3d,0x29,0x14,0x0};

uint16_t square[100] = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,
0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,
0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,
0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,
0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,0x3ff,
0x3ff,0x3ff,0x3ff,0x3ff};

uint16_t sawtooth[100] = {0,11,22,33,44,55,66,77,88,99,110,
121,132,143,154,165,176,187,198,209,220,231,242,253,264,
275,286,297,308,319,330,341,352,363,374,385,396,407,418,
429,440,451,462,473,484,495,506,517,528,539,550,561,572,
583,594,605,616,627,638,649,660,671,682,693,704,715,726,
737,748,759,770,781,792,803,814,825,836,847,858,869,880,
891,902,913,924,935,946,957,968,979,990,1001,1012,1023,
1023,1023,1023,1023,1023,1023};

uint16_t LUTData[100];
uint16_t OutData;
uint8_t OutDataUpper;
uint8_t OutDataLower;

volatile uint16_t ADCPeriod;
uint16_t Period;

// Returns the command and data in SPI format
uint16_t SPIConvertData(uint16_t Data);
// outputs data to DAC
void delayUS(uint32_t usec);
// calculates the amplitude based on pot value
float AmpCalc(uint16_t ADCVal);
// calculates frequency based on pot value
uint16_t PeriodCalc(uint16_t ADCVal);

void main(void)
{
    uint8_t DIPValues = 0;
    uint8_t OutputSelect = 0;
    // Initialize the device
    SYSTEM_Initialize();
    SSP1CON1bits.SSPEN = 1;
    

    // Enable the Global Interrupts
//    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
//    INTERRUPT_PeripheralInterruptEnable();
    
    ADCC_StartConversion(0b011001);

    while (1)
    {
        DIPValues = (DIP1_GetValue() << 1) | DIP2_GetValue();
        OutputSelect = DIPValues;   
        if(OutputSelect == 0){
            for(uint16_t j = 0; j< 100; j++){

                LUTData[j] = sine[j];
//                LUTData[j] = (uint16_t)((float)LUTData[j]*(float)Amplitude*0.000977517);
            }
        }
        if(OutputSelect == 1){
            for(uint16_t j = 0; j< 100; j++){

                LUTData[j] = triangle[j];
//                LUTData[j] = (uint16_t)((float)LUTData[j]*(float)Amplitude*0.000977517);
            }
        }
        if(OutputSelect == 2){
            for(uint16_t j = 0; j< 100; j++){

                LUTData[j] = square[j];
//                LUTData[j] = (uint16_t)((float)LUTData[j]*(float)Amplitude*0.000977517);
            }
        }    
        if(OutputSelect == 3){
            for(uint16_t j = 0; j< 100; j++){

                LUTData[j] = sawtooth[j];
//                LUTData[j] = (uint16_t)((float)LUTData[j]*(float)Amplitude*0.000977517);
            }
        }
            while(DIPValues == OutputSelect){
                DIPValues = DIP1_GetValue() + DIP2_GetValue();
                ADCPeriod = ADCC_GetConversionResult();
                Period = PeriodCalc(ADCPeriod);
                for(uint16_t i = 0; i < 100; i++){
                    delayUS(Period);
                    OutData = SPIConvertData(LUTData[i]);
                    OutDataUpper = (OutData >> 8);
                    OutDataLower = OutData;
                    CS_SetLow();
                    SPI1_ExchangeByte(OutDataUpper);
                    SPI1_ExchangeByte(OutDataLower);
                    CS_SetHigh();
                }
            } 

    }
}
uint16_t SPIConvertData(uint16_t Data){
    // stores the Digital data sent to the DAC via SPI
    uint16_t DigiPacket = 0x9000 | (Data << 2);  
    return DigiPacket;
}
uint16_t PeriodCalc(uint16_t ADCVal){
    // calculates theoretical Frequency of waveform
    uint16_t T = 0.3*ADCVal;
    return T;
}
void delayUS(uint32_t usec){
  for(uint32_t i=0;i<usec;i++){
    __delay_us(1); /* some kind of provided software delay */  
  }
}