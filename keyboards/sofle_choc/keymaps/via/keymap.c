/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// doesn't work
#define LAYOUT_VERTICAL(k0A, k0B, k0C, k0D, k0E, k0F, \
                        k1A, k1B, k1C, k1D, k1E, k1F, \
                        k2A, k2B, k2C, k2D, k2E, k2F, \
                        k3A, k3B, k3C, k3D, k3E, k3F, \
                        k8B, k8A, k4A, k4B, k4C, k4D, \
                            k5F, k5E, k5D, k5C, k5B, k5A, \
                            k6F, k6E, k6D, k6C, k6B, k6A, \
                            k7F, k7E, k7D, k7C, k7B, k7A, \
                            k4F, k9F, k8F, k8E, k8D, k8C, \
                            k4E, k9E, k9D, k9C, k9B, k9A) { \
	 {k0A, k0B, k0C, k0D, k0E, k0F}, \
	 {k2A, k2B, k2C, k2D, k2E, k2F}, \
	 {k4A, k4B, k4C, k4D, k4E, k4F}, \
	 {k6A, k6B, k6C, k6D, k6E, k6F}, \
	 {k8A, k8B, k8C, k8D, k8E, k8F}, \
	    {k1A, k1B, k1C, k1D, k1E, k1F}, \
	    {k3A, k3B, k3C, k3D, k3E, k3F}, \
	    {k5A, k5B, k5C, k5D, k5E, k5F}, \
	    {k7A, k7B, k7C, k7D, k7E, k7F}, \
	    {k9A, k9B, k9C, k9D, k9E, k9F} \
}

enum layers {
  BASE,
  QWERTY,
  SYM,
  SYM2,
  NUM,
};

// not used
#define SYM_PLUS LT(SYM,KC_PLUS)
#define SYM_LPRN LT(SYM,KC_LPRN)
#define SYM_3    LT(SYM,KC_3)
#define SYM_2    LT(SYM,KC_2)
// not used

// #define LM_LCTL		LM(QWERTY,MOD_LCTL)
#define LM_LCTL     LT(QWERTY, KC_Z)

#define LM_LGUI 	LM(QWERTY,MOD_LGUI)
#define OSM_LGUI 	OSM(MOD_LGUI)
#define OSM_LCTL 	OSM(MOD_LCTL)
#define OSM_LSFT 	OSM(MOD_LSFT)

#define HOME_N 	LALT_T(KC_N)
#define HOME_S 	LGUI_T(KC_S)
#define HOME_T 	LCTL_T(KC_T)
#define HOME_C 	LT(SYM,KC_C)

#define HOME_H  LT(SYM,KC_H)
#define HOME_A	RCTL_T(KC_A)
#define HOME_E 	RGUI_T(KC_E)
#define HOME_I 	LALT_T(KC_I)

#define NUM_R   LT(NUM,KC_R)

#define SYM_EQL  LT(SYM,KC_EQL)
#define SYM_SCLN LT(SYM2,KC_SCLN)
#define SYM_1    LT(SYM,KC_1)
#define SYM_0    LT(SYM2,KC_0)

#define SYM_N    LT(SYM,KC_N)
#define SYM_I    LT(SYM2,KC_I)

