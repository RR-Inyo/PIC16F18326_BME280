/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
? [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA1 aliases
#define SW_TRIS                 TRISAbits.TRISA1
#define SW_LAT                  LATAbits.LATA1
#define SW_PORT                 PORTAbits.RA1
#define SW_WPU                  WPUAbits.WPUA1
#define SW_OD                   ODCONAbits.ODCA1
#define SW_ANS                  ANSELAbits.ANSA1
#define SW_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SW_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SW_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SW_GetValue()           PORTAbits.RA1
#define SW_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SW_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SW_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define SW_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define SW_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define SW_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define SW_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define SW_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)
#define RA1_SetInterruptHandler  SW_SetInterruptHandler
// get/set IO_RA2 aliases
#define LED_TRIS                 TRISAbits.TRISA2
#define LED_LAT                  LATAbits.LATA2
#define LED_PORT                 PORTAbits.RA2
#define LED_WPU                  WPUAbits.WPUA2
#define LED_OD                   ODCONAbits.ODCA2
#define LED_ANS                  ANSELAbits.ANSA2
#define LED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_GetValue()           PORTAbits.RA2
#define LED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)
// get/set IO_RC0 aliases
#define SCL_TRIS                 TRISCbits.TRISC0
#define SCL_LAT                  LATCbits.LATC0
#define SCL_PORT                 PORTCbits.RC0
#define SCL_WPU                  WPUCbits.WPUC0
#define SCL_OD                   ODCONCbits.ODCC0
#define SCL_ANS                  ANSELCbits.ANSC0
#define SCL_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SCL_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SCL_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SCL_GetValue()           PORTCbits.RC0
#define SCL_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SCL_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SCL_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SCL_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SCL_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SCL_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SCL_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)
// get/set IO_RC1 aliases
#define SDA_TRIS                 TRISCbits.TRISC1
#define SDA_LAT                  LATCbits.LATC1
#define SDA_PORT                 PORTCbits.RC1
#define SDA_WPU                  WPUCbits.WPUC1
#define SDA_OD                   ODCONCbits.ODCC1
#define SDA_ANS                  ANSELCbits.ANSC1
#define SDA_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SDA_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SDA_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SDA_GetValue()           PORTCbits.RC1
#define SDA_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SDA_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SDA_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SDA_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SDA_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SDA_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SDA_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)
// get/set IO_RC2 aliases
#define LCD_Power_TRIS                 TRISCbits.TRISC2
#define LCD_Power_LAT                  LATCbits.LATC2
#define LCD_Power_PORT                 PORTCbits.RC2
#define LCD_Power_WPU                  WPUCbits.WPUC2
#define LCD_Power_OD                   ODCONCbits.ODCC2
#define LCD_Power_ANS                  ANSELCbits.ANSC2
#define LCD_Power_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LCD_Power_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LCD_Power_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LCD_Power_GetValue()           PORTCbits.RC2
#define LCD_Power_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LCD_Power_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LCD_Power_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LCD_Power_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LCD_Power_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LCD_Power_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LCD_Power_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LCD_Power_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define LCD_Power_2_TRIS                 TRISCbits.TRISC3
#define LCD_Power_2_LAT                  LATCbits.LATC3
#define LCD_Power_2_PORT                 PORTCbits.RC3
#define LCD_Power_2_WPU                  WPUCbits.WPUC3
#define LCD_Power_2_OD                   ODCONCbits.ODCC3
#define LCD_Power_2_ANS                  ANSELCbits.ANSC3
#define LCD_Power_2_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LCD_Power_2_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LCD_Power_2_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LCD_Power_2_GetValue()           PORTCbits.RC3
#define LCD_Power_2_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LCD_Power_2_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LCD_Power_2_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LCD_Power_2_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LCD_Power_2_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LCD_Power_2_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LCD_Power_2_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LCD_Power_2_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the SW pin functionality
 * @param none
 * @return none
 */
void SW_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for SW pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for SW at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void SW_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for SW pin.
 *        This is a dynamic interrupt handler to be used together with the SW_SetInterruptHandler() method.
 *        This handler is called every time the SW ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*SW_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for SW pin. 
 *        This is a predefined interrupt handler to be used together with the SW_SetInterruptHandler() method.
 *        This handler is called every time the SW ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void SW_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/