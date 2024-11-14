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

// get/set PizoOutput aliases
#define PizoOutput_TRIS                 TRISBbits.TRISB3
#define PizoOutput_LAT                  LATBbits.LATB3
#define PizoOutput_PORT                 PORTBbits.RB3
#define PizoOutput_WPU                  WPUBbits.WPUB3
#define PizoOutput_OD                   ODCONBbits.ODCB3
#define PizoOutput_ANS                  ANSELBbits.ANSELB3
#define PizoOutput_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define PizoOutput_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define PizoOutput_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define PizoOutput_GetValue()           PORTBbits.RB3
#define PizoOutput_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define PizoOutput_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define PizoOutput_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define PizoOutput_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define PizoOutput_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define PizoOutput_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define PizoOutput_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define PizoOutput_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set LEDOutput aliases
#define LEDOutput_TRIS                 TRISBbits.TRISB4
#define LEDOutput_LAT                  LATBbits.LATB4
#define LEDOutput_PORT                 PORTBbits.RB4
#define LEDOutput_WPU                  WPUBbits.WPUB4
#define LEDOutput_OD                   ODCONBbits.ODCB4
#define LEDOutput_ANS                  ANSELBbits.ANSELB4
#define LEDOutput_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LEDOutput_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LEDOutput_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LEDOutput_GetValue()           PORTBbits.RB4
#define LEDOutput_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LEDOutput_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LEDOutput_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LEDOutput_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LEDOutput_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define LEDOutput_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define LEDOutput_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define LEDOutput_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set SwitchInput aliases
#define SwitchInput_TRIS                 TRISBbits.TRISB5
#define SwitchInput_LAT                  LATBbits.LATB5
#define SwitchInput_PORT                 PORTBbits.RB5
#define SwitchInput_WPU                  WPUBbits.WPUB5
#define SwitchInput_OD                   ODCONBbits.ODCB5
#define SwitchInput_ANS                  ANSELBbits.ANSELB5
#define SwitchInput_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SwitchInput_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SwitchInput_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SwitchInput_GetValue()           PORTBbits.RB5
#define SwitchInput_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SwitchInput_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SwitchInput_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SwitchInput_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SwitchInput_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SwitchInput_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SwitchInput_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define SwitchInput_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

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