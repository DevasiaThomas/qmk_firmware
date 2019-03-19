#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE    0
#define _QWERTY  1
#define _LOWER   2
#define _RAISE   3
#define _ADJUST  4

#define ____     KC_TRNS

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_ENT  ALT_T(KC_ENT)

#define LW_DEL   LT(_LOWER, KC_DELT)
#define RS_ENT   LT(_RAISE, KC_ENT)

#define RAISE    MO(_RAISE)
#define LOWER    MO(_LOWER)
#define ADJUST   TG(_ADJUST)
#define REBASE   TO(_BASE)
#define QWERTY   TO(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  KC_SCLN, KC_COMM, KC_DOT,  KC_P, KC_Y,                                     KC_F, KC_G, KC_C,    KC_R,   KC_L,
  KC_A,    KC_O,    KC_E,    KC_U, KC_I,                                     KC_D, KC_H, KC_T,    KC_N,   KC_S,
  KC_QUOT, KC_Q,    KC_J,    KC_K, KC_X,                                     KC_B, KC_M, KC_W,    KC_V,   KC_Z,
           KC_TAB,  KC_LGUI,                                                             KC_MINS, KC_SLSH,
                                         KC_BSPC, SFT_ESC,  RAISE,   KC_SPC,
                                         KC_LCTL, LW_DEL,   ALT_ENT, KC_LCTL,
                                         KC_LALT, KC_ESC,   KC_LSFT, KC_LALT
),

[_RAISE] = LAYOUT(
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                             KC_BSLS, KC_7, KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                              KC_EQL,  KC_4, KC_5,   KC_6, KC_ENT ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                             KC_GRV,  KC_1, KC_2,   KC_3, KC_PLUS ,
             KC_INS,  KC_LGUI,                                                        KC_0, KC_DOT,
                                               KC_DELT, ____,    ____, ____,
                                               ____,    ____,    ____, ____,
                                               ____,    ADJUST,  ____, ____
),
[_LOWER] = LAYOUT(
    KC_ESC,  KC_PSCR, KC_PAUS, KC_F1, KC_F2,                           KC_F3,  KC_F4,  KC_INS,  KC_DELT, KC_BSPC ,
    KC_CLCK, KC_TAB,  KC_PGUP, KC_F5, KC_F6,                           KC_F7,  KC_F8,  KC_HOME, KC_LALT, KC_ENT  ,
    KC_LSFT, KC_SLCK, KC_PGDN, KC_F9, KC_F10,                          KC_F11, KC_F12, KC_END,  KC_MINS, KC_SLSH ,
             KC_INS,  KC_LGUI,                                                         KC_APP,  ____,
                                             ____, ____,  ____, ____,
                                             ____, ____,  ____, ____,
                                             ____, ____,  ____, ____
),
[_ADJUST] = LAYOUT(
    ____, ____, ____,    KC_MPLY, ____,                            ____,   ____,    ____,    ____,   ____,
    ____, ____, KC_VOLU, ____,    ____,                            ____,   ____,    KC_BRIU, ____,   ____,
    ____, ____, KC_VOLD, ____,    RESET,                           QWERTY, KC_MUTE, KC_BRID, ____,   ____,
          ____, ____,                                                               ____, ____,
                                        ____, ____,  REBASE, ____,
                                        ____, ____,  ____,   ____,
                                        ____, ____,  ____,   ____
),
[_QWERTY] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I,    KC_O,   KC_P    ,
    KC_A, KC_S, KC_D, KC_F, KC_G,                                      KC_H, KC_J, KC_K,    KC_L,   KC_SCLN ,
    KC_Z, KC_X, KC_C, KC_V, KC_B,                                      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH ,
          ____, ____,                                                              KC_MINS, KC_QUOT,
                                   KC_BSPC, SFT_ESC,  RS_ENT,  KC_SPC,
                                   KC_LCTL, LW_DEL,   ALT_ENT, KC_LCTL,
                                   KC_LALT, KC_ESC,   KC_LSFT, KC_LALT
),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

