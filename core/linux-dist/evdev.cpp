#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include "linux-dist/evdev.h"
#include "linux-dist/main.h"
#include "hw/maple/controller.h"

#if defined(USE_EVDEV)

  int input_evdev_init(Controller* controller, u32 port, const char* device)
  {
    char name[256] = "Unknown";

    printf("evdev: Trying to open device at '%s'\n", device);

    int fd = open(device, O_RDONLY);

    if (fd >= 0)
    {
      fcntl(fd, F_SETFL, O_NONBLOCK);
      if(ioctl(fd, EVIOCGNAME(sizeof(name)), name) < 0)
      {
        perror("evdev: ioctl");
        return -2;
      }
      else
      {
        printf("evdev: Found '%s' at '%s'\n", name, device);

        controller->fd = fd;

        #if defined(TARGET_PANDORA)
          *controller.mapping = &controller_mapping_pandora;
        #elif defined(TARGET_GCW0)
          *controller.mapping = &controller_mapping_gcwz;
        #else
          if (strcmp(name, "Microsoft X-Box 360 pad") == 0 ||
              strcmp(name, "Xbox Gamepad (userspace driver)") == 0 ||
              strcmp(name, "Xbox 360 Wireless Receiver (XBOX)") == 0)
          {
              controller->mapping = &controller_mapping_xbox360;
          }
          else if (strstr(name, "keyboard") != NULL ||
                   strstr(name, "Keyboard") != NULL)
          {
              controller->mapping = &controller_mapping_keyboard;
          }
          else
          {
              controller->mapping = &controller_mapping_generic;
          }
        #endif
        printf("evdev: Using '%s' mapping\n", controller->mapping->name);

        dc_controller_state[port].enabled = true;

        return 0;
      }
    }
    else
    {
      perror("evdev: open");
      return -1;
    }
  }

  bool input_evdev_handle(Controller* controller, u32 port)
  {
    if (dc_controller_state[port].enabled == 0 || controller->fd < 0 || controller->mapping == NULL)
    {
      return false;
    }

    input_event ie;

    while(read(controller->fd, &ie, sizeof(ie)) == sizeof(ie))
    {
      if(ie.type != EV_SYN)
      {
        printf("type %i key %i state %i\n", ie.type, ie.code, ie.value);
      }
      switch(ie.type)
      {
        case EV_KEY:
          if (controller->mapping->buttons.count(ie.code) == 1) {
            dc_controller_state[port].set_key(controller->mapping->buttons[ie.code], ie.value);
          } else  if (ie.code == controller->mapping->Btn_Escape) {
            die("death by escape key");
          } else if (ie.code == controller->mapping->Btn_Trigger_Left) {
            lt[port] = (ie.value ? 255 : 0);
          } else if (ie.code == controller->mapping->Btn_Trigger_Right) {
            rt[port] = (ie.value ? 255 : 0);
          }
          break;
        case EV_ABS:
          if (ie.code == controller->mapping->Axis_DPad_X) {
            switch(ie.value)
            {
              case -1:
                dc_controller_state[port].set_key(DC_DPAD_LEFT,  1);
                dc_controller_state[port].set_key(DC_DPAD_RIGHT, 0);
                break;
              case 0:
                dc_controller_state[port].set_key(DC_DPAD_LEFT,  0);
                dc_controller_state[port].set_key(DC_DPAD_RIGHT, 0);
                break;
              case 1:
                dc_controller_state[port].set_key(DC_DPAD_LEFT,  0);
                dc_controller_state[port].set_key(DC_DPAD_RIGHT, 1);
                break;
            }
          } else if (ie.code == controller->mapping->Axis_DPad_Y) {
            switch(ie.value)
            {
              case -1:
                dc_controller_state[port].set_key(DC_DPAD_UP,   1);
                dc_controller_state[port].set_key(DC_DPAD_DOWN, 0);
                break;
              case 0:
                dc_controller_state[port].set_key(DC_DPAD_UP,   0);
                dc_controller_state[port].set_key(DC_DPAD_DOWN, 0);
                break;
              case 1:
                dc_controller_state[port].set_key(DC_DPAD_UP,   0);
                dc_controller_state[port].set_key(DC_DPAD_DOWN, 1);
                break;
            }
          } else if (ie.code == controller->mapping->Axis_DPad2_X) {
            switch(ie.value)
            {
              case -1:
                dc_controller_state[port].set_key(DC_DPAD2_LEFT,  1);
                dc_controller_state[port].set_key(DC_DPAD2_RIGHT, 0);
                break;
              case 0:
                dc_controller_state[port].set_key(DC_DPAD2_LEFT,  0);
                dc_controller_state[port].set_key(DC_DPAD2_RIGHT, 0);
                break;
              case 1:
                dc_controller_state[port].set_key(DC_DPAD2_LEFT,  0);
                dc_controller_state[port].set_key(DC_DPAD2_RIGHT, 1);
                break;
            }
          } else if (ie.code == controller->mapping->Axis_DPad2_X) {
            switch(ie.value)
            {
              case -1:
                dc_controller_state[port].set_key(DC_DPAD2_UP,   1);
                dc_controller_state[port].set_key(DC_DPAD2_DOWN, 0);
                break;
              case 0:
                dc_controller_state[port].set_key(DC_DPAD2_UP,  0);
                dc_controller_state[port].set_key(DC_DPAD2_DOWN, 0);
                break;
              case 1:
                dc_controller_state[port].set_key(DC_DPAD2_UP,  0);
                dc_controller_state[port].set_key(DC_DPAD2_DOWN, 1);
                break;
            }
          } else if (ie.code == controller->mapping->Axis_Analog_X) {
            printf("%d", ie.value);
            joyx[port] = (s8)(ie.value/256);
          } else if (ie.code == controller->mapping->Axis_Analog_Y) {
            joyy[port] = (s8)(ie.value/256);
          } else if (ie.code == controller->mapping->Axis_Trigger_Left) {
            lt[port] = (s8)ie.value;
          } else if (ie.code == controller->mapping->Axis_Trigger_Right) {
            rt[port] = (s8)ie.value;
          }
        break;
      }
    }
    kcode[port] = dc_controller_state[port].keycodes;
    joyx[port] = dc_controller_state[port].analog_x;
    joyy[port] = dc_controller_state[port].analog_y;
    lt[port] = dc_controller_state[port].trigger_left;
    rt[port] = dc_controller_state[port].trigger_right;
  }
#endif