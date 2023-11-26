#pragma once
#include "features/supertabs/supertabs.c"
#include "features/shiftsymbols/shiftsymbols.h"
#include "features/taphold/holdactions.h"


uint16_t get_key_with_layer(uint8_t layer, keyrecord_t *record) {

    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;

    return keymap_key_to_keycode(layer, (keypos_t) {.row = row, .col = col});
}


void send_key_with_layer(uint8_t layer, keyrecord_t *record) {

    uint16_t keycode = get_key_with_layer(layer, record);

    if (!handle_super_tabs(keycode, record)) return;

    if (!handle_shift_symbols(keycode, record)) return;

    //  layer lock not implemented
    //   if (!handle_layer_lock(keycode, record, LLOCK)) return;

    switch (keycode) {
        case KC_NO:
            // Do nothing if keycode is KC_NO
            break;

        default:
            tap_code16(keycode); // Send the keycode for all other cases
            break;
    }
}


void send_action(tap_hold_action_t *action, keyrecord_t *record) {

    uint8_t layer = get_active_layer(&action->active_stack);

    send_key_with_layer(layer, record);

}

void register_action(tap_hold_action_t *action) {

    action->sent = true;

    switch (action -> keycode) {
        case KC_NO:
            // Do nothing if keycode is KC_NO
            break;

        default:
            register_code16(action->keycode); // Send the keycode for all other cases
            break;
    }


}

void unregister_action(tap_hold_action_t *action) {

    unregister_code16(action->keycode);
}