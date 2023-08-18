// 
#include "keydefs.c"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
        KC_Q,                   LT(BREAKPOINTS,KC_W),   LT(STEPPING,KC_E),      LT(DEBUGGING,KC_R),     KC_T,                   KC_Y,                   KC_U,                   KC_I,                   KC_O,                   KC_P,
        LT(DELETE,KC_A),        LT(TABS,KC_S),          LT(NAVIGATION,KC_D),    LT(UP_DOWN_NAVIGATION,KC_F),KC_G,               KC_H,                   KC_J,                   KC_K,                   KC_L,                   LT(DEBUGGING_LAYER_SELECT, KC_DOT),
        LT(NUMS,KC_Z),     LT(MEDIA,KC_X),         KC_C,                   KC_V,                   KC_B,                   KC_N,                   KC_M,                   KC_COMM,                LT(MEDIA,KC_DOT),       KC_NUHS,
                                                                                XXXXXXX,                CAPS_ALT,               LT(WINDOWS,KC_DEL),     XXXXXXX,
        KC_LGUI,                MO(MOD),                ENTER_SHIFT,              CTRL_ESCAPE,            LT(DELETE,KC_BSPC),     LT(NAVIGATION,KC_SPC),  LT(TABS,KC_ENT),        LT(NUMS,KC_ESC)
),





[_MOD] = LAYOUT(
        KC_QUES,                S(KC_QUOT),             KC_NO,                  S(KC_2),                KC_NUBS,                S(KC_EQL),              S(KC_8),                KC_EQL,                 KC_MINS,                KC_PSLS,
        S(KC_1),                LT(TABS,KC_NUHS),       LT(NAVIGATION,KC_EQL),LT(UP_DOWN_NAVIGATION,KC_QUOT),KC_NUHS,           KC_F23,                 S(KC_9),                KC_LBRC,                S(KC_LBRC),             KC_NUBS,
        LT(FN_NUMS,S(KC_6)),  S(KC_4),                S(KC_5),                KC_GRV,                 S(KC_BSLS),             KC_F24,                 S(KC_0),                KC_RBRC,                S(KC_RBRC),             KC_TRNS,
                                                                                KC_TRNS,                KC_LGUI,                KC_TRNS,                KC_TRNS,
                                KC_TRNS,                KC_TRNS,                KC_TRNS,                LT(SHORTCUTS, KC_F22),  KC_TRNS,                LT(MOD_NAVIGATION,KC_NO),KC_F22,                MO(FN_NUMS)
),





[_MOD2] = LAYOUT(
        RALT(KC_1),             S(KC_QUOT),             XXXXXXX,                S(KC_2),                KC_NUBS,                S(KC_EQL),              S(KC_8),                KC_EQL,                 KC_MINS,                KC_PSLS,
        S(KC_1),                KC_NUHS,                KC_EQL,                 KC_QUOT,                KC_NUHS,                KC_F23,                 S(KC_9),                KC_LBRC,                S(KC_LBRC),             KC_COMM,
        S(KC_6),                S(KC_4),                S(KC_5),                KC_GRV,                 S(KC_BSLS),             KC_F24,                 S(KC_0),                KC_RBRC,                S(KC_RBRC),             _______,
                                                                                XXXXXXX,                KC_LGUI,                XXXXXXX,                XXXXXXX,
                                KC_LALT,                XXXXXXX,                KC_LSFT,                KC_LCTL,                LT(MOD_NAVIGATION,KC_F22),XXXXXXX,              C(KC_Y),                XXXXXXX
),





[_DELETE] = LAYOUT(
        XXXXXXX,                C(KC_NUHS),             C(KC_Z),                S(C(KC_Z)),             XXXXXXX,                XXXXXXX,                C(KC_Y),                KC_BSPC,                KC_DEL,                 C(KC_NUHS),
        XXXXXXX,                C(KC_Y),                KC_BSPC,                KC_DEL,                 XXXXXXX,                XXXXXXX,                KC_BSPC,                KC_DEL,                 C(KC_Y),                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                MEH(KC_F23),            MEH(KC_F24),            XXXXXXX,                C(KC_NUHS),
                                                                                _______,                _______,                _______,                _______,
                                _______,                _______,                _______,                _______,                _______,                _______,                _______,                _______
),





