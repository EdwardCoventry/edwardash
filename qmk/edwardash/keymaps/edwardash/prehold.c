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



bool check_pre_hold_press(uint16_t keycode, keyrecord_t *record) {
  pre_hold_key_t* data;

  // First, check if any of the pre-hold keys have been held down long enough
  int i;
  for (i = 0; i < sizeof(pre_hold_keys) / sizeof(pre_hold_key_t); i++) {
    if (pre_hold_keys[i].held && timer_elapsed(pre_hold_keys[i].timer) > 150) {
      pre_hold_keys[i].held = false;  // Reset the flag
      pre_hold_keys[i].interupted = true;   // Ensure tap function won't activate on release
    }
  }

  // Then, handle the actual key press/release event
  if (is_pre_hold_key(keycode, &data)) {
    if (record->event.pressed) {
      data->timer = timer_read();  // Start the timer for this key
      register_code(data->modifier);
      data->interupted = false;
      data->held = true;  // Mark the key as held.
    } else {
      if (!data->interupted && timer_elapsed(data->timer) < 150) {
        unregister_code(data->modifier);
        tap_code(data->tap_key);
      } else {
        unregister_code(data->modifier);
      }
      data->held = false;  // Mark the key as unheld.
    }
    return true;
  }
  return false;
}

