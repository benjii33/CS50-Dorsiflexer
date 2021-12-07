#ifndef touch_interface_h
#define touch_interface_h

#define touch_XL 22 // Y+
#define touch_XR 27 // Y-
#define touch_YU 26 // X-
#define touch_YD 21 // X+

#define touch_XIN 0
#define touch_YIN 1

#define touch_sample_delay 10

int touch_getX();

int touch_getY();

void touch_init();

#endif