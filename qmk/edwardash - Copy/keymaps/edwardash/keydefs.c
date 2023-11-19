#pragma once
#include QMK_KEYBOARD_H

enum layer_names {
  _ABC,
  _SYMBOLS,
  _SYMBOLS_2,
  _SHORTCUTS,
  _TABS,
  _DELETE,
  _LEFT_RIGHT_NAVIGATION,
  _UP_DOWN_NAVIGATION,
  _BOOKMARKS,
  _NUMS,
  _DEBUGGING,
  _STEPPING,
  _BREAKPOINTS,
  _REFACTOR,
  _COPILOT,
  _MEDIA,

  _QWERTY,

  _MOD_LEFT_RIGHT_NAVIGATION,
  _MOD_UP_DOWN_NAVIGATION,
  _MOD,
  _WINDOWS_NAVIGATION,
  _DEBUGGING_LAYER_SELECT,
  _WINDOWS,
  _FN_NUMS,
  _RUNNING,
  _RUN_TO_CURSOR,
  _TOOLS,


  _EMPTY,
  _LAYER_A,
  _KEYBOARD,

};

enum custom_keycodes {

  ABC = SAFE_RANGE,
  SYMBOLS,
  SYMBOLS_2,
  SHORTCUTS,
  TABS,
  DELETE,
  LEFT_RIGHT_NAVIGATION,
  UP_DOWN_NAVIGATION,
  BOOKMARKS,
  NUMS,
  DEBUGGING,
  STEPPING,
  BREAKPOINTS,
  REFACTOR,
  COPILOT,
  MEDIA,

  QWERTY,

  MOD_LEFT_RIGHT_NAVIGATION,
  MOD_UP_DOWN_NAVIGATION,
  MOD,
  WINDOWS_NAVIGATION,
  DEBUGGING_LAYER_SELECT,
  WINDOWS,
  FN_NUMS,
  RUN_TO_CURSOR,
  TOOLS,
  RUNNING,






  EMPTY,
  LAYER_A,
  KEYBOARD,

  TAB_LEFT,
  TAB_RIGHT,
  SHIFT_TAB_MOD,
  ALT_TAB,
  SALT_TAB,
  CTL_TAB,
  SCTL_TAB,
  DESKTOP_LEFT,
  DESKTOP_RIGHT,
  LLOCK,


  TAB_SHIFT,
  ENTER_SHIFT,
  SHORTCUTS_WIN,
  CTRL_ESCAPE,
  ALT_WIN,
  CAPS_ALT,
  WIN_SPACE,



};// 


#define EISU LALT(KC_GRV)

//#define SHIFT_TAB_MOD LT(MOD, KC_SFTAB)
//#define TAB_SHIFT LSFT_T(KC_TAB)
//#define ENTER_SHIFT LSFT_T(KC_ENT)
//#define SHORTCUTS_WIN LT(SHORTCUTS, KC_LGUI)
//define CTRL_ESCAPE LCTL_T(KC_ESC)
//#define ALT_WIN LALT_T(KC_LGUI)
//#define CAPS_ALT LALT_T(KC_CAPS)



