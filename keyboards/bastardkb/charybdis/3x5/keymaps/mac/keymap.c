/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

enum charybdis_keymap_layers {
  BASE = 0,
  SYMB = 1,
  SYMB2 = 2,
  MOUSE = 3,
};

void pointing_device_init_user(void) {
  set_auto_mouse_layer(MOUSE);
  set_auto_mouse_enable(true);
}

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();
  switch (keycode) {

  case KC_J:
    {
      // Initialize a boolean variable that keeps track
      // of the key status: registered or not?
      static bool entkey_registered;
      if (record->event.pressed) {
        // Detect the activation of either ctrl keys
        //   for oneshot mods
        if (get_oneshot_mods() & MOD_MASK_GUI) {
          // First temporarily canceling ctrl so that
          //   ctrl isn't applied to the KC_ENT keycode
          del_oneshot_mods(MOD_MASK_GUI);
          register_code(KC_ENT);
          // Update the boolean variable to reflect the status of KC_ENT
          entkey_registered = true;
          // Reapplying modifier state so that the held ctrl key(s)
          // still work even after having tapped the key.
          //register_mods(MOD_MASK_CTRL);
          return false;
        }
        // for general mods
        else if (mod_state & MOD_MASK_GUI) {
          del_mods(MOD_MASK_GUI);
          register_code(KC_ENT);
          entkey_registered = true;
          set_mods(mod_state);
          return false;
        }
      } else { // on release of KC_J
        // In case KC_ENT is still being sent even after the release of KC_J
        if (entkey_registered) {
          unregister_code(KC_ENT);
          entkey_registered = false;
          return false;
        }
      }
      // Let QMK process the KC_J keycode as usual outside of ctrl key
      return true;
    }
  case KC_H:
    {
      static bool bskey_registered;
      if (record->event.pressed) {
        if (get_oneshot_mods() & MOD_MASK_GUI) {
          del_oneshot_mods(MOD_MASK_GUI);
          register_code(KC_BSPC);
          bskey_registered = true;
          //register_mods(MOD_MASK_CTRL);
          return false;
        }
        // for general mods
        else if (mod_state & MOD_MASK_GUI) {
          del_mods(MOD_MASK_GUI);
          register_code(KC_BSPC);
          bskey_registered = true;
          set_mods(mod_state);
          return false;
        }
      } else { // on release of KC_J
        // In case KC_ENT is still being sent even after the release of KC_J
        if (bskey_registered) {
          unregister_code(KC_BSPC);
          bskey_registered = false;
          return false;
        }
      }
      // Let QMK process the KC_J keycode as usual outside of ctrl key
      return true;
    }
  case KC_U:
    {
      static bool entkey_registered;
      if (record->event.pressed) {
        if (get_oneshot_mods() & MOD_MASK_GUI) {
          del_oneshot_mods(MOD_MASK_GUI);
          register_code(KC_ESC);
          entkey_registered = true;
          return false;
        }
        // for general mods
        else if (mod_state & MOD_MASK_GUI) {
          del_mods(MOD_MASK_GUI);
          register_code(KC_ESC);
          entkey_registered = true;
          set_mods(mod_state);
          return false;
        }
      } else { // on release of KC_J
        // In case KC_ENT is still being sent even after the release of KC_J
        if (entkey_registered) {
          unregister_code(KC_ESC);
          entkey_registered = false;
          return false;
        }
      }
      // Let QMK process the KC_J keycode as usual outside of ctrl key
      return true;
    }
  case KC_COMM:
    {
      if (record->event.pressed) {
        if (get_oneshot_mods() & MOD_MASK_GUI) {
          del_oneshot_mods(MOD_MASK_GUI);
          layer_on(MOUSE);
          return false;
        }
        // for general mods
        else if (mod_state & MOD_MASK_GUI) {
          del_mods(MOD_MASK_GUI);
          layer_on(MOUSE);
          set_mods(mod_state);
          return false;
        }
      } // Let QMK process the KC_COMM keycode as usual outside of ctrl key
      return true;
    }

  }
  return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_A,    KC_S, LT(SYMB2,KC_D), KC_F,KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_COLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     SFT_T(KC_Z), KC_X, KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM, LALT_T(KC_DOT), SFT_T(KC_SLSH),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                   LT(SYMB, KC_TAB), OSM(MOD_LGUI),LT(SYMB,KC_SPC),     LT(SYMB,KC_SPC), OSM(MOD_RGUI)
                                      //`--------------------------'  `--------------------------'

  ),

  [SYMB] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_AMPR, KC_ASTR, KC_SCLN, KC_PLUS, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCBR, KC_LBRC, KC_LPRN, KC_DQUO, KC_EQL,                       KC_UNDS, KC_QUOT, KC_RPRN, KC_RBRC, KC_RCBR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,      KC_9,     KC_0,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MINS, KC_CIRC, KC_GRV,    KC_TILD, KC_PIPE
                                      //`--------------------------'  `--------------------------'
  ),

  [SYMB2] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
                               ),

  [MOUSE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_BTN4, KC_BTN1, KC_BTN2, KC_BTN5, TO(BASE),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX,                      KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BTN2,KC_BTN1, KC_WH_U, KC_WH_D,KC_BTN1
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on
