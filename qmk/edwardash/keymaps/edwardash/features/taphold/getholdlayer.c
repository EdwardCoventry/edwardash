#pragma once


extern active_key_stack_t active_keys_stack;

int get_hold_layer_of_keypress(keypos_t keypos){
    uint8_t active_layer = get_active_layer(&active_keys_stack); // Get the active layer
    // Check if the active_layer is valid and defined before attempting to access the array
    if (layer_in_hold_layers(active_layer)) {
        // Access the hold_layers array to get the layer value
        int layer_value = pgm_read_word(&hold_layers[active_layer][keypos.row][keypos.col]);
        return layer_value;
    } else {
        return ____; // Return NO_LAYER if the active layer is not present or not defined
    }
}