/*
 * ST7032.h - Library for controlling ST7032-based LCD, header file
 * (c) 2022-2025 @RR_Inyo
 */

#ifndef ST7032_H
#define	ST7032_H

#ifdef	__cplusplus
extern "C" {
#endif

// Constants (I2C address, register addresses, etc.)
#define ST7032_ADDRESS          0x3e
#define ST7032_COMMAND          0x00
#define ST7032_DATA             0x40

#define ST7032_CLEAR_DISPLAY    0x01
#define ST7032_RETURN_HOME      0x02
#define ST7032_ENTRY_MODE_I     0x06
#define ST7032_DISPLAY_ON       0x0c
#define ST7032_DISPLAY_OFF      0x08
#define ST7032_TWO_LINE         0x38
#define ST7032_TWO_LINE_IS1     0x39
#define ST7032_INTOSC_BIAS      0x14
#define ST7032_FOLLOWER_CTRL    0x6d
#define ST7032_SET_DDRAM_ADDR   0x80
#define ST7032_SET_CONTRAST_H   0x54
#define ST7032_SET_CONTRAST_L   0x70

#define ST7032_DEFAULT_CONT     0x1f

#define N_BUF 16

// Function prototypes
void ST7032_WriteCommand(uint8_t cmd);
void ST7032_WriteData(uint8_t data);
void ST7032_SetContrast(uint8_t cntr);
void ST7032_SetCursor(uint8_t loc);
void ST7032_DisplayOn(void);
void ST7032_DisplayOff(void);
void ST7032_ClearDisplay(void);
void ST7032_Initialize(void);
void ST7032_PutChar(char c);
void ST7032_PutString(char* buf);

#ifdef	__cplusplus
}
#endif

#endif	/* ST7032_H */

