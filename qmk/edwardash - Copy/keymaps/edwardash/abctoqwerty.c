#include QMK_KEYBOARD_H

// Assuming _ABC and _QWERTY are the indices of your layers
#define ABC_LAYER _ABC
#define QWERTY_LAYER _QWERTY

bool process_record_abctoqwerty(uint16_t keycode, keyrecord_t *record) {
  // Check if we are on the ABC layer
  if (layer_state_is(ABC_LAYER) && record->event.pressed) {
    uint8_t mods = get_mods();
    bool mod_pressed = mods & (MOD_BIT(KC_LCTRL) | MOD_BIT(KC_RCTRL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI));

    // Check if CTRL, ALT, or GUI is held down
    if (mod_pressed) {
      // Temporarily switch to QWERTY layer to get the keycode
      layer_move(QWERTY_LAYER);
      uint16_t qwerty_keycode = keymap_key_to_keycode(QWERTY_LAYER, record->event.key);
      
      // Send the QWERTY keycode
      if (record->event.pressed) { // Key pressed
        register_code(qwerty_keycode);
      } else { // Key released
        unregister_code(qwerty_keycode);
      }
      
      // Immediately return to ABC layer
      layer_move(ABC_LAYER);

      // Skip all further processing so QMK doesn't process the key normally
      return false;
    }
  }

  // Process all other key events as normal
  return true;
}
