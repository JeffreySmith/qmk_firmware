// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _CM 1
#define _HD 2
#define _HDP 3
#define _HDN 4
#define _HDG 5
#define _RS 6
#define _LW 7
#define _RAISE 8

#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

#define CGUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTLT LCTL_T(KC_T)

#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O LGUI_T(KC_O)

//#define COMBO_COUNT 2

enum custom_keycode {
    QWERTY= SAFE_RANGE,
    COLEMAK,
    HANDSDOWN,
    HANDSDOWNP,
    NEU,
    GOLD,
    EMAIL,
    KC_QU,
    
};
enum combo_events {
    TESTEMAIL,
    UNDERSCORE_COMBO,
};

enum {
    TD_Q_QU,
};

void qu_tap(tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1)
    {
        tap_code16(KC_Q);
        //tap_code16(KC_U);
        reset_tap_dance(state);
    }
    if (state->count == 2)
    {
        tap_code16(KC_Q);
        tap_code16(KC_U);
        reset_tap_dance(state);
    }
}
tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_QU] = ACTION_TAP_DANCE_FN(qu_tap),
};
    

const uint16_t PROGMEM quot[] = {KC_W,KC_F, COMBO_END};
const uint16_t PROGMEM dash[] = {KC_F,KC_P, COMBO_END};
const uint16_t PROGMEM enter[] = {KC_H,KC_COMM, COMBO_END};
const uint16_t PROGMEM scln[] = {KC_Q,KC_C,COMBO_END};
const uint16_t PROGMEM caps[] = {KC_P,KC_B,COMBO_END};
const uint16_t PROGMEM underscore[] = {KC_J,KC_L,COMBO_END};

