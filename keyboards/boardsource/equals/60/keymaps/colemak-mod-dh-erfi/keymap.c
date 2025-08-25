// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK,
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_ortho_5x12(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_DEL,
        KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_APP, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
    ),
    [_QWERTY] = LAYOUT_ortho_5x12(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_APP, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
    ),
    [_RAISE] = LAYOUT_ortho_5x12(
        LSFT(KC_GRAVE), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_BSPC,
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, LSFT(KC_MINUS), KC_KP_PLUS, LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_BSLS),
        KC_RSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NONUS_HASH, KC_MPRV, KC_MNXT, KC_SLASH, KC_ENTER,
        _______, _______, _______, _______, _______, KC_SPC, KC_SPC, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
    ),
    [_LOWER] = LAYOUT_ortho_5x12(
        LSFT(KC_GRAVE), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_BSPC,
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_RSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NONUS_HASH, _______, _______, KC_SLASH, KC_ENTER,
        _______, RGB_TOG, RGB_MOD, RGB_RMOD, _______, KC_SPC, KC_SPC, _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_ortho_5x12(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        QK_BOOT, KC_PWR, KC_SLEP, KC_WAKE, _______, _______, _______, _______, DF(_QWERTY), DF(_COLEMAK), _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return state;
}
