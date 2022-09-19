#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

typedef struct {
    bool is_press_action;
    int state;
} tap;

// CUSTOM KEYCODES
enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    MC_DBL_ARW,
    MC_SGL_ARW,
    DYNAMIC_MACRO_RANGE,
    DRAGLOCK = SAFE_RANGE,
    LEFTCLICK = EZ_SAFE_RANGE,
};

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD,
    MORE_TAPS,
};

// TAP DANCE CODES
enum tap_dance_codes {
    TD_LSHIFT,
    TD_RSHIFT,
    TD_COLON,
    TD_RGUI,
    TD_FLSH,
    TD_CAPS,
    TD_SHORTCAT,
};

// TRACK ACTIVE LAYER
int active_layer

// TRACK CAPS LOCK STATE
int caps_state

// COMBO KEYS
const uint16_t PROGMEM jkesc[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(jkesc, KC_ESC),
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           DYN_MACRO_PLAY1,                                TD(TD_FLSH),    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_DELETE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TD(TD_SHORTCAT),                                MO(3),          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    TD(TD_CAPS),    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_HYPR,                                        KC_MEH,         KC_H,           KC_J,           KC_K,           KC_L,           TD(TD_COLON),    TD(TD_RGUI),
    TD(TD_LSHIFT),  MT(MOD_LCTL, KC_Z),KC_X,        KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         MT(MOD_RCTL, KC_SLASH),TD(TD_RSHIFT),
    CAPS_WORD,      KC_LALT,        LALT(KC_LSHIFT),KC_LEFT,        KC_RIGHT,       MT(MOD_LALT, KC_APPLICATION),                                                   MT(MOD_LCTL, KC_ESCAPE),KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    DYN_REC_STOP,
    LT(1,KC_SPACE), KC_BSPACE,      LSFT(KC_LGUI),                  MT(MOD_LALT, KC_ESCAPE),KC_TAB,         LT(1,KC_ENTER)
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        TD(DANCE_4),    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    LCTL(KC_LBRACKET),KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     KC_TRANSPARENT,
    ST_MACRO_0,     KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,                                        KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_SLASH,       ST_MACRO_1,
    KC_TRANSPARENT, KC_COMMA,       HSV_0_255_255,  HSV_86_255_128, HSV_172_255_255,RGB_MOD,                                                                                                        RGB_TOG,        KC_0,           KC_DOT,         KC_MINUS,       KC_EQUAL,       KC_TRANSPARENT,
    TD(DANCE_5),    RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
    MU_TOG,         KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    MU_MOD,         KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  LALT(LCTL(LSFT(KC_C))),KC_MS_WH_RIGHT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
    LEFTCLICK,      KC_MS_BTN2,     DRAGLOCK,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, DYN_REC_START1, DYN_REC_START2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,KC_TRANSPARENT, DYN_REC_STOP,   KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
    MU_TOG,         KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    MU_MOD,         KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       TG(4),          KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  LALT(LCTL(LSFT(KC_C))),KC_MS_WH_RIGHT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
    LEFTCLICK,      KC_MS_BTN2,     DRAGLOCK,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,255}, {0,0,255}, {67,248,234}, {67,248,234}, {215,255,254}, {0,0,255}, {0,0,255}, {0,0,255}, {67,248,234}, {67,248,234}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {67,248,234}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {246,237,255}, {215,255,254}, {67,248,234}, {140,255,255}, {0,0,255}, {67,248,234}, {0,0,255}, {0,0,255}, {0,0,255}, {67,248,234}, {67,248,234}, {246,237,255}, {0,0,255}, {0,0,255}, {94,228,254}, {67,248,234}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {215,255,254}, {246,237,255}, {67,248,234}, {140,255,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [1] = { {140,255,255}, {140,255,255}, {140,255,255}, {215,255,254}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {215,255,254}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255}, {140,255,255} },

    [2] = { {94,228,254}, {94,228,254}, {94,228,254}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {94,228,254}, {94,228,254}, {94,228,254}, {0,0,0}, {0,0,0}, {94,228,254}, {94,228,254}, {94,228,254}, {94,228,254}, {0,0,0}, {94,228,254}, {94,228,254}, {94,228,254}, {94,228,254}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {94,228,254}, {94,228,254}, {0,0,0}, {0,0,0}, {215,255,254}, {0,0,0}, {94,228,254}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {94,228,254}, {94,228,254}, {94,228,254}, {0,0,0}, {0,0,0}, {94,228,254}, {94,228,254}, {94,228,254}, {0,0,0}, {0,0,0}, {94,228,254}, {94,228,254}, {94,228,254}, {0,0,0}, {0,0,0}, {94,228,254}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {246,237,255}, {246,237,255}, {246,237,255}, {0,0,0}, {0,0,0}, {246,237,255}, {246,237,255}, {246,237,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {246,237,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool drag_lock_toggle = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MC_SGL_ARW:
            if (record->event.pressed) {
                SEND_STRING("->");
            } else {
                return true;
            }
            return false;
        case MC_DBL_ARW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            } else {
                return true;
            }
            return false;
        case DRAGLOCK:
            if (record->event.pressed && !drag_lock_toggle) {
                register_code(KC_MS_BTN1);
                ergodox_right_led_3_on();
                drag_lock_toggle = true;
            } else if (record->event.pressed && drag_lock_toggle) {
                unregister_code(KC_MS_BTN1);
                ergodox_right_led_3_off();
                drag_lock_toggle = false;
                return true;
            }
            return false;
        case LEFTCLICK:
            if (record->event.pressed) {
                if (drag_lock_toggle) {
                    unregister_code(KC_MS_BTN1);
                    ergodox_right_led_3_off();
                    drag_lock_toggle = false;
                    return true;
                } else {
                    register_code(KC_MS_BTN1);
                }
            } else {
                unregister_code(KC_MS_BTN1);
            }
            return false;

        default:
            return true;
    }
  return true;
}

