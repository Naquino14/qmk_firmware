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

    if (mute_btn_pressed && !mute_btn_prev)
        tap_code(KC_MUTE);

    mute_btn_prev = mute_btn_pressed;
}
