#include QMK_KEYBOARD_H
#include "quantum.h"
#include "debugging.c"
#include "features/taphold/activestack.c"
#include "features/taphold/sendkey.c"
#include "features/taphold/getholdlayer.c"
#include "features/taphold/holdactions.c"
#include "features/taphold/modkeys.c"
#include "features/supertabs/supertabs.c"


bool handle_tap_hold_press(uint16_t keycode, keyrecord_t *record) {

    print_free_memory();

    keypos_t key_position = {.row = record->event.key.row, .col = record->event.key.col};
    tap_hold_action_t *current_action = get_tap_hold_action(key_position);

    // On key press
    if (record->event.pressed) {
//        if (!handle_super_tabs(keycode, record)) return;
        add_tap_hold_action(current_action, key_position);
        add_key_to_active_stack(&active_keys_stack, key_position);
        //  register any modifiers on press
        register_hold_mod_key(current_action->hold_layer);
        return false; // Do not process the key press now
    } else {
        if (current_action->hold_layer) {
            unregister_hold_mod_key(current_action->hold_layer);
            release_super_tabs(false);
        }
        remove_key_from_active_stack(&active_keys_stack, key_position);
        subtract_unpressed_keys(&current_action->active_stack, &active_keys_stack);
        mark_held_keys(&current_action->active_stack);
        //only send the key already being used as part of a hold, and if the timer hasn't expired
        if (!current_action->used_as_hold && timer_elapsed(current_action->timer) < TAPPING_TERM) {
            uint8_t active_layer = get_active_layer(&current_action->active_stack);
            send_key_with_layer(active_layer, record);
        }
        reset_tap_hold_action(current_action);
        return false; // Key release handled
    }
}
