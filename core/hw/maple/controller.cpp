#include "hw/maple/controller.h"

DreamcastController::DreamcastController(bool enable) {
  enabled = enable;
  keycodes = 0xFFFF;
  trigger_left = 0;
  trigger_right = 0;
  analog_x = 0;
  analog_y = 0;
};

void DreamcastController::set_key(u16 mask, bool value)
{
  if (value)
  {
    this->keycodes |= mask;
  }
  else
  {
    this->keycodes &= ~mask;
  }
};

std::vector<DreamcastController> dc_controller_state (4, 0);