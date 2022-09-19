/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define IGNORE_MOD_TAP_INTERRUPT
#undef TAPPING_TERM
#define TAPPING_TERM 150

#define ONESHOT_TAP_TOGGLE 4

#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0
#define AUTO_SHIFT_TIMEOUT 160
#define NO_AUTO_SHIFT_NUMERIC
#define CAPS_LOCK_STATUS
#define HOLD_ON_OTHER_KEY_PRESS
#define FIRMWARE_VERSION u8"r5KK9/RPyr5"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define RGB_MATRIX_STARTUP_SPD 60
