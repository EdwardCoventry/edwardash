// use qmk toolbox tools - HID console


#include "print.h"

void keyboard_post_init_user(void) {
  // Call the post init code.
  debug_enable=true;   // Enable debugging
  debug_keyboard=true; // Enable keyboard debug messages
  debug_matrix=true;   // Enable matrix debug messages
  // Other debug options are available. Check QMK's documentation for more info.
}


void print_free_memory(void) {
    extern int __heap_start, *__brkval;
    int v;
    int free_memory;

    if ((int)__brkval == 0) {
        free_memory = ((int)&v) - ((int)&__heap_start);
    } else {
        free_memory = ((int)&v) - ((int)__brkval);
    }

    uprintf("Free RAM: %d bytes\n", free_memory);
}