static tap dance_state[8];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    }
    return MORE_TAPS;
}

// LEFT SHIFT TAP DANCE
static tap td_lshift_state = {.is_press_action = true, .state = 0};
void td_lshift_finished(qk_tap_dance_state_t *state, void *user_data);
void td_lshift_reset(qk_tap_dance_state_t *state, void *user_data);

void td_lshift_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_lshift_state.step = dance_step(state);
    switch (td_lshift_state.step) {
        case SINGLE_TAP:
            register_code16(LSFT(KC_9));
            break;
        case SINGLE_HOLD:
            register_code16(KC_LSFT);
            break;
        case DOUBLE_TAP:
            register_code16(LSFT(KC_LBRC));
            break;
        case TRIPLE_TAP:
            register_code16(KC_LBRC);
            break;
    }
}

void td_lshift_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_lshift_state.step) {
        case SINGLE_TAP:  // type "("
            unregister_code16(LSFT(KC_9));
            break;
        case SINGLE_HOLD:  // release "shift"
            unregister_code(KC_LSFT);
            break;
        case DOUBLE_TAP:  // type "{"
            unregister_code(LSFT(KC_LBRC));
            break;
        case TRIPLE_TAP:  // type "["
            unregister_code(KC_LBRC);
    }
    td_lshift_state.step = 0;
}

// RIGHT SHIFT TAP DANCE
static tap td_rshift_state     = {.is_press_action = true, .state = 0};
void td_rshift_finished(qk_tap_dance_state_t *state, void *user_data);
void td_rshift_reset(qk_tap_dance_state_t *state, void *user_data);

void td_rshift_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_rshift_state.step = dance_step(state);
    switch (td_rshift_state.step) {
        case SINGLE_TAP:
            register_code16(LSFT(KC_0));
            break;
        case SINGLE_HOLD:
            register_code16(KC_RSFT);
            break;
        case DOUBLE_TAP:
            register_code16(LSFT(KC_RBRC));
            break;
        case TRIPLE_TAP:
            register_code16(KC_RBRC);
            break;
    }
}

