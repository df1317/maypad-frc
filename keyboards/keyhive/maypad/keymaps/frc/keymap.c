#include QMK_KEYBOARD_H

// Custom keycodes — one per key, mapped to joystick buttons 0-19.
// WPILib getRawButton() is 1-based, so button 0 here = getRawButton(1).
enum custom_keycodes {
    BTN_0 = SAFE_RANGE,
    BTN_1,  BTN_2,  BTN_3,  BTN_4,
    BTN_5,  BTN_6,  BTN_7,  BTN_8,
    BTN_9,  BTN_10, BTN_11, BTN_12,
    BTN_13, BTN_14, BTN_15, BTN_16,
    BTN_17, BTN_18, BTN_19,
};

// Physical layout (row 0 = top):
//
//   Row 0:  [ 1] [ 2] [ 3] [ 4]
//   Row 1:  [ 5] [ 6] [ 7] [ 8]
//   Row 2:  [ 9] [10] [11] [12]
//   Row 3:  [13] [14] [15] [16]
//   Row 4:  [17] [18] [19] [20]

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x4(
        BTN_0,  BTN_1,  BTN_2,  BTN_3,
        BTN_4,  BTN_5,  BTN_6,  BTN_7,
        BTN_8,  BTN_9,  BTN_10, BTN_11,
        BTN_12, BTN_13, BTN_14, BTN_15,
        BTN_16, BTN_17, BTN_18, BTN_19
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode >= BTN_0 && keycode <= BTN_19) {
        uint8_t button = keycode - BTN_0;
        if (record->event.pressed) {
            register_joystick_button(button);
        } else {
            unregister_joystick_button(button);
        }
        return false;
    }
    return true;
}
