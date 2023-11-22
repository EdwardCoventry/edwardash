#pragma once
//#include "features/layerlock/layerlock.h"
// salt_tab, sctrl_tab, swin_tab, etc
#include "features/supertabs/supertabs.c"
//
#include "features/shiftsymbols/shiftsymbols.h"


uint16_t get_key_with_layer(uint8_t layer, keyrecord_t *record) {

    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;

    //        uprintf("Layer: %d, Row: %u, Col: %u \n", layer, row, col);


    return keymap_key_to_keycode(layer, (keypos_t) {.row = row, .col = col});
}


void send_key_with_layer(uint8_t layer, keyrecord_t *record) {


    uint16_t keycode = get_key_with_layer(layer, record);

    // Print the row, column, and layer values, and the keycode
//    uprintf("Layer: %d, Row: %u, Col: %u -> %u\n", layer, row, col, keycode);

    if (!handle_super_tabs(keycode, record)) return;

    if (!handle_shift_symbols(keycode, record)) return;

//    if (!handle_layer_lock(keycode, record, LLOCK)) return;

    switch (keycode) {
        case KC_NO:
            // Do nothing if keycode is KC_NO
            break;

        default:
            tap_code16(keycode); // Send the keycode for all other cases
            break;
    }
}
