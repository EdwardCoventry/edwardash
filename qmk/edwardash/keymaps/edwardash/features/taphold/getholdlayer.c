#pragma once


extern active_key_stack_t active_keys_stack;

int get_hold_layer_of_keypress(keypos_t keypos){
    uprintf("get_hold_layer_of_keypress called: row=%u, col=%u\n", keypos.row, keypos.col);

    uint8_t active_layer = get_active_layer(&active_keys_stack); // Get the active layer
    uprintf("Active layer: %d\n", active_layer);

    // Check if the active_layer is valid and defined before attempting to access the array
    if (layer_in_hold_layers(active_layer)) {
        uprintf("Active layer is in hold_layers\n");
        // Access the hold_layers array to get the layer value
        int layer_value = pgm_read_word(&hold_layers[active_layer][keypos.row][keypos.col]);
        uprintf("Layer value retrieved: %d\n", layer_value);
        return layer_value;
    } else {
        uprintf("Active layer is not in hold_layers, returning NO_LAYER\n");
        return NO_LAYER; // Replace ____ with NO_LAYER or the appropriate constant for no layer
    }
}
