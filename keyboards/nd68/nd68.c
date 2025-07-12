/* Copyright 2025 Nate Aquino
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

 #include "quantum.h"

void keyboard_post_init_kb(void) {
    // Initialize the encoder button GPIO pin
    gpio_set_pin_input_high(ENCODERS_BUTTON_GPIO);

    // set led effect
    rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
}

 void matrix_scan_kb(void) {
    static bool mute_btn_prev = false;
    bool mute_btn_pressed = !gpio_read_pin(ENCODERS_BUTTON_GPIO); // Active low
    bool fn_act = layer_state_is(1);

    if (mute_btn_pressed && !mute_btn_prev) {
        if (!fn_act)
            tap_code(KC_MUTE);
        else
            rgb_matrix_step_noeeprom();
    }

    mute_btn_prev = mute_btn_pressed;
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise))
      return false; // user overwrote callback
    // if fn is held, change led brightness
    bool fn_act = layer_state_is(1);

    if (clockwise) {
        if (!fn_act)
            tap_code(KC_VOLU);
        else
            rgb_matrix_increase_val_noeeprom();
    }
    else {
        if (!fn_act)
            tap_code(KC_VOLD);
        else
            rgb_matrix_decrease_val_noeeprom();
    }

    return true;
}

bool rgb_matrix_indicators_kb() {
    rgb_matrix_indicators_user();

    if (host_keyboard_led_state().caps_lock)
        rgb_matrix_set_color(CAPS_LOCK_IDX, 255, 255, 255);

    return true;
}

led_config_t g_led_config = {{
    // Key matrix to led index
    { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14},
    {15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
    {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, NO_LED},
    {44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, NO_LED},
    {58, 59, 60, 62, 64, 65, 66, 67, 68, 69, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}
}, {
    // led index to physical position
    {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {15, 0},
    {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}, {8, 1}, {9, 1}, {10, 1}, {11, 1}, {12, 1}, {13, 1}, {15, 1},
    {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2}, {8, 2}, {9, 2}, {10, 2}, {11, 2}, {12, 2}, {15, 2},
    {0, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}, {7, 3}, {8, 3}, {9, 3}, {10, 3}, {11, 3}, {12, 3}, {14, 3}, {15, 3},
    {0, 4}, {1, 4}, {2, 4}, {4, 4}, {7, 4}, {10, 4}, {10, 4}, {11, 4}, {12, 4}, {13, 4}, {14, 4}, {15, 4}
}, {
    // flags
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
}};
