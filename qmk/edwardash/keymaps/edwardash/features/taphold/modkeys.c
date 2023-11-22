
#pragma once

// check if it's a hold mod key
bool is_hold_mod_key(uint16_t hold_key) {
    return hold_key == CTRL || hold_key == SHIFT || hold_key == ALT || hold_key == WIN;
}

// register the hold mod key
void register_hold_mod_key(uint16_t hold_key) {
    switch (hold_key) {
        case CTRL:
            register_code(KC_LCTL);
            break;
        case SHIFT:
            register_code(KC_LSFT);
            break;
        case ALT:
            register_code(KC_LALT);
            break;
        case WIN:
            register_code(KC_LGUI);
            break;
    }
}

// unregister the hold mod key
void unregister_hold_mod_key(uint16_t hold_key) {
    switch (hold_key) {
        case CTRL:
            unregister_code(KC_LCTL);
            break;
        case SHIFT:
            unregister_code(KC_LSFT);
            break;
        case ALT:
            unregister_code(KC_LALT);
            break;
        case WIN:
            unregister_code(KC_LGUI);
            break;
    }
}


////  register modifier keycodes
//void register_keycode_layer_key(uint16_t hold_key) {
//    switch (hold_key) {
//        case CTRL:
//            register_code(KC_LCTL);
//            break;
//        case SHIFT:
//            register_code(KC_LSFT);
//            break;
//        case ALT:
//            register_code(KC_LALT);
//            break;
//        case WIN:
//            register_code(KC_LGUI);
//            break;
//    }
//}