[_WINDOWS] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                G(KC_TAB),              C(G(KC_LEFT)),          C(G(KC_RGHT)),          XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                G(KC_LEFT),             G(KC_RIGHT),            XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                G(KC_UP),               G(KC_DOWN),             XXXXXXX,
                                                                                XXXXXXX,                MO(WINDOWS_NAVIGATION), XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                MO(WINDOWS_NAVIGATION), XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_SHORTCUTS] = LAYOUT(
        XXXXXXX,                XXXXXXX,                C(S(KC_W)),             LSA(KC_E),              S(KC_F6),               LCA(KC_T),              LCA(KC_F9),             XXXXXXX,                LSA(KC_I),              XXXXXXX,
        XXXXXXX,                C(S(KC_A)),             XXXXXXX,                XXXXXXX,                C(S(KC_F)),             C(KC_NUHS),             XXXXXXX,                XXXXXXX,                C(S(KC_J)),             XXXXXXX,
        XXXXXXX,                C(S(KC_Z)),             XXXXXXX,                XXXXXXX,                C(S(KC_V)),             C(S(KC_B)),             C(S(KC_N)),             XXXXXXX,                C(G(KC_LEFT)),          C(G(KC_RGHT)),
                                                                                XXXXXXX,                C(S(KC_ENT)),           XXXXXXX,                C(S(KC_SPC)),
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                C(S(KC_ENT)),           XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_NAVIGATION] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_DOWN),           LCA(KC_UP),             XXXXXXX,                C(S(KC_F8)),            G(KC_TAB),              C(KC_LBRC),             C(KC_RBRC),
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_LEFT),           LCA(KC_RGHT),           XXXXXXX,                KC_LEFT,                KC_RGHT,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                LCA(KC_F18),            LCA(KC_F19),            LCA(KC_F20),            LCA(KC_F21),            LCA(KC_F22),            XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                MO(MOD_NAVIGATION),     XXXXXXX,                XXXXXXX,                XXXXXXX,
                                _______,                _______,                _______,                _______,                _______,                _______,                _______,                XXXXXXX
),





[_UP_DOWN_NAVIGATION] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_DOWN),           LCA(KC_UP),             XXXXXXX,                C(S(KC_F8)),            G(KC_TAB),              C(KC_LBRC),             C(KC_RBRC),
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_LEFT),           LCA(KC_RGHT),           XXXXXXX,                KC_UP,                  KC_DOWN,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                LCA(KC_F18),            LCA(KC_F19),            LCA(KC_F20),            LCA(KC_F21),            LCA(KC_F22),            XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                MO(MOD_NAVIGATION),     XXXXXXX,                XXXXXXX,                XXXXXXX,
                                _______,                _______,                _______,                _______,                _______,                _______,                _______,                XXXXXXX
),





[_MOD_NAVIGATION] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_DOWN),           LCA(KC_UP),             XXXXXXX,                C(S(KC_F8)),            G(KC_TAB),              A(KC_UP),               A(KC_DOWN),
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_LEFT),           LCA(KC_RGHT),           XXXXXXX,                KC_HOME,                KC_END,                 XXXXXXX,                XXXXXXX,
        XXXXXXX,                LCA(KC_F18),            LCA(KC_F19),            LCA(KC_F20),            LCA(KC_F21),            LCA(KC_F22),            LCA(KC_F16),            LCA(KC_F17),            _______,                XXXXXXX,
                                                                                _______,                _______,                _______,                _______,
                                _______,                _______,                _______,                _______,                _______,                _______,                _______,                XXXXXXX
),





[_NUMS] = LAYOUT(
        XXXXXXX,                KC_7,                  KC_8,                  KC_9,                  KC_MINS,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                KC_4,                  KC_5,                  KC_6,                  KC_0,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
    XXXXXXX,                KC_1,                  KC_2,                  KC_3,                  KC_DOT,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                _______,                _______,                 LLOCK,                  XXXXXXX,
                                _______,                MO(FN_NUMS),                _______,                _______,                XXXXXXX,                KC_ENT,                 XXXXXXX,                XXXXXXX
),



