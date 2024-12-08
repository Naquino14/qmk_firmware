#include "quantum.h"
#include "rgb_matrix/rgb_matrix.h"

led_config_t g_led_config = {{
    // Key matrix to led index
    {0, 1},
    {2, 3}
}, {
    // led index to physical position, not sure what units
    {0, 0}, {0, 15}, {15, 0}, {15, 15}
}, {
    // flags
    4, 4,
    4, 4
}};

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(255 * 0.33, 255 * 0.43, 255 * 0.73); // sets the color to teal/cyan without saving
  //rgblight_mode_noeeprom(RGB_MATRIX_RAINBOW_BEACON); // sets mode to Fast breathing without saving
}