void td_rshift_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_rshift_state.step) {
        case SINGLE_TAP:
            unregister_code16(LSFT(KC_0));
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_RSFT);
            break;
        case DOUBLE_TAP:
            unregister_code16(LSFT(KC_RBRC));
            break;
        case TRIPLE_TAP:
            unregister_code16(KC_RBRC);
            break;
    }
    td_rshift_state.state = 0;
}

static tap td_colon_state      = {.is_press_action = true, .state = 0};
void td_colon_finished(qk_tap_dance_state_t *state, void *user_data);
void td_colon_reset(qk_tap_dance_state_t *state, void *user_data);

void td_colon_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_colon_state.step = dance_step(state);
    switch (td_colon_state.step) {
        case SINGLE_TAP:
            if (active_layer == 2) {
                if (drag_lock_toggle) {
                    unregister_code16(KC_MS_BTN1);
                    // ergodox_right_led_3_off();
                    drag_lock_toggle = false;
                }
                layer_off(2);
            } else if (active_layer == 4) {
                if (drag_lock_toggle) {
                    unregister_code16(KC_MS_BTN1);
                    // ergodox_right_led_3_off();
                    drag_lock_toggle = false;
                }
                layer_off(4);
            } else
                register_code16(KC_SCLN);
            break;
        case SINGLE_HOLD:
            layer_on(2);
            break;
        case DOUBLE_TAP:
            register_code16(LSFT(KC_SCLN));
            break;
        case TRIPLE_TAP:
            if (active_layer == 2) {
                layer_off(2);
            } else if (active_layer == 4) {
                layer_off(4);
            } else {
                layer_on(2);
            }
            break;
        case TRIPLE_HOLD:
            layer_on(2);
    }
}

void td_colon_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_colon_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_SCLN);
            break;
        case SINGLE_HOLD:
            if (drag_lock_toggle) {
                unregister_code16(KC_MS_BTN1);
                // ergodox_right_led_3_off();
                drag_lock_toggle = false;
            }
            if (active_layer == 2) {
                layer_off(2);
            } else {
                layer_off(4);
            }

            break;
        case DOUBLE_TAP:
            unregister_code16(LSFT(KC_SCLN));
            break;
        case TRIPLE_HOLD:
            if (active_layer == 2) {
                layer_off(2);
            } else {
                layer_off(4);
            }
    }
    td_colon_state.state = 0;
}

static tap td_rgui_state       = {.is_press_action = true, .state = 0};
void td_rgui_finished(qk_tap_dance_state_t *state, void *user_data);
void td_rgui_reset(qk_tap_dance_state_t *state, void *user_data);

void td_rgui_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_rgui_state.step = dance_step(state);
    switch (td_rgui_state.step) {
        case SINGLE_TAP:
            register_code16(KC_QUOTE);
            break;
        case SINGLE_HOLD:
            register_code16(KC_RGUI);
            break;
        case DOUBLE_TAP:
            register_code16(RSFT(KC_QUOTE));
            break;
        case DOUBLE_HOLD:
            register_code16(KC_RGUI);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_QUOTE);
            register_code16(KC_QUOTE);
            break;
    }
}

void td_rgui_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_rgui_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_QUOTE);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_RGUI);
            break;
        case DOUBLE_TAP:
            unregister_code16(RSFT(KC_QUOTE));
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_RGUI);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_QUOTE);
            break;
    }
    td_rgui_state.state = 0;
}

static tap td_caps_state      = {.is_press_action = true, .state = 0};
void td_caps_finished(qk_tap_dance_state_t *state, void *user_data);
void td_caps_reset(qk_tap_dance_state_t *state, void *user_data);

