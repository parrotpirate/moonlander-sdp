/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#pragma once
#define ORYX_CONFIGURATOR
#define IGNORE_MOD_TAP_INTERRUPT
#undef TAPPING_TERM
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

#define ONESHOT_TAP_TOGGLE 4

#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0
#define AUTO_SHIFT_TIMEOUT 160
#define NO_AUTO_SHIFT_NUMERIC
#define CAPS_LOCK_STATUS
#define HOLD_ON_OTHER_KEY_PRESS
#define LAYER_STATE_8BIT
#define RGB_MATRIX_STARTUP_SPD 60

#undef DEBOUNCE_DELAY
#define DEBOUNCE_DELAY 5

#define COMBO_COUNT 1
