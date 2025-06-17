# fifi-chocofi-config

This is a custom QMK layout using a split 3x6_3 layout with Mod-Tap functionality on the home row and custom tap dance logic.

---

## Layer 0: Base (Mod-Tap Home Row)

```text
,-----------------------------------------------------.                    ,-----------------------
|       |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   ;  |       |
|-------+------+------+------+------+------|           |------+------+------+------+------+-------|
|       | A/GUI| R/ALT| S/CTL| T/SFT|   G  |           |   M  | N/SFT| E/ALT| I/CTL| O/GUI|       |
|-------+------+------+------+------+------|           |------+------+------+------+------+-------|
|       |   Z  |   X  |   C  |   D  |   V  |           |   N  |   M  |   ,  |   .  |   /  |       |
`----------------------------+------+------'           `------+----------------------------+------'
                             |      |Enter |  [Fn1] |  [Fn2] |Space |      |
                             `---------------------'         `---------------------'
```

## Layer 1: Number & Symbols

```text
,-----------------------------------------------------.                    ,-----------------------
|       |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |       |
|-------+------+------+------+------+------|           |------+------+------+------+------+-------|
|       |       |   4  |   5  |   6  |      |           |  -   |  =   |  '   |  [   |  ]   |      |
|-------+------+------+------+------+------|           |------+------+------+------+------+-------|
|       |       |   1  |   2  |   3  |      |           |  `   |  +   |  ;   |  _   |  \   |      |
`----------------------------+------+------'           `------+----------------------------+------'
                             |      |      |           | Esc  | BSPC |      |
                             `---------------------'         `---------------------'
```

## Layer 2: Numpad & Navigation

```text
,-----------------------------------------------------.                    ,-----------------------
|       |      | KP_7 | KP_8 | KP_9 | KP_0 |           |      |      |      |      |      |       |
|-------+------+------+------+------+------|           |------+------+------+------+------+-------|
|       |      | KP_4 | KP_5 | KP_6 |      |           |Left  |Down  | Up   |Right |      |       |
|-------+------+------+------+------+------|           |------+------+------+------+------+-------|
|       |      | KP_1 | KP_2 | KP_3 |      |           |      |      |      |      |      |       |
`----------------------------+------+------'           `------+----------------------------+------'
                             |      | Tab  |           |      |      |      |
                             `---------------------'         `---------------------'
```

## Encoder Map

Encoder 0: Volume Down / Up  
Encoder 1: Previous / Next Track  
Encoder 2: RM_VALD / RM_VALU (custom)  
Encoder 3: Right / Left Arrow

Layers: Same behavior across layers 0–3

## Mod-Tap Home Row (Tap Dance Logic)

| Key | Tap | Hold  |
| --- | --- | ----- |
| A   | A   | GUI   |
| R   | R   | ALT   |
| S   | S   | CTRL  |
| T   | T   | SHIFT |
| N   | N   | SHIFT |
| E   | E   | ALT   |
| I   | I   | CTRL  |
| O   | O   | GUI   |

Tap dance is implemented manually in keymap.c, using a tap_dance_tap_hold_t structure and handler functions.

## Compile & Flash

Use QMK CLI or QMK Toolbox:

```bash
qmk compile -kb <your_keyboard> -km <your_keymap>
qmk flash -kb <your_keyboard> -km <your_keymap>
```
