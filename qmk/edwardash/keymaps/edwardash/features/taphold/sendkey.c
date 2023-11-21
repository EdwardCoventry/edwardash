#pragma once

void send_key_with_layer(uint8_t layer, keyrecord_t *record) {
    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;

        uprintf("Layer: %d, Row: %u, Col: %u \n", layer, row, col);


    uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){.row = row, .col = col});


    // Print the row, column, and layer values, and the keycode
    uprintf("Layer: %d, Row: %u, Col: %u -> %u\n", layer, row, col, keycode);


    switch (keycode) {
        case KC_NO:
            // Do nothing if keycode is KC_NO
            break;

        default:
            tap_code16(keycode); // Send the keycode for all other cases
            break;
    }}
