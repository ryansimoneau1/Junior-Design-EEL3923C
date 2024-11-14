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

// get/set channel_ANA0 aliases
#define channel_ANA0_TRIS                 TRISAbits.TRISA0
#define channel_ANA0_LAT                  LATAbits.LATA0
#define channel_ANA0_PORT                 PORTAbits.RA0
#define channel_ANA0_WPU                  WPUAbits.WPUA0
#define channel_ANA0_OD                   ODCONAbits.ODCA0
#define channel_ANA0_ANS                  ANSELAbits.ANSELA0
#define channel_ANA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_ANA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_ANA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_ANA0_GetValue()           PORTAbits.RA0
#define channel_ANA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_ANA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_ANA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define channel_ANA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define channel_ANA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define channel_ANA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define channel_ANA0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define channel_ANA0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

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