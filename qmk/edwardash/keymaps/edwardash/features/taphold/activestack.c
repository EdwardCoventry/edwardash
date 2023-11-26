#pragma once
#include "features/taphold/getholdlayer.c"
#include "features/taphold/modkeys.c"


//Global active keys stack and its count
active_key_stack_t active_keys_stack;

// Function to add a key to the active keys stack
bool add_key_to_active_stack(active_key_stack_t *stack, keypos_t keypos) {
    if (stack->count < MAX_ACTIVE_KEYS) {
        stack->keys[stack->count] = keypos;
        stack->count++;
        return true;
    }
    return false; // Stack is full, key not added
}
// Function to remove a key from the active keys stack
bool remove_key_from_active_stack(active_key_stack_t *stack, keypos_t keypos) {
    for (uint8_t i = 0; i < stack->count; i++) {
        if (stack->keys[i].row == keypos.row && stack->keys[i].col == keypos.col) {
            // Shift the rest of the stack down by one
            for (uint8_t j = i; j < stack->count - 1; j++) {
                stack->keys[j] = stack->keys[j + 1];
            }
            stack->count--;
            return true;
        }
    }
    return false; // Key not found in stack
}

// Function to check if a key is in the active keys stack
bool is_key_in_active_stack(const active_key_stack_t *stack, keypos_t keypos) {
    for (uint8_t i = 0; i < stack->count; i++) {
        if (stack->keys[i].row == keypos.row && stack->keys[i].col == keypos.col) {
            return true;
        }
    }
    return false; // Key not found in stack
}

// Function to return a new active stack of the intersection between two stacks, preserving the order of the first
// Function to modify the first stack to be the intersection of the two stacks, preserving the order of the first
void subtract_unpressed_keys(active_key_stack_t *stack1, const active_key_stack_t *stack2) {
    uint8_t intersection_count = 0;

    for (uint8_t i = 0; i < stack1->count; i++) {
        if (is_key_in_active_stack(stack2, stack1->keys[i])) {
            // If the key is in both stacks, keep it in the intersection
            stack1->keys[intersection_count++] = stack1->keys[i];
        }
    }

    // Update the count of the first stack to the count of the intersection
    stack1->count = intersection_count;
}


// Assuming hold_layers is globally available
//extern const int hold_layers[][MATRIX_ROWS][MATRIX_COLS];
uint8_t get_active_layer(active_key_stack_t *stack) {

    uint8_t active_layer = 0; // Start with the base layer

    for (uint8_t i = 0; i < stack->count; i++) {
        uint8_t row = stack->keys[i].row;
        uint8_t col = stack->keys[i].col;

        // Check if the position in hold_layers is valid and not ____
        if (row < MATRIX_ROWS && col < MATRIX_COLS && (active_layer == 0 || layer_in_hold_layers(active_layer))) {
            // Read the value from the program space (flash memory)
            uint8_t layer = pgm_read_byte_near(&hold_layers[active_layer][row][col]);
            if (layer != ____ && !is_hold_mod_key(layer) ) { // Check if the layer is defined
                // Update active_layer to the new layer found at the current key position
                active_layer = layer;
            }
        }
        // If ____ or invalid position, continue to the next key in the stack
    }

    return active_layer; // Return the last layer we land on
                }