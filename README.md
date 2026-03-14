# Maypad

> [!NOTE]
> QMK firmware for the [Keyhive Maypad](https://keyhive.xyz/shop/may-pad) as an FRC operator panel.

## What's this?

This is the QMK firmware for 1317's Keyhive Maypad. It enumerates as a **USB HID joystick** — no keyboard interface, no drivers, no software needed on the DS laptop. Plug it in and it shows up in the FRC Driver Station joystick tab.

## Button Layout

```
Row 0:  [ 1] [ 2] [ 3] [ 4]
Row 1:  [ 5] [ 6] [ 7] [ 8]
Row 2:  [ 9] [10] [11] [12]
Row 3:  [13] [14] [15] [16]
Row 4:  [17] [18] [19] [20]
```

Numbers match `getRawButton()` in WPILib (1-based). All 20 keys are available.

## WPILib Usage

Subclass `GenericHID` and give each button a name:

```java
public class OperatorPanel extends GenericHID {
    public OperatorPanel(int port) { super(port); }

    public Trigger intake()    { return new JoystickButton(this, 1); }
    public Trigger shoot()     { return new JoystickButton(this, 2); }
    public Trigger climbUp()   { return new JoystickButton(this, 5); }
    public Trigger climbDown() { return new JoystickButton(this, 6); }
}
```

Then in `RobotContainer`:

```java
private final OperatorPanel panel = new OperatorPanel(2); // DS port

panel.intake().whileTrue(intake.intakeCommand());
panel.shoot().onTrue(shooter.shootCommand());
```

## Build

### Setup

> [!WARNING]
> You need the QMK toolchain before building. Run these once.

```bash
brew install qmk/qmk/qmk
qmk setup
qmk config user.overlay_dir="$(pwd)"
```

### Compile

```bash
qmk compile -kb keyhive/maypad -km frc
```

This produces `keyhive_maypad_frc.hex`.

### Flash

Put the Maypad into bootloader mode (double-tap the reset button on the Pro Micro), then:

```bash
qmk flash -kb keyhive/maypad -km frc
```

Or use [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) and load the `.hex` manually.

CI also builds the `.hex` on every push — grab it from the **Actions** tab as a build artifact.

## Hardware

| Property   | Value                    |
| ---------- | ------------------------ |
| MCU        | ATmega32u4 (Pro Micro)   |
| Matrix     | 5 rows × 4 cols, COL2ROW |
| Col pins   | F6, F7, B1, B3           |
| Row pins   | C6, D7, E6, B4, B5       |
| Bootloader | Caterina                 |

<p align="center">
	<img src="https://raw.githubusercontent.com/taciturnaxolotl/carriage/main/.github/images/line-break.svg" />
</p>

<p align="center">
	<code>&copy 2026-present <a href="https://github.com/df1317">Digital Fusion FRC team 1317</a></code>
</p>

<p align="center">
	<a href="https://github.com/df1317/maypad-frc/blob/main/LICENSE.md"><img src="https://img.shields.io/static/v1.svg?style=for-the-badge&label=License&message=MIT&logoColor=d9e0ee&colorA=363a4f&colorB=b7bdf8"/></a>
</p>
