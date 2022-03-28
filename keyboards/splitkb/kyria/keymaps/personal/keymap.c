/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _SYM,
    _NAV,
    _NUM,
    _ADJ
};


/* /\* thumb mod tap *\/ */
#define T_SP_SH MT(MOD_LSFT, KC_SPC)
#define T_EN_NV LT(_NAV, KC_ENT)
#define T_TB_AG MT(MOD_RALT, KC_TAB)
#define T_BS_NU LT(_NUM, KC_BSPC)
#define T_BS_SY LT(_SYM, KC_BSPC)
#define T_TB_AL MT(MOD_LALT, KC_TAB)
#define SYM_ESC LT(_SYM, KC_ESC)

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


enum custom_keycodes {
    AC_E_GR = SAFE_RANGE,
    AC_A_GR,
};

void unshifted_grav (void) {
    bool isShifted = get_mods() & MOD_MASK_SHIFT;
    if (isShifted) {
        del_mods(MOD_MASK_SHIFT);
        SEND_STRING(SS_RALT("`"));
        register_code(KC_LSFT);
    } else {
        SEND_STRING(SS_RALT("`"));
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case AC_E_GR:
        if (record->event.pressed) {
            unshifted_grav();
            SEND_STRING("e");
        } else {
        }
        break;
    case AC_A_GR:
        if (record->event.pressed) {
            unshifted_grav();
            SEND_STRING("a");
        } else {
        }
        break;
    }
    return true;
};
#define AC_C_CE RALT(KC_COMM)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer  _QWERTY
 * ┌───────────────────────────────────────────┐                              ┌─────────────────────────────────────────┐
 * │  ESC   │  Q   │  W   │  E   │  R   │  T   │                              │  Y   │  U   │  I   │  O   │  P   │  `   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │   L⇧   │A / G │S / A │D / C │F / S │  G   │                              │  H   │J / S │K / C │L / A │; / G │ ' "  │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  LCTL  │  Z   │  X   │  C   │  V   │  B   │ ESC  │ ESC  │  │      │      │  N   │  M   │ , <  │ . >  │ / ?  │ - _  │
 * └────────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┤  ├──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 *                   │  ⇆   │ LGUI │T_TB_AL│T_SP_SH │ L_SYM  │  │T_BS_NU │T_EN_NV │T_TB_AG│L_ADJ │      │
 *                   │      │      │       │        │        │  │        │        │       │      │      │
 *                   └──────┴──────┴───────┴────────┴────────┘  └────────┴────────┴───────┴──────┴──────┘
 *                                                                               generated by [keymapviz] */
    [_QWERTY] = LAYOUT(
     KC_ESC,  KC_Q,   KC_W,    KC_E,   KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
     KC_LSFT, HOME_A, HOME_S,  HOME_D, HOME_F,  KC_G,                                        KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
     KC_LCTL, KC_Z,   KC_X,    KC_C,   KC_V,    KC_B,    KC_ESC,  KC_ESC,  _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                              KC_TAB, KC_LGUI, T_TB_AL, T_SP_SH, SYM_ESC,   T_BS_NU, T_EN_NV, T_TB_AG, L_ADJ,   _______
    ),

/* Layer   _SYM
 * ┌───────────────────────────────────────────┐                              ┌─────────────────────────────────────────┐
 * │        │  !   │  @   │  {   │  }   │ | \  │                              │  "   │ ' "  │  `   │  ^   │AC_GRA│      │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │        │  #   │  $   │  (   │  )   │  &   │                              │  _   │ - _  │ / ?  │  *   │AC_AIG│      │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │        │  %   │  ^   │  [   │  ]   │  ~   │      │      │  │      │      │  +   │ = +  │ | \  │  %   │AC_CIR│      │
 * └────────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┤  ├──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 *                   │      │      │       │        │        │  │        │   (    │   )   │      │      │
 *                   │      │      │       │        │        │  │        │        │       │      │      │
 *                   └──────┴──────┴───────┴────────┴────────┘  └────────┴────────┴───────┴──────┴──────┘
 *                                                                               generated by [keymapviz] */
    [_SYM] = LAYOUT(
      _______, AC_C_CE, KC_EURO, KC_LCBR, KC_RCBR, _______,                                     AC_CIRC, AC_AIGU, AC_E_AI, AC_GRAV, AC_C_CE, _______,
      _______, HM_1,    HM_2,    KC_LPRN, KC_RPRN, _______,                                     KC_CIRC, KC_QUOT, KC_DQT,  KC_GRV,  KC_BSLS, _______,
      _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_EURO, AC_CIRC, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* Layer   _NAV
 * ┌───────────────────────────────────────────┐                              ┌─────────────────────────────────────────┐
 * │        │      │      │      │      │      │                              │ PGUP │ HOME │  ↑   │ END  │      │      │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │        │ LGUI │ Alt  │ LCTL │  L⇧  │      │                              │ PGDN │  ←   │  ↓   │  →   │      │      │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │        │      │      │      │      │      │      │      │  │      │      │      │  ←─  │ DEL  │ WBAK │ WFWD │      │
 * └────────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┤  ├──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 *                   │      │      │       │        │        │  │        │        │       │      │      │
 *                   │      │      │       │        │        │  │        │        │       │      │      │
 *                   └──────┴──────┴───────┴────────┴────────┘  └────────┴────────┴───────┴──────┴──────┘
 *                                                                               generated by [keymapviz] */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
      _______, HM_1,    HM_2,    HM_3,    HM_4,    _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_DEL,  KC_WBAK, KC_WFWD, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/* Layer   _NUM
 * ┌───────────────────────────────────────────┐                              ┌─────────────────────────────────────────┐
 * │        │      │      │      │      │      │                              │ = +  │  7   │  8   │  9   │ / ?  │      │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │        │ LGUI │ Alt  │ LCTL │  L⇧  │      │                              │ - _  │  4   │  5   │  6   │  0   │      │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │        │      │      │      │      │      │      │      │  │      │      │ - _  │  1   │  2   │  3   │ . >  │      │
 * └────────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┤  ├──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 *                   │      │      │       │        │        │  │        │        │       │      │      │
 *                   │      │      │       │        │        │  │        │        │       │      │      │
 *                   └──────┴──────┴───────┴────────┴────────┘  └────────┴────────┴───────┴──────┴──────┘
 *                                                                               generated by [keymapviz] */

    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_EQL,  KC_7,    KC_8,    KC_9,    KC_SLSH, _______,
      _______, HM_1,    HM_2,    HM_3,    HM_4,    _______,                                     KC_MINS, KC_4,    KC_5,    KC_6,    KC_0,    _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
                    ),

/* Layer   _ADJ
 * ┌───────────────────────────────────────────┐                              ┌─────────────────────────────────────────┐
 * │        │ MUTE │ VOLD │ VOLU │ PSCR │      │                              │  F1  │  F2  │  F3  │  F4  │  F5  │      │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │        │      │ BRID │ BRIU │      │      │                              │  F6  │  F7  │  F8  │  F9  │ F10  │      │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │        │RGB_HU│RGB_SA│RGB_VA│      │      │      │      │  │      │      │ F11  │ F12  │      │      │      │      │
 * └────────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┤  ├──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 *                   │      │      │       │        │        │  │        │        │       │      │      │
 *                   │      │      │       │        │        │  │        │        │       │      │      │
 *                   └──────┴──────┴───────┴────────┴────────┘  └────────┴────────┴───────┴──────┴──────┘
 *                                                                               generated by [keymapviz] */
    [_ADJ] = LAYOUT(
      XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR, XXXXXXX,                                     KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,  XXXXXXX,
      XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,                                     KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10, XXXXXXX,
      XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F11, KC_F12,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif
