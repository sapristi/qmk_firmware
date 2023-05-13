
/* Layers */
#define L_SYM MO(_SYM)
#define L_NAV MO(_NAV)
#define L_NUM MO(_NUM)
#define L_ADJ MO(_ADJ)

/* thumb mod tap */
#define SFT_SPC MT(MOD_LSFT, KC_SPC)
#define NAV_ENT LT(_NAV, KC_ENT)
#define NUM_BSP LT(_NUM, KC_BSPC)
#define SYM_ESC LT(_SYM, KC_ESC)
#define ALT_TAB MT(MOD_LALT, KC_TAB)

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
