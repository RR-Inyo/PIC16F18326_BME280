/*
 * ST7032.c - Library for controlling ST7032-based LCD, source file
 * (c) 2022-2025 @RR_Inyo
 */

#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/i2c_host/mssp1.h"
#include "mcc_generated_files/timer/delay.h"
#include "ST7032.h"

// Functions to control ST7032-based character LCD
void ST7032_WriteCommand(uint8_t cmd)
{
    uint8_t buf[2];
    buf[0] = ST7032_COMMAND;
    buf[1] = cmd;
    while(I2C1_IsBusy()) {
        // Wait until I2C bus is available
    }
    I2C1_Write(ST7032_ADDRESS, buf, 2);
    DELAY_microseconds(600);
}

// Functions to control ST7032-based character LCD
void ST7032_WriteData(uint8_t data)
{  
    uint8_t buf[2];
    buf[0] = ST7032_DATA;
    buf[1] = data;
    while(I2C1_IsBusy()) {
        // Wait until I2C bus is available
    }
    I2C1_Write(ST7032_ADDRESS, buf, 2);
    DELAY_microseconds(600);
}

void ST7032_SetContrast(uint8_t cntr)
{
    uint8_t cntr_L, cntr_H;
    cntr_L = cntr & 0b00001111;
    cntr_H = (cntr & 0b00110000) >> 4;
    ST7032_WriteCommand(ST7032_TWO_LINE_IS1);
    ST7032_WriteCommand(ST7032_SET_CONTRAST_L | cntr_L);
    ST7032_WriteCommand(ST7032_SET_CONTRAST_H | cntr_H);
    ST7032_WriteCommand(ST7032_TWO_LINE);
}

void ST7032_SetCursor(uint8_t loc)
{
    ST7032_WriteCommand(ST7032_SET_DDRAM_ADDR | loc);
}

void ST7032_DisplayOn(void)
{
    ST7032_WriteCommand(ST7032_DISPLAY_ON);
}

void ST7032_DisplayOff(void)
{
    ST7032_WriteCommand(ST7032_DISPLAY_OFF);
}

void ST7032_ClearDisplay(void)
{
    ST7032_WriteCommand(ST7032_CLEAR_DISPLAY);
}

// Function to initialize ST7032-based character LCD
void ST7032_Initialize(void)
{
    // Wait for 50 ms
    DELAY_milliseconds(50);
    
    // Initialize ST7032-based character LCD
    ST7032_WriteCommand(ST7032_TWO_LINE);
    ST7032_WriteCommand(ST7032_TWO_LINE_IS1);
    ST7032_WriteCommand(ST7032_INTOSC_BIAS);
    ST7032_WriteCommand(ST7032_SET_CONTRAST_L | (0b00001111 & ST7032_DEFAULT_CONT));
    ST7032_WriteCommand(ST7032_SET_CONTRAST_H | ((0b00110000 & ST7032_DEFAULT_CONT) >> 4));
    ST7032_WriteCommand(ST7032_FOLLOWER_CTRL);
    DELAY_milliseconds(200);
    ST7032_WriteCommand(ST7032_TWO_LINE);
    ST7032_WriteCommand(ST7032_DISPLAY_ON);
    ST7032_WriteCommand(ST7032_RETURN_HOME);
    ST7032_WriteCommand(ST7032_ENTRY_MODE_I);
    ST7032_WriteCommand(ST7032_CLEAR_DISPLAY);
}

void ST7032_PutChar(char c)
{
    ST7032_WriteData((uint8_t) c);                                
}

void ST7032_PutString(char* buf)
{
    for (int i = 0; i < N_BUF; i++) {
        if (buf[i] != '\0') {
            ST7032_PutChar(buf[i]);
        }
        else {
            break;
        }
    }
}
