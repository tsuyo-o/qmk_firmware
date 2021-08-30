/* Copyright 2020
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

extern keymap_config_t keymap_config;

#define BASE 0
#define SYMB 1
#define SYMB2 2
#define MOUSE 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum my_keycodes {
      TD_ESC_TO_S,
      TD_ESC_TO_B,
      TD_OSL_TO_S,
      TD_OSL_TO_B,
      KC_FNX = SAFE_RANGE,
      KC_FNY
};

enum combos {
             /*
  JK_ESC
             */
  JK_MOUSE
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_TO_S] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, SYMB),
  [TD_ESC_TO_B] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, BASE),
  [TD_OSL_TO_S] = ACTION_TAP_DANCE_DUAL_ROLE(OSL(SYMB), SYMB),
  [TD_OSL_TO_B] = ACTION_TAP_DANCE_DUAL_ROLE(OSL(BASE), BASE)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD(TD_ESC_TO_S):
      return 130;
    case TD(TD_ESC_TO_B):
      return 130;
    case JK_MOUSE:
      return 130;
    case SFT_T(KC_Z):
      return 300;
    case SFT_T(KC_SLSH):
      return 300;
    default:
      return TAPPING_TERM;
  }
}

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  /*  [JK_ESC] = COMBO(jk_combo, KC_ESC) */
  [JK_MOUSE] = COMBO_ACTION(jk_combo)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  WIN |   | WIN  |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Ent  |   A  |   S  |   D  |   F  |   G  |  BS  |   |  BS  |   H  |   J  |   K  |   L  |   :  |  Ent |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |   Z  |   X  |   C  |   V  |   B  |  ESC |   |  ESC |   N  |   M  |   ,  |   .  |   /  |  Sft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | MOUS |  Alt | ESC  |ESC   | SYMB |SPACE/|   |SPACE/| SYMB | ESC  | Ent  | PRT  | UP   | DOWN |
   * |      |      |      |      |      |      |Ctrl  |   |CTRL  |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   [BASE] = LAYOUT( \
    KC_BSPC,   KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,                           KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_MINS, \
    KC_TAB,   KC_A,    KC_S,   KC_D,    KC_F,   KC_G,  OSL(SYMB),       OSL(SYMB),  KC_H,     KC_J,    KC_K,     KC_L,     KC_COLN,  KC_ENT, \
    OSM(MOD_LSFT),  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,                     KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, OSM(MOD_RSFT), \
    TO(MOUSE), KC_LCTRL, KC_ESC, TD(TD_ESC_TO_S), OSM(MOD_RCTL), RCTL_T(KC_SPC), OSL(SYMB), OSL(SYMB), RCTL_T(KC_SPC),  OSM(MOD_RCTL), TD(TD_ESC_TO_S), RCTL(KC_TAB), KC_UP, KC_DOWN \
  ),
   */
                                                              /*                                                              
  [BASE] = LAYOUT( \
    KC_BSPC,   KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,                           KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_MINS, \
    SFT_T(KC_TAB),   KC_A,    KC_S,   KC_D,    KC_F,   KC_G,  OSL(SYMB),       OSL(SYMB),  KC_H,     KC_J,    KC_K,     KC_L,     KC_COLN,  SFT_T(KC_ENT), \
    OSL(SYMB),  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,                     KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, OSL(SYMB), \
    TO(MOUSE), KC_LCTRL, KC_ESC, TD(TD_ESC_TO_S), OSM(MOD_RCTL), RCTL_T(KC_SPC), OSL(SYMB), OSL(SYMB), RCTL_T(KC_SPC),  OSM(MOD_RCTL), TD(TD_ESC_TO_S), RCTL(KC_TAB), KC_UP, KC_DOWN \
  ),
                                                              */
                                                              /*                                                              
  [BASE] = LAYOUT( \
    KC_BSPC,  KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,                           KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_MINS, \
    KC_TAB,   KC_A,    KC_S,   KC_D,    KC_F,   KC_G,  XXXXXXX,      XXXXXXX,  KC_H,     KC_J,    KC_K,     KC_L,     KC_COLN,  KC_ENT, \
    KC_BSPC,  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,                     KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_BSPC, \
    TO(MOUSE), KC_LCTRL, KC_ESC, KC_ESC, KC_FNY, LT(SYMB,KC_SPC), OSL(SYMB), OSL(SYMB), LT(SYMB,KC_SPC),  KC_FNY, TD(TD_ESC_TO_S), RCTL(KC_TAB), KC_UP, KC_DOWN \
  ),
                                                              */
  [BASE] = LAYOUT( \
    XXXXXXX, KC_Q,        KC_W,    KC_E,           KC_R,          KC_T,                                                      KC_Y,          KC_U,   KC_I,    KC_O,    KC_P,              XXXXXXX, \
    XXXXXXX, KC_A,        KC_S,    LT(SYMB2,KC_D), KC_F,          KC_G,  XXXXXXX,                           XXXXXXX,         KC_H,          KC_J,   KC_K,    KC_L,    KC_COLN,           XXXXXXX, \
    XXXXXXX, SFT_T(KC_Z), KC_X,    KC_C,           KC_V,          KC_B,                                                      KC_N,          KC_M,   KC_COMM, KC_DOT,  SFT_T(KC_SLSH),    XXXXXXX, \
    XXXXXXX, XXXXXXX,     XXXXXXX, SFT_T(KC_TAB),  OSM(MOD_LCTL), LT(SYMB,KC_SPC), XXXXXXX,        XXXXXXX, LT(SYMB,KC_SPC), OSM(MOD_RCTL), SFT_T(KC_ESC),   XXXXXXX, XXXXXXX,          XXXXXXX \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |      |   |      |   &  |   *  |   ;  |   +  |   \  |  ~   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |   <  |   {  |   [  |   (  |   "  |   =  |  BS  |   |  BS  |   _  |  '   |   )  |  ]   |   }  |  >   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |  1   |  1   |   2  |   3  |   4  |   5  |  6   |   |  7   |   8  |   9  |   0  |   ?  |  ^   |  ^   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | WIN  |  Alt |   @  |  ESC |   |  |  #   |   |  *   |   -  |  ESC |   ;  | PRT  | LEFT | RGHT |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
      XXXXXXX, KC_EXLM,    KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,                    KC_AMPR, KC_ASTR, KC_SCLN,   KC_PLUS,  KC_BSLS,  XXXXXXX, \
      XXXXXXX, KC_LCBR,    KC_LBRC, KC_LPRN,  KC_DQUO,  KC_EQL,   XXXXXXX, XXXXXXX, KC_UNDS, KC_QUOT, KC_RPRN,   KC_RBRC,  KC_RCBR,  XXXXXXX, \
      XXXXXXX, KC_1,       KC_2,    KC_3,     KC_4,     KC_5,                       KC_6,    KC_7,    KC_8,      KC_9,     KC_0,     XXXXXXX, \
      XXXXXXX, XXXXXXX,    XXXXXXX, KC_BSPC,  KC_CIRC,  KC_MINS,  XXXXXXX, XXXXXXX, KC_PIPE, KC_TILD, KC_GRV,    XXXXXXX,  XXXXXXX,  XXXXXXX \
  ),

  [SYMB2] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,                             KC_TAB, KC_MINS, KC_PIPE, KC_MINS, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  ),


  /* mouse
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |   |  ]   |   Y  |   U  |   I  |   O  |   P  |  @   |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  :   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |   Z  |   X  |   C  |   V  |   B  |  {   |   |  }   |   N  |   M  |   ,  |   .  |   /  |\/Sft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc | ESC  |Space |Tab   |   |Back  |Enter | Del  |PrtSc |=>GAME|=>SYMB|  \   |
   * |      |      |      |      |      |      |      |   |Space |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [MOUSE] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, TO(BASE), XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX,                   KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RCTL(KC_V), XXXXXXX, XXXXXXX, RCTL(KC_C), KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX \
  )

};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    static uint16_t fnx_layer_timer;
//
//    switch (keycode){
//        case KC_FNX:
//            if(record->event.pressed){
//                fnx_layer_timer = timer_read();
//                layer_on(SYMB);
//            } else {
//                layer_off(SYMB);
//                if (timer_elapsed(fnx_layer_timer) < 150) {
//                    set_oneshot_mods(MOD_LALT);
//                }
//            }
//            return false;
//       case KC_FNY:
//            if(record->event.pressed){
//                fnx_layer_timer = timer_read();
//                register_code(KC_LSFT);
//            } else {
//                unregister_code(KC_LSFT);
//                if (timer_elapsed(fnx_layer_timer) < 150) {
//                    set_oneshot_mods(MOD_LALT);
//                }
//            }
//            return false;
//    }
//    return true;
//}

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
        if (get_oneshot_mods() & MOD_MASK_CTRL) {
          // First temporarily canceling ctrl so that
          //   ctrl isn't applied to the KC_ENT keycode
          del_oneshot_mods(MOD_MASK_CTRL);
          register_code(KC_ENT);
          // Update the boolean variable to reflect the status of KC_ENT
          entkey_registered = true;
          // Reapplying modifier state so that the held ctrl key(s)
          // still work even after having tapped the key.
          //register_mods(MOD_MASK_CTRL);
          return false;
        }
        // for general mods
        else if (mod_state & MOD_MASK_CTRL) {
          del_mods(MOD_MASK_CTRL);
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
        if (get_oneshot_mods() & MOD_MASK_CTRL) {
          del_oneshot_mods(MOD_MASK_CTRL);
          register_code(KC_BSPC);
          bskey_registered = true;
          //register_mods(MOD_MASK_CTRL);
          return false;
        }
        // for general mods
        else if (mod_state & MOD_MASK_CTRL) {
          del_mods(MOD_MASK_CTRL);
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
  }
  return true;
};


/*
https://www.reddit.com/r/olkb/comments/ccptk9/i_need_to_activate_a_temp_layer_with_ctrlalt/
*/
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case JK_MOUSE:
            if (pressed) {
                layer_on(MOUSE);
            }
            break;
    }
}
