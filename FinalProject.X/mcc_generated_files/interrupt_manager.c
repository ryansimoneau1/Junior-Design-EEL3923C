/**
  Generated Interrupt Manager Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.c

  @Summary:
    This is the Interrupt Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F47K40
        Driver Version    :  2.04
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above or later
        MPLAB 	          :  MPLAB X 5.45
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

#include "interrupt_manager.h"
#include "mcc.h"

uint16_t SPIConvertData(uint16_t Data);

extern uint8_t PBFlag;
extern uint8_t Tim3Flag;
extern uint8_t Tim1Flag;
extern uint16_t SPIOutData;
extern uint8_t SPIOutDataLower;
extern uint8_t SPIOutDataUpper;
extern uint8_t wavecount;

extern uint16_t sine[100];
extern uint16_t zeros[100];

extern uint8_t Waveselect;

// Beep Waveform selection
extern uint8_t TempBeepFlag;
extern uint8_t HumBeepFlag;
extern uint8_t BothBeepFlag;
extern uint8_t BeepCount;
extern uint16_t TempC;
extern uint16_t HumRH;
extern int16_t TempLimit;
extern int16_t HumLimit;

void  INTERRUPT_Initialize (void)
{
    // Disable Interrupt Priority Vectors (16CXXX Compatibility Mode)
    INTCONbits.IPEN = 0;
}

void __interrupt() INTERRUPT_InterruptManager (void)
{
    // interrupt handler
    if(PIE0bits.IOCIE == 1 && PIR0bits.IOCIF == 1)
    {
        PIN_MANAGER_IOC();
        PBFlag = 1;
    }
    else if(INTCONbits.PEIE == 1)
    {
        if(PIE4bits.TMR3IE == 1 && PIR4bits.TMR3IF == 1)
        {
            TMR3_ISR();
            // Temp Beep
            if(TempLimit <= TempC && HumLimit > HumRH){
                TempBeepFlag = 1;
                HumBeepFlag  = 0;
                BothBeepFlag = 0;
                HumidityAlert_SetLow();
                if(Waveselect == 1){
                    Waveselect = 0;
                    BeepCount++;
                    TempAlert_SetHigh();
                    if(BeepCount > 2){
                        Waveselect = 1;
                        TempAlert_SetLow();
                        BeepCount = 0;
                    }     
                    wavecount = 0;
                }else{  
                    Waveselect = 1;
                    TempAlert_SetLow();
                    wavecount = 0;                   
                }
            }
            // Hum Beep
            if(TempLimit > TempC && HumLimit <= HumRH){
                TempBeepFlag = 0;
                HumBeepFlag  = 1;
                BothBeepFlag = 0;
                TempAlert_SetLow();
                if(Waveselect == 1){
                    Waveselect = 0;
                    HumidityAlert_SetHigh();
                    BeepCount++;
                    if(BeepCount > 3){
                        Waveselect = 1;
                        HumidityAlert_SetLow();
                        BeepCount = 0;
                    }     
                    wavecount = 0;
                }else{  
                    Waveselect = 1;
                    HumidityAlert_SetLow();
                    wavecount = 0;                   
                }
            }
            // Both Beep
            if(TempLimit <= TempC && HumLimit <= HumRH){
                TempBeepFlag = 0;
                HumBeepFlag  = 0;
                BothBeepFlag = 1;
                if(Waveselect == 1){
                    Waveselect = 0;
                    TempAlert_SetHigh();
                    HumidityAlert_SetHigh();
                    wavecount = 0;
                }else{
                    Waveselect = 1;
                    TempAlert_SetLow();
                    HumidityAlert_SetLow();
                    wavecount = 0;
                }
            } 
            // Temp Beep Shut Off
            if(TempLimit > TempC && TempBeepFlag == 1){
                Waveselect = 1;
                TempAlert_SetLow();
                TempBeepFlag = 0;
            }
            // Hum Beep Shut Off
            if(HumLimit > HumRH && HumBeepFlag == 1){
                Waveselect = 1;
                HumidityAlert_SetLow();
                HumBeepFlag = 0;
            }
            // Both Beep Shut Off
            if(TempLimit > TempC && HumLimit > HumRH && BothBeepFlag == 1){
                Waveselect = 1;
                TempAlert_SetLow();
                HumidityAlert_SetLow();
                BothBeepFlag = 0;
            }
        } 
        else if(PIE4bits.TMR2IE == 1 && PIR4bits.TMR2IF == 1)
        {
            TMR2_ISR();
            //            Tim2Flag = 1;
            if(Waveselect == 0){
                SPIOutData = SPIConvertData(sine[wavecount]);
            }else{
                SPIOutData = SPIConvertData(zeros[wavecount]);
            }
            CS_SetLow();
            SPIOutDataUpper = (SPIOutData >> 8);
            SPIOutDataLower = SPIOutData;
            SPI1_ExchangeByte(SPIOutDataUpper);
            SPI1_ExchangeByte(SPIOutDataLower);
            CS_SetHigh();
            
            wavecount++;
            if(wavecount >= 99){
                wavecount = 0;
            }
        } 
        else if(PIE4bits.TMR1IE == 1 && PIR4bits.TMR1IF == 1)
        {
            TMR1_ISR();
            Tim1Flag = 1;
        } 
        else
        {
            //Unhandled Interrupt
        }
    }      
    else
    {
        //Unhandled Interrupt
    }
}

