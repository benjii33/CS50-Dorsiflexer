#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "LCD_interface.h"
#include "touch_interface.h"
#include "graphics.h"
#include "menu.h"
#include "actuator_interface.h"
#include "actions.h"
#include "flash_interface.h"

int main() {
    stdio_init_all();
    set_sys_clock_khz(130000, true);

    LCD_init();
    touch_init();
    actuator_init();
    actions_init();
    flash_init();

    // flash_update_setting(ACTUATOR_FORCE_LIMIT, 10);
    // flash_update_setting(ACTUATOR_SPEED_LIMIT, 100);
    // flash_update_setting(ACTUATOR_TIME_DELAY, 2);

    menu_HOME_SCREEN_render();

    uint16_t x = 0, y = 0;

    while(true) {
        x = touch_getX();
        y = touch_getY();
        
        actions_testAction(x, y);

        actions_updateMenu();
    
        sleep_ms(50);
    }
}