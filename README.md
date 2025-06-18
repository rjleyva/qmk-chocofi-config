# fifi-chocofi-config

This is a custom QMK layout using a split 3x6_3 layout with Mod-Tap functionality on the home row and custom tap dance logic.

## Credits

This configuration is built on top of [QMK Firmware](https://qmk.fm/), an open-source keyboard firmware project.

- Originally based on the work of **Jun Wako** (creator of TMK Keyboard Firmware) – © 2012 <wakojun@gmail.com>
- Further developed and maintained by Jack Humbert (creator of QMK Firmware) – © 2015

> IMPORTANT: This project does not aim to replace or rebrand QMK. It leverages QMK’s existing functionality to implement personal customizations suited to my workflow.

This configuration follows the [GNU General Public License v2.0 or later](https://www.gnu.org/licenses/old-licenses/gpl-2.0.html), as used by QMK.

> NOTE: The GPL link may initially show a 404 error before the page fully loads. Please try refreshing the page - it typically resolves quickly once the full content is fetched.

---

## Mod-Tap Home Row (Tap Dance Logic)

| Key | Tap | Hold  |
| --- | --- | ----- |
| A   | a   | GUI   |
| R   | r   | ALT   |
| S   | s   | CTRL  |
| T   | t   | SHIFT |
| N   | n   | SHIFT |
| E   | e   | ALT   |
| I   | i   | CTRL  |
| O   | o   | GUI   |

Tap dance is implemented manually in keymap.c, using a tap_dance_tap_hold_t structure and handler functions.

## Layer 0: Base (Mod-Tap Home Row)

```text
,------------------------------------------.                  ,-------------------------------------------
|       |   Q  |   W  |   F  |   P  |   B  |                  |   J  |   L  |   U  |   Y  |   ;  |       |
|-------+------+------+------+------+------|                  |------+------+------+------+------+-------|
|       | A/GUI| R/ALT| S/CTL| T/SFT|   G  |                  |   M  | N/SFT| E/ALT| I/CTL| O/GUI|       |
|-------+------+------+------+------+------|                  |------+------+------+------+------+-------|
|       |   Z  |   X  |   C  |   D  |   V  |                  |   N  |   M  |   ,  |   .  |   /  |       |
`----------------------------+------+------'                  `------+----------------------------+------'
                             |      |Enter |  [Fn1] |  [Fn2] |Space |      |
                             `---------------------'   `--------------------'
```

## Layer 1: Number & Symbols

```text
,------------------------------------------.                 ,-------------------------------------------
|       |   1  |   2  |   3  |   4  |   5  |                 |   6  |   7  |   8  |   9  |   0  |       |
|-------+------+------+------+------+------|                 |------+------+------+------+------+-------|
|       |       |   4  |   5  |   6  |     |                 |  -   |  =   |  '   |  [   |  ]   |       |
|-------+------+------+------+------+------|                 |------+------+------+------+------+-------|
|       |       |   1  |   2  |   3  |     |                 |  `   |  +   |  ;   |  _   |  \   |       |
`----------------------------+------+------'                 `------+----------------------------+------'
                             |      |      |           | Esc  | BSPC |      |
                             `---------------------'   `---------------------'
```

## Layer 2: Numpad & Navigation

```text
,------------------------------------------.                  ,-------------------------------------------
|       |      | KP_7 | KP_8 | KP_9 | KP_0 |                  |      |      |      |      |      |       |
|-------+------+------+------+------+------|                  |------+------+------+------+------+-------|
|       |      | KP_4 | KP_5 | KP_6 |      |                  |      | Left | Down   |Up | Right |       |
|-------+------+------+------+------+------|                  |------+------+------+------+------+-------|
|       |      | KP_1 | KP_2 | KP_3 |      |                  |      |      |      |      |      |       |
`----------------------------+------+------'                  `------+----------------------------+------'
                             |      | Tab  |           |      |      |      |
                             `---------------------'   `---------------------'
```
