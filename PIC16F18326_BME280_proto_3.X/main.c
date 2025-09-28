 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
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
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/delay.h"
#include "ST7032.h"
#include "BME280.h"
#include "numstringify.h"

/*
 *  Global variables
*/
bool SLEEP_FLAG = false;
const int DEFAULT_CONTRAST = 38;

/*
 *  Interrupt handler for the push button
*/
void mySW_ISR(void)
{
    // Wait until chattering settles
    DELAY_milliseconds(20);
    
    if (!SW_GetValue()) {
        // Proceed when button if released
        DELAY_milliseconds(20);
        while (!SW_GetValue()) {
            // Do nothing here
        }
        DELAY_milliseconds(50);
        
        SLEEP_FLAG = true;
    }
    
    // Clear interrupt-on-change flag here to allow sleep        
    IOCAFbits.IOCAF1 = 0;
}

/*
 *  Main application
*/

int main(void)
{
    SYSTEM_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

    // Turn on LCD power, added RC3 pin to sink current
    LCD_Power_SetLow();
    LCD_Power_2_SetLow();
    
    // Wait
    DELAY_milliseconds(200);
    
    // Initialize I2C bus
    I2C1_Initialize();
    
    // Wait
    DELAY_milliseconds(100);
    
    // Initialize ST7032-based LCD
    ST7032_Initialize();
    ST7032_SetContrast(DEFAULT_CONTRAST);
    
    // Turn on LED
    LED_SetHigh();
    
    // Show message
    ST7032_SetCursor(0x00);
    ST7032_PutString("PIC16F18326     ");
    ST7032_SetCursor(0x40);
    ST7032_PutString(" BME280 Air-Moni");

    // Initialize BME280-based sensor
    if(BME280_Initialize()){
        ST7032_ClearDisplay();
        ST7032_SetCursor(0x00);
        ST7032_PutString("BME280 Failed!  ");
        while(1) {
            // Do nothing, infinate loop
        }
    }
    
    DELAY_milliseconds(500);
    
    // Set interrupt handler for the push button
    SW_SetInterruptHandler(mySW_ISR);
    
    // Clear LCD
    ST7032_ClearDisplay();    
      
    while(1) {
        // Turn on LED
        LED_SetHigh();
        
        // Perform BME280 measurement
        BME280_PerformMeasurement();
        while(BME280_IsMeasurementOngoing()){
            DELAY_milliseconds(10);
        }
        
        // Turn off LED
        LED_SetLow();
        
        float t = BME280_GetTemperatureCelcius();
        float p = BME280_GetPressurehPa();
        float h = BME280_GetHumidityPercentRH();
        char buf[16];
        
        // Show temperature
        numstringify(buf, t, 3, 5);
        ST7032_SetCursor(0x00);
        ST7032_PutString(buf);
        ST7032_PutChar((char) 0xdf);
        ST7032_PutString("C ");
        
        // Show humidity
        numstringify(buf, h, 3, 5);
        ST7032_SetCursor(0x0a);
        ST7032_PutString(buf);
        ST7032_PutString("% ");
        
        // Show pressure
        numstringify(buf, p, 5, 7);
        ST7032_SetCursor(0x40);
        ST7032_PutString(buf);
        ST7032_PutString(" hPa ");
        
        // ------------------------------------------------
        // Check sleep flag and go into sleep if true
        // ------------------------------------------------
        if (SLEEP_FLAG) {
            // Turn off LED
            LED_SetLow();

            // Clear interrupt-on-change flag here to allow sleep        
            IOCAFbits.IOCAF1 = 0;
            
            // Show message to sleep
            ST7032_ClearDisplay();
            ST7032_SetCursor(0x00);
            ST7032_PutString("Going to sleep..");
            ST7032_SetCursor(0x40);
            ST7032_PutString("Bye!  (=.=)zzz  ");            
            DELAY_milliseconds(1000);
            
            // Turn off LCD power, added RC3 pin to sink current
            LCD_Power_SetHigh();
            LCD_Power_2_SetHigh();

            // Disable peripheral interrupts 
            INTERRUPT_PeripheralInterruptDisable();

            // Get into sleep mode!
            SLEEP();
            NOP();
            
            // Turn on LCD power, added RC2
            LCD_Power_SetLow();
            LCD_Power_2_SetLow();
            
            // Enable peripheral interrupts 
            INTERRUPT_PeripheralInterruptEnable();
            
            // Wait for ST7032 power-up and internal initialization
            DELAY_milliseconds(100);
            
            // Initialize ST7032-based LCD
            ST7032_Initialize();
            ST7032_SetContrast(DEFAULT_CONTRAST);
            
            // Proceed when button if released
            DELAY_milliseconds(20);
            while (!SW_GetValue()) {
                // Do nothing here
            }
            DELAY_milliseconds(50);
            
            // Show message to wake up
            ST7032_ClearDisplay();
            ST7032_SetCursor(0x00);
            ST7032_PutString("Waking up!      ");
            ST7032_SetCursor(0x40);
            ST7032_PutString("Hello!  (^o^)/  ");            
            DELAY_milliseconds(1000);
            
            // Clear LCD
            ST7032_ClearDisplay();
            
            // Clear sleep flag
            SLEEP_FLAG = false;
            
            // Clear interrupt-on-change flag here to allow sleep        
            IOCAFbits.IOCAF1 = 0;
        }
        
        // Wait until Timer 1 overflows (500 ms)
        while (!TMR1_OverflowStatusGet()) {
            // Do nothing here. Just wait.
        }
        
        TMR1_OverflowStatusClear();
    }
}