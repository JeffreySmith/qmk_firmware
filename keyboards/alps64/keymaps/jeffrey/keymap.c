#include QMK_KEYBOARD_H

#define _QW 0
#define _CM 1
#define _HDN 2
#define _LOWER 3
#define _RAISE 4


enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  NEU,
  COLEMAK
};
/*enum combo_events {
    C_AU,
    C_FM,
    C_UAMINS,
    COMBO_LENGTH
};

uint8_t mod_state;

const uint16_t PROGMEM AU[]={KC_A,KC_COMM,COMBO_END};
const uint16_t PROGMEM FM[]={KC_F,KC_M,COMBO_END};
const uint16_t PROGMEM UAMINS[]={KC_U,KC_MINS,COMBO_END};
*/

 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  [_QW]= LAYOUT_aek_103( 
    QK_GESC       , KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSPC,
    LT(_LOWER,KC_TAB)        , KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, LCTL_T(KC_ENT),
    KC_LSFT       , KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
    KC_LCAP       , KC_LGUI, KC_LALT,                 KC_SPC,              KC_LALT, KC_RGUI, KC_RCTL
  ),
  [_CM]=LAYOUT_aek_103( 
    QK_GESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_F,   KC_P,   KC_B,   KC_J,   KC_L,   KC_U,   KC_Y,    KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_T(KC_ESC), KC_A,    KC_R,    KC_S,   KC_T,   KC_G,   KC_M,   KC_N,   KC_E,   KC_I,    KC_O, KC_QUOT, KC_ENT,
    SC_LSPO, KC_Z,    KC_X,   KC_C,   KC_D,   KC_V,   KC_K,   KC_H,   KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,
    KC_LCAP, KC_LGUI, KC_LALT,                 LT(_LOWER,KC_SPC),                                  KC_RALT, KC_RGUI, KC_RCTL
    ),
  [_HDN] =LAYOUT_aek_103( 
    QK_GESC       , KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_SCLN, KC_EQL, KC_BSPC,
    KC_TAB        , KC_W,    KC_F,    KC_M,   KC_P,   KC_V,   KC_SLSH, KC_DOT,   KC_Q,   KC_QUOT,    KC_Z,    KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_T(KC_ESC), KC_R,    KC_S,    KC_N,   KC_T,   KC_G,   KC_COMM,   KC_A,   KC_E,   KC_I,    KC_H, KC_J, LCTL_T(KC_ENT),
    SC_LSPO, KC_X , KC_C,   KC_L,   KC_D,   KC_B,   KC_MINS,   KC_U,   KC_O, KC_Y,  KC_K, SC_RSPC,
    KC_LCAP       , KC_LGUI, KC_LALT,                 LT(_LOWER,KC_SPC),                                  KC_LALT, KC_RGUI, OSM(MOD_MASK_CTRL)
    ),
  [_LOWER]= LAYOUT_aek_103( 
	KC_GRAVE, KC_F1  ,KC_F2   , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL,
    _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, TG(_RAISE),
    NEU    , COLEMAK, QWERTY , _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______
    ),
  [_RAISE]= LAYOUT_aek_103( 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    QWERTY,  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
    COLEMAK, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,TG(_RAISE),
    NEU    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______
    ),
};
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool get_retro_tapping(uint16_t keycode,keyrecord_t *record) {
	switch (keycode) {
	case LT(_LOWER,KC_TAB):
		return true;
	default:
		return false;
	}
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
      case NEU:
          if(record->event.pressed) {
              persistent_default_layer_set(1UL<<_HDN);
          }
          return false;
        default:
          return true;
      }
    return true;
};
/*
void process_combo_event(uint16_t combo_index, bool pressed) {
    mod_state=get_mods();
    switch(combo_index) {
        case C_AU:
            if(pressed){
                tap_code16(KC_A);
                if(get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                }
                tap_code16(KC_U);
                set_mods(mod_state);
            }
            break;
        
    
    case C_FM:
        if(pressed){     
            tap_code16(KC_F);
            if(get_mods() & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
            }
            tap_code16(KC_L);
            set_mods(mod_state);
        }
        break;
    case C_UAMINS:
        if(pressed){
            
                
            tap_code16(KC_U);
            if(get_mods() & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
            }
            tap_code16(KC_A);
            set_mods(mod_state);
        }
        break;
    }
}
*/                          
