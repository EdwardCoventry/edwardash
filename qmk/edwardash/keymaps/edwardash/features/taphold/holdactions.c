#pragma once
#include "features/taphold/getholdlayer.c"

typedef struct {
    uint16_t timer;                    // Timer for this particular key
    bool used_as_hold;                     // Flag to indicate if key press was used as a hold
    bool held;                         // Flag to indicate if key is being held
    active_key_stack_t active_stack;   // Active stack of keys
    int hold_layer;                     // if this key activates a mod layer, store it here
} tap_hold_action_t;


// Define an array to hold the tap-hold actions for each key.
static tap_hold_action_t tap_hold_actions[MATRIX_ROWS][MATRIX_COLS];


//
// Function to get a reference to the tap-hold action for a given key position
static tap_hold_action_t* get_tap_hold_action(keypos_t key_position) {
    return &tap_hold_actions[key_position.row][key_position.col];
}

 //Function to copy the current active stack to a tap-hold action, excluding the key itself
void copy_active_stack_to_tap_hold_action(tap_hold_action_t *action, keypos_t key_position) {
    // Assuming active_keys_stack is the global stack where all currently pressed keys are recorded
    action->active_stack.count = 0;
    for (uint8_t i = 0; i < active_keys_stack.count; i++) {
        if (active_keys_stack.keys[i].row != key_position.row || active_keys_stack.keys[i].col != key_position.col) {
            action->active_stack.keys[action->active_stack.count++] = active_keys_stack.keys[i];
        }
    }
}

// Function to add a tap-hold action
void add_tap_hold_action(tap_hold_action_t* action, keypos_t key_position) {
    action->timer = timer_read();
    action->held = true;
    action->used_as_hold = false;
    action->hold_layer = get_hold_layer_of_keypress(key_position);
    uprintf("hold_layer: %d\n", action->hold_layer);
    copy_active_stack_to_tap_hold_action(action, key_position);


}

// Function to reset the tap-hold action
void reset_tap_hold_action(tap_hold_action_t* action) {
    action->timer = 0;
    action->held = false;
    action->used_as_hold = false;
    action->active_stack.count = 0;
    action->hold_layer = 0;
}

void mark_held_keys(active_key_stack_t *stack) {
    for (uint8_t i = 0; i < stack->count; i++) {
        tap_hold_action_t* action = get_tap_hold_action(stack->keys[i]);
        action->used_as_hold = true;
    }
}
