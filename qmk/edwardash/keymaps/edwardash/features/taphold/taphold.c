#include QMK_KEYBOARD_H
#include "quantum.h"
#include "debugging.c"
#include "features/taphold/activestack.c"
#include "features/taphold/sendkey.c"
#include "features/taphold/getholdlayer.c"
#include "features/taphold/holdactions.c"
#include "features/taphold/modkeys.c"
#include "features/supertabs/supertabs.c"


void handle_matrix_scan(void) {
    // Iterate over all rows and columns
    for (int row = 0; row < MATRIX_ROWS; row++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            keypos_t key_position = {.row = row, .col = col};
            tap_hold_action_t *current_action = get_tap_hold_action(key_position);

            // Check if the key is a tap-hold key and is currently held down
            if (current_action->held && !current_action->used_as_hold && !current_action->sent && current_action->keycode) {
                // Check if the tapping term has expired
                if (timer_elapsed(current_action->timer) > TAPPING_TERM) {
                    // Process the key as a hold
                    register_action(current_action);
                }
            }
        }
    }
}


void register_pending_repeat(tap_hold_action_t *action, keyrecord_t *record) {

    uint8_t layer = get_active_layer(&action->active_stack);

    action -> keycode = get_key_with_layer(layer, record);

}


bool handle_tap_hold_press(uint16_t keycode, keyrecord_t *record) {

//    print_free_memory();

    keypos_t key_position = {.row = record->event.key.row, .col = record->event.key.col};
    tap_hold_action_t *current_action = get_tap_hold_action(key_position);

    // On key press
    if (record->event.pressed) {
//        if (!handle_super_tabs(keycode, record)) return;
        add_tap_hold_action(current_action, key_position);
        add_key_to_active_stack(&active_keys_stack, key_position);

        uprintf("hold_layer: %d\n", current_action->hold_layer);

        if (current_action->hold_layer) {
            register_hold_mod_key(current_action->hold_layer);
        }
        else {
            register_pending_repeat(current_action, record);
        }

        return false; // Do not process the key press now
    } else {
        if (current_action->hold_layer) {
            unregister_hold_mod_key(current_action->hold_layer);
            release_super_tabs(false);
        }
        remove_key_from_active_stack(&active_keys_stack, key_position);
        subtract_unpressed_keys(&current_action->active_stack, &active_keys_stack);
        mark_held_keys(&current_action->active_stack);

        if (current_action->sent) {
            unregister_action(current_action);
        } else if (!current_action->used_as_hold &&
                   timer_elapsed(current_action->timer) < TAPPING_TERM) {
            //only send the key already being used as part of a hold, and if the timer hasn't expired
            send_action(current_action, record);
        }
        reset_tap_hold_action(current_action);

        return false; // Key release handled
    }
}