[_FN_NUMS] = LAYOUT(
        XXXXXXX,                KC_F7,                  KC_F8,                  KC_F9,                  XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                KC_F4,                  KC_F5,                  KC_F6,                  XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                KC_F1,                  KC_F2,                  KC_F3,                  XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                _______,                _______,                 LLOCK,                  XXXXXXX,
                                _______,                _______,                _______,                _______,                XXXXXXX,                KC_ENT,                 XXXXXXX,                XXXXXXX
),





[_WINDOWS_NAVIGATION] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                LCAG(KC_1),             LCAG(KC_2),             LCAG(KC_3),             LCAG(KC_4),             LCAG(KC_5),             XXXXXXX,                LCAG(KC_6),             LCAG(KC_7),             LCAG(KC_8),
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                _______,                XXXXXXX,                LCAG(KC_9),             LCAG(KC_0),
                                                                                _______,                _______,                _______,                _______,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                _______,                _______,                _______,                XXXXXXX
),





[_TABS] = LAYOUT(
        A(KC_F18),              A(KC_F19),              A(KC_F20),              A(KC_F21),              A(KC_F22),              XXXXXXX,                XXXXXXX,                G(KC_TAB),              SALT_TAB,               ALT_TAB,
        KC_ENT,                XXXXXXX,                TAB_LEFT,               TAB_RIGHT,              XXXXXXX,                XXXXXXX,                TAB_LEFT,                TAB_RIGHT,                XXXXXXX,                KC_ENT,
        KC_ESC,             A(KC_F17),              A(KC_F16),              A(KC_F13),              A(KC_F14),              XXXXXXX,                XXXXXXX,                XXXXXXX,               XXXXXXX,                KC_ESC,
                                                                                _______,                LLOCK,                XXXXXXX,                XXXXXXX,
                        _______,                _______,                _______,                _______,                _______,                _______,                _______,                _______
),





[_DEBUGGING] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_STOP,                 PC_DEBUG_CHOOSE,  XXXXXXX,       PC_RUN_TO_CURSOR,       PC_QUICK_EVALUATE_EXPRESSION,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_PAUSE,                PC_DEBUG,        PC_RESUME_PROGRAM,      PC_FORCE_RUN_TO_CURSOR, PC_EVALUATE_EXPRESSION,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_STOP_BACKGROUND_PROCESSES,PC_DEBUG_CONTEXT,XXXXXXX,                XXXXXXX,                PC_SHOW_EXECUTION_POINT,
                                                                                XXXXXXX,                LLOCK,                  XXXXXXX,                  XXXXXXX,
                                XXXXXXX,                MO(_RUNNING),           XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_RUNNING] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_STOP,PC_RUN_CONTEXT,    XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_PAUSE,                PC_RUN,           PC_RESUME_PROGRAM,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_STOP_BACKGROUND_PROCESSES,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                LLOCK,                  XXXXXXX,                  XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_BREAKPOINTS] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                MEH(KC_F8),             S(KC_F7),               XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                KC_F7,                  C(KC_F8),               PC_EDIT_BREAKPOINT,     PC_MUTE_BREAKPOINTS,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                LLOCK,                  XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_STEPPING] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_FORCE_STEP_OVER,     PC_SMART_STEP_INTO,               XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_STEP_OUT,            PC_STEP_OVER,           PC_STEP_INTO,           XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_STEP_INTO_MY_CODE,            XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                LLOCK,                  XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_RUN_TO_CURSOR] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                LLOCK,                  XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_DEBUGGING_LAYER_SELECT] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                LLOCK,                  XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_REFACTOR] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                LLOCK,                  XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_MEDIA] = LAYOUT(
    KC_MUTE,                XXXXXXX,                KC_VOLD,                KC_VOLU,                XXXXXXX,                XXXXXXX,                XXXXXXX,              XXXXXXX,               XXXXXXX,                XXXXXXX,
    KC_MPLY,                XXXXXXX,                KC_MPRV,                KC_MNXT,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
    KC_MPLY,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                 XXXXXXX,                 XXXXXXX,                  XXXXXXX,
                                XXXXXXX,                XXXXXXX,                MO(KEYBOARD),                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_KEYBOARD] = LAYOUT(
    XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
    BL_TOGG,                BL_UP,                BL_DOWN,                BL_BRTG,                BL_UP,                  BL_DOWN,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
    XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                QK_MAKE,                QK_MAKE,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                QK_BOOT,                QK_BOOT,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_EMPTY] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),




    



            };