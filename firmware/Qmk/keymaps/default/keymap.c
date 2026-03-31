// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// ─────────────────────────────────────
// KEYMAP (1 layer, 5 keys)
// Układ:
// I I
// I I I
//
// ┌──────┬──────┐
// │  1   │  2   │
// ├──────┼──────┬──────┐
// │  3   │  4   │  5   │
// └──────┴──────┴──────┘
// ─────────────────────────────────────

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_P1,   KC_P2,
        KC_CALC, KC_P4,   KC_P5
    )
};

// ─────────────────────────────────────
// ENCODER (volume)
// ─────────────────────────────────────
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

// ─────────────────────────────────────
// OLED (prosty status)
// ─────────────────────────────────────
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_clear();

    oled_write_ln_P(PSTR("KostekPad"), false);
    oled_write_ln_P(PSTR("Layer: BASE"), false);

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);

    return false;
}
#endif