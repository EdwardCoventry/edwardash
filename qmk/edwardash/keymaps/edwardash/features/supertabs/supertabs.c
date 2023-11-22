
#include "debugging.c"

#pragma once

bool is_alt_tab_active = false;
bool is_ctl_tab_active = false;


void release_alt_tab(bool escape) {

    uprintf("release_alt_tab start: is_alt_tab_active=%d, escape=%d\n", is_alt_tab_active, escape);

    if (is_alt_tab_active) {
        //  send escape to exit alt tab menu at the point we're on, rather than release to go to the next
        //  note that we wont do this for ctrl, since ctrls menu is app specific (so may just send an escape key to the program)
        if (escape) {
            uprintf("Exiting Alt-Tab with escape\n");
            tap_code16(KC_ESC);
        }

        unregister_code16(LSFT(KC_LALT));
        unregister_code16(KC_LALT);
        is_alt_tab_active = false;
            uprintf("release_alt_tab end\n");
                            }
}

void release_ctl_tab(void) {
    uprintf("release_ctl_tab start: is_ctl_tab_active=%d\n", is_ctl_tab_active);
    if (is_ctl_tab_active) {
        unregister_code16(LSFT(KC_LCTL));
        unregister_code16(KC_LCTL);
        is_ctl_tab_active = false;
    }
    uprintf("release_ctl_tab end\n");
}

void release_super_tabs(bool escape) {
    release_alt_tab(escape);
    release_ctl_tab();
}


layer_state_t release_super_tabs_on_layer_change(layer_state_t state) {
    uprintf("release_super_tabs_on_layer_change called\n");
    release_super_tabs(false);
    return state;
}

void do_tab(keyrecord_t *record) {
    uprintf("do_tab: pressed=%d\n", record->event.pressed);
    tap_code16(KC_TAB);
}

void do_stab(keyrecord_t *record) {
    uprintf("do_stab: pressed=%d\n", record->event.pressed);
        tap_code16(LSFT(KC_TAB));
}

void do_alt_tab(keyrecord_t *record) {
    uprintf("do_alt_tab: pressed=%d, is_alt_tab_active=%d\n", record->event.pressed, is_alt_tab_active);
    release_ctl_tab();
    if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code16(KC_LALT);
    }
    if (get_mods() & MOD_MASK_SHIFT)
        tap_code16(LSFT(KC_TAB));
    else
        tap_code16(KC_TAB);
}

void do_salt_tab(keyrecord_t *record) {
        uprintf("do_salt_tab: pressed=%d, is_alt_tab_active=%d\n", record->event.pressed, is_alt_tab_active);

    release_ctl_tab();

        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            tap_code16(LSFT(KC_LALT));
        }
        tap_code16(LSFT(KC_TAB));
    }

void do_ctrl_tab(keyrecord_t *record) {
    uprintf("do_ctrl_tab called: pressed=%d, is_ctl_tab_active=%d\n", record->event.pressed, is_ctl_tab_active);
    release_alt_tab(true);

    if (!is_ctl_tab_active) {
        is_ctl_tab_active = true;
        register_code16(KC_LCTL);
    }
    if (get_mods() & MOD_MASK_SHIFT) {
        uprintf("Shift mod active, sending Shift+Tab\n");
        tap_code16(LSFT(KC_TAB));
    } else {
        uprintf("No shift mod active, sending Tab\n");
        tap_code16(KC_TAB);
    }
}

void do_sctrl_tab(keyrecord_t *record) {
    uprintf("do_sctrl_tab called: pressed=%d, is_ctl_tab_active=%d\n", record->event.pressed, is_ctl_tab_active);
    release_alt_tab(true);

    if (!is_ctl_tab_active) {
        is_ctl_tab_active = true;
        register_code16(LSFT(KC_LCTL));
    }
    tap_code16(LSFT(KC_TAB));
}

void do_desktop_left(keyrecord_t *record) {
    uprintf("do_desktop_left called: pressed=%d\n", record->event.pressed);
    release_alt_tab(true);
    release_ctl_tab();

    tap_code16(C(G(KC_LEFT)));
}

void do_desktop_right(keyrecord_t *record) {
    uprintf("do_desktop_right called: pressed=%d\n", record->event.pressed);
    release_alt_tab(true);
    release_ctl_tab();

    tap_code16(C(G(KC_RIGHT)));
}



bool handle_super_tabs(uint16_t keycode, keyrecord_t *record) {
    uprintf("handle_super_tabs entered: keycode=%u, event.pressed=%d\n", keycode, record->event.pressed);

    switch (keycode) {
        case TAB_RIGHT:
            uprintf("TAB_RIGHT detected\n");
            if (get_mods() & MOD_BIT(KC_LCTL)) {
                uprintf("CTRL modifier is active\n");
                do_ctrl_tab(record);
            } else if (get_mods() & MOD_BIT(KC_LSFT)) {
                uprintf("ALT modifier is active\n");
                // Temporarily unregister shift
                unregister_code16(KC_LSFT);
                do_alt_tab(record);
                // Re-register shift after ALT_TAB action
                register_code16(KC_LSFT);
            } else if (get_mods() & MOD_BIT(KC_LGUI)) {
                uprintf("GUI modifier is active\n");
                do_desktop_right(record);
            } else {
                uprintf("No modifier active, sending TAB\n");
                do_tab(record);
            }
            break;

        case TAB_LEFT:
            uprintf("TAB_LEFT detected\n");
            if (get_mods() & MOD_BIT(KC_LCTL)) {
                uprintf("CTRL modifier is active\n");
                do_sctrl_tab(record);
            } else if (get_mods() & MOD_BIT(KC_LSFT)) {
                uprintf("ALT modifier is active\n");
                do_salt_tab(record);
            } else if (get_mods() & MOD_BIT(KC_LGUI)) {
                uprintf("GUI modifier is active\n");
                do_desktop_left(record);
            } else {
                uprintf("No modifier active, sending Shift+TAB\n");
                do_stab(record);
            }
            break;

        case DESKTOP_LEFT:
            uprintf("DESKTOP_LEFT detected\n");
            do_desktop_left(record);
            break;

        case DESKTOP_RIGHT:
            uprintf("DESKTOP_RIGHT detected\n");
            do_desktop_right(record);
            break;

        case ALT_TAB_RIGHT:
            uprintf("ALT_TAB_RIGHT detected\n");
            do_alt_tab(record);
            break;

        case ALT_TAB_LEFT:
            uprintf("ALT_TAB_LEFT detected\n");
            do_salt_tab(record);
            break;

        case CTRL_TAB_RIGHT:
            uprintf("CTRL_TAB_RIGHT detected\n");
            do_ctrl_tab(record);
            break;

        case CTRL_TAB_LEFT:
            uprintf("CTRL_TAB_LEFT detected\n");
            do_sctrl_tab(record);
            break;

        default:
            uprintf("Unknown keycode %u\n", keycode);
            return true; // Returning true to process the keycode further if not handled here
    }

    uprintf("handle_super_tabs exiting\n");
    return false; // Returning false to stop further processing of the keycode
}
