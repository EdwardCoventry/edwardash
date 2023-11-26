// activestack.h
#pragma once

#define MAX_ACTIVE_KEYS 8 // Maximum number of active keys

typedef struct {
    keypos_t keys[MAX_ACTIVE_KEYS];
    uint8_t count;
} active_key_stack_t;

// Function declarations
uint8_t get_active_layer(active_key_stack_t *stack);
bool add_key_to_active_stack(active_key_stack_t *stack, keypos_t keypos);
bool remove_key_from_active_stack(active_key_stack_t *stack, keypos_t keypos);
bool is_key_in_active_stack(const active_key_stack_t *stack, keypos_t keypos);
void subtract_unpressed_keys(active_key_stack_t *stack1, const active_key_stack_t *stack2);
