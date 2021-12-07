#ifndef graphics_h
#define graphics_h

#include "pico/stdlib.h"
#include "menu_defs.h"

void graphics_text(uint16_t x, uint16_t y, char *string, float size, uint32_t color, uint32_t backgroundColor);

uint8_t* graphics_scale(uint8_t* buf, uint16_t width, uint16_t height, float xfactor, float yfactor);

void graphics_value(uint16_t x, uint16_t y, valueID id, float size, uint32_t color, uint32_t backgroundColor);

void graphics_setting(uint16_t x, uint16_t y, settings setting, float size, uint32_t color, uint32_t backgroundColor);

void graphics_icon(uint16_t x, uint16_t y, iconType icon, float size);

#endif