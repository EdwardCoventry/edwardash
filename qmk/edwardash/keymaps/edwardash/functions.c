#include QMK_KEYBOARD_H
// https://getreuer.info/posts/keyboards/layer-lock/index.html
#include "features/layerlock/layerlock.h"
// salt_tab, sctrl_tab, swin_tab, etc
#include "features/supertabs/supertabs.c"
// 
#include "features/taphold/taphold.c"

#include "features/shiftsymbols/shiftsymbols.h"

// enumed keys and layers, and also tap mods like TAB_SHIFT
#include "layers.c"

//  https://github.com/qmk/qmk_firmware/blob/master/docs/understanding_qmk.md

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!handle_super_tabs(keycode, record)) return false;

    if (!handle_tap_hold_press(keycode, record)) return false;

    if (!handle_shift_keycombos(keycode, record)) return false;

    if (!handle_layer_lock(keycode, record, LLOCK)) return false;

    return true;

}


layer_state_t layer_state_set_user(layer_state_t state) {
  state = release_on_layer_change(state);
  return state;
}