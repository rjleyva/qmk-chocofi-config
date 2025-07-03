/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#include QMK_KEYBOARD_H

// Tap Dance Structure
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
      .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}) }

enum {
    CT_A = 0,
    CT_R,
    CT_S,
    CT_T,
    CT_N,
    CT_E,
    CT_I,
    CT_O,
};

tap_dance_action_t tap_dance_actions[] = {
    [CT_A] = ACTION_TAP_DANCE_TAP_HOLD(KC_A, KC_LGUI),
    [CT_R] = ACTION_TAP_DANCE_TAP_HOLD(KC_R, KC_LALT),
    [CT_S] = ACTION_TAP_DANCE_TAP_HOLD(KC_S, KC_LCTL),
    [CT_T] = ACTION_TAP_DANCE_TAP_HOLD(KC_T, KC_LSFT),
    [CT_N] = ACTION_TAP_DANCE_TAP_HOLD(KC_N, KC_RSFT),
    [CT_E] = ACTION_TAP_DANCE_TAP_HOLD(KC_E, KC_RALT),
    [CT_I] = ACTION_TAP_DANCE_TAP_HOLD(KC_I, KC_LCTL),
    [CT_O] = ACTION_TAP_DANCE_TAP_HOLD(KC_O, KC_RGUI),
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, XXXXXXX,
        XXXXXXX, TD(CT_A),TD(CT_R),TD(CT_S),TD(CT_T),KC_G,                      KC_M,    TD(CT_N),TD(CT_E),TD(CT_I),TD(CT_O), XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                                      XXXXXXX, KC_ENT,  MO(1),     MO(2), KC_SPC, XXXXXXX
    ),

    [1] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,                   KC_PMNS, KC_PEQL, KC_QUOT, KC_LBRC, KC_RBRC, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,                   KC_GRV,  KC_PPLS, KC_SCLN, KC_MINS, KC_BSLS, XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,   KC_ESC, KC_BSPC, XXXXXXX
    ),

    [2] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      XXXXXXX, KC_TAB, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

// Optional Encoder Map
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { 
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
        ENCODER_CCW_CW(RM_VALD, RM_VALU),
        ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
    },
    [1] = { 
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
        ENCODER_CCW_CW(RM_VALD, RM_VALU),
        ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
    },
    [2] = { 
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
        ENCODER_CCW_CW(RM_VALD, RM_VALU),
        ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
    },
    [3] = { 
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MPRV, KC_MNXT),
        ENCODER_CCW_CW(RM_VALD, RM_VALU),
        ENCODER_CCW_CW(KC_RGHT, KC_LEFT),
    },
};
#endif
