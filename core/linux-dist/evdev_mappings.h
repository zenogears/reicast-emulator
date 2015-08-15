#pragma once
#include <linux/input.h>
#include <map>

/* GCW Zero Button Codes */
#define GCWZ_BTN_A      0x1D
#define GCWZ_BTN_B      0x38
#define GCWZ_BTN_TL     0x0F
#define GCWZ_BTN_TR     0x0E
#define GCWZ_BTN_X      0x2A
#define GCWZ_BTN_Y      0x39
#define GCWZ_BTN_START  0x1C
#define GCWZ_BTN_SELECT 0x01
#define GCWZ_BTN_LEFT   0x69
#define GCWZ_BTN_RIGHT  0x6A
#define GCWZ_BTN_UP     0x67
#define GCWZ_BTN_DOWN   0x6C

/* Controller Mapping */
struct s_evdev_controller_mapping
{
  const char* name;

  /* Buttons and axes that directly map to their
   * Dreamcast Controller counterpart.
   */
  const std::map <int, int> buttons;
  const int Axis_Analog_X;
  const int Axis_Analog_Y;
  const int Axis_Trigger_Left;
  const int Axis_Trigger_Right;

  /* Escape button, useful for quitting the emulator.
   */
  const int Btn_Escape;

  /* Digital trigger buttons. These will emulate
   * the analog Dreamcast triggers.
   */
  const int Btn_Trigger_Left;
  const int Btn_Trigger_Right;

  /* Analog DPad axes. These will emulate the
   * digital Dreamcast DPad.
   */
  const int Axis_DPad_X;
  const int Axis_DPad_Y;
  const int Axis_DPad2_X;
  const int Axis_DPad2_Y;
};
typedef struct s_evdev_controller_mapping ControllerMapping;

extern ControllerMapping controller_mapping_generic;
extern ControllerMapping controller_mapping_keyboard;
extern ControllerMapping controller_mapping_xbox360;
extern ControllerMapping controller_mapping_gcwz;
extern ControllerMapping controller_mapping_pandora;
