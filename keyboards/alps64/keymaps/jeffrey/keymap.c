#include QMK_KEYBOARD_H

#define _QW 0
#define _CM 1
#define _LOWER 2
#define _RAISE 3

#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)


enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  COLEMAK
};

 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  [_QW]= LAYOUT_aek_103( 
    KC_GESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
    KC_LCAP, KC_LGUI, KC_LALT,                 LT(_LOWER,KC_SPC),              KC_RALT, KC_RGUI, KC_RCTL
  ),
  [_CM]= LAYOUT_aek_103( 
    KC_GESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_F,   KC_P,   KC_B,   KC_J,   KC_L,   KC_U,   KC_Y,    KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_T(KC_ESC), KC_A,    KC_R,    KC_S,   KC_T,   KC_G,   KC_M,   KC_N,   KC_E,   KC_I,    KC_O, KC_QUOT, KC_ENT,
    KC_LSPO, KC_Z,    KC_X,   KC_C,   KC_D,   KC_V,   KC_K,   KC_H,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    KC_LCAP, KC_LGUI, KC_LALT,                 LT(_LOWER,KC_SPC),                                  KC_RALT, KC_RGUI, KC_RCTL
    ),
  [_LOWER]= LAYOUT_aek_103( 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, TG(_RAISE),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______
    ),
  [_RAISE]= LAYOUT_aek_103( 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    QWERTY,  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
    COLEMAK, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, TG(_RAISE),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______
    ),
};
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch(keycode) {
          /*    case DVORAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_DV);
          }
         return false;
          */
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
        default:
          return true;
      }
    return true;
};
