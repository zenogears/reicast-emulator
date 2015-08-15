#include "linux-dist/evdev_mappings.h"
#include "hw/maple/controller.h"

#if defined(USE_EVDEV)

  ControllerMapping controller_mapping_generic = {
    "Generic Controller",
    { 
      { BTN_A,              DC_BTN_A      },
      { BTN_B,              DC_BTN_B      },
      { BTN_C,              DC_BTN_C      },
      { BTN_THUMBL,         DC_BTN_D      },
      { BTN_X,              DC_BTN_X      },
      { BTN_Y,              DC_BTN_Y      },
      { BTN_Z,              DC_BTN_Z      },
      { BTN_START,          DC_BTN_START  },
      { BTN_DPAD_LEFT,      DC_DPAD_LEFT  },
      { BTN_DPAD_RIGHT,     DC_DPAD_RIGHT },
      { BTN_DPAD_UP,        DC_DPAD_UP    },
      { BTN_DPAD_DOWN,      DC_DPAD_DOWN  }
    },
    ABS_X,
    ABS_Y,
    ABS_Z,
    ABS_RZ,
    BTN_SELECT,
    BTN_TL,
    BTN_TR,
    ABS_HAT0X,
    ABS_HAT0Y,
    ABS_HAT1X,
    ABS_HAT1Y
  };

  ControllerMapping controller_mapping_keyboard = {
    "Generic Keyboard",
    {
      { KEY_A,              DC_BTN_A      },
      { KEY_B,              DC_BTN_B      },
      { KEY_C,              DC_BTN_C      },
      { KEY_D,              DC_BTN_D      },
      { KEY_X,              DC_BTN_X      },
      { KEY_Y,              DC_BTN_Y      },
      { KEY_Z,              DC_BTN_Z      },
      { KEY_ENTER,          DC_BTN_START  },
      { KEY_LEFT,           DC_DPAD_LEFT  },
      { KEY_RIGHT,          DC_DPAD_RIGHT },
      { KEY_UP,             DC_DPAD_UP    },
      { KEY_DOWN,           DC_DPAD_DOWN  }
    },
    -1,
    -1,
    -1,
    -1,
    KEY_ESC,
    KEY_LEFTCTRL,
    KEY_RIGHTCTRL
  };

  ControllerMapping controller_mapping_xbox360 = {
    "XBox360 Controller",
    { 
      { BTN_A,              DC_BTN_A      },
      { BTN_B,              DC_BTN_B      },
      { BTN_TL,             DC_BTN_C      },
      { BTN_TR,             DC_BTN_D      },
      { BTN_X,              DC_BTN_X      },
      { BTN_Y,              DC_BTN_Y      },
      { BTN_THUMBL,         DC_BTN_Z      },
      { BTN_START,          DC_BTN_START  },
      { BTN_TRIGGER_HAPPY1, DC_DPAD_LEFT  },
      { BTN_TRIGGER_HAPPY2, DC_DPAD_RIGHT },
      { BTN_TRIGGER_HAPPY3, DC_DPAD_UP    },
      { BTN_TRIGGER_HAPPY4, DC_DPAD_DOWN  }
    },
    ABS_X,
    ABS_Y,
    ABS_Z,
    ABS_RZ,
    BTN_SELECT,
    -1,
    -1,
    ABS_HAT0X,
    ABS_HAT0Y,
    ABS_HAT1X,
    ABS_HAT1Y
  }
;
  ControllerMapping controller_mapping_gcwz = {
    "GCW Zero",
    { 
      { GCWZ_BTN_A,         DC_BTN_A      },
      { GCWZ_BTN_B,         DC_BTN_B      },
      { GCWZ_BTN_TL,        DC_BTN_C      },
      { GCWZ_BTN_TR,        DC_BTN_D      },
      { GCWZ_BTN_X,         DC_BTN_X      },
      { GCWZ_BTN_Y,         DC_BTN_Y      },
      { GCWZ_BTN_START,     DC_BTN_START  },
      { GCWZ_BTN_LEFT,      DC_DPAD_LEFT  },
      { GCWZ_BTN_RIGHT,     DC_DPAD_RIGHT },
      { GCWZ_BTN_UP,        DC_DPAD_UP    },
      { GCWZ_BTN_DOWN,      DC_DPAD_DOWN  }
    },
    -1,
    -1,
    -1,
    -1,
    GCWZ_BTN_SELECT
  };

  ControllerMapping controller_mapping_pandora = {
    "Pandora",
    {
      { KEY_PAGEDOWN,       DC_BTN_A      },
      { KEY_END,            DC_BTN_B      },
      { KEY_SPACE,          DC_BTN_C      },
      { KEY_HOME,           DC_BTN_X      },
      { KEY_PAGEUP,         DC_BTN_Y      },
      { KEY_LEFTALT,        DC_BTN_START  },
      { KEY_LEFT,           DC_DPAD_LEFT  },
      { KEY_RIGHT,          DC_DPAD_RIGHT },
      { KEY_UP,             DC_DPAD_UP    },
      { KEY_DOWN,           DC_DPAD_DOWN  }
    },
    -1,
    -1,
    -1,
    -1,
    KEY_MENU,
    KEY_RIGHTSHIFT,
    KEY_RIGHTCTRL
  };
#endif
  