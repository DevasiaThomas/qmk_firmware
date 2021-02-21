#include QMK_KEYBOARD_H

#define RAISE MO(1)
#define LOWER MO(2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
     KC_ESC,   KC_F1  , KC_F2 , KC_F3 , KC_F4, KC_F5 , KC_F6  ,                         KC_F7 , KC_F8 , KC_F9  , KC_F10, KC_F11 , KC_F12 ,  M(0),
     KC_GRAVE, KC_1   , KC_2  , KC_3  , KC_4 , KC_5  , KC_6   ,                         KC_7  , KC_8  , KC_9   , KC_0  , KC_0   , KC_MINS,  KC_EQL,
     KC_INS,   KC_TAB , KC_Q  , KC_W  , KC_F , KC_P  , KC_G   ,                         KC_J  , KC_L  , KC_U   , KC_Y  , KC_SCLN, KC_LBRC,  KC_RBRC,
     KC_LALT,  KC_CAPS, KC_A  , KC_R  , KC_S , KC_T  , KC_D   ,                         KC_H  , KC_N  , KC_E   , KC_I  , KC_O   , KC_QUOT,  KC_BSLS,
     KC_LCTL,  KC_LSFT, KC_Z  , KC_X  , KC_C , KC_V  , KC_B   ,                         KC_K  , KC_M  , KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,  KC_ALGR,
                                    KC_LEFT,KC_UP,                                                  KC_DOWN, KC_RGHT,
                                               KC_ENT,  KC_DEL,                        KC_BSPC,  KC_SPC,
                                               KC_HOME, KC_LGUI,                       KC_RGUI,  KC_END,
                                               KC_PGUP, RAISE,                         LOWER, KC_PGDOWN  
  ),
  [1] = LAYOUT(
     _______, _______,_______,_______,_______,KC_BRID,KC_BRIU,                        KC_VOLD,KC_VOLU,KC_MPRV,KC_MPLY,KC_MNXT,_______,RESET , 
     _______, _______,_______,_______,_______,_______,_______,                        KC_LPRN, KC_P7 , KC_P8 , KC_P9 ,KC_PSLS,_______,_______, 
     _______, _______,_______,_______,_______,_______,_______,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_PAST,_______,_______, 
     _______, _______,_______,_______,_______,_______,_______,                        KC_CIRC, KC_P1 , KC_P2 , KC_P3 ,KC_PPLS,_______,_______, 
     _______, _______,_______,_______,_______,_______,_______,                        KC_PERC,_______, KC_P0 ,KC_PDOT,KC_PMNS,_______,KC_PSCR, 
                              _______,_______,                                                         _______,_______,
                                             KC_PENT,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______
  ),
  [2] = LAYOUT(
      _______,_______,_______,_______,_______,KC_BRID,KC_BRIU,                        KC_VOLD,KC_VOLU,KC_MPRV,KC_MPLY,KC_MNXT,_______,RESET , 
      _______,_______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,_______, 
      _______,_______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,_______, 
      _______,_______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,_______, 
      _______,_______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,KC_PSCR, 
                              _______,_______,                                                        _______ ,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
            //Lock Screen    
            case 0:
                return MACRO(D(LGUI), T(L), U(LGUI), END);
        }
    }
    return MACRO_NONE;
};
