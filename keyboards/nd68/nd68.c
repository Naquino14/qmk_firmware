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
}

 void matrix_scan_kb(void) {
    static bool mute_btn_prev = false;
    bool mute_btn_pressed = !gpio_read_pin(ENCODERS_BUTTON_GPIO); // Active low
    bool fn_act = layer_state_is(1);

    if (mute_btn_pressed && !mute_btn_prev) {
        if (!fn_act)
            tap_code(KC_MUTE);
        else
            rgb_matrix_step();
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
            rgb_matrix_increase_val();
    }
    else {
        if (!fn_act)
            tap_code(KC_VOLD);
        else
            rgb_matrix_decrease_val();
    }

    return true;
}

bool rgb_matrix_indicators_kb() {
    rgb_matrix_indicators_user();

    if (host_keyboard_led_state().caps_lock)
        rgb_matrix_set_color(CAPS_LOCK_IDX, 255, 255, 255);

    // check if _FIGHT layer is active to light right alt
    if (layer_state_is(FIGHT_LAYER))
        rgb_matrix_set_color(RIGHT_ALT_IDX, 255, 0, 0);

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
    {  0,  0}, { 16,  0}, { 32,  0}, { 48,  0}, { 64,  0}, { 80,  0}, { 96,  0}, {112,  0}, {128,  0}, {144,  0}, {160,  0}, {176,  0}, {192,  0}, {208,  0}, {224,  0},
    {  0, 16}, { 16, 16}, { 32, 16}, { 48, 16}, { 64, 16}, { 80, 16}, { 96, 16}, {112, 16}, {128, 16}, {144, 16}, {160, 16}, {176, 16}, {192, 16}, {208, 16}, {224, 16},
    {  0, 32}, { 16, 32}, { 32, 32}, { 48, 32}, { 64, 32}, { 80, 32}, { 96, 32}, {112, 32}, {128, 32}, {144, 32}, {160, 32}, {176, 32}, {192, 32}, {208, 32},
    {  0, 48}, { 32, 48}, { 48, 48}, { 64, 48}, { 80, 48}, { 96, 48}, {112, 48}, {128, 48}, {144, 48}, {160, 48}, {176, 48}, {192, 48}, {208, 48}, {224, 48},
    {  0, 64}, { 16, 64}, { 32, 64}, { 64, 64}, { 94, 64}, {112, 64}, {130, 64}, {160, 64}, {176, 64}, {192, 64}, {208, 64}, {224, 64}
}, {
    // flags
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
}};
