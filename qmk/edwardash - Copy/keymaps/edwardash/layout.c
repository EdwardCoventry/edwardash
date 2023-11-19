// 
#include "keydefs.c"




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_DOT,
        KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
        XXXXXXX, KC_LALT, KC_DEL,  XXXXXXX,
        XXXXXXX, KC_LGUI,  KC_ENT,  KC_ESC, KC_BSPC, KC_SPC, XXXXXXX, KC_GRV
        ),



[_ABC] = LAYOUT(
        KC_Q,                   LT(BREAKPOINTS,KC_W),   LT(STEPPING,KC_H),      LT(DEBUGGING,KC_F),     KC_V,                   KC_K,                   KC_M,                   KC_D,                   KC_U,                   KC_Z,
        LT(DELETE,KC_A),        LT(TABS,KC_R),          LT(LEFT_RIGHT_NAVIGATION,KC_S),LT(SYMBOLS,KC_T),KC_X,                   KC_J,                   LT(TOOLS,KC_N),         LT(COPILOT,KC_E),     KC_I,                   LT(DEBUGGING_LAYER_SELECT, KC_O),
        LT(NUMS,KC_G),          LT(MEDIA,KC_P),         LT(COPILOT, KC_C),      LT(SYMBOLS_2,KC_L),                   KC_NO,                   KC_NO,                   LT(BOOKMARKS, KC_DOT),    KC_COMM,                LT(MEDIA,KC_B),       KC_Y,
                                                                                XXXXXXX,                KC_LALT,                LT(WINDOWS,KC_DEL),     XXXXXXX,
        XXXXXXX,                KC_LGUI,                ENTER_SHIFT,            CTRL_ESCAPE,            LT(DELETE,KC_BSPC),     KC_SPC,XXXXXXX,KC_GRV
        ),




[_SYMBOLS] = LAYOUT(
        KC_QUES,                S(KC_QUOT),             KC_NO,                  S(KC_2),                KC_NUBS,                KC_PPLS,                KC_PAST,                KC_EQL,                 KC_MINS,                KC_PSLS,
        S(KC_1),                LT(TABS,KC_NUHS),       LT(UP_DOWN_NAVIGATION,KC_EQL),MO(UP_DOWN_NAVIGATION),KC_NUHS,           KC_F23,                 S(KC_9),                KC_LBRC,                S(KC_LBRC),             KC_F23,
        LT(FN_NUMS,S(KC_6)),    S(KC_4),                S(KC_5),                KC_GRV,                 S(KC_BSLS),          KC_F24,                 KC_COLON,                KC_SEMICOLON,                S(KC_RBRC),             KC_QUOTE,
                                                                                KC_TRNS,                KC_LGUI,                KC_TRNS,                KC_TRNS,
                                XXXXXXX,                KC_TRNS,                 S(KC_ENT),                 XXXXXXX,  KC_TRNS,                LT(MOD_LEFT_RIGHT_NAVIGATION,KC_NO),KC_F22,     XXXXXXX
),





[_MOD] = LAYOUT(
        _______,                _______,                _______,                _______,                _______,                _______,                _______,                _______,                _______,                _______,
        _______,                MO(TABS),               TAB_LEFT,               TAB_RIGHT,              _______,                _______,                _______,                _______,                _______,                _______,
        _______,                _______,                _______,                _______,                _______,                _______,                _______,                _______,                _______,                _______,
                                                                                _______,                _______,                _______,                _______,
                                _______,                _______,                _______,                _______,                _______,                _______,                _______,                _______
),





