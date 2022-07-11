// Copyright 2022 Mathias Millet (@Mathias Millet)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
                     KC_F1, KC_F2, KC_F3, KC_F4,
                     KC_F5, KC_F6, KC_F7,
                     KC_F8
    )
    /* [_BASE] = LAYOUT( */
    /*                  KC_A, KC_B, KC_C, KC_D, */
    /*                  KC_E, KC_F, KC_G, */
    /*                  KC_H */
    /*                  ) */
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    // default layer
    else {
        if (clockwise) {
            tap_code(KC_F9);
        } else {
            tap_code(KC_F10);
        }
    }
    return true;
}
