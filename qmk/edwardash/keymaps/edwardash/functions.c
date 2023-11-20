#include QMK_KEYBOARD_H
// https://getreuer.info/posts/keyboards/layer-lock/index.html
#include "features/layer_lock.h"
// enumed keys and layers, and also tap mods like TAB_SHIFT
#include "layers.c"
// salt_tab, sctrl_tab, swin_tab, etc
#include "features/supertabs.c"
// 
#include "features/taphold.c"

#include "features/shifts.h"

//  https://github.com/qmk/qmk_firmware/blob/master/docs/understanding_qmk.md

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


uint16_t shift_tab_key_timer;
static bool shift_tab_other_key_pressed = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  

  // If any other key is pressed while SHIFT_TAB_MOD is held down, set shift_tab_other_key_pressed to true.
  if (keycode != SHIFT_TAB_MOD && layer_state_is(_MOD)) {
    if (record->event.pressed) {
      shift_tab_other_key_pressed = true;
    }
  }

  
  
  if (!handle_shift_keycombos(keycode, record)) return false;

  // layer lock handled here
  if (!process_layer_lock(keycode, record, LLOCK)) return false;
  
  if (!check_tap_hold_press(keycode, record)) return false;

  
  // switch logic here
  switch (keycode) {
  
  // pseudo permissive_hold LT for mod, shift_tab
  case SHIFT_TAB_MOD:
    if (record->event.pressed) {
      // this key is being pressed, so we start the timer
      shift_tab_key_timer = timer_read();
      shift_tab_other_key_pressed = false; // reset the other key flag
      // activate the layer
      layer_on(_MOD);
    } else {
      // this key is being released, so we stop the layer								
      layer_off(_MOD);
      if (!shift_tab_other_key_pressed && timer_elapsed(shift_tab_key_timer) < 150) {
        // the key was tapped (not held), and no other key was pressed

        register_code(KC_LSFT);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
    }
  break;
  
  
  case TAB_RIGHT:
    if (get_mods() & MOD_BIT(KC_LCTL)) {
      do_ctrl_tab(record);
    } else if (get_mods() & MOD_BIT(KC_LSFT)) {
      //  unregister shift
      unregister_code(KC_LSFT);
      //  now do as if shift was not held
      do_alt_tab(record);
      //  register shift again
      register_code(KC_LSFT);
    } else if (get_mods() & MOD_BIT(KC_LGUI)) {
      do_desktop_right(record);
    } else {
      do_tab(record);
    }
    break;

  case TAB_LEFT:
    if (get_mods() & MOD_BIT(KC_LCTL)) {
      do_sctrl_tab(record);
    } else if (get_mods() & MOD_BIT(KC_LSFT)) {
      do_salt_tab(record);
    } else if (get_mods() & MOD_BIT(KC_LGUI)) {
      do_desktop_left(record);
  } else {
      do_stab(record);
    }
    break;

  case DESKTOP_LEFT:
    do_desktop_left(record);
    break;

  case DESKTOP_RIGHT:
    do_desktop_right(record);
    break;

  case ALT_TAB:
    do_alt_tab(record);
    break;
    
  case SALT_TAB:
    do_salt_tab(record);
    break;
    
  case CTL_TAB:
    do_ctrl_tab(record);
    break;

  case SCTL_TAB:
    do_sctrl_tab(record);
    break;
    
    
  return false;
    
  }
  
  
  return true;
}




void matrix_scan_user(void) {
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = release_on_layer_change(state);
  return state;
}