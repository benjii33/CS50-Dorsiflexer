#ifndef actuator_interface_h
#define actuator_interface_h

#define AH 14 // A high
#define AL 15 // A low
#define BH 16 // B low
#define BL 17 // B low

#define act_FB 28 // Analog feedback from actuator

uint8_t A_slice_num;
uint8_t B_slice_num;

void actuator_init();

void actuator_set_power(uint16_t power, bool dir);

uint16_t actuator_get_position();

uint16_t actuator_get_force();

#endif