const uint16_t PROGMEM jgz[] = {KC_J,KC_G,COMBO_END};
const uint16_t PROGMEM pvq[] = {KC_P,KC_V,COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
    COMBO(quot, KC_QUOT),
    COMBO(dash, KC_MINS),
    COMBO(enter,KC_ENTER),
    COMBO(scln,KC_SCLN),
    COMBO(caps,KC_CAPS),
    COMBO(underscore,KC_UNDS),
    COMBO(jgz,KC_Z),
    COMBO(pvq,KC_Q),
    //[UNDERSCORE_COMBO] = COMBO_ACTION(UNDERSCORE_COMBO), 
    //[EMAIL] = COMBO_ACTION(TESTEMAIL),  -j
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    GUI_A,    ALT_S,    SFT_D,    CTL_F, KC_G,                      KC_H,    CTL_J,    SFT_K,    ALT_L,    GUI_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_TAB, KC_LGUI,  KC_LALT, KC_BSPC, LT(_RS,KC_SPACE), LSFT_T(KC_DEL), KC_SPC, KC_RALT, KC_MINS, KC_QUOT, KC_ENT
  ),
  [_CM] = LAYOUT( /* COLEMAK  */
    KC_QU,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN    ,
    CGUI_A,    ALT_R,    SFT_S,   CTLT,    KC_G,                      KC_M,    CTL_N,    SFT_E,    ALT_I,    GUI_O ,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,              KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_TAB, KC_LGUI,  KC_LALT, KC_BSPC, LT(_RS,KC_SPACE), LT(_RS,KC_SPC), KC_SPC, KC_RALT, KC_MINS, KC_QUOT, KC_ENT
  ),
  [_HD] = LAYOUT( /* HANDSOFF  */
    KC_QU,    KC_C,    KC_H,    KC_P,    KC_V,                      KC_K,    KC_Y,    KC_O,    KC_J,    KC_SLASH    ,
    LGUI_T(KC_R),    LALT_T(KC_S),   SFT_T(KC_N),   CTLT,    KC_G,                      KC_W,    CTL_T(KC_U),    SFT_E,    ALT_I,    LGUI_T(KC_A) ,
    KC_X,    KC_M,    KC_L,    KC_D,    KC_B,              KC_Z,    KC_F,    KC_QUOT, KC_COMM,  KC_DOT ,
    QK_GESC, KC_TAB, KC_LGUI,  KC_SCLN, KC_BSPC, LT(_RS,KC_R), LT(_RS,KC_A), KC_SPC, KC_RALT, KC_MINS, KC_QUOT, KC_ENT
  ),
  [_HDP] = LAYOUT( /* HANDSOFF platinum  */
      KC_J,    KC_G,    KC_H,    KC_P,    KC_V,                      KC_SCLN,    KC_DOT,    KC_SLASH,    KC_QUOT,    KC_Q    ,
      LGUI_T(KC_R),    LALT_T(KC_S),   SFT_T(KC_N),   LCTL_T(KC_T),    KC_B ,                      KC_COMM,    CTL_T(KC_A),    SFT_E,    LALT_T(KC_C),    LGUI_T(KC_I) ,
    KC_X,    KC_F,    KC_M,    KC_D,    KC_K,              KC_MINS,    KC_U,    KC_O, KC_W,  KC_Y ,
    QK_GESC, KC_TAB, KC_LGUI,  KC_SCLN, KC_BSPC, LT(_RS,KC_L), LT(_RS,KC_SPC), KC_SPC, KC_Z, KC_RALT, KC_QUOT, KC_ENT
  ),
  [_HDG] = LAYOUT( /* HANDSOFF GOLD  */
    KC_J,    KC_G,    KC_M,    KC_P,    KC_V,                      KC_SCLN,    KC_DOT,    KC_SLASH,    KC_QUOT,    KC_Q    ,
    LGUI_T(KC_R),    LALT_T(KC_S),   SFT_T(KC_N),   LCTL_T(KC_D),    KC_B , KC_COMM,    CTL_T(KC_A),    SFT_E,    LALT_T(KC_I),    LGUI_T(KC_H) ,
    KC_X,    KC_F,    KC_L,    KC_C,    KC_W,              KC_MINS,    KC_U,    KC_O, KC_Y,  KC_K ,
    QK_GESC, KC_TAB, KC_LGUI,  KC_SCLN, KC_BSPC, LT(_RS,KC_T), LT(_RS,KC_F), KC_SPC, KC_Z, KC_MINS, KC_QUOT, KC_ENT
  ),
  [_HDN] = LAYOUT( /* HANDSOFF NEU */
      // It doesn't actually fit! Not sure what to do about that
     // added the J key to the right thumb button. Hopefully that's good enough?
    KC_W,    KC_F,    KC_M,    KC_P,    KC_V,                      KC_SLSH,     KC_DOT,    KC_QU,    KC_QUOT,    KC_Z    ,
    LGUI_T(KC_R),    LALT_T(KC_S),   SFT_T(KC_N),   CTLT,    KC_G,              KC_COMM, CTL_T(KC_A), SFT_E, ALT_I, LGUI_T(KC_H) ,
    KC_X,    KC_C,    KC_L,    KC_D,    KC_B,              KC_MINS,    KC_U,    KC_O, KC_Y,  KC_K ,
    QK_GESC, KC_TAB, KC_LGUI,  KC_SCLN, KC_BSPC, LT(_RS,KC_SCLN), LT(_RS,KC_J), KC_SPC, KC_RALT, KC_MINS, KC_SCLN, KC_ENT
  ),
  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_UNDS, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    TG(_LW), KC_UNDS,  KC_LGUI, KC_LSFT, KC_DEL, _______, KC_ENTER, KC_SPC,  EMAIL, KC_DOT, KC_0, KC_EQL  ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    HANDSDOWN,  HANDSDOWNP, KC_UP,   KC_END,  KC_PGUP,                   KC_MS_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    QWERTY,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_MS_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    COLEMAK,   NEU, GOLD,   KC_NO,   QK_BOOT,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    _______, _______, KC_LGUI, KC_LSFT, KC_BSPC, TG(_LW), TG(_LW), KC_SPC,  TO(_QW), KC_PSCR, _______, KC_PAUS ),

  [_RAISE] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    TG(_LW), QWERTY,  CM_TOGG, KC_LSFT, KC_DEL, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL  )

  
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
uint16_t key_timer;
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
    case HANDSDOWN:
        if(record->event.pressed) {
            persistent_default_layer_set(1UL<<_HD);
        }
        return false;
    case HANDSDOWNP:
        if(record->event.pressed) {
            persistent_default_layer_set(1UL<<_HDP);
        }
        return false;
    case NEU:
        if(record->event.pressed) {
            persistent_default_layer_set(1UL<<_HDN);
        }
        return false;
    case GOLD:
        if(record->event.pressed) {
            persistent_default_layer_set(1UL<<_HDG);
        }
        return false;
    case EMAIL:
        if(record->event.pressed) {
            SEND_STRING("jeffrey.smith7@gmail.com");
        }
        break;
    
    case KC_QU:
        if (record->event.pressed) {
            key_timer = timer_read();
        }
        else {
            if (timer_elapsed(key_timer) < TAPPING_TERM) {
                tap_code16(KC_Q);
                
            }
            else {
                tap_code16(KC_Q);
                tap_code16(KC_U);

            }
        }
        break;
    default:
        return true;
    }
    return true;
};
void process_combo_event(uint16_t combo_index,bool pressed) {
    switch(combo_index) {
    case TESTEMAIL:
        if(pressed) {
            SEND_STRING("jeffrey.smith7@gmail.com");
        }
        break;
    
    case UNDERSCORE_COMBO:
        if(pressed) {
            //SS_DOWN(X_LSFT);
            tap_code16(KC_MINS);
            //SS_UP(X_LSFT);
        }
        break;
    }
}
