// Copyright 2023 

#include QMK_KEYBOARD_H
#ifndef LEGACY_PINOUT
    #include "quantum/rgblight/rgblight.h"
#endif

enum layer_number {
    PC = 0,
    PCSHFT,
    PCFN,
    BMC64,
    VICE,
    VICESHIFT
};

enum custom_keycodes {
  PC_MODE = SAFE_RANGE,
  BMC64_MODE,
  VICE_MODE
};

#define PCLSHFT LM(PCSHFT, MOD_LSFT)
#define PCRSHFT LM(PCSHFT, MOD_RSFT)
#define VICELSHFT LM(VICESHIFT, MOD_LSFT)
#define VICERSHFT LM(VICESHIFT, MOD_RSFT)

enum combos {
    PC_LAYER_SET_DEFAULT,
    BMC64_LAYER_SET_DEFAULT,
    VICE_LAYER_SET_DEFAULT,
    VICE_MENU_F12
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM pc_layer_set_default[] = {KC_LALT, KC_F1, COMBO_END};
const uint16_t PROGMEM bmc64_layer_set_default[] = {KC_LALT, KC_F3, COMBO_END};
const uint16_t PROGMEM vice_layer_set_default[] = {KC_LALT, KC_F5, COMBO_END};
const uint16_t PROGMEM vice_menu_f12[] = {KC_F1, KC_F7, COMBO_END};

combo_t key_combos[] = {
    [PC_LAYER_SET_DEFAULT] = COMBO(pc_layer_set_default, PC_MODE),
    [BMC64_LAYER_SET_DEFAULT] = COMBO(bmc64_layer_set_default, BMC64_MODE),
    [VICE_LAYER_SET_DEFAULT] = COMBO(vice_layer_set_default, VICE_MODE),
    [VICE_MENU_F12] = COMBO(vice_menu_f12, KC_F12)
};
#endif // COMBO_ENABLE

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
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,          KC_TRNS,                 KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,                 KC_TRNS,
                                                        KC_TRNS
    ),
    // Function Layer (US Layout)
    [PCFN] = LAYOUT_c64_9x9(
        KC_GRAVE,         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_CIRC, KC_END, KC_TRNS,         KC_F2,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_F4,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS,          KC_TRNS,                 KC_F6,
        KC_TRNS, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,          KC_UP,   KC_LEFT,                 KC_F8,
                                                        KC_TRNS
    ),
    // BMC64 Positional Map (US Layout)
    [BMC64] = LAYOUT_c64_9x9(
        KC_GRAVE,         KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,     KC_MINS,  KC_EQL,  KC_INS,  KC_HOME, KC_BSPC,    KC_F1,
        KC_TAB,           KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,     KC_LBRC,  KC_RBRC, KC_DEL, KC_PGUP,              KC_F3,
        KC_ESC,           KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,  KC_QUOTE, KC_BSLS,          KC_ENT,              KC_F5,
        KC_LCTL, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,           KC_DOWN, KC_RGHT,             KC_F7,
                                                        KC_SPC
    ),
    // Vice Positional Map (US Layout) enables VICE_MENU_F12 combo with F1+F7
    [VICE] = LAYOUT_c64_9x9(
        KC_GRAVE,           KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,     KC_MINS,   KC_EQL,  KC_INS,  KC_HOME, KC_BSPC,    KC_F1,
        KC_TAB,             KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,     KC_LBRC,   KC_RBRC, KC_DEL,  KC_PGUP,             KC_F3,
        KC_ESC,             KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,  KC_QUOTE,  KC_BSLS,          KC_ENT,              KC_F5,
        KC_LCTL, VICELSHFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,  VICERSHFT,          KC_DOWN, KC_RGHT,             KC_F7,
                                                        KC_SPC
    ),
    // Vice shifted layout to enable keys cursor up and left to work in menus and even function keys
    [VICESHIFT] = LAYOUT_c64_9x9(
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_F2,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_F4,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,              KC_F6,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_UP,   KC_LEFT,              KC_F8,
                                                        KC_SPC
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
            break;

        case PC_MODE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(PC);
            }
            break;

        case BMC64_MODE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(BMC64);
            }
            break;
            
        case VICE_MODE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(VICE);
            }
            break;
    }
    return true;
}

#ifdef COMBO_ENABLE
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case VICE_MENU_F12:
            // Only allow the F1+F7->F12 combo on the VICE layer
            if (!layer_state_cmp(default_layer_state, VICE)) {
                return false;
            }
            break;
    }
    return true;
}
#endif

#ifndef LEGACY_PINOUT
void keyboard_post_init_user(void) {
  rgblight_setrgb_range(0, 0, 0, 0, 1);  // Off
  //rgblight_setrgb_range(25, 0, 0, 0, 1);  // Red
  //rgblight_setrgb_range(0, 25, 0, 0, 1);  // Green
  //rgblight_setrgb_range(0, 0, 25, 0, 1);  // Blue
  //rgblight_setrgb_range(0, 25, 25, 0, 1);  // Cyan
  //rgblight_setrgb_range(25, 0, 50, 0, 1);  // Purple
  //rgblight_setrgb_range(25, 25, 0, 0, 1);  // Yellow
  //rgblight_setrgb_range(25, 25, 25, 0, 1);  // White
}
#endif