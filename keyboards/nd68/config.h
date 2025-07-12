#define ENCODER_A_PINS { GP23 }
#define ENCODER_B_PINS { GP22 }
#define ENCODER_RESOLUTION 4
#define ENCODERS_BUTTON_GPIO GP24

// Led Matrix Defs
#define WS2812_DI_PIN GP21
#define RGB_MATRIX_LED_COUNT 70 // 68 keys + 2 more for spacebar
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 190 // rev 1 missing decouplers, this is a safety net

// RGB effects
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
