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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    _SYM,
    _NAV,
    _NUM,
    _ADJ
};


/* thumb mod tap */
#define SFT_SPC MT(MOD_LSFT, KC_SPC)
#define NAV_ENT LT(_NAV, KC_ENT)
#define NUM_BSP LT(_NUM, KC_BSPC)
#define SYM_ESC LT(_SYM, KC_ESC)
#define ALT_TAB MT(MOD_LALT, KC_TAB)

/* Layers */
#define L_SYM MO(_SYM)
#define L_NAV MO(_NAV)
#define L_NUM MO(_NUM)
#define L_ADJ MO(_ADJ)

/* AltGr accents */
#define AC_AIGU RALT(KC_QUOT)
#define AC_GRAV RALT(KC_GRV)
#define AC_CIRC RALT(KC_6)

/* accented */
#define AC_E_AI RALT(KC_E)
#define AC_C_CE RALT(KC_COMM)
#define KC_EURO RALT(KC_5)


/* home row mods /\ mods order */
#define HMT_1 LGUI_T
#define HMT_2 LCTL_T
#define HMT_3 LSFT_T
#define HMT_4 LALT_T

#define HM_1 KC_LGUI
#define HM_2 KC_LCTL
#define HM_3 KC_LSFT
#define HM_4 KC_LALT

/* home row mods */
#define HOME_A HMT_1(KC_A)
#define HOME_S HMT_2(KC_S)
#define HOME_D HMT_3(KC_D)
#define HOME_F HMT_4(KC_F)

// Right-hand home row mods
#define HOME_J HMT_4(KC_J)
#define HOME_K HMT_3(KC_K)
#define HOME_L HMT_2(KC_L)
#define HOME_SCLN HMT_1(KC_SCLN)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,       KC_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         ALT_TAB, SFT_SPC, SYM_ESC,    NUM_BSP, NAV_ENT
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_SYM] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, AC_C_CE, AC_E_AI, KC_LCBR, KC_RCBR,    KC_DQT,  KC_QUOT, KC_GRV,  KC_CIRC, AC_GRAV,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       HM_1,    HM_2,    HM_3,    KC_LPRN, KC_RPRN,    _______, _______, _______, _______, AC_AIGU,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       DRGSCRL, _______, _______, KC_LBRC, KC_RBRC,    KC_BSLS, KC_BTN1, KC_BTN2, KC_BTN3, AC_CIRC,
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
       RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,    KC_DEL,  _______, _______, _______, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [_NUM] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      _______, _______, _______, _______, _______,     KC_EQL,  KC_7,    KC_8,    KC_9,    KC_SLSH,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       HM_1,    HM_2,    HM_3,    HM_4,    _______,    KC_MINS, KC_4,    KC_5,    KC_6,    KC_0,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    KC_ASTR, KC_1,    KC_2,    KC_3,    KC_DOT,
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
