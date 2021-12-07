#ifndef LCD_interface_h
#define LCD_interface_h

#include "hardware/pio.h"

#define LCD_PARALLEL_BASE 0

#define LCD_RST 8
#define LCD_RD 9 // Read strobe/clock (Active Low)
#define LCD_WR 10 // Write strobe/clock (Active Low)
#define LCD_CD 11 // Command/Data (Command Low)
#define LCD_CS 12 // Chip Select (Active Low)

void LCD_init();

void LCD_write_byte(uint8_t byte);

void LCD_flood(uint32_t color);

void LCD_rect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);

void LCD_buffer(uint8_t *buf, uint16_t x, uint16_t y, uint16_t width, uint16_t height);

void LCD_text(uint16_t x, uint16_t y, char *string, uint32_t color, uint32_t backgroundColor);

#endif