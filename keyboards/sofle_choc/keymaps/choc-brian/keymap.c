#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#include "oled.c"
#include "encoder.c"

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
  KC_ESC,   MAGIC,   MAGIC,    MAGIC,    QK_CAPS_WORD_TOGGLE,    KC_T,                     KC_Y,     KC_U,     KC_I,    KC_O,   KC_P,    KC_BSPC, \
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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif

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
// clang-format on

#include "keymap_combo.h"

// #define easy_toggle
#ifdef easy_toggle
const uint16_t PROGMEM CM1[] = {KC_E,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM2[] = {KC_T,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM3[] = {KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM4[] = {KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM5[] = {KC_E,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM6[] = {KC_T,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM7[] = {KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM8[] = {KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM9[] = {KC_I,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM10[] = {KC_N,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM11[] = {KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM12[] = {KC_R,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM13[] = {KC_I,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM14[] = {KC_N,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM15[] = {KC_S,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM16[] = {KC_R,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM17[] = {KC_E,KC_T,COMBO_END};
const uint16_t PROGMEM CM18[] = {KC_O,KC_A,COMBO_END};
const uint16_t PROGMEM CM19[] = {KC_I,KC_N,COMBO_END};
const uint16_t PROGMEM CM20[] = {KC_S,KC_R,COMBO_END};
const uint16_t PROGMEM CM21[] = {KC_E,KC_T,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM22[] = {KC_O,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM23[] = {KC_I,KC_N,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM24[] = {KC_S,KC_R,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM25[] = {KC_E,KC_T,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM26[] = {KC_O,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM27[] = {KC_I,KC_N,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM28[] = {KC_S,KC_R,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM29[] = {KC_I,KC_R,COMBO_END};
const uint16_t PROGMEM CM30[] = {KC_T,KC_O,COMBO_END};
const uint16_t PROGMEM CM31[] = {KC_E,KC_A,COMBO_END};
const uint16_t PROGMEM CM32[] = {KC_N,KC_S,COMBO_END};
const uint16_t PROGMEM CM33[] = {KC_I,KC_R,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM34[] = {KC_T,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM35[] = {KC_E,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM36[] = {KC_N,KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM37[] = {KC_I,KC_R,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM38[] = {KC_T,KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM39[] = {KC_E,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM40[] = {KC_N,KC_S,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM41[] = {KC_E,KC_O,COMBO_END};
const uint16_t PROGMEM CM42[] = {KC_T,KC_A,COMBO_END};
const uint16_t PROGMEM CM43[] = {KC_I,KC_S,COMBO_END};
const uint16_t PROGMEM CM44[] = {KC_N,KC_R,COMBO_END};
const uint16_t PROGMEM CM45[] = {KC_E,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM46[] = {KC_T,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM47[] = {KC_I,KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM48[] = {KC_N,KC_R,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM49[] = {KC_E,KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM50[] = {KC_T,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM51[] = {KC_I,KC_S,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM52[] = {KC_N,KC_R,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM53[] = {KC_S,KC_E,COMBO_END};
const uint16_t PROGMEM CM54[] = {KC_R,KC_T,COMBO_END};
const uint16_t PROGMEM CM55[] = {KC_I,KC_O,COMBO_END};
const uint16_t PROGMEM CM56[] = {KC_N,KC_A,COMBO_END};
const uint16_t PROGMEM CM57[] = {KC_S,KC_E,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM58[] = {KC_R,KC_T,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM59[] = {KC_I,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM60[] = {KC_N,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM61[] = {KC_S,KC_E,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM62[] = {KC_R,KC_T,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM63[] = {KC_I,KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM64[] = {KC_N,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM65[] = {KC_N,KC_O,COMBO_END};

const uint16_t PROGMEM CM66[] = {KC_I,KC_A,COMBO_END};

const uint16_t PROGMEM CM67[] = {KC_R,KC_E,COMBO_END};
const uint16_t PROGMEM CM68[] = {KC_S,KC_T,COMBO_END};
const uint16_t PROGMEM CM69[] = {KC_N,KC_O,KC_SPC,COMBO_END};

const uint16_t PROGMEM CM70[] = {KC_I,KC_A,KC_SPC,COMBO_END};

const uint16_t PROGMEM CM71[] = {KC_R,KC_E,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM72[] = {KC_S,KC_T,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM73[] = {KC_N,KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM74[] = {KC_I,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM75[] = {KC_R,KC_E,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM76[] = {KC_S,KC_T,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM77[] = {KC_S,KC_A,COMBO_END};
const uint16_t PROGMEM CM78[] = {KC_R,KC_O,COMBO_END};
const uint16_t PROGMEM CM79[] = {KC_I,KC_T,COMBO_END};
const uint16_t PROGMEM CM80[] = {KC_N,KC_E,COMBO_END};
const uint16_t PROGMEM CM81[] = {KC_S,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM82[] = {KC_R,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM83[] = {KC_I,KC_T,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM84[] = {KC_N,KC_E,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM85[] = {KC_S,KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM86[] = {KC_N,KC_E,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM87[] = {KC_E,KC_T,KC_O,COMBO_END};
const uint16_t PROGMEM CM88[] = {KC_I,KC_N,KC_S,COMBO_END};
const uint16_t PROGMEM CM89[] = {KC_E,KC_T,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM90[] = {KC_I,KC_N,KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM91[] = {KC_E,KC_T,KC_O,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM92[] = {KC_I,KC_N,KC_S,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM93[] = {KC_A,KC_R,COMBO_END};
const uint16_t PROGMEM CM94[] = {KC_O,KC_S,COMBO_END};
const uint16_t PROGMEM CM95[] = {KC_T,KC_N,COMBO_END};
const uint16_t PROGMEM CM96[] = {KC_E,KC_I,COMBO_END};
const uint16_t PROGMEM CM97[] = {KC_A,KC_R,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM98[] = {KC_O,KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM99[] = {KC_T,KC_N,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM100[] = {KC_E,KC_I,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM101[] = {KC_A,KC_R,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM102[] = {KC_O,KC_S,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM103[] = {KC_T,KC_N,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM104[] = {KC_E,KC_I,KC_BSPC,COMBO_END};

const uint16_t PROGMEM CM105[] = {KC_T,KC_O,KC_A,COMBO_END};
const uint16_t PROGMEM CM106[] = {KC_T,KC_O,KC_A,KC_BSPC,COMBO_END};

const uint16_t PROGMEM CM107[] = {KC_X,KC_BSPC,COMBO_END};

const uint16_t PROGMEM CM108[] = {KC_E,KC_T,KC_O,KC_A,COMBO_END};
const uint16_t PROGMEM CM109[] = {KC_E,KC_T,KC_O,KC_A,KC_BSPC,COMBO_END};

const uint16_t PROGMEM CM110[] = {KC_N,KC_S,KC_A,COMBO_END};
const uint16_t PROGMEM CM111[] = {KC_N,KC_S,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM112[] = {KC_N,KC_S,KC_A,KC_BSPC,COMBO_END};

// 🟪🟩🟪
// 🟩🟪🟩🟪 g G #
const uint16_t PROGMEM CM113[] = {KC_E,KC_N,KC_O,COMBO_END};
const uint16_t PROGMEM CM114[] = {KC_E,KC_N,KC_O,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM115[] = {KC_E,KC_N,KC_O,KC_BSPC,COMBO_END};

// 🟪🟩🟩
// 🟩🟪🟪🟪 w W 8
const uint16_t PROGMEM CM116[] = {KC_E,KC_N,KC_S,COMBO_END};
const uint16_t PROGMEM CM117[] = {KC_E,KC_N,KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM118[] = {KC_E,KC_N,KC_S,KC_BSPC,COMBO_END};

// 🟪🟪🟩
// 🟪🟩🟪🟩 x X ^
const uint16_t PROGMEM CM119[] = {KC_T,KC_S,KC_A,COMBO_END};
const uint16_t PROGMEM CM120[] = {KC_T,KC_S,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM121[] = {KC_T,KC_S,KC_A,KC_BSPC,COMBO_END};

// 🟪🟪🟪
// 🟪🟩🟩🟩 m M $
const uint16_t PROGMEM CM122[] = {KC_T,KC_O,KC_A,COMBO_END};
const uint16_t PROGMEM CM123[] = {KC_T,KC_O,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM124[] = {KC_T,KC_O,KC_A,KC_BSPC,COMBO_END};

// 🟪🟪🟩
// 🟩🟩🟪🟪 ?   !
const uint16_t PROGMEM CM125[] = {KC_E,KC_T,KC_S,COMBO_END};
const uint16_t PROGMEM CM126[] = {KC_E,KC_T,KC_S,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM127[] = {KC_E,KC_T,KC_S,KC_BSPC,COMBO_END};

// 🟪🟪🟪
// 🟩🟩🟩🟩 ENTER  ESC
const uint16_t PROGMEM CM128[] = {KC_E,KC_T,KC_O,KC_A,COMBO_END};
const uint16_t PROGMEM CM129[] = {KC_E,KC_T,KC_O,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM130[] = {KC_E,KC_T,KC_O,KC_A,KC_BSPC,COMBO_END};

// 🟪🟩🟩
// 🟩🟪🟪🟩 TAB   DEL
const uint16_t PROGMEM CM131[] = {KC_E,KC_N,KC_S,KC_A,COMBO_END};
const uint16_t PROGMEM CM132[] = {KC_E,KC_N,KC_S,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM133[] = {KC_E,KC_N,KC_S,KC_A,KC_BSPC,COMBO_END};

// 🟪🟩🟪
// 🟪🟪🟩🟩 j J =
const uint16_t PROGMEM CM134[] = {KC_N,KC_O,KC_A,COMBO_END};
const uint16_t PROGMEM CM135[] = {KC_N,KC_O,KC_A,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM136[] = {KC_N,KC_O,KC_A,KC_BSPC,COMBO_END};

// arrow keys
const uint16_t PROGMEM CM137[] = {KC_F1,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM138[] = {KC_F2,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM139[] = {KC_F3,KC_SPC,COMBO_END};
const uint16_t PROGMEM CM140[] = {KC_F4,KC_SPC,COMBO_END};

const uint16_t PROGMEM CM141[] = {KC_F1,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM142[] = {KC_F2,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM143[] = {KC_F3,KC_BSPC,COMBO_END};
const uint16_t PROGMEM CM144[] = {KC_F4,KC_BSPC,COMBO_END};

combo_t key_combos[] = {
	COMBO(CM1,S(KC_O)),
	COMBO(CM2,S(KC_E)),
	COMBO(CM3,S(KC_A)),
	COMBO(CM4,S(KC_I)),

	COMBO(CM5,KC_LPRN),
	COMBO(CM6,KC_LBRC),
	COMBO(CM7,KC_LCBR),
	COMBO(CM8,KC_LT),

	COMBO(CM9,S(KC_N)),
	COMBO(CM10,S(KC_R)),
	COMBO(CM11,S(KC_T)),

	COMBO(CM12,S(KC_S)),
	COMBO(CM13,KC_RPRN),
	COMBO(CM14,KC_RBRC),
	COMBO(CM15,KC_RCBR),
	COMBO(CM16,KC_GT),
	COMBO(CM17,KC_H),
	COMBO(CM18,KC_L),
	COMBO(CM19,KC_Y),
	COMBO(CM20,KC_B),
	COMBO(CM21,S(KC_H)),
	COMBO(CM22,S(KC_L)),
	COMBO(CM23,S(KC_Y)),
	COMBO(CM24,S(KC_B)),
	COMBO(CM25,KC_0),
	COMBO(CM26,KC_4),
	COMBO(CM27,KC_5),
	COMBO(CM28,KC_9),
	COMBO(CM29,KC_G),
	COMBO(CM30,KC_U),
	COMBO(CM31,KC_D),
	COMBO(CM32,KC_P),
	COMBO(CM33,S(KC_G)),
	COMBO(CM34,S(KC_U)),
	COMBO(CM35,S(KC_D)),
	COMBO(CM36,S(KC_P)),
	COMBO(CM37,KC_HASH),
	COMBO(CM38,KC_2),
	COMBO(CM39,KC_AT),
	COMBO(CM40,KC_7),
	COMBO(CM41,KC_C),
	COMBO(CM42,KC_Q),
	COMBO(CM43,KC_F),
	COMBO(CM44,KC_Z),
	COMBO(CM45,S(KC_C)),
	COMBO(CM46,S(KC_Q)),
	COMBO(CM47,S(KC_F)),
	COMBO(CM48,S(KC_Z)),
	COMBO(CM49,KC_1),
	COMBO(CM50,KC_3),
	COMBO(CM51,KC_6),
	COMBO(CM52,KC_8),
	COMBO(CM53,KC_V),
	COMBO(CM54,KC_X),
	COMBO(CM55,KC_K),
	COMBO(CM56,KC_J),
	COMBO(CM57,S(KC_V)),
	COMBO(CM58,S(KC_X)),
	COMBO(CM59,S(KC_K)),
	COMBO(CM60,S(KC_J)),
	COMBO(CM61,KC_ASTR),
	COMBO(CM62,KC_CIRC),
	COMBO(CM63,KC_PERCENT),
	COMBO(CM64,KC_EQL),
	COMBO(CM65,KC_MINS),
	COMBO(CM66,KC_W),
	COMBO(CM67,KC_M),
	COMBO(CM68,KC_SLSH),
	COMBO(CM69,KC_UNDS),
	COMBO(CM70,S(KC_W)),
	COMBO(CM71,S(KC_M)),
	COMBO(CM72,KC_BSLS),
	COMBO(CM73,KC_PLUS),
	COMBO(CM74,KC_AMPR),
	COMBO(CM75,KC_DLR),
	COMBO(CM76,KC_PIPE),
	COMBO(CM77,KC_QUOT),
	COMBO(CM78,KC_SCLN),
	COMBO(CM79,KC_QUES),
	COMBO(CM80,KC_COMMA),
	COMBO(CM81,KC_DQT),
	COMBO(CM82,KC_COLN),
	COMBO(CM83,KC_EXLM),
	COMBO(CM84,KC_DOT),
	COMBO(CM85,KC_GRAVE),
	COMBO(CM86,KC_TILDE),

	COMBO(CM87,KC_S),
	COMBO(CM88,KC_SCLN),
	COMBO(CM89,S(KC_S)),
	COMBO(CM90,KC_DEL),
	COMBO(CM91,KC_RIGHT_ANGLE_BRACKET),

	COMBO(CM92,S(KC_SCLN)),
	//COMBO(CM93,MY_LGUI),
	//COMBO(CM94,MY_LALT),
	//COMBO(CM95,MY_LCTL),
	//COMBO(CM96,MY_LSFT),
    COMBO(CM94,KC_UNDERSCORE),
    COMBO(CM95,KC_EQUAL),
    COMBO(CM96,OSM(MOD_LSFT)),

	COMBO(CM97,KC_RIGHT),
	COMBO(CM98,KC_UP),
	COMBO(CM99,KC_DOWN),
	COMBO(CM100,KC_LEFT),
	COMBO(CM101,KC_PGUP),
	COMBO(CM102,KC_HOME),
	COMBO(CM103,KC_END),
	COMBO(CM104,KC_PGDN),

    COMBO(CM105,KC_SCLN),
    COMBO(CM106,S(KC_SCLN)), // colon ':'
    COMBO(CM107,KC_RIGHT_ANGLE_BRACKET), // redundant?
    COMBO(CM108,KC_QUESTION),
    COMBO(CM109,KC_EXCLAIM),

    COMBO(CM110,KC_B),
    COMBO(CM111,S(KC_B)),
    COMBO(CM112,KC_9),

    COMBO(CM113,KC_G),
    COMBO(CM114,S(KC_G)),
    COMBO(CM115,KC_HASH),

    COMBO(CM116,KC_W),
    COMBO(CM117,S(KC_W)),
    COMBO(CM118,KC_8),

    COMBO(CM119,KC_X),
    COMBO(CM120,S(KC_X)),
    COMBO(CM121,KC_CIRC),

    COMBO(CM122,KC_M),
    COMBO(CM123,S(KC_M)),
    COMBO(CM124,KC_DOLLAR),

    COMBO(CM125,KC_QUESTION),
    // COMBO(CM126, NOT DECIDED YET),
    COMBO(CM127,KC_EXCLAIM),

    COMBO(CM128,KC_ENTER),
    // COMBO(CM129, NOT DECIDED YET),
    COMBO(CM130,KC_ESC),

    COMBO(CM131,KC_TAB),
    // COMBO(CM132, NOT DECIDED YET),
    COMBO(CM133,KC_DEL),

    COMBO(CM134,KC_J),
    COMBO(CM135,S(KC_J)),
    COMBO(CM136,KC_EQUAL),

    COMBO(CM141,KC_LEFT),
    COMBO(CM142,KC_UP),
    COMBO(CM143,KC_DOWN),
    COMBO(CM144,KC_RIGHT),
};
#endif


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  return true;
}

void keyboard_post_init_user(void) {
    set_single_persistent_default_layer(0);
}