[_SYMBOLS_2] = LAYOUT(
        KC_QUES,                S(KC_QUOT),             KC_NO,                  S(KC_2),                KC_NUBS,                KC_AMPR,                KC_CIRC,                KC_PIPE,                 KC_TILDE,                KC_NUBS,
        S(KC_1),                LT(TABS,KC_NUHS),       LT(UP_DOWN_NAVIGATION,KC_EQL),MO(UP_DOWN_NAVIGATION),KC_NUHS,           KC_F23,                 S(KC_0),                KC_RBRC,                S(KC_RBRC),             KC_F24,
        LT(FN_NUMS,S(KC_6)),    S(KC_4),                S(KC_5),                KC_GRV,                 S(KC_BSLS),             KC_F24,                 KC_EXCLAIM,                KC_QUESTION,               XXXXXXX,             KC_DOUBLE_QUOTE,
                                                                                KC_TRNS,                KC_LGUI,                KC_TRNS,                KC_TRNS,
                                XXXXXXX,                KC_TRNS,                KC_F22,                 LT(SHORTCUTS, KC_F22),  KC_TRNS,                LT(MOD_LEFT_RIGHT_NAVIGATION,KC_NO),KC_F22,     XXXXXXX
        ),






[_DELETE] = LAYOUT(
        XXXXXXX,                C(KC_NUHS),             C(KC_Z),                S(C(KC_Z)),             XXXXXXX,                XXXXXXX,                C(KC_Y),                KC_BSPC,                KC_DEL,                 C(KC_NUHS),
        XXXXXXX,                C(KC_Y),                KC_BSPC,                KC_DEL,                 XXXXXXX,                XXXXXXX,                KC_BSPC,                KC_DEL,                 C(KC_Y),                XXXXXXX,
        XXXXXXX,                C(KC_X),                C(KC_C),                C(KC_V),                XXXXXXX,                XXXXXXX,                MEH(KC_F23),            MEH(KC_F24),            XXXXXXX,                C(KC_NUHS),
                                                                                _______,                _______,                _______,                _______,
                                _______,                _______,                COPILOT_COMPLETE_IN_EDITOR,                _______,                _______,                _______,                _______,                _______
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





[_LEFT_RIGHT_NAVIGATION] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_DOWN),           LCA(KC_UP),             XXXXXXX,                KC_HOME,                KC_END,                 XXXXXXX,                XXXXXXX,
        KC_LEFT,                KC_RGHT,                XXXXXXX,                MO(UP_DOWN_NAVIGATION), XXXXXXX,                XXXXXXX,                KC_LEFT,                KC_RGHT,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                C(KC_LBRC),             C(KC_RBRC),             XXXXXXX,                XXXXXXX,
                                                                                MO(MOD_LEFT_RIGHT_NAVIGATION),KC_LALT,          XXXXXXX,                XXXXXXX,
        XXXXXXX,                MO(MOD_LEFT_RIGHT_NAVIGATION),A(KC_ENT),      CTRL_ESCAPE,            _______,                _______,                _______,                XXXXXXX
),





[_BOOKMARKS] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        LCA(KC_F18),            LCA(KC_F19),            LCA(KC_F20),            LCA(KC_F21),            LCA(KC_F22),            XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_UP_DOWN_NAVIGATION] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_DOWN),           LCA(KC_UP),             XXXXXXX,                KC_PGUP,                KC_PGDN,                C(KC_LBRC),             C(KC_RBRC),
        KC_UP,                  KC_DOWN,                XXXXXXX,                LCA(KC_LEFT),           LCA(KC_RGHT),           XXXXXXX,                KC_UP,                  KC_DOWN,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                LCA(KC_F18),            LCA(KC_F19),            LCA(KC_F20),            LCA(KC_F21),            LCA(KC_F22),            XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                MO(MOD_LEFT_RIGHT_NAVIGATION),KC_LALT,          XXXXXXX,                XXXXXXX,
                                XXXXXXX,                KC_LGUI,                ENTER_SHIFT,            CTRL_ESCAPE,            _______,                _______,                _______,                XXXXXXX
),





[_MOD_LEFT_RIGHT_NAVIGATION] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_DOWN),           LCA(KC_UP),             XXXXXXX,                C(S(KC_F8)),            G(KC_TAB),              A(KC_UP),               A(KC_DOWN),
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_LEFT),           LCA(KC_RGHT),           XXXXXXX,                KC_HOME,                KC_END,                 XXXXXXX,                XXXXXXX,
        XXXXXXX,                LCA(KC_F18),            LCA(KC_F19),            LCA(KC_F20),            LCA(KC_F21),            LCA(KC_F22),            LCA(KC_F16),            LCA(KC_F17),            _______,                XXXXXXX,
                                                                                _______,                _______,                _______,                _______,
                                _______,                _______,                _______,                _______,                _______,                _______,                _______,                XXXXXXX
),





