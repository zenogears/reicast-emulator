#pragma once
#include <vector>
#include "types.h"

enum DreamcastControllerButtons
{
  DC_BTN_C       = 1,
  DC_BTN_B       = 1<<1,
  DC_BTN_A       = 1<<2,
  DC_BTN_START   = 1<<3,
  DC_DPAD_UP     = 1<<4,
  DC_DPAD_DOWN   = 1<<5,
  DC_DPAD_LEFT   = 1<<6,
  DC_DPAD_RIGHT  = 1<<7,
  DC_BTN_Z       = 1<<8,
  DC_BTN_Y       = 1<<9,
  DC_BTN_X       = 1<<10,
  DC_BTN_D       = 1<<11,
  DC_DPAD2_UP    = 1<<12,
  DC_DPAD2_DOWN  = 1<<13,
  DC_DPAD2_LEFT  = 1<<14,
  DC_DPAD2_RIGHT = 1<<15,

  DC_AXIS_LT = 0X10000,
  DC_AXIS_RT = 0X10001,
  DC_AXIS_X  = 0X20000,
  DC_AXIS_Y  = 0X20001,
};

class DreamcastController
{
  public:
    bool enabled;
    u16 keycodes;
    u8 trigger_left; // Allowed values: 0 to 255
    u8 trigger_right;
    s8 analog_x; // Allowed values: -127 to +127
    s8 analog_y;

    DreamcastController(bool);
    void set_key(u16, bool);
};

extern std::vector<DreamcastController> dc_controller_state;
