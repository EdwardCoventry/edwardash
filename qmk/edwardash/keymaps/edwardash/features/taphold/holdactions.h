#pragma once

#include "quantum.h"

typedef struct {
    uint16_t timer;                    // Timer for this particular key
    bool used_as_hold;                 // Flag to indicate if key press was used as a hold
    bool held;                         // Flag to indicate if key is being held
    uint16_t keycode;                         // Flag to indicate if key has been sent
    bool sent;                         // Flag to indicate if key has been sent
    active_key_stack_t active_stack;   // Active stack of keys
    int hold_layer;                    // if this key activates a mod layer, store it here
} tap_hold_action_t;

// Function prototypes
tap_hold_action_t* get_tap_hold_action(keypos_t key_position);
void copy_active_stack_to_tap_hold_action(tap_hold_action_t *action, keypos_t key_position);
void add_tap_hold_action(tap_hold_action_t* action, keypos_t key_position);
void reset_tap_hold_action(tap_hold_action_t* action);
void mark_held_keys(active_key_stack_t *stack);