[_MOD_UP_DOWN_NAVIGATION] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_DOWN),           LCA(KC_UP),             XXXXXXX,                C(S(KC_F8)),            G(KC_TAB),              A(KC_UP),               A(KC_DOWN),
        XXXXXXX,                XXXXXXX,                XXXXXXX,                LCA(KC_LEFT),           LCA(KC_RGHT),           XXXXXXX,                KC_HOME,                KC_END,                 XXXXXXX,                XXXXXXX,
        XXXXXXX,                LCA(KC_F18),            LCA(KC_F19),            LCA(KC_F20),            LCA(KC_F21),            LCA(KC_F22),            LCA(KC_F16),            LCA(KC_F17),            _______,                XXXXXXX,
                                                                                _______,                _______,                _______,                _______,
                                _______,                _______,                _______,                _______,                _______,                _______,                _______,                XXXXXXX
),





[_NUMS] = LAYOUT(
        XXXXXXX,                KC_7,                   KC_8,                   KC_9,                   KC_MINS,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                KC_4,                   KC_5,                   KC_6,                   KC_0,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                KC_1,                   KC_2,                   KC_3,                   KC_DOT,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                _______,                _______,                LLOCK,                  XXXXXXX,
                                MO(FN_NUMS),            _______,                MO(FN_NUMS),            _______,                XXXXXXX,                KC_ENT,                 XXXXXXX,                XXXXXXX
),





[_FN_NUMS] = LAYOUT(
        XXXXXXX,                KC_F7,                  KC_F8,                  KC_F9,                  XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                KC_F4,                  KC_F5,                  KC_F6,                  XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                KC_F1,                  KC_F2,                  KC_F3,                  XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                _______,                _______,                LLOCK,                  XXXXXXX,
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
        KC_ENT,                 XXXXXXX,                TAB_LEFT,               TAB_RIGHT,              XXXXXXX,                XXXXXXX,                TAB_LEFT,               TAB_RIGHT,              XXXXXXX,                KC_ENT,
        KC_ESC,                 A(KC_F17),              A(KC_F14),              A(KC_F13),              A(KC_F16),              XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                KC_ESC,
                                                                                _______,                LLOCK,
        XXXXXXX,                XXXXXXX,
                                MO(MOD),                _______,                _______,                _______,                _______,                _______,                _______,                _______
),





