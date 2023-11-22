#include QMK_KEYBOARD_H
// https://getreuer.info/posts/keyboards/layer-lock/index.html

#include "features/taphold/taphold.c"


// enumed keys and layers
#include "layers.c"

//  https://github.com/qmk/qmk_firmware/blob/master/docs/understanding_qmk.md

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

        if (!handle_tap_hold_press(keycode, record)) return false;

    return true;

}


layer_state_t layer_state_set_user(layer_state_t state) {
//  state = release_super_tabs_on_layer_change(state);
  return state;
}