// clang-format off
#define SYM_LAYER LAYOUT( \
    _______,   	_______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,    _______, \
    _______,	  KC_TILD,  KC_LT,	KC_GT,	  KC_HASH,  KC_DEL,                           KC_DEL,   KC_DLR,   KC_LBRC,  KC_RBRC,  KC_PERC,	  _______, \
    _______,  	KC_EXLM,  KC_MINS, 	KC_PLUS,  SYM_EQL,	KC_AMPR,                        KC_GRV,   SYM_SCLN, KC_LPRN,  KC_RPRN,  KC_QUES,   	_______, \
    _______,  	KC_CIRC,  KC_PIPE,  KC_ASTR,  KC_BSLS,  KC_ENT,  XXXXXXX,     XXXXXXX,  KC_ENT,   KC_COLN,  KC_LCBR,  KC_RCBR,	KC_AT,   	  _______, \
                          _______,  _______,  _______,  _______, _______,     _______,  _______,  _______,  _______,  _______ \
) \

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT(
    KC_ESC,   	KC_F1,    KC_F2,  	KC_F3,    KC_F4,    KC_F5,                          KC_F6,    KC_F7,  	KC_F8,    KC_F9,    KC_F10,     KC_DOT,
    KC_TAB, 	  KC_X,	    KC_F,		  KC_D,	    KC_P, 	  KC_Q,                           KC_J,	    QK_AREP,	KC_O,     KC_U,		  KC_COMMA,	  KC_Z,
    KC_BSPC,  	HOME_N,	  HOME_S, 	HOME_T,	  HOME_C,	  KC_Y,                           KC_M,     HOME_H,	  HOME_A,	  HOME_E,	  HOME_I,   	KC_UNDS,
    LM_LCTL,  	KC_B,     KC_V,		  KC_K,	    KC_G,		  KC_W,    XXXXXXX,     XXXXXXX,  KC_DQUO,  KC_L,		  KC_QUOT,  KC_SLSH,	KC_DOT,   	KC_ENT,
                          KC_ENT,   KC_LALT,  OSM_LSFT,	KC_SPC,  KC_ENT,      KC_ENT,   NUM_R,    QK_REP,   _______,  KC_ENT
),
// SYM2 == SYM, is needed for layer tap issues when rapidly alternating hands
[SYM] = SYM_LAYER,
[SYM2] = SYM_LAYER,
[NUM] = LAYOUT(
    _______,   	_______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,    _______,
    _______,	  _______,  KC_DEL,	  KC_DEL,   KC_DEL,   _______,                        _______,  _______,  _______,  _______,  _______,	  _______,
    _______,  	KC_7,     KC_5,  	  KC_3,     SYM_1,    KC_9,                           KC_8,     SYM_0,  	KC_2,     KC_4,     KC_6,   	  _______,
    _______,  	KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  _______, XXXXXXX,     XXXXXXX,  KC_PSCR,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT,   _______,
                          _______,  _______,  _______,  _______, _______,     _______,  _______,  _______,  _______,	_______
),
[QWERTY] = LAYOUT(
    KC_GRV,   	_______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,    _______,
    _______,	  KC_Q,	    KC_W,     KC_E,	    KC_R,	    KC_T,                           KC_Y,	    KC_U,     KC_I,	    KC_O,	    KC_P,	      _______,
    _______,  	KC_A,	    KC_S,     KC_D,	    KC_F,	    KC_G,                           KC_H,	    KC_J,     KC_K,	    KC_L,	    KC_SCLN,   	_______,
    _______,  	KC_Z,	    KC_X,     KC_C,	    KC_V,	    KC_B,    XXXXXXX,     XXXXXXX,  _______,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT,   _______,
                          _______,  _______,  _______,  _______, _______,     _______,  _______,  _______,  _______,	_______
),
};

#include "features/achordion.h"

static bool lt_with_mods_key(keyrecord_t* record, uint8_t mods) {
  if (!record->tap.count) {      // If holding.
    if (record->event.pressed) { // On hold press.
      register_mods(mods);       // Hold mods.
    } else {                     // On hold release.
      unregister_mods(mods);     // Release mods.
    }
  }
  return true;  // Continue normal handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // Behave as KC_D on tap, LM(_NAV, MOD_LCTL) on hold.
        case LM_LCTL:
            return lt_with_mods_key(record, MOD_BIT(KC_LCTL));
    }
    if (!process_achordion(keycode, record)) { return false; }

    // #define HOME_PLUS LT(2,KC_PLUS)
    // #define HOME_LPRN LT(2,KC_LPRN)
    // workaround because kc argument of MT() is limited to the Basic Keycode set
    // https://docs.qmk.fm/mod_tap 
    // switch (keycode) {
    //     case SYM_PLUS:
    //         if (record->tap.count && record->event.pressed) {
    //             tap_code16(KC_PLUS); // Send KC_PLUS on tap
    //             return false;        // Return false to ignore further processing of key
    //         }
    //         break;
    //     case SYM_LPRN:
    //         if (record->tap.count && record->event.pressed) {
    //             tap_code16(KC_LPRN); // Send KC_LPRN on tap
    //             return false;        // Return false to ignore further processing of key
    //         }
    //         break;
    // }
    return true;
}


void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand
  switch (tap_hold_keycode) {
    case NUM_R:

    case HOME_C:
    case HOME_H:
    case SYM_EQL:
    case SYM_SCLN:
    case SYM_1:
    case SYM_0:
      return true;
      break;

  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case HOME_N: return KC_X;  
        case HOME_S: return KC_F;  
        case HOME_T: return KC_D;  // For "TD" bigram.
		case HOME_C: return KC_P;

        case NUM_R: return KC_R;


		case KC_B: return KC_X;
		case KC_V: return KC_F;
		case KC_K: return KC_D;
		case KC_G: return KC_P;
		
		case KC_X: return KC_B;
		case KC_F: return KC_V;
		case KC_D: return KC_K;
		case KC_P: return KC_G;

		case HOME_A: return KC_O; 
		case HOME_E: return KC_U; 
        case HOME_I: return KC_COMMA;

        case KC_M: return KC_M;
        case KC_L: return KC_M;

        case KC_O: return KC_A;
        case KC_U: return KC_E; 

    }

    return KC_TRNS;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif
