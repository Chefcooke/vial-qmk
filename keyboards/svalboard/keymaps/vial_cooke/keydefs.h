#pragma once

#define CUSTOM_CODES_BASE_INDEX QK_USER
#define NUMBER_OF_OS 2
#ifdef SVALBOARD
#include "../keymap_support.h"
#define RANGE_START SV_SAFE_RANGE
#else
#define RANGE_START SAFE_RANGE
#endif

enum OS {
	OSX = 0,
	WINDOWS
};

extern enum OS os;  //it holds the OS mode of the keyboard. OSX by default

//═══════════════════════════════════════════════════════════════
//   KEYCODE DECLARATIONS
//═══════════════════════════════════════════════════════════════
//most keycodes (except the ones manually handled) are order dependent. If you are
//going to add new codes, add them at the bottom of each section and use them in the
//same order when handling them in handlers.c

enum custom_keycodes {

	//────────────── NULL KEY ──────────────
	//used when no action is required
	NULL_KEY = CUSTOM_CODES_BASE_INDEX, //SAFE_RANGE = 23849

	//────────────── OS DEPENDENT KEYS ──────────────
	FIRST_OS_INDEX,
	CMD_OS,
	CTR_OS,
	CUT_OS,
	COPY_OS,
	PASTE_OS,
	PST_CLN_OS,
	PST_PLACE_OS,
	UNDO_OS,
	REDO_OS,
	SCRSHT1_OS,
	SCRSHT2_OS,
	REFRESH_OS,
	SAVE_OS,
	SELECT_OS,
	MUTE_OS,
	VOL_UP_OS,
	VOL_DOWN_OS,
	FIRST_OS,
	LAST_OS,
	MINMZ_OS,
	CLS_W_OS,
	SPOTL_OS,
	EMOJI_OS,
	DEL_W_OS,
	CLS_APP_OS,
	LAST_OS_INDEX,

	//────────────── CUSTOM HANDLED KEYS ──────────────
	FIRST_CUSTOM_INDEX,
	SWAP_OS,
	SWIN_OS,
	SMAC_OS,
    BRACES,
};

// original :: static uint16_t getOSKey(uint16_t keyName );
static uint16_t getOSKey(uint16_t keyName );