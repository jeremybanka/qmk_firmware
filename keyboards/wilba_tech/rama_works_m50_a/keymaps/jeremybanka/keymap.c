/* Copyright 2020 Jason Williams (Wilba)
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
#include QMK_KEYBOARD_H

#include "muse.h"

enum m50_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER TG(_LOWER)
#define RAISE TG(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |  F11 |  F12 |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |CmdA  |AltS  |SftD  |CmdF  |   G  | Mute |  F13 |   H  |   J  |SftK  |   L  |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |CtlZ  |SftX  |AltC  |CtlV  |   B  | Vol- | Vol+ |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   `  |Lower |Raise | Esc  |LTLSpc|   LTR Tab   | Enter| Bksp | Brt- | Brt+ |   ;  |
 * `------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
    RGB_TOG,    KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,                   _______,   _______,  KC_Y,     KC_U,     KC_I,              KC_O,       KC_P,
    _______,    MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LSFT, KC_D),MT(MOD_RGUI, KC_F),KC_G,               _______,   _______,  KC_H,     KC_J,     MT(MOD_RSFT, KC_K),KC_L,       KC_QUOT,
    _______,    MT(MOD_LCTL, KC_Z),MT(MOD_LSFT, KC_X),MT(MOD_RCTL, KC_C),MT(MOD_RALT, KC_V),KC_B,               _______,   _______,  KC_N,     KC_M,     KC_COMM,           KC_DOT,     KC_SLSH,
    _______,    KC_GRV,            LOWER,             RAISE,             KC_ESC,            LT(_LOWER, KC_SPC), LT(_RAISE, KC_TAB),  KC_ENT,   KC_BSPC,  KC_BRMD,           KC_BRMU,    KC_SCLN
),

/* Lower
 * ,------------------------------------------------------------------------------------------.
 * |      | Left |  Up  | Down | Rigt | Bksp | Prev | Next |  F1  |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Cmd[ | Alt] | Sft; | Cmd` |   '  |      | Play |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctl, | Sft. | Ctl/ | Alt\ |NmEntr|      |      |  F11 |  F12 |  F13 |  F14 |  F15 |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |  F16 |  F17 |  F18 |  F19 |  F20 |
 * `------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
    _______,    KC_LEFT,              KC_UP,                KC_DOWN,              KC_RIGHT,             KC_BSPC,     _______,   _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,
    _______,    MT(MOD_LGUI, KC_LBRC),MT(MOD_LALT, KC_RBRC),MT(MOD_LSFT, KC_SCLN),MT(MOD_RGUI, KC_GRV), KC_QUOT,     _______,   _______,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,
    _______,    MT(MOD_LCTL, KC_COMM),MT(MOD_LSFT, KC_DOT), MT(MOD_RCTL, KC_SLSH),MT(MOD_RALT, KC_BSLS),KC_KP_ENTER, _______,   _______,  KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,
    _______,    _______,              _______,              _______,              _______,              _______,     _______,             KC_F16, KC_F17, KC_F18, KC_F19, KC_F20
),

/* Raise
 * ,------------------------------------------------------------------------------------------.
 * |      |   4  |   5  |   6  |   -  |   =  |      |      | Nmlk |  Ins |  Del | SysRq| Scrlk|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Cmd1 | Alt2 | Sft3 | Cmd0 |  Tab |      |      | Left | Down |  Up  | Rigt | Space|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctl7 | Sft8 | Ctl9 | Alt, |   .  |      |      | Home | PgDn | PgUp | End  |  Tab |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   /  |      |      |      |      |             |NmEntr|      |      |      |      |
 * `------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
    _______,    KC_4,              KC_5,              KC_6,              KC_MINS,              KC_EQL,  _______, _______,  KC_NLCK,     KC_INS,   KC_DEL,  KC_PSCR,  KC_SLCK,
    _______,    MT(MOD_LGUI, KC_1),MT(MOD_LALT, KC_2),MT(MOD_LSFT, KC_3),MT(MOD_RGUI, KC_0),   KC_SPC,  _______, _______,  KC_LEFT,     KC_DOWN,  KC_UP,   KC_RIGHT, KC_SPC,
    _______,    MT(MOD_LCTL, KC_7),MT(MOD_LSFT, KC_8),MT(MOD_RCTL, KC_9),MT(MOD_RALT, KC_COMM),KC_DOT,  _______, _______,  KC_HOME,     KC_PGDN,  KC_PGUP, KC_END,   KC_TAB,
    _______,    _______,           _______,           _______,           _______,              _______, _______,           KC_KP_ENTER, _______,  _______, _______,  _______
),

/* Adjust (Lower + Raise)
 * ,------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      `|      |             |      |      |      |      |      |
 * `------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
)

};
