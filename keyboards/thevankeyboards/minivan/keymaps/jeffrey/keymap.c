#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _DV 1
#define _CM 2
#define _HD 3
#define _HDN 4
#define _L1 5
#define _L2 6
#define _L3 7

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  HANDSDOWN,
  NEU
};

enum {
    TD_TEST,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_TEST] = ACTION_TAP_DANCE_DOUBLE(KC_Q,KC_TILD),
};
enum unicode_names {
    LAMBDA,
    SNAKE
};


const uint32_t PROGMEM unicode_map[] = {
    [LAMBDA]=0x0370,
    [SNAKE]=0x1F40D,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_TAB,  TD(TD_TEST),    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LCTL_T(KC_ENTER),
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    KC_LCTL, KC_LALT, KC_LGUI,                   LT(_L2,KC_SPC),   LT(_L1,KC_SPC),   KC_RALT, KC_QUOT,  TG(_L3)
  ),
  [_CM] = LAYOUT( /* Colemak */
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, LCTL_T(KC_ENTER),
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    KC_LCTL, KC_LALT, KC_LGUI,                   LT(_L2,KC_SPC),  LT(_L1,KC_SPC),   KC_RALT, KC_QUOT,  TG(_L3)
  ),
  [_HD] = LAYOUT( /* Handsdown reference */
    KC_TAB,  KC_Q,    KC_C,    KC_H,    KC_P,    KC_V,    KC_K,    KC_Y,    KC_O,    KC_J,    KC_SLSH, KC_BSPC,
    LCTL_T(KC_ESC), KC_R,    KC_S,    KC_N,    KC_T,    KC_G,    KC_W,    KC_U,    KC_E,    KC_I,    KC_A,    LCTL_T(KC_ENTER),
   OSM(MOD_LSFT), KC_X,    KC_M,    KC_L,    KC_D,    KC_B,    KC_Z,    KC_F,    KC_QUOT, KC_COMM,  KC_DOT, KC_RSPC,
    KC_LCTL, KC_LALT, KC_LGUI,                   LT(_L2,KC_SPC),  LT(_L1,KC_SPC),   KC_RALT, KC_QUOT,  TG(_L3)
  ),
  [_HDN] = LAYOUT( /* Handsdown NEU*/
      // Again, have to mess with the J key to make it work. Eugh
    KC_TAB,  KC_W,    KC_F,    KC_M,    KC_P,    KC_V,    KC_SLSH,    KC_DOT,    KC_Q,    KC_QUOT,    KC_Z, KC_BSPC,
    LCTL_T(KC_ESC), KC_R,    KC_S,    KC_N,    KC_T,    KC_B,    KC_COMM,    KC_A,    KC_E,    KC_I,    KC_H,    LCTL_T(KC_J),
    OSM(MOD_LSFT), KC_X,    KC_C,    KC_L,    KC_D,    KC_G,    KC_MINS,    KC_U,    KC_O, KC_Y,  KC_K, RSFT_T(KC_SCLN),
    KC_LCTL, KC_LALT, KC_LGUI,                   LT(_L2,KC_SPC),  LT(_L1,KC_SPC),   KC_RALT, KC_QUOT,  TG(_L3)
  ),
  [_L1] = LAYOUT( /* LAYER 1 */
    KC_GRAVE,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
    _______, KC_ESC,  _______, KC_PSCR, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, _______,
    _______, KC_LGUI, _______,                   KC_ENT, _______,                   _______, _______, _______
  ),
  [_L2] = LAYOUT( /* LAYER 2 */
      KC_GRAVE, QWERTY,  COLEMAK, HANDSDOWN, NEU, _______, _______, KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_ESC,  KC_PIPE, KC_DQUO, KC_UNDS, KC_PLUS, L_CURBR, R_CURBR, KC_4,    KC_5,    KC_6,    _______, KC_ENT,
    _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    _______, _______,
    _______, _______, _______,                   _______, KC_ENT,                   _______, _______, _______
  ),
  [_L3] = LAYOUT( /* LAYER 3 */
      _______, KC_F, KC_UP, _______, KC_KP_7,KC_KP_8, KC_KP_9, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
      KC_ESC,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_KP_4, KC_KP_5,KC_KP_6, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
    KC_LSFT, KC_1,    KC_2,    KC_KP_0,    KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, KC_LSFT, KC_B,                      KC_SPC,  KC_C,                      _______, _______, _______
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch(keycode) {
        case QWERTY:
          if (record->event.pressed) {
              
            persistent_default_layer_set(1UL<<_QW);
          }
          return false;
        case COLEMAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_CM);
          }
          return false;
      case HANDSDOWN:
          if (record->event.pressed) {
              persistent_default_layer_set(1UL<<_HD);
          }
          return false;
      case NEU:
          if (record->event.pressed){
              persistent_default_layer_set(1UL<<_HDN);
          }
          return false;
        default:
          return true;
      }
    return true;
};
