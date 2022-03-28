/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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


#define SLH_MOU LT(_MOU, KC_SLSH)

enum userspace_keycodes {
    SCLN_DRG = CHARYBDIS_SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t my_hash_timer;
    switch (keycode) {
    case SCLN_DRG:
        if(record->event.pressed) {
            my_hash_timer = timer_read();
            charybdis_set_pointer_dragscroll_enabled(!charybdis_get_pointer_dragscroll_enabled());
        } else {
            charybdis_set_pointer_dragscroll_enabled(!charybdis_get_pointer_dragscroll_enabled());
            if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
                SEND_STRING(";"); // Change the character(s) to be sent on tap here
            }
        }
        return false; // We handled this keypress
    }
    return true; // We didn't handle other keypresses
}


/* // clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,       KC_H,  HOME_J,  HOME_K,  HOME_L,SCLN_DRG,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, SLH_MOU,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         ALT_TAB, SFT_SPC, SYM_ESC,    NUM_BSP, NAV_ENT
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_SYM] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, KC_EURO, KC_LCBR, KC_RCBR, _______,    AC_CIRC, AC_AIGU, AC_E_AI, AC_GRAV, AC_C_CE,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT, _______, KC_LPRN, KC_RPRN, _______,    KC_CIRC, KC_QUOT, KC_DQT,  KC_GRV,  KC_BSLS,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       DRGSCRL, _______, KC_LBRC, KC_RBRC, _______,    _______, KC_BTN1, KC_BTN3, KC_BTN2, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_NAV] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, _______, _______, _______, _______,    KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       HM_1,    HM_2,    HM_3,    HM_4,    _______,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_BRIU, KC_BRID, _______, _______, _______,    KC_DEL,  _______, _______, _______, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, L_ADJ,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [_NUM] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      _______, _______, _______, _______, _______,     KC_EQL,  KC_7,    KC_8,    KC_9,    KC_QUOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       HM_1,    HM_2,    HM_3,    HM_4,    _______,    KC_MINS, KC_4,    KC_5,    KC_6,    KC_0,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    KC_ASTR, KC_1,    KC_2,    KC_3,    KC_DOT,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
                                ),
  [_ADJ] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR, XXXXXXX,    KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,    KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,    KC_F11, KC_F12,   XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
                                ),
  [_MOU] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      _______, _______, _______, _______, _______,    _______, KC_BTN1, KC_BTN3, KC_BTN2, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                        _______, _______, _______,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
                                ),

};
// clang-format on
#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

void shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb_red();
#endif  // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif  // RGB_MATRIX_ENABLE
}
