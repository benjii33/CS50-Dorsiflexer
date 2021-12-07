#ifndef actions_h
#define actions_h

#define MAX_LINKS 10

#include "menu_defs.h"

menuLink* linkStack;

menuID currentMenu;

void actions_init();

void actions_clearLinks();

uint8_t actions_addAction(uint16_t x, uint16_t y, uint16_t width, uint16_t height, menuAction action);

uint8_t actions_addLink(uint16_t x, uint16_t y, uint16_t width, uint16_t height, menuID menu);

uint8_t actions_addSetting(uint16_t x, uint16_t y, uint16_t width, uint16_t height, settings setting, settingActions settingAction);

uint8_t actions_testAction(uint16_t x, uint16_t y);

void actions_executeAction(menuLink activeLink);

void actions_renderMenu(menuID menu);

void actions_updateMenu();

void actions_updateSetting(settings setting, settingActions settingAction);

#endif