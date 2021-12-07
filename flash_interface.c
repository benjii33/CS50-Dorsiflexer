#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"
#include "flash_interface.h"
#include "hardware/flash.h"
#include "hardware/sync.h"
#include "hardware/gpio.h"

// Doesn't really init flash
void flash_init() {
    settingsFlashOffset = 256 * 1024; // 256k from start of flash

    flashSettingsTarget = (uint8_t *)(XIP_BASE + settingsFlashOffset);

    settingsBuffer = calloc(FLASH_PAGE_SIZE, sizeof(uint8_t));
    
    memcpy(settingsBuffer, flashSettingsTarget, FLASH_PAGE_SIZE); // Get settings from flash
}

void flash_update_setting(settings setting, uint16_t new_value) {
    settingsBuffer[(uint8_t)setting] = new_value >> 8; // Upper half
    settingsBuffer[(uint8_t)setting + 1] = new_value & 0xFF; // Lower half

    uint32_t ints = save_and_disable_interrupts();
    flash_range_erase(settingsFlashOffset, 4096);
    flash_range_program(settingsFlashOffset, settingsBuffer, FLASH_PAGE_SIZE);
    restore_interrupts(ints);
}

uint16_t flash_get_setting(settings setting) {
    uint16_t retval;
    retval = (settingsBuffer[(uint8_t)setting] << 8) | settingsBuffer[(uint8_t)setting + 1]; // Upper half + lower half

    return retval;
}