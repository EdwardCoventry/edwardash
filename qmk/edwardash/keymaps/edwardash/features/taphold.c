#include QMK_KEYBOARD_H


#define NO_MODIFIER 0 // Define as 0 or some value that you treat as "no modifier"
#define NO_LAYER 0    // Define as 0 or some value that you treat as "no layer"

// Define macros for each type of action
#define MOD_ACTION(KEY, TAP_KEY, MODIFIER) {KEY, MODIFIER, NO_LAYER, TAP_KEY, false, 0, false, false}
//  hold onother key press
#define HOOKP_MOD_ACTION(KEY, TAP_KEY, MODIFIER) {KEY, MODIFIER, NO_LAYER, TAP_KEY, true, 0, false, false}
#define LAYER_ACTION(KEY, TAP_KEY, LAYER) {KEY, NO_MODIFIER, LAYER, TAP_KEY, false, 0, false, false}
#define MOD_LAYER_ACTION(KEY, TAP_KEY, MODIFIER, LAYER) {KEY, MODIFIER, LAYER, TAP_KEY, false, 0, false, false}
#define NO_ACTION(KEY, TAP_KEY) {KEY, NO_MODIFIER, NO_LAYER, TAP_KEY, false, 0, false, false}



typedef struct {
  uint16_t key;            // Custom key code to trigger action
  uint16_t modifier;       // Modifier key code (use KC_NO if not applicable)
  uint16_t layer;          // Layer to switch to when the key is held (use 0 if not applicable)
  uint16_t tap_key;        // Key code to send on tap
  bool hold_on_other_key_press;
  uint16_t timer;          // Timer for this particular key
  bool fix_hold;        // Flag to indicate if key press was fix_hold
  bool held;               // Flag to indicate if key is being held
} tap_hold_action_t;


// Initializing tap_hold_actions array. Unspecified values default to 0 or false.
tap_hold_action_t tap_hold_actions[] = {
    // mods
    HOOKP_MOD_ACTION(ALT_WIN, KC_LGUI, KC_LALT),
    HOOKP_MOD_ACTION(CAPS_ALT, KC_CAPS, KC_LALT),
    HOOKP_MOD_ACTION(CTRL_ESCAPE, KC_ESCAPE, KC_LCTL),
    HOOKP_MOD_ACTION(ENTER_SHIFT, KC_ENTER, KC_LSFT),
    HOOKP_MOD_ACTION(WIN_SPACE, KC_SPACE, KC_LGUI),
    
    
    // layers
    LAYER_ACTION(HK_W, KC_W, _BREAKPOINTS),
    LAYER_ACTION(HK_H, KC_H, _STEPPING),
    LAYER_ACTION(HK_F, KC_F, _DEBUGGING),
    LAYER_ACTION(HK_A, KC_A, _DELETE),
    LAYER_ACTION(HK_R, KC_R, _TABS),
    LAYER_ACTION(HK_S, KC_S, _LEFT_RIGHT_NAVIGATION),
    LAYER_ACTION(HK_T, KC_T, _SYMBOLS),
    LAYER_ACTION(HK_N, KC_N, _TOOLS),
    LAYER_ACTION(HK_E, KC_E, _COPILOT),
    LAYER_ACTION(HK_G, KC_G, _NUMS),
    LAYER_ACTION(HK_P, KC_P, _MEDIA),
    LAYER_ACTION(HK_C, KC_C, _COPILOT),
    LAYER_ACTION(HK_L, KC_L, _SYMBOLS_2),
    LAYER_ACTION(HK_DOT, KC_DOT, _BOOKMARKS),
    LAYER_ACTION(HK_O, KC_O, _DEBUGGING_LAYER_SELECT),
    
    NO_ACTION(HK_Q, KC_Q),
    NO_ACTION(HK_V, KC_V),
    NO_ACTION(HK_K, KC_K),
    NO_ACTION(HK_M, KC_M),
    NO_ACTION(HK_D, KC_D),
    NO_ACTION(HK_U, KC_U),
    NO_ACTION(HK_Z, KC_Z),
 
    NO_ACTION(HK_X, KC_X),
    NO_ACTION(HK_J, KC_J),
    NO_ACTION(HK_I, KC_I),
    NO_ACTION(HK_B, KC_B),
    NO_ACTION(HK_Y, KC_Y),
    
    
};


bool is_tap_hold_key(uint16_t keycode, void **data) {
  for (int i = 0; i < sizeof(tap_hold_actions) / sizeof(tap_hold_actions[0]); i++) {
    if (keycode == tap_hold_actions[i].tap_key) {
      *data = &tap_hold_actions[i];
      return true;
    }
  }
  return false;
}

void register_action(tap_hold_action_t *action) {
  if (action->modifier != NO_MODIFIER) {
    register_mods(MOD_BIT(action->modifier)); // Register the modifier
  }
  if (action->layer != NO_LAYER) {
    layer_on(action->layer); // Activate the layer
  }
}

void unregister_action(tap_hold_action_t *action) {
  if (action->modifier != NO_MODIFIER) {
    unregister_mods(MOD_BIT(action->modifier)); // Unregister the modifier
  }
  if (action->layer != NO_LAYER) {
    layer_off(action->layer); // Deactivate the layer
  }
}



bool layer_switching = false;

bool process_tap_hold_action(tap_hold_action_t *action, keyrecord_t *record) {

  if (record->event.pressed) {
    // If there's no action to take on press, skip processing
    if (action->modifier == NO_MODIFIER && action->layer == NO_LAYER) {
      tap_code(action->tap_key);
      return false;
    }

    action->timer = timer_read(); // Start the timer
    action->fix_hold = false;
    action->held = true;

    register_action(action);
  } else {
    unregister_action(action);
    // Send tap code if the key was not held for too long and was not fix_hold
    if (!action->fix_hold && timer_elapsed(action->timer) < TAPPING_TERM) {
      tap_code(action->tap_key);
    }
    action->held = false;
  }

  return false; // Skip all further processing of this key
}



bool check_tap_hold_press(uint16_t keycode, keyrecord_t *record) {

  // First, check if any of the pre-hold keys have been held down long enough
  for (int i = 0; i < sizeof(tap_hold_actions) / sizeof(tap_hold_action_t); i++) {
    // If a key has been held and it's not already marked as fix_hold
    if (tap_hold_actions[i].held && !tap_hold_actions[i].fix_hold) {
      // If the key has been held past the tapping term, mark it as fix_hold
      // this meanr it will be
      if (timer_elapsed(tap_hold_actions[i].timer) > TAPPING_TERM) {
        tap_hold_actions[i].fix_hold = true;
      }
      // If any key is pressed, mark all held keys as fix_hold
      else if (tap_hold_actions[i].hold_on_other_key_press) {
        if (record->event.pressed) {
          tap_hold_actions[i].fix_hold = true;
        }
        
        else {
          unregister_action(&tap_hold_actions[i]);
        }
      }
    }

  }

  // Now, handle the actual key press/release event
  for (int i = 0; i < sizeof(tap_hold_actions) / sizeof(tap_hold_action_t); i++) {
    if (keycode == tap_hold_actions[i].key) {
      return process_tap_hold_action(&tap_hold_actions[i], record);
    }
  }

  // If no pre-hold actions are matched, process the keycode normally
  return true;
}
