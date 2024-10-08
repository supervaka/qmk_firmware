// Copyright 2024 supervaka (@supervaka)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT
#define DEVICE_VER 0x0001

// #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
// #define CAPS_WORD_INVERT_ON_SHIFT

// https://precondition.github.io/home-row-mods#using-home-row-mods-with-qmk
#define QUICK_TAP_TERM 0


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 15
