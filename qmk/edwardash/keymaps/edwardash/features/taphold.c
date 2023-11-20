#include QMK_KEYBOARD_H
#include "quantum.h"
#include "debugging.c"
typedef struct {
    bool hold_on_other_key_press;
    uint16_t timer;          // Timer for this particular key
    bool fix_hold;           // Flag to indicate if key press was fix_hold
    bool held;               // Flag to indicate if key is being held
    uint8_t layer;           // Layer to switch to when the key is held
} tap_hold_action_t;


// Define an array to hold the tap-hold actions for each key.
static tap_hold_action_t tap_hold_actions[MATRIX_ROWS][MATRIX_COLS] = {{{false, 0, false, false}}};

void send_key_with_layer(keyrecord_t *record, uint8_t layer) {
    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;

    // Print the row, column, and layer values
    uprintf("Layer: %d, Row: %u, Col: %u\n", layer, row, col);

    uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){row, col});

    tap_code16(keycode); // Send the keycode
}





bool check_tap_hold_press(uint16_t keycode, keyrecord_t *record) {
    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;

    // On key press
    if (record->event.pressed) {
        // Start the timer and mark as held, assign the layer from hold_layers
        tap_hold_actions[row][col].timer = timer_read();
        tap_hold_actions[row][col].held = true;
tap_hold_actions[row][col].layer = (uint8_t)(hold_layers[0][row][col]);
        return false; // Do not process the key press now
    } else {
        // On key release, reset the timer and held flag
        tap_hold_actions[row][col].timer = 0;
        tap_hold_actions[row][col].held = false;
        tap_hold_actions[row][col].layer = 0;

        bool any_holds = false;
        uint8_t highest_layer = 0;

        // Check if any other keys are held and find the highest active layer
        for (int r = 0; r < MATRIX_ROWS; r++) {
            for (int c = 0; c < MATRIX_COLS; c++) {
                if (tap_hold_actions[r][c].held) {
                    any_holds = true;

                    highest_layer = MAX(highest_layer, tap_hold_actions[r][c].layer);
                }
            }
        }

        // If no other keys are held, send the key as a normal tap
        if (!any_holds) {
            tap_code16(keycode);
        } else {
            // If other keys are held, send the key with the highest active layer
            send_key_with_layer(record, highest_layer);
        }

        return false; // Key release handled
    }
}

