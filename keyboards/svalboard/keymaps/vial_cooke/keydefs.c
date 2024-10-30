#include QMK_KEYBOARD_H
#include "keydefs.h"
#include "handlers.h"

//CODES:
//ALT A,  CMD G,  CONTROL C, SHIFT S, C+A LCA, ALGR (for Windows), LWIN, H (hyper)


//Definition of those shortcuts that perform the same action using different
//key combinations accordint to the OS. Currently: {OSX, Windows}
static const uint16_t osKeys[][NUMBER_OF_OS] PROGMEM = {
	//CMD_OS
	{ KC_LCMD, KC_LCTL},
	//CTR_OS
	{ KC_LCTL, KC_LWIN},
	//CUT
	{ G(KC_X), C(KC_X) },
	//COPY
	{ G(KC_C), C(KC_C) },
	//PASTE
	{ G(KC_V), C(KC_V) },
	//PLAIN_PASTE
	{ G(A(S(KC_V))), C(S(KC_V)) },
	//PASTE_IN_PLACE
	{ G(S(KC_V)), C(S(KC_V)) },
	//UNDO
	{ G(KC_Z), C(KC_Z) },
	//REDO
	{ G(S(KC_Z)), C(S(KC_Z)) },
	//SCRSHT1
	{ G(S(C(KC_4))), LWIN(S(KC_S)) },
	//SCRSHT2
	{ G(S(KC_5)), KC_PSCR },
	//REFRESH
	{ G(S(KC_R)), C(KC_F5) },
	//SAVE
	{ G(KC_S), C(KC_S) },
	//SELECT
	{ G(KC_A), C(KC_A) },
	//MUTE
	{ KC_MUTE, KC_MUTE },
	//VOL_UP
	{ KC_VOLU, KC_VOLU },
	//VOL_DOWN
	{ KC_VOLD, KC_VOLD },
	//FIRST
	{ G(KC_LEFT), KC_HOME},
	//LAST
	{ G(KC_RIGHT), KC_END},
	//MINMZ
	{ G(KC_H), LWIN(KC_DOWN)},
	//CLS_W
	{ G(KC_W), A(KC_F4)},
	//SPOTL
	{ G(KC_SPC), LWIN(KC_S)},
	//EMOJI
	{ G(C(KC_SPC)), LWIN(KC_DOT)},
	//DEL_W
	{ A(KC_BSPC), C(KC_BSPC)},
	//CLS_APP
	{ G(KC_Q), A(KC_F4)},

};

//returns the extendend shortcut keycode according to the current OS
static uint16_t getOSKey(uint16_t keyName ){
	return pgm_read_word( &( osKeys[ keyName - FIRST_OS_INDEX -1 ][ os ] ) );
};
