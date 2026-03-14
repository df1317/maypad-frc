#include QMK_KEYBOARD_H

// FRC operator panel keymap for the Keyhive Maypad (ortho 5x4 = 20 keys).
//
// Every key maps to a joystick button. WPILib getRawButton() is 1-based,
// so JS_BUTTON0 corresponds to getRawButton(1).
//
// Physical layout (row 0 = top):
//
//   Row 0:  [ 1] [ 2] [ 3] [ 4]
//   Row 1:  [ 5] [ 6] [ 7] [ 8]
//   Row 2:  [ 9] [10] [11] [12]
//   Row 3:  [13] [14] [15] [16]
//   Row 4:  [17] [18] [19] [20]
//
// WPILib usage example (port 2, for instance):
//
//   CommandJoystick panel = new CommandJoystick(2);
//   panel.button(1).onTrue(new IntakeCommand());
//   panel.button(5).onTrue(new ShootCommand());
//   // etc.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x4(
        JS_BUTTON0,  JS_BUTTON1,  JS_BUTTON2,  JS_BUTTON3,
        JS_BUTTON4,  JS_BUTTON5,  JS_BUTTON6,  JS_BUTTON7,
        JS_BUTTON8,  JS_BUTTON9,  JS_BUTTON10, JS_BUTTON11,
        JS_BUTTON12, JS_BUTTON13, JS_BUTTON14, JS_BUTTON15,
        JS_BUTTON16, JS_BUTTON17, JS_BUTTON18, JS_BUTTON19
    ),
};
