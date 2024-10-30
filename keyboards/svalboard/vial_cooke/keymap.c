/*
Copyright 2023 Morgan Venable @_claussen

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../keymap_support.c"
#include "keycodes.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include <stdbool.h>
#include <stdint.h>
#include "svalboard.h"
#include "keydefs.c"
#include "handlers.c"

#define LAYER_COLOR(name, color) rgblight_segment_t const (name)[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, color})

LAYER_COLOR(layer0_colors, HSV_GREEN); // NORMAL
LAYER_COLOR(layer1_colors, HSV_GREEN); // NORMAL_HOLD
LAYER_COLOR(layer2_colors, HSV_ORANGE); // FUNC
LAYER_COLOR(layer3_colors, HSV_ORANGE); // FUNC_HOLD
LAYER_COLOR(layer4_colors, HSV_AZURE); // NAS
LAYER_COLOR(layer5_colors, HSV_AZURE); // would be NAS hold
LAYER_COLOR(layer6_colors, HSV_RED); // maybe 10kp
LAYER_COLOR(layer7_colors, HSV_RED);
LAYER_COLOR(layer8_colors, HSV_PINK);
LAYER_COLOR(layer9_colors, HSV_PURPLE);
LAYER_COLOR(layer10_colors, HSV_CORAL);
LAYER_COLOR(layer11_colors, HSV_SPRINGGREEN);
LAYER_COLOR(layer12_colors, HSV_TEAL);
LAYER_COLOR(layer13_colors, HSV_TURQUOISE);
LAYER_COLOR(layer14_colors, HSV_YELLOW);
LAYER_COLOR(layer15_colors, HSV_MAGENTA); // MBO
#undef LAYER_COLOR

const rgblight_segment_t*  const __attribute((weak))sval_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer0_colors, layer1_colors, layer2_colors, layer3_colors,
    layer4_colors, layer5_colors, layer6_colors, layer7_colors,
    layer8_colors, layer9_colors, layer10_colors, layer11_colors,
    layer12_colors, layer13_colors, layer14_colors, layer15_colors
);

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, 0));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  for (int i = 0; i < RGBLIGHT_LAYERS; ++i) {
      rgblight_set_layer_state(i, layer_state_cmp(state, i));
  }
  return state;
}



void keyboard_post_init_user(void) {
  // Customise these values if you need to debug the matrix
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
  rgblight_layers = sval_rgb_layers;
}

enum layer {
    NORMAL,
    NUMNAV,
    SYMB,
    MBO = MH_AUTO_BUTTONS_LAYER,
};

const uint16_t PROGMEM keymaps[DYNAMIC_KEYMAP_LAYER_COUNT][MATRIX_ROWS][MATRIX_COLS] = {
    [NORMAL] = LAYOUT(
        /*Center           North           East            South           West*/

        /*R1*/ KC_A,            KC_DOT,         KC_MINS,        KC_U,           KC_COMM, XXXXXXX,
        /*R2*/ KC_E,            KC_AMPR,        KC_SLSH,        KC_O,           KC_AT, XXXXXXX,
        /*R3*/ KC_I,            KC_Z,           XXXXXXX,        KC_DOT,         KC_N, XXXXXXX,
        /*R4*/ KC_H,            KC_Q,           XXXXXXX,        KC_B,           KC_QUOT, XXXXXXX,

        /*L1*/ KC_T,            KC_P,           KC_W,           KC_D,           KC_V, XXXXXXX,
        /*L2*/ KC_N,            KC_M,           XXXXXXX,        KC_L,           XXXXXXX, XXXXXXX,
        /*L3*/ KC_S,            KC_G,           XXXXXXX,        KC_F,           XXXXXXX, XXXXXXX,
        /*L4*/ KC_C,            KC_J,           XXXXXXX,        KC_X,           KC_ESC, XXXXXXX,

        /*     Down                  Pad                    Up             Nail           Knuckle    DoubleDown*/
        /*RT*/ LT(NUMNAV,KC_SPACE),  OSM(MOD_LSFT),         KC_ENTER,      QK_REP,        XXXXXXX,     XXXXXXX,
        /*LT*/ LT(SYMB, KC_R),       LT(MACROS,KC_BSPC),    TO(NORMAL),    KC_DEL,        KC_TAB,     XXXXXXX
        ),

    [NUMNAV] = LAYOUT(
        /*Center                North           East            South           West*/
        /*R1*/ KC_LEFT,         KC_HOME,        KC_RIGHT,       KC_RSFT,        KC_LEFT, XXXXXXX,
        /*R2*/ KC_UP,           KC_PGUP,        XXXXXXX,        KC_RCTL,        KC_END, XXXXXXX,
        /*R3*/ KC_DOWN,         KC_PGDN,        KC_LGUI,        KC_RALT,        KC_INS, XXXXXXX,
        /*R4*/ KC_RIGHT,        KC_END,         KC_F12,         KC_RGUI,        KC_F11, XXXXXXX,

        /*L1*/ KC_3,         KC_6,              KC_EQL,         KC_9,           KC_LEFT, XXXXXXX,
        /*L2*/ KC_2,         KC_5,              XXXXXXX,        KC_8,           LSFT(KC_8), XXXXXXX,
        /*L3*/ KC_1,         KC_4,              XXXXXXX,        KC_7,           KC_MINS, XXXXXXX,
        /*L4*/ KC_0,         XXXXXXX,           XXXXXXX,        KC_DOT,         LSFT(KC_EQL), XXXXXXX,

        /*     Down            Pad            Up             Nail           Knuckle    DoubleDown*/
        /*RT*/ _______,        _______,       _______,       _______,       _______,    _______,
        /*LT*/ _______,        _______,       _______,       _______,       _______,    _______
        ),

    [SYMB] = LAYOUT(
        /*Center           North           East            South           West*/
        /*R1*/ KC_7,            KC_AMPR,        KC_UNDS,        KC_KP_PLUS,     KC_6, XXXXXXX,
        /*R2*/ KC_8,            KC_KP_ASTERISK, KC_COLON,       KC_COMMA,       KC_CIRCUMFLEX, XXXXXXX,
        /*R3*/ KC_9,            KC_LPRN,        KC_LGUI,        KC_DOT,         KC_SEMICOLON, XXXXXXX,
        /*R4*/ KC_0,            KC_RPRN,        XXXXXXX,        KC_QUES,        KC_RBRC, XXXXXXX,

        /*L1*/ KC_4,            KC_DOLLAR,      KC_5,           KC_MINUS,       KC_SLASH, XXXXXXX,
        /*L2*/ KC_3,            KC_HASH,        KC_GT,          KC_PERCENT,     KC_LT, XXXXXXX,
        /*L3*/ KC_2,            KC_AT,          XXXXXXX,        KC_X,           KC_ESC, XXXXXXX,
        /*L4*/ KC_1,            KC_EXCLAIM,     KC_TILDE,       KC_EQUAL,       KC_DEL, XXXXXXX,

        /*     Down            Pad            Up             Nail           Knuckle    DoubleDown*/
        /*RT*/ MO(NAS),         KC_SPACE,       _______,       KC_BSPC,        KC_LALT, _______,
        /*LT*/ KC_LSFT,         KC_ENTER,       _______,        KC_TAB,         KC_LCTL, _______
        ),

    [MBO] = LAYOUT(
        /*Center           North           East            South           West*/
        /*R1*/ KC_BTN1,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, XXXXXXX,
        /*R2*/ KC_BTN3,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, XXXXXXX,
        /*R3*/ KC_BTN2,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, XXXXXXX,
        /*R4*/ SV_RECALIBRATE_POINTER,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, XXXXXXX,
        /*L1*/ KC_BTN1,        KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS, XXXXXXX,
        /*L2*/ KC_BTN3,        KC_TRNS,       KC_TRNS,       SV_SNIPER_2,        KC_TRNS, XXXXXXX,
        /*L3*/ KC_BTN2,        KC_TRNS,       KC_TRNS,       SV_SNIPER_3,        KC_TRNS, XXXXXXX,
        /*L4*/ SV_RECALIBRATE_POINTER, KC_TRNS, KC_TRNS,       SV_SNIPER_5,      KC_TRNS, XXXXXXX,
        /*     Down            Pad            Up             Nail           Knuckle    DoubleDown*/
        /*RT*/ KC_TRNS,        KC_BTN1,       KC_TRNS,       KC_BTN2,       KC_BTN3,   KC_TRNS,
        /*LT*/ KC_TRNS,        KC_BTN1,       KC_TRNS,       KC_BTN2,       KC_BTN3,   KC_TRNS
        )

};

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
    if (tap_hold_record->event.key.row == 0 || tap_hold_record->event.key.row == 5 ||
        other_record->event.key.row    == 0 || other_record->event.key.row    == 5) {
        return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

