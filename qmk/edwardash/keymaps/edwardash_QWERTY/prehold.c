#include QMK_KEYBOARD_H

typedef struct {
  uint16_t key;
  uint16_t modifier;
  uint16_t tap_key;
  uint16_t timer;        // Timer for this particular key
  bool interupted;           // Interupted flag for this key
  bool held;           // held flag for this key
} pre_hold_key_t;

// Initializing pre_hold_keys array. Unspecified values default to 0 or false.
pre_hold_key_t pre_hold_keys[] = {
    {ALT_WIN, KC_LALT, KC_LGUI},
    {CAPS_ALT, KC_LALT, KC_CAPS},
    {CTRL_ESCAPE, KC_LCTL, KC_ESCAPE},
    {ENTER_SHIFT, KC_LEFT_SHIFT, KC_ENTER},
    {WIN_SPACE, KC_LGUI, KC_SPACE},
    // ... add more keys as needed ...
};

bool is_pre_hold_key(uint16_t keycode, pre_hold_key_t **data) {
  int i;
  for (i = 0; i < sizeof(pre_hold_keys) / sizeof(pre_hold_keys[0]); i++) {
    if (keycode == pre_hold_keys[i].key) {
      *data = &pre_hold_keys[i];
      return true;
    }
  }
  return false;
}



bool layer_switching = false;


layer_state_t detect_layer_change(layer_state_t state) {
  // Detects any layer change
  static layer_state_t last_layer_state = 0;  // Store the last layer state
  if (state != last_layer_state) {            // If current state differs from the last
    layer_switching = true;                 // Set flag indicating layer switch
  } else {
    layer_switching = false;                // Clear flag if no change in layer state
  }
  last_layer_state = state;                   // Update the last layer state for next call
  return state;                               // Return the updated layer state
}


bool check_pre_hold_press(uint16_t keycode, keyrecord_t *record) {
  pre_hold_key_t* data;

  // First, check if any of the pre-hold keys have been held down long enough
  int i;
  for (i = 0; i < sizeof(pre_hold_keys) / sizeof(pre_hold_key_t); i++) {
    if (pre_hold_keys[i].held && record->event.pressed) {
      pre_hold_keys[i].interupted = true;
    }
    if (pre_hold_keys[i].held && timer_elapsed(pre_hold_keys[i].timer) > 150) {
      pre_hold_keys[i].interupted = true;  // Reset the flag
    }
  }

  // Then, handle the actual key press/release event
  if (is_pre_hold_key(keycode, &data)) {
    if (record->event.pressed) {
      data->timer = timer_read();  // Start the timer when key is pressed
      register_code(data->modifier);  // Register the modifier
      data->interupted = false;
      data->held = true;
    } else {  // Key release
      unregister_code(data->modifier);  // Always unregister the modifier

      if (!layer_switching && !data->interupted && timer_elapsed(data->timer) < 150) {
        tap_code(data->tap_key);  // If within time threshold and not interrupted, tap the key
      }

      data->held = false;
    }
    layer_switching = false;  // Reset the layer switching flag
    return true;
  }

  layer_switching = false;  // Also reset for non pre-hold keys
  return false;
}

