bool is_alt_tab_active = false;
bool is_ctl_tab_active = false;

void release_alt_tab(bool escape) {
    if (is_alt_tab_active) {
        //  send escape to exit alt tab menu at the point we're on, rather than release to go to the next
        //  note that we wont do this for ctrl, since ctrls menu is app specific (so may just send an escape key to the program)
        if (escape) {
            tap_code(KC_ESC);
        }

        unregister_code16(LSFT(KC_LALT));
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
}

void release_ctl_tab(void) {
    if (is_ctl_tab_active) {
        unregister_code16(LSFT(KC_LCTL));
        unregister_code(KC_LCTL);
        is_ctl_tab_active = false;
    }
}

layer_state_t release_on_layer_change(layer_state_t state) {
    release_alt_tab(false);
    release_ctl_tab();
    return state;
}

void do_tab(keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_TAB);
        unregister_code(KC_TAB);
    }
}

void do_stab(keyrecord_t *record) {
    if (record->event.pressed) {
        register_code16(LSFT(KC_TAB));
        unregister_code16(LSFT(KC_TAB));
    }
}

void do_alt_tab(keyrecord_t *record) {
    release_ctl_tab();

    if (record->event.pressed) {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        if (get_mods() & MOD_MASK_SHIFT)
            register_code16(LSFT(KC_TAB));
        else
            register_code(KC_TAB);
    } else {
        unregister_code(KC_TAB);
    }
}

void do_salt_tab(keyrecord_t *record) {
    release_ctl_tab();

    if (record->event.pressed) {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code16(LSFT(KC_LALT));
        }
        register_code16(LSFT(KC_TAB));
    } else {
        unregister_code16(LSFT(KC_TAB));
    }
}

void do_ctrl_tab(keyrecord_t *record) {
    release_alt_tab(true);

    if (record->event.pressed) {
        if (!is_ctl_tab_active) {
            is_ctl_tab_active = true;
            register_code(KC_LCTL);
        }
        if (get_mods() & MOD_MASK_SHIFT)
            register_code16(LSFT(KC_TAB));
        else
            register_code(KC_TAB);
    } else {
        unregister_code(KC_TAB);
    }
}

void do_sctrl_tab(keyrecord_t *record) {
    release_alt_tab(true);

    if (record->event.pressed) {
        if (!is_ctl_tab_active) {
            is_ctl_tab_active = true;
            register_code16(LSFT(KC_LCTL));
        }
        register_code16(LSFT(KC_TAB));
    } else {
        unregister_code16(LSFT(KC_TAB));
    }
}

void do_desktop_left(keyrecord_t *record) {
    if (record->event.pressed) {
        release_alt_tab(true);
        release_ctl_tab();

        tap_code16(C(G(KC_LEFT)));
    }
}

void do_desktop_right(keyrecord_t *record) {
    if (record->event.pressed) {
        release_alt_tab(true);
        release_ctl_tab();

        tap_code16(C(G(KC_RIGHT)));
    }
}


bool handle_super_tabs(uint16_t keycode, keyrecord_t *record) {

    // switch logic here
    switch (keycode) {

        case TAB_RIGHT:
            if (get_mods() & MOD_BIT(KC_LCTL)) {
                do_ctrl_tab(record);
            } else if (get_mods() & MOD_BIT(KC_LSFT)) {
                //  unregister shift
                unregister_code(KC_LSFT);
                //  now do as if shift was not held
                do_alt_tab(record);
                //  register shift again
                register_code(KC_LSFT);
            } else if (get_mods() & MOD_BIT(KC_LGUI)) {
                do_desktop_right(record);
            } else {
                do_tab(record);
            }
            break;

        case TAB_LEFT:
            if (get_mods() & MOD_BIT(KC_LCTL)) {
                do_sctrl_tab(record);
            } else if (get_mods() & MOD_BIT(KC_LSFT)) {
                do_salt_tab(record);
            } else if (get_mods() & MOD_BIT(KC_LGUI)) {
                do_desktop_left(record);
            } else {
                do_stab(record);
            }
            break;

        case DESKTOP_LEFT:
            do_desktop_left(record);
            break;

        case DESKTOP_RIGHT:
            do_desktop_right(record);
            break;

        case ALT_TAB:
            do_alt_tab(record);
            break;

        case SALT_TAB:
            do_salt_tab(record);
            break;

        case CTL_TAB:
            do_ctrl_tab(record);
            break;

        case SCTL_TAB:
            do_sctrl_tab(record);
            break;


            return false;

    }


    return true;
}