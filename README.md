# maypad-frc

QMK firmware for the [Keyhive Maypad](https://keyhive.xyz/shop/may-pad) configured as an FRC operator panel.

The pad enumerates as a **USB HID joystick** (no keyboard interface). The FRC Driver Station picks it up automatically — no drivers or software required on the DS laptop.

## Button layout

```
Row 0:  [ 1] [ 2] [ 3] [ 4]
Row 1:  [ 5] [ 6] [ 7] [ 8]
Row 2:  [ 9] [10] [11] [12]
Row 3:  [13] [14] [15] [16]
Row 4:  [17] [18] [19] [20]
```

Numbers match `getRawButton()` in WPILib (1-based). All 20 keys are available.

## WPILib usage

```java
CommandJoystick panel = new CommandJoystick(2); // whatever DS port it lands on

panel.button(1).onTrue(new IntakeCommand());
panel.button(2).onTrue(new ShootCommand());
// etc.
```

Or subclass `GenericHID` for named accessors:

```java
public class OperatorPanel extends GenericHID {
    public OperatorPanel(int port) { super(port); }

    public Trigger intake()   { return new JoystickButton(this, 1); }
    public Trigger shoot()    { return new JoystickButton(this, 2); }
    public Trigger climbUp()  { return new JoystickButton(this, 5); }
    public Trigger climbDown(){ return new JoystickButton(this, 6); }
}
```

## Setup and build

### 1. Install QMK

```bash
brew install qmk/qmk/qmk
qmk setup
```

### 2. Register this userspace

```bash
qmk config user.overlay_dir="$(pwd)"
```

### 3. Build

```bash
qmk compile -kb keyhive/maypad -km frc
# or
qmk userspace-compile
```

This produces `keyhive_maypad_frc.hex`.

### 4. Flash

Put the Maypad into bootloader mode (press the reset button on the Pro Micro, or short RST to GND twice quickly), then:

```bash
qmk flash -kb keyhive/maypad -km frc
```

Or use [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) and load the `.hex` file manually.

## Hardware

- MCU: ATmega32u4 (Pro Micro)
- Matrix: 5 rows × 4 cols, COL2ROW diodes
- Col pins: F6, F7, B1, B3
- Row pins: C6, D7, E6, B4, B5
