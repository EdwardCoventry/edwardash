// shifts.h

#pragma once

#include QMK_KEYBOARD_H

// Helper function to send a keycode with shift temporarily cleared
static void send_keycode(uint16_t keycode, bool clear_shift) {
  uint8_t mods = get_mods(); // Save the current state of the mods

  // Clear shift mods if they are currently on and clear_shift is true
  if (clear_shift) {
    del_mods(MOD_MASK_SHIFT);
  }

  // Send the keycode
  register_code(keycode);
  unregister_code(keycode);

  // Restore original mods only if shift was cleared
  if (clear_shift) {
    set_mods(mods);
  }
}


// Function to handle special shift key combinations
bool handle_shift_keycombos(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {

    // this function is for handling shifts, so otherwise return
    if (!(get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))) {
      return true; // If no shift mods are active, no special handling is needed
    }

    switch (keycode) {
    case KC_SPACE:
      send_keycode(KC_UNDERSCORE, false); // True indicates that shift is needed to send underscore
      return false; // Skip all further processing of this key
    case KC_DOT:
      send_keycode(KC_EXCLAIM, false); // Send KC_DOT with shift
      return false; // Skip all further processing of this key
    case KC_COMMA:
      send_keycode(KC_QUESTION, false); // Send KC_EXLM with shift
      return false; // Skip all further processing of this key
    // ... handle other keycodes if needed
    default:
      break;
    }
  }
  return true; // Return true if no special handling was needed
}
