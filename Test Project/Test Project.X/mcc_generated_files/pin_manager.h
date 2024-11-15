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

// get/set LEDOut aliases
#define LEDOut_TRIS                 TRISAbits.TRISA0
#define LEDOut_LAT                  LATAbits.LATA0
#define LEDOut_PORT                 PORTAbits.RA0
#define LEDOut_WPU                  WPUAbits.WPUA0
#define LEDOut_OD                   ODCONAbits.ODCA0
#define LEDOut_ANS                  ANSELAbits.ANSELA0
#define LEDOut_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LEDOut_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LEDOut_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LEDOut_GetValue()           PORTAbits.RA0
#define LEDOut_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LEDOut_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LEDOut_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LEDOut_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LEDOut_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define LEDOut_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define LEDOut_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define LEDOut_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set SwitchInput aliases
#define SwitchInput_TRIS                 TRISAbits.TRISA1
#define SwitchInput_LAT                  LATAbits.LATA1
#define SwitchInput_PORT                 PORTAbits.RA1
#define SwitchInput_WPU                  WPUAbits.WPUA1
#define SwitchInput_OD                   ODCONAbits.ODCA1
#define SwitchInput_ANS                  ANSELAbits.ANSELA1
#define SwitchInput_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SwitchInput_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SwitchInput_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SwitchInput_GetValue()           PORTAbits.RA1
#define SwitchInput_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SwitchInput_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SwitchInput_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define SwitchInput_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define SwitchInput_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define SwitchInput_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define SwitchInput_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define SwitchInput_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

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