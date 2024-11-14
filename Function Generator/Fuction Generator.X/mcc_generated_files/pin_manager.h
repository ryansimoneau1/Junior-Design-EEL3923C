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

// get/set DIP1 aliases
#define DIP1_TRIS                 TRISAbits.TRISA0
#define DIP1_LAT                  LATAbits.LATA0
#define DIP1_PORT                 PORTAbits.RA0
#define DIP1_WPU                  WPUAbits.WPUA0
#define DIP1_OD                   ODCONAbits.ODCA0
#define DIP1_ANS                  ANSELAbits.ANSELA0
#define DIP1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define DIP1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define DIP1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define DIP1_GetValue()           PORTAbits.RA0
#define DIP1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define DIP1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define DIP1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define DIP1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define DIP1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define DIP1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define DIP1_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define DIP1_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set DIP2 aliases
#define DIP2_TRIS                 TRISAbits.TRISA1
#define DIP2_LAT                  LATAbits.LATA1
#define DIP2_PORT                 PORTAbits.RA1
#define DIP2_WPU                  WPUAbits.WPUA1
#define DIP2_OD                   ODCONAbits.ODCA1
#define DIP2_ANS                  ANSELAbits.ANSELA1
#define DIP2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define DIP2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define DIP2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define DIP2_GetValue()           PORTAbits.RA1
#define DIP2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define DIP2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define DIP2_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define DIP2_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define DIP2_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define DIP2_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define DIP2_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define DIP2_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set CS aliases
#define CS_TRIS                 TRISBbits.TRISB5
#define CS_LAT                  LATBbits.LATB5
#define CS_PORT                 PORTBbits.RB5
#define CS_WPU                  WPUBbits.WPUB5
#define CS_OD                   ODCONBbits.ODCB5
#define CS_ANS                  ANSELBbits.ANSELB5
#define CS_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define CS_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define CS_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define CS_GetValue()           PORTBbits.RB5
#define CS_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define CS_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define CS_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set Frequency_CTRL aliases
#define Frequency_CTRL_TRIS                 TRISDbits.TRISD1
#define Frequency_CTRL_LAT                  LATDbits.LATD1
#define Frequency_CTRL_PORT                 PORTDbits.RD1
#define Frequency_CTRL_WPU                  WPUDbits.WPUD1
#define Frequency_CTRL_OD                   ODCONDbits.ODCD1
#define Frequency_CTRL_ANS                  ANSELDbits.ANSELD1
#define Frequency_CTRL_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define Frequency_CTRL_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define Frequency_CTRL_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define Frequency_CTRL_GetValue()           PORTDbits.RD1
#define Frequency_CTRL_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define Frequency_CTRL_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define Frequency_CTRL_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define Frequency_CTRL_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define Frequency_CTRL_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define Frequency_CTRL_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define Frequency_CTRL_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define Frequency_CTRL_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/