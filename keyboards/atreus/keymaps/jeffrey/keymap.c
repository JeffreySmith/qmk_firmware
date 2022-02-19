// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _CM 1
#define _RS 2
#define _LW 3
#define _RAISE 4

#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

//#define COMBO_COUNT 2

enum custom_keycode {
    QWERTY= SAFE_RANGE,
    COLEMAK,
};



const uint16_t PROGMEM quot[] = {KC_W,KC_E, COMBO_END};
const uint16_t PROGMEM dash[] = {KC_E,KC_R, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(quot, KC_QUOT),
    COMBO(dash, KC_MINS),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_B,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    GUI_A,    ALT_S,    SFT_D,    CTL_F, KC_T,                      KC_M,    CTL_J,    SFT_K,    ALT_L,    GUI_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_G,    KC_V,              KC_N,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_GESC, KC_TAB, KC_LGUI,  KC_LALT, KC_BSPC, LT(_RS,KC_SPACE), LSFT_T(KC_DEL), KC_SPC, KC_RALT, KC_MINS, KC_QUOT, KC_ENT
  ),
  [_CM] = LAYOUT( /* COLEMAK  */
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN    ,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O ,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,              KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_GESC, KC_TAB, KC_LGUI,  KC_LALT, KC_BSPC, LT(_RS,KC_SPACE), LCTL_T(KC_ESC), KC_SPC, KC_RALT, KC_MINS, KC_QUOT, KC_ENT
  ),
  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    TG(_LW), KC_X,  KC_LGUI, KC_LSFT, KC_DEL, _______, KC_ENTER, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL  ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_MS_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    QWERTY,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_MS_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    COLEMAK,   KC_ASDN, KC_ASUP,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_ASTG, KC_ASRP, KC_LGUI, KC_LSFT, KC_BSPC, TG(_LW), TG(_LW), KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS ),

  [_RAISE] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    TG(_LW), QWERTY,  KC_LGUI, KC_LSFT, KC_DEL, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL  )

  
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
    case COLEMAK:
        if(record->event.pressed) {
            persistent_default_layer_set(1UL<<_CM);
        }
        return false;
    
    case QWERTY:
        if(record->event.pressed) {
                persistent_default_layer_set(1UL<<_QW);
            }
            return false;
        
    default:
        return true;
    }
    return true;
};