[_DEBUGGING] = LAYOUT(
        XXXXXXX,                XXXXXXX,                MO(PC_RUN_TO_CURSOR),                XXXXXXX,                XXXXXXX,                PC_STOP,                PC_DEBUG_CHOOSE,        XXXXXXX,                PC_RUN_TO_CURSOR,       PC_QUICK_EVALUATE_EXPRESSION,
        PC_FORCE_RUN_TO_CURSOR,               PC_FORCE_RUN_TO_CURSOR,               PC_RESUME_PROGRAM,      PC_DEBUG, PC_PAUSE, PC_PAUSE,               PC_DEBUG,               PC_RESUME_PROGRAM,      PC_FORCE_RUN_TO_CURSOR, PC_FORCE_RUN_TO_CURSOR,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_STOP_BACKGROUND_PROCESSES,PC_DEBUG_CONTEXT,  XXXXXXX,                XXXXXXX,                PC_SHOW_EXECUTION_POINT,
                                                                                XXXXXXX,                LLOCK,
        XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                MO(RUNNING),           XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_RUNNING] = LAYOUT(
        XXXXXXX,                XXXXXXX,                MO(PC_RUN_TO_CURSOR),   XXXXXXX,                PC_STOP,                PC_STOP,                PC_RUN_CONTEXT,         XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                PC_RESUME_PROGRAM,      PC_RUN,                 PC_PAUSE,               PC_PAUSE,               PC_RUN,                 PC_RESUME_PROGRAM,      XXXXXXX,                XXXXXXX,
        PC_STOP_BACKGROUND_PROCESSES,XXXXXXX,           XXXXXXX,                XXXXXXX,                PC_STOP_BACKGROUND_PROCESSES,PC_STOP_BACKGROUND_PROCESSES,XXXXXXX,      XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                LLOCK,
        XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_BREAKPOINTS] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_TOGGLE_TEMP_BREAKPOINT,XXXXXXX,              XXXXXXX,
        PC_MUTE_BREAKPOINTS,    PC_DISABLE_BREAKPOINT,  PC_TOGGLE_BREAKPOINT,   PC_EDIT_BREAKPOINT,     PC_MUTE_BREAKPOINTS,    XXXXXXX,                PC_EDIT_BREAKPOINT,     PC_TOGGLE_BREAKPOINT,   PC_DISABLE_BREAKPOINT,  PC_MUTE_BREAKPOINTS,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                LLOCK,
        XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_STEPPING] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                MO(PC_RUN_TO_CURSOR),   XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_FORCE_STEP_OVER,     PC_SMART_STEP_INTO,     XXXXXXX,
        XXXXXXX,                PC_STEP_INTO,           PC_STEP_OVER,           PC_STEP_OUT,            PC_STEP_OUT,            XXXXXXX,                PC_STEP_OUT,            PC_STEP_OVER,           PC_STEP_INTO,           XXXXXXX,
        XXXXXXX,                PC_STEP_INTO_MY_CODE,   XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_STEP_INTO_MY_CODE,   XXXXXXX,
                                                                                XXXXXXX,                LLOCK,
        XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_RUN_TO_CURSOR] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                PC_FORCE_RUN_TO_CURSOR, XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                PC_RUN_TO_CURSOR,       PC_JUMP_TO_CURSOR,      XXXXXXX,                XXXXXXX,                PC_JUMP_TO_CURSOR,      PC_RUN_TO_CURSOR,       XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                LLOCK,
        XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_DEBUGGING_LAYER_SELECT] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                LLOCK,
        XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_REFACTOR] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                LLOCK,
        XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_TOOLS] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                EASY_CLICK,             XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),




[_COPILOT] = LAYOUT(
    XXXXXXX,                XXXXXXX,                COPILOT_DISABLE,                COPILOT_DISABLE,           XXXXXXX,          XXXXXXX,                COPILOT_DISABLE,                XXXXXXX,                XXXXXXX,                XXXXXXX,
    COPILOT_PREV,             COPILOT_NEXT,             COPILOT_COMPLETE_IN_EDITOR,             COPILOT_COMPLETE_IN_EDITOR,                XXXXXXX,             XXXXXXX,                COPILOT_COMPLETE_IN_EDITOR,                XXXXXXX,                COPILOT_PREV,             COPILOT_NEXT,
    XXXXXXX,                XXXXXXX,                COPILOT_SHOW_COMPLETIONS,                COPILOT_SHOW_COMPLETIONS,                XXXXXXX,                XXXXXXX,                COPILOT_SHOW_COMPLETIONS,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
    XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
    ),





[_MEDIA] = LAYOUT(
        KC_MUTE,                XXXXXXX,                KC_VOLD,                KC_VOLU,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        KC_MPLY,                XXXXXXX,                KC_MPRV,                KC_MNXT,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        KC_MPLY,                XXXXXXX,                KC_MRWD,                KC_MFFD,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                                                                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
                                XXXXXXX,                XXXXXXX,                MO(KEYBOARD),           XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX
),





[_KEYBOARD] = LAYOUT(
        XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
        BL_TOGG,                BL_UP,                  BL_DOWN,                BL_BRTG,                BL_UP,
        BL_DOWN,                XXXXXXX,                XXXXXXX,                XXXXXXX,                XXXXXXX,
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