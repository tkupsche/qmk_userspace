/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H


// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define SFT_S LSFT_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define GUI_F LGUI_T(KC_F)


// Right-hand home row mods
#define GUI_J RALT_T(KC_J)
#define ALT_K RALT_T(KC_K)
#define SFT_L RSFT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

#define KC_TIK KC_GRV
#define KC_TLD S(KC_GRV)

// COMBOS

const uint16_t PROGMEM LAYER_1_COMBO[] = {KC_ENT, KC_Y, COMBO_END};
const uint16_t PROGMEM LAYER_2_COMBO[] = {KC_ENT, KC_U, COMBO_END};
const uint16_t PROGMEM LAYER_3_COMBO[] = {KC_ENT, KC_I, COMBO_END};
const uint16_t PROGMEM ESC_COMBO[] =     {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM UNDS_COMBO[] =    {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM EXLM_COMBO[] =    {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM DQUO_COMBO[] =    {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM QUOT_COMBO[] =    {KC_H, KC_N, COMBO_END};

// CAPS_WORD
const uint16_t PROGMEM CAPS_WORD_COMBO[] = {SFT_S, SFT_L, COMBO_END};

// copy, paste, undo, cut
const uint16_t PROGMEM UNDO_COMBO[] =    {CTL_A, KC_Z, COMBO_END};
const uint16_t PROGMEM CUT_COMBO[] =     {SFT_S, KC_X, COMBO_END};
const uint16_t PROGMEM COPY_COMBO[] =    {ALT_D, KC_C, COMBO_END};
const uint16_t PROGMEM PASTE_COMBO[] =   {GUI_F, KC_V, COMBO_END};

// volume up, down, mic mute
const uint16_t PROGMEM VOL_UP_COMBO[] =    {KC_P, CTL_SCLN, COMBO_END};
const uint16_t PROGMEM VOL_DOWN_COMBO[] =  {CTL_SCLN, KC_SLSH, COMBO_END};
const uint16_t PROGMEM VOL_MUTE_COMBO[] =  {KC_P, CTL_SCLN, KC_SLSH, COMBO_END};

// Numberpad ergonomics
const uint16_t PROGMEM NUM_PAD_DEC_COMBO[] = {KC_PMNS, KC_0, COMBO_END};

combo_t key_combos[] = {
    COMBO(LAYER_1_COMBO, TO(1)),
    COMBO(LAYER_2_COMBO, TO(2)),
    COMBO(LAYER_3_COMBO, TO(3)),
	// ESC
    COMBO(ESC_COMBO, KC_ESC),
	// CENTER COMBOS
	COMBO(DQUO_COMBO, KC_DQUO),
	COMBO(QUOT_COMBO, KC_QUOT),
	COMBO(UNDS_COMBO, KC_UNDS),
	COMBO(EXLM_COMBO, KC_EXLM),
    // CAPS_WORD
    COMBO(CAPS_WORD_COMBO, CW_TOGG),
	// COPY, PASTE, ETC
	COMBO(UNDO_COMBO, LCTL(KC_Z)),
	COMBO(CUT_COMBO, LCTL(KC_X)),
	COMBO(COPY_COMBO, LCTL(KC_C)),
	COMBO(PASTE_COMBO, LCTL(KC_V)),

	// Volume up, down, mic mute
	COMBO(VOL_UP_COMBO, KC_VOLU),
    COMBO(VOL_DOWN_COMBO, KC_VOLD),
    COMBO(VOL_MUTE_COMBO, KC_MUTE),
    // Decimal for numpad ergonomics
    COMBO(NUM_PAD_DEC_COMBO, KC_DOT),
};

// TODO:
//
// KC_BSLS - backslack
//
// Home - KC_HOME
// END - KC_END
//
// Macro for "* [ ]" - using combos + macros in keymap.json
//
// Moving more punctuation to combos on first layer?

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,	 CTL_A,	  SFT_S,  ALT_D,    GUI_F,    KC_G,                         KC_H,   GUI_J,   ALT_K,   SFT_L,CTL_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(2),   MO(1),  KC_TAB,   KC_ENT, KC_SPACE, KC_BSPC
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, _______, _______, _______, KC_LPRN, KC_RPRN,                      KC_PAST,    KC_1,    KC_2,   KC_3, KC_PPLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, _______, KC_LCBR, KC_RCBR,                      KC_PSLS,    KC_4,    KC_5,    KC_6, KC_PMNS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, _______, KC_LBRC, KC_RBRC,                     KC_EQUAL,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           _______, TO(0) , _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_DEL, _______,   KC_AT,  KC_HASH, KC_DLR,                       KC_TIK, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, _______, KC_AMPR, KC_PIPE,                       KC_TLD, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, _______, KC_PERC, KC_CIRC,                      KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, TO(0), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, QK_BOOT, XXXXXXX, XXXXXXX, RGB_MOD, RGB_RMOD,                     RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_TOG, XXXXXXX, XXXXXXX, RGB_HUI, RGB_HUD,                      RGB_SPI, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAI, RGB_SAD,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, TO(0), XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};
