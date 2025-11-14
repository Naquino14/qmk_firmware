// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum fsm_keycodes {
    JS_X = SAFE_RANGE,
    JS_Y,
    JS_R1,
    JS_L1,
    JS_A,
    JS_B,
    JS_R2,
    JS_L2,
    JS_UP,
    JS_DOWN,
    JS_LEFT,
    JS_RIGHT,
    JS_START,
    JS_SELECT,
    JS_GUIDE
};

enum layers {
    _BASE,
    _FN,
    _FIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Hom│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │Del│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PgU│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │PgD│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │                        │Alt│ Fn│Ctl│ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_65_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    TG(_FIGHT), MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │Scr│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │BootL│   │   │   │   │   │   │   │Ins│   │PSc│SPU│SPD│Pause│   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │MPT│MNT│MPP│      │SAU│End│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    │    │    │                        │   │   │   │HUU│SAD│HUD│
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [_FN] = LAYOUT_65_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_SCRL,
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, KC_INS,  _______, KC_PSCR, RM_SPDD, RM_SPDU, KC_PAUS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY, _______, RM_SATU, KC_END,
        _______, _______, _______,                            _______,                   _______, _______, _______, RM_HUEU, RM_SATD, RM_HUED
    ),

        /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │Up │   │   │   │   │ X │ Y │RB │LB │   │   │     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │Lef│Dow│Rgt│   │   │   │ A │ B │RT │LT │   │ Start  │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │ Sel  │   │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │    │    │    │                        │FSM│   │   │   │   │   │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
    [_FIGHT] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, JS_GUIDE,
        _______, _______, JS_UP,   _______, _______, _______, _______, JS_X,    JS_Y,    JS_R1,   JS_L1,   _______, _______, _______, _______,
        _______, JS_LEFT, JS_DOWN, JS_RIGHT, _______, _______, _______, JS_A,    JS_B,    JS_R2,   JS_L2,   _______,          JS_START, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, JS_SELECT, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    )

};

enum xbox_btns {
    BTN_A = 0,
    BTN_B,
    BTN_X,
    BTN_Y,
    BTN_LB,
    BTN_RB,
    BTN_BACK,
    BTN_START,
    BTN_GUIDE,
    BTN_RT,
    BTN_LT,
};

static uint8_t dpad_state = 0;

// bitmask
#define DPAD_UP    (1<<0)
#define DPAD_RIGHT (1<<1)
#define DPAD_DOWN  (1<<2)
#define DPAD_LEFT  (1<<3)

static int8_t dpad_to_hat(uint8_t state) {
    // cancel opposite vertical directions
    if ((state & DPAD_UP) && (state & DPAD_DOWN)) state &= ~(DPAD_UP | DPAD_DOWN);
    // cancel opposite horizontal directions
    if ((state & DPAD_LEFT) && (state & DPAD_RIGHT)) state &= ~(DPAD_LEFT | DPAD_RIGHT);

    // now map remaining pressed keys to hat values
    switch (state) {
        case DPAD_UP: return 0;
        case DPAD_UP | DPAD_RIGHT: return 1;
        case DPAD_RIGHT: return 2;
        case DPAD_DOWN | DPAD_RIGHT: return 3;
        case DPAD_DOWN: return 4;
        case DPAD_DOWN | DPAD_LEFT: return 5;
        case DPAD_LEFT: return 6;
        case DPAD_UP | DPAD_LEFT: return 7;
        default: return -1; // neutral if nothing pressed
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(_FIGHT)) {
        switch (keycode) {

            // Face buttons / shoulders
            case JS_X:   record->event.pressed ? register_joystick_button(BTN_X) : unregister_joystick_button(BTN_X); return false;
            case JS_Y:   record->event.pressed ? register_joystick_button(BTN_Y) : unregister_joystick_button(BTN_Y); return false;
            case JS_R1:   record->event.pressed ? register_joystick_button(BTN_RB) : unregister_joystick_button(BTN_RB); return false;
            case JS_L1:   record->event.pressed ? register_joystick_button(BTN_LB) : unregister_joystick_button(BTN_LB); return false;

            case JS_A:   record->event.pressed ? register_joystick_button(BTN_A) : unregister_joystick_button(BTN_A); return false;
            case JS_B:   record->event.pressed ? register_joystick_button(BTN_B) : unregister_joystick_button(BTN_B); return false;
            case JS_R2:   record->event.pressed ? register_joystick_button(BTN_RT) : unregister_joystick_button(BTN_RT); return false;
            case JS_L2:   record->event.pressed ? register_joystick_button(BTN_LT) : unregister_joystick_button(BTN_LT); return false;

            // D-pad (hat switch)
            case JS_UP:
                if (record->event.pressed)
                    dpad_state |= DPAD_UP;
                else
                    dpad_state &= ~DPAD_UP;
                joystick_set_hat(dpad_to_hat(dpad_state));
                return false;

            case JS_RIGHT:
                if (record->event.pressed)
                    dpad_state |= DPAD_RIGHT;
                else
                    dpad_state &= ~DPAD_RIGHT;
                joystick_set_hat(dpad_to_hat(dpad_state));
                return false;

            case JS_DOWN:
                if (record->event.pressed)
                    dpad_state |= DPAD_DOWN;
                else
                    dpad_state &= ~DPAD_DOWN;
                joystick_set_hat(dpad_to_hat(dpad_state));
                return false;

            case JS_LEFT:
                if (record->event.pressed)
                    dpad_state |= DPAD_LEFT;
                else
                    dpad_state &= ~DPAD_LEFT;
                joystick_set_hat(dpad_to_hat(dpad_state));
                return false;


            // Start / Select / Guide
            case JS_START:  record->event.pressed ? register_joystick_button(BTN_START) : unregister_joystick_button(BTN_START); return false;
            case JS_SELECT: record->event.pressed ? register_joystick_button(BTN_BACK) : unregister_joystick_button(BTN_BACK); return false;
            case JS_GUIDE:  record->event.pressed ? register_joystick_button(BTN_GUIDE) : unregister_joystick_button(BTN_GUIDE); return false;
        }
    }

    return true;
}

