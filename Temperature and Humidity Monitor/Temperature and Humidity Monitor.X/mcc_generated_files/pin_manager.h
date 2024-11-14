/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F47K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set CS aliases
#define CS_TRIS                 TRISAbits.TRISA0
#define CS_LAT                  LATAbits.LATA0
#define CS_PORT                 PORTAbits.RA0
#define CS_WPU                  WPUAbits.WPUA0
#define CS_OD                   ODCONAbits.ODCA0
#define CS_ANS                  ANSELAbits.ANSELA0
#define CS_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define CS_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define CS_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define CS_GetValue()           PORTAbits.RA0
#define CS_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define CS_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define CS_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set TempAlert aliases
#define TempAlert_TRIS                 TRISAbits.TRISA1
#define TempAlert_LAT                  LATAbits.LATA1
#define TempAlert_PORT                 PORTAbits.RA1
#define TempAlert_WPU                  WPUAbits.WPUA1
#define TempAlert_OD                   ODCONAbits.ODCA1
#define TempAlert_ANS                  ANSELAbits.ANSELA1
#define TempAlert_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define TempAlert_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define TempAlert_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define TempAlert_GetValue()           PORTAbits.RA1
#define TempAlert_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define TempAlert_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define TempAlert_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define TempAlert_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define TempAlert_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define TempAlert_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define TempAlert_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define TempAlert_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set HumidityAlert aliases
#define HumidityAlert_TRIS                 TRISAbits.TRISA2
#define HumidityAlert_LAT                  LATAbits.LATA2
#define HumidityAlert_PORT                 PORTAbits.RA2
#define HumidityAlert_WPU                  WPUAbits.WPUA2
#define HumidityAlert_OD                   ODCONAbits.ODCA2
#define HumidityAlert_ANS                  ANSELAbits.ANSELA2
#define HumidityAlert_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define HumidityAlert_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define HumidityAlert_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define HumidityAlert_GetValue()           PORTAbits.RA2
#define HumidityAlert_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define HumidityAlert_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define HumidityAlert_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define HumidityAlert_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define HumidityAlert_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define HumidityAlert_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define HumidityAlert_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define HumidityAlert_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set DB4 aliases
#define DB4_TRIS                 TRISBbits.TRISB0
#define DB4_LAT                  LATBbits.LATB0
#define DB4_PORT                 PORTBbits.RB0
#define DB4_WPU                  WPUBbits.WPUB0
#define DB4_OD                   ODCONBbits.ODCB0
#define DB4_ANS                  ANSELBbits.ANSELB0
#define DB4_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define DB4_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define DB4_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define DB4_GetValue()           PORTBbits.RB0
#define DB4_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define DB4_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define DB4_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define DB4_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define DB4_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define DB4_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define DB4_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define DB4_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set DB5 aliases
#define DB5_TRIS                 TRISBbits.TRISB1
#define DB5_LAT                  LATBbits.LATB1
#define DB5_PORT                 PORTBbits.RB1
#define DB5_WPU                  WPUBbits.WPUB1
#define DB5_OD                   ODCONBbits.ODCB1
#define DB5_ANS                  ANSELBbits.ANSELB1
#define DB5_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define DB5_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define DB5_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define DB5_GetValue()           PORTBbits.RB1
#define DB5_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define DB5_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define DB5_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define DB5_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define DB5_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define DB5_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define DB5_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define DB5_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set DB6 aliases
#define DB6_TRIS                 TRISBbits.TRISB2
#define DB6_LAT                  LATBbits.LATB2
#define DB6_PORT                 PORTBbits.RB2
#define DB6_WPU                  WPUBbits.WPUB2
#define DB6_OD                   ODCONBbits.ODCB2
#define DB6_ANS                  ANSELBbits.ANSELB2
#define DB6_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define DB6_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define DB6_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define DB6_GetValue()           PORTBbits.RB2
#define DB6_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define DB6_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define DB6_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define DB6_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define DB6_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define DB6_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define DB6_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define DB6_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set DB7 aliases
#define DB7_TRIS                 TRISBbits.TRISB3
#define DB7_LAT                  LATBbits.LATB3
#define DB7_PORT                 PORTBbits.RB3
#define DB7_WPU                  WPUBbits.WPUB3
#define DB7_OD                   ODCONBbits.ODCB3
#define DB7_ANS                  ANSELBbits.ANSELB3
#define DB7_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define DB7_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define DB7_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define DB7_GetValue()           PORTBbits.RB3
#define DB7_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define DB7_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define DB7_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define DB7_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define DB7_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define DB7_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define DB7_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define DB7_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSELB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set TD aliases
#define TD_TRIS                 TRISCbits.TRISC0
#define TD_LAT                  LATCbits.LATC0
#define TD_PORT                 PORTCbits.RC0
#define TD_WPU                  WPUCbits.WPUC0
#define TD_OD                   ODCONCbits.ODCC0
#define TD_ANS                  ANSELCbits.ANSELC0
#define TD_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define TD_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define TD_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define TD_GetValue()           PORTCbits.RC0
#define TD_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define TD_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define TD_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define TD_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define TD_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define TD_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define TD_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define TD_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set TI aliases
#define TI_TRIS                 TRISCbits.TRISC1
#define TI_LAT                  LATCbits.LATC1
#define TI_PORT                 PORTCbits.RC1
#define TI_WPU                  WPUCbits.WPUC1
#define TI_OD                   ODCONCbits.ODCC1
#define TI_ANS                  ANSELCbits.ANSELC1
#define TI_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define TI_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define TI_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define TI_GetValue()           PORTCbits.RC1
#define TI_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define TI_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define TI_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define TI_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define TI_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define TI_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define TI_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define TI_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set HD aliases
#define HD_TRIS                 TRISCbits.TRISC2
#define HD_LAT                  LATCbits.LATC2
#define HD_PORT                 PORTCbits.RC2
#define HD_WPU                  WPUCbits.WPUC2
#define HD_OD                   ODCONCbits.ODCC2
#define HD_ANS                  ANSELCbits.ANSELC2
#define HD_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define HD_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define HD_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define HD_GetValue()           PORTCbits.RC2
#define HD_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define HD_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define HD_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define HD_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define HD_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define HD_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define HD_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define HD_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set HI aliases
#define HI_TRIS                 TRISCbits.TRISC3
#define HI_LAT                  LATCbits.LATC3
#define HI_PORT                 PORTCbits.RC3
#define HI_WPU                  WPUCbits.WPUC3
#define HI_OD                   ODCONCbits.ODCC3
#define HI_ANS                  ANSELCbits.ANSELC3
#define HI_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define HI_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define HI_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define HI_GetValue()           PORTCbits.RC3
#define HI_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define HI_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define HI_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define HI_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define HI_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define HI_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define HI_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define HI_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RHVal aliases
#define RHVal_TRIS                 TRISCbits.TRISC4
#define RHVal_LAT                  LATCbits.LATC4
#define RHVal_PORT                 PORTCbits.RC4
#define RHVal_WPU                  WPUCbits.WPUC4
#define RHVal_OD                   ODCONCbits.ODCC4
#define RHVal_ANS                  ANSELCbits.ANSELC4
#define RHVal_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RHVal_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RHVal_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RHVal_GetValue()           PORTCbits.RC4
#define RHVal_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RHVal_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RHVal_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define RHVal_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define RHVal_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define RHVal_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define RHVal_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RHVal_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS                 TRISCbits.TRISC5
#define RS_LAT                  LATCbits.LATC5
#define RS_PORT                 PORTCbits.RC5
#define RS_WPU                  WPUCbits.WPUC5
#define RS_OD                   ODCONCbits.ODCC5
#define RS_ANS                  ANSELCbits.ANSELC5
#define RS_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RS_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RS_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RS_GetValue()           PORTCbits.RC5
#define RS_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RS_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define RS_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define RS_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define RS_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define RS_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RS_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set R_W aliases
#define R_W_TRIS                 TRISCbits.TRISC6
#define R_W_LAT                  LATCbits.LATC6
#define R_W_PORT                 PORTCbits.RC6
#define R_W_WPU                  WPUCbits.WPUC6
#define R_W_OD                   ODCONCbits.ODCC6
#define R_W_ANS                  ANSELCbits.ANSELC6
#define R_W_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define R_W_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define R_W_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define R_W_GetValue()           PORTCbits.RC6
#define R_W_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define R_W_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define R_W_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define R_W_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define R_W_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define R_W_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define R_W_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define R_W_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set En aliases
#define En_TRIS                 TRISCbits.TRISC7
#define En_LAT                  LATCbits.LATC7
#define En_PORT                 PORTCbits.RC7
#define En_WPU                  WPUCbits.WPUC7
#define En_OD                   ODCONCbits.ODCC7
#define En_ANS                  ANSELCbits.ANSELC7
#define En_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define En_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define En_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define En_GetValue()           PORTCbits.RC7
#define En_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define En_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define En_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define En_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define En_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define En_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define En_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define En_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set TempVal aliases
#define TempVal_TRIS                 TRISDbits.TRISD3
#define TempVal_LAT                  LATDbits.LATD3
#define TempVal_PORT                 PORTDbits.RD3
#define TempVal_WPU                  WPUDbits.WPUD3
#define TempVal_OD                   ODCONDbits.ODCD3
#define TempVal_ANS                  ANSELDbits.ANSELD3
#define TempVal_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define TempVal_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define TempVal_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define TempVal_GetValue()           PORTDbits.RD3
#define TempVal_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define TempVal_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define TempVal_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define TempVal_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define TempVal_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define TempVal_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define TempVal_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define TempVal_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF0 pin functionality
 * @Example
    IOCCF0_ISR();
 */
void IOCCF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF0_SetInterruptHandler() method.
    This handler is called every time the IOCCF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(IOCCF0_InterruptHandler);

*/
extern void (*IOCCF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF0_SetInterruptHandler() method.
    This handler is called every time the IOCCF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(IOCCF0_DefaultInterruptHandler);

*/
void IOCCF0_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF1 pin functionality
 * @Example
    IOCCF1_ISR();
 */
void IOCCF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_InterruptHandler);

*/
extern void (*IOCCF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_DefaultInterruptHandler);

*/
void IOCCF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF2 pin functionality
 * @Example
    IOCCF2_ISR();
 */
void IOCCF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_InterruptHandler);

*/
extern void (*IOCCF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_DefaultInterruptHandler);

*/
void IOCCF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF3 pin functionality
 * @Example
    IOCCF3_ISR();
 */
void IOCCF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF3_SetInterruptHandler() method.
    This handler is called every time the IOCCF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(IOCCF3_InterruptHandler);

*/
extern void (*IOCCF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF3_SetInterruptHandler() method.
    This handler is called every time the IOCCF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(IOCCF3_DefaultInterruptHandler);

*/
void IOCCF3_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/