#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// #include "oled.c"
// #include "encoder.c"

enum custom_keycodes {
    KC_LOWER = SAFE_RANGE,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

// magic key
#define MAGIC QK_AREP  // The "magic" key is Alternate Repeat.

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,     KC_7,     KC_8,    KC_9,   KC_0,    KC_GRV, \
  KC_ESC,   MAGIC,   MAGIC,    MAGIC,    KC_R,    KC_T,                     KC_Y,     KC_U,     KC_I,    KC_O,   KC_P,    KC_BSPC, \
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,     KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,   XXXXXXX, KC_N,     KC_M,     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
                 KC_LGUI,KC_LALT,KC_LCTL, KC_LOWER, KC_ENT,    KC_SPC,  KC_RAISE, KC_RCTL, KC_RALT, KC_RGUI \
),
/* LOWER
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______,  _______,                         _______, _______,  _______, _______,  _______ , _______, \
  _______, MAGIC,  MAGIC, MAGIC,  XXXXXXX,  XXXXXXX,                         KC_PGUP, KC_PRVWD, KC_UP,   KC_NXTWD, KC_DLINE, KC_BSPC, \
  _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,  KC_CAPS,                         KC_PGDN, KC_LEFT,  KC_DOWN, KC_RGHT,  KC_DEL,   KC_BSPC, \
  _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, XXXXXXX, _______,       _______, XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,  XXXXXXX,  _______, \
                    _______, _______, _______,  _______, _______,       _______, _______, _______,  _______, _______ \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,\
  KC_GRV,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12, \
  _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
  _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______, \
                   _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | XXXXXXX|    |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  ),
  [4] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  ),
  [5] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  )
};

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 28, 21, 20, 11, 10,      0 },
  { 27, 22, 19, 12,  9,      1 },
  { 26, 23, 18, 13,  8,      2 },
  { 25, 24, 17, 14,  7,      3 },
  { 16, 15,  6,  5,  4, NO_LED }
}, {
  // LED Index to Physical Position
  { 195, 7 },{ 195, 21 },{ 195, 36 },{ 195, 50 },{ 224, 64 },
  { 185, 62 },{ 146, 60 },{ 156, 48 },{ 156, 33 },{ 156, 19 },
  { 156, 5 },{ 117, 3 },{ 117, 17 },{ 117, 31 },{ 117, 46 },
  { 107, 62 },{ 68, 64 },{ 78, 48 },{ 78, 33 },{ 78, 19 },
  { 78, 5 },{ 39, 7 },{ 39, 21 },{ 39, 36 },{ 39, 50 },
  { 0, 50 },{ 0, 36 },{ 0, 21 },{ 0, 7 }
}, {
  // LED Index to Flag
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1
} };

#endif

// clang-format off
// https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOLLAR, S(KC_GRV)}, // $~
  {KC_AMPERSAND, S(KC_5)}, // &%
  {KC_LBRC, KC_7}, // [7
  {KC_LEFT_CURLY_BRACE, KC_5}, // {5
  {KC_RIGHT_CURLY_BRACE, KC_3}, // }3
  {KC_LEFT_PAREN, KC_1}, // (1
  {KC_EQL, KC_9}, // =9
  {KC_ASTERISK, KC_0}, // *0
  {KC_RIGHT_PAREN, KC_2}, // )2
  {KC_PLUS, KC_4}, // +4
  {KC_RBRC, KC_6}, // ]6
  {KC_EXCLAIM, KC_8}, // !8
  {KC_HASH, KC_GRV}, // #`
  {KC_AT, KC_CIRCUMFLEX}, // @^
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


// magic key impl
// clang-format off
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  if ((mods & ~MOD_MASK_SHIFT) == 0) {
    switch (keycode) {

      // Behavior for Magic Sturdy's "magic" key.
      case KC_A: return KC_O;       // A <-> O
      case KC_O: return KC_A;

      case KC_E: return KC_U;       // E <-> U
      case KC_U: return KC_E;


      // ysv col
      case KC_S: return KC_Y;
      case KC_Y: return KC_S;

      case KC_V: return KC_Y;
      // btg col
      case KC_B: return KC_T;
      case KC_T: return KC_B;

      case KC_G: return KC_Y;

      // lrx col
      case KC_L: return KC_R;
      case KC_R: return KC_L;
      // dhf col
      case KC_D: return KC_F;

    }
  } else if ((mods & MOD_MASK_CTRL)) {
    switch (keycode) {
      case KC_A:  // Ctrl+A -> Ctrl+C
        return C(KC_C);
    }
  }
  return KC_TRNS;
}
// clang-format on


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }

  return true;
}