void td_caps_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_caps_state.step = dance_step(state);
    switch (td_caps_state.step) {
        case SINGLE_TAP:
            if (caps_state == 1) {
                register_code16(KC_CAPSLOCK);
                _delay_ms(100);
                unregister_code16(KC_CAPSLOCK);
                caps_state = 0;
                // ergodox_right_led_1_off();
                // ergodox_right_led_2_off();
                // ergodox_right_led_3_off();
            } else {
                register_code16(KC_GRAVE);
            }
            break;
        case SINGLE_HOLD:
            register_code16(KC_LGUI);
            break;
        case DOUBLE_TAP:
            register_code16(KC_CAPSLOCK);
            _delay_ms(100);
            unregister_code16(KC_CAPSLOCK);
            caps_state = 1;
            // ergodox_right_led_1_on();
            // ergodox_right_led_2_on();
            // ergodox_right_led_3_on();
            break;
    }
}

void td_caps_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_caps_state.step) {
        case SINGLE_TAP:
            unregister_code16(KC_GRAVE);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_LGUI);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_CAPSLOCK);
            caps_state = 0;
            // ergodox_right_led_1_off();
            // ergodox_right_led_2_off();
            // ergodox_right_led_3_off();
    }
    td_caps_state.state = 0;
}

static tap td_shortcat_state = {.is_press_action = true, .state = 0};
void td_shortcat_finished(qk_tap_dance_state_t *state, void *user_data);
void td_shortcat_reset(qk_tap_dance_state_t *state, void *user_data);

void td_shortcat_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_shortcat_state.step = dance_step(state);
    switch (td_shortcat_state.step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_SPACE));
            break;
        case DOUBLE_TAP:
            register_code16(LCTL(LALT(LGUI(KC_SPACE))));
            break;
    }
}

void td_shortcat_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_shortcat_state.step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_SPACE));
            break;
        case DOUBLE_TAP:
            unregister_code16(LCTL(LALT(LGUI(KC_SPACE))));
            break;
    }
    td_shortcat_state.state = 0;
}

void td_flsh_each(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            ergodox_right_led_3_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_1_on();
            break;
        case 4:
            ergodox_right_led_3_off();
            _delay_ms(50);
            ergodox_right_led_2_off();
            _delay_ms(50);
            ergodox_right_led_1_off();
            _delay_ms(50);
            ergodox_right_led_3_on();
            _delay_ms(50);
            ergodox_right_led_2_on();
            _delay_ms(50);
            ergodox_right_led_1_on();
            _delay_ms(50);
            ergodox_right_led_3_off();
            _delay_ms(50);
            ergodox_right_led_2_off();
            _delay_ms(50);
            ergodox_right_led_1_off();
            _delay_ms(50);
            ergodox_right_led_3_on();
            _delay_ms(50);
            ergodox_right_led_2_on();
            _delay_ms(50);
            ergodox_right_led_1_on();
            _delay_ms(50);
            ergodox_right_led_3_off();
            _delay_ms(50);
            ergodox_right_led_2_off();
            _delay_ms(50);
            ergodox_right_led_1_off();
    }
}

void td_flsh_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 4) {
        reset_keyboard();
        reset_tap_dance(state);
    }
}

void td_flsh_reset(qk_tap_dance_state_t *state, void *user_data) {
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    _delay_ms(250);
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    _delay_ms(250);
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    _delay_ms(250);
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    _delay_ms(250);
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSHIFT]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_lshift_finished, td_lshift_reset, 200),
    [TD_RSHIFT]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_rshift_finished, td_rshift_reset, 200),
    [TD_COLON]      = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_colon_finished, td_colon_reset, 200),
    [TD_RGUI]       = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_rgui_finished, td_rgui_reset, 175),
    [TD_CAPS]       = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_caps_finished, td_caps_reset, 200),
    [TD_FLSH]       = ACTION_TAP_DANCE_FN_ADVANCED_TIME(td_flsh_each, td_flsh_finished, td_flsh_reset, 300),
    [TD_SHORTCAT]   = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, td_shortcat_finished, td_shortcat_reset, 200),
};
