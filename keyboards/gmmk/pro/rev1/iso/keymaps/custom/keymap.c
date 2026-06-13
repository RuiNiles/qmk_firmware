#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, C(KC_C), C(KC_V), KC_PSCR, KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,
        KC_TRNS, C(KC_Z), KC_LCTL, KC_TRNS, KC_LSFT, C(KC_F), KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [2] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}
};
#endif

static const HSV RED = {HSV_RED};

#if defined(RGB_MATRIX_ENABLE)
typedef struct {
    uint16_t keycode;
    HSV color;
} key_color_t;

static const key_color_t key_colors[] = {
    {KC_HOME,  {HSV_YELLOW}},
    {KC_END,  {HSV_YELLOW}},
    {C(KC_C),  {HSV_GREEN}},
    {C(KC_V),  {HSV_GREEN}},
    {KC_CAPS,  {HSV_PINK}},
    {KC_LGUI,  {HSV_CYAN}},
    {KC_PSCR,  {HSV_BLUE}},
    {C(KC_Z),  {HSV_CORAL}},
    {KC_LCTL,  {HSV_PURPLE}},
    {KC_LCTL,  {HSV_PURPLE}},
    {KC_LSFT,  {HSV_PURPLE}},
    {C(KC_F),  {HSV_GOLD}},
};

static HSV get_key_color(uint16_t keycode) {
    for (uint8_t i = 0; i < ARRAY_SIZE(key_colors); i++) {
        if (key_colors[i].keycode == keycode) {
            return key_colors[i].color;
        }
    }

    return (HSV){HSV_RED}; // default
}

// clang-format on
bool rgb_matrix_indicators_user(void) {
    uint8_t brightness = rgb_matrix_get_val();
    uint8_t layer      = get_highest_layer(layer_state);
    rgb_matrix_set_color_all(brightness, brightness, brightness);

    switch (layer) {
        case 1:
        case 2:
            for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
                for (uint8_t col = 0; col < MATRIX_COLS; col++) {
                    uint16_t keycode = keymaps[layer][row][col];

                    if (keycode != KC_TRNS) {
                        uint8_t index = g_led_config.matrix_co[row][col];

                        if (index != NO_LED) {
                            HSV color_hsv = get_key_color(keycode);
                            color_hsv.v   = brightness;
                            RGB color_rgb = hsv_to_rgb(color_hsv);

                            rgb_matrix_set_color(index, color_rgb.r, color_rgb.g, color_rgb.b);
                        }
                    }
                }
            }
    }

    return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}
#endif