// Copyright 2023 

#include QMK_KEYBOARD_H

#define PC              0   
#define PCSHFT          1   
#define PCFN            2   

#define PCLSHFT LM(PCSHFT, MOD_LSFT)
#define PCRSHFT LM(PCSHFT, MOD_RSFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ,--------------------------------------------------------------------.
     * | <- | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | + | - | £ | HOME | BS |
     * |--------------------------------------------------------------------|
     * | CTRL | Q | W | E | R | T | Y | U | I | O | P | @ | * | ↑ | RESTORE |
     * |--------------------------------------------------------------------|
     * | RS | SL | A | S | D | F | G | H | J | K | L | : | ; | = |  RETURN  |  (SL - Shift Lock, is NOT part of the keymap)
     * |--------------------------------------------------------------------|
     * | C= | SFT  | Z | X | C | V | B | N | M | , | . | / | SFT |  ↓ | ->  |
     * |--------------------------------------------------------------------|
     *                     |           SPACE          |
     *                     `--------------------------'
     */

    // Base Map (US Layout)
    [PC] = LAYOUT_c64_9x9(
        KC_ESC,            KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,     KC_PLUS, KC_MINS, KC_BSLS, KC_HOME, KC_DEL,     KC_F1,
        CTL_T(KC_TAB),     KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,     KC_AT,   KC_ASTR, KC_UP,   KC_BSPC,             KC_F3,
        KC_LALT,           KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_COLON, KC_SCLN, KC_EQL,           KC_ENT,              KC_F5,
        MO(PCFN), PCLSHFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,  PCRSHFT,          KC_DOWN, KC_RGHT,             KC_F7,
                                                        KC_SPC
    ),
    // Shifted Base Map (US Layout)
    [PCSHFT] = LAYOUT_c64_9x9(
        KC_TILD,          KC_EXLM, KC_DQUO, KC_HASH, KC_DLR, KC_PERC, KC_AMPR, KC_QUOTE, KC_LPRN, KC_RPRN,   KC_NO, KC_TRNS, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS,
        KC_LALT,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,          KC_TRNS,                 KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,                 KC_TRNS,
                                                        KC_TRNS
    ),
    // Function Layer (US Layout)
    [PCFN] = LAYOUT_c64_9x9(
        KC_GRAVE,         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_CIRC, KC_END, KC_TRNS,         KC_F2,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_F4,
        KC_LALT,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS,          KC_TRNS,                 KC_F6,
        KC_TRNS, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,          KC_UP,   KC_LEFT,                 KC_F8,
                                                        KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case KC_LBRC:
        case KC_RBRC:
        case KC_QUOTE:
            if (IS_LAYER_ON(PCSHFT)) {
                if (record->event.pressed) {
                    const uint8_t mods = get_mods();

                    // Send without the mods
                    del_mods(mods);
                    register_code(keycode);
                    set_mods(mods);
                } else {
                    unregister_code(keycode);
                }
                return false;
            }
    }
    return true;
}
