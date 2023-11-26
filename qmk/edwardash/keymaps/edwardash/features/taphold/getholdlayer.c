#pragma once

#include "layermap.c"
#include "features/taphold/activestack.h"

const size_t defined_hold_layers_count = sizeof(defined_hold_layers) / sizeof(defined_hold_layers[0]);
extern active_key_stack_t active_keys_stack;


bool layer_in_hold_layers(uint8_t layer) {
    for (size_t i = 0; i < defined_hold_layers_count; ++i) {
        if (defined_hold_layers[i] == layer) {
            return true;
        }
    }
    return false;
}

int get_hold_layer_of_keypress(keypos_t keypos) {

    uint8_t active_layer = get_active_layer(&active_keys_stack); // Get the active layer

    int layer;

    // Check if the active_layer is valid and defined before attempting to access the array
    if (layer_in_hold_layers(active_layer)) {
        // Access the hold_layers array to get the layer value
        layer = pgm_read_word(&hold_layers[active_layer][keypos.row][keypos.col]);
    } else {
        layer = NO_LAYER;
    }


    if (layer == NO_LAYER) {
        //  use default hold layer, if any. aorn this would just be a modifier key
        return pgm_read_word(&hold_layer_default[keypos.row][keypos.col]);
    } else {
        return layer;

    }
}
