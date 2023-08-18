#pragma once
#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _MOD,
  _SHORTCUTS,
  _TABS,
  _DELETE,
  _NAVIGATION,
  _UP_DOWN_NAVIGATION,
  _WINDOWS,
  _NUMS,
  _DEBUGGING,
  _BREAKPOINTS,
  _STEPPING,
  _RUN_TO_CURSOR,
  _DEBUGGING_LAYER_SELECT,
  _REFACTOR,
  _MEDIA,

  _MOD_NAVIGATION,
  _MOD2,
  _FN_NUMS,
  _WINDOWS_NAVIGATION,
  _RUNNING,

  _EMPTY,
  _LAYER_A,
  _KEYBOARD,

};

enum custom_keycodes {

  QWERTY = SAFE_RANGE,
  MOD,
  SHORTCUTS,
  TABS,
  DELETE,
  NAVIGATION,
  UP_DOWN_NAVIGATION,
  WINDOWS,
  NUMS,
  FN_NUMS,
  DEBUGGING,
  BREAKPOINTS,
  STEPPING,
  RUN_TO_CURSOR,
  REFACTOR,
  MEDIA,

  MOD_NAVIGATION,
  MOD2,
  WINDOWS_NAVIGATION,
  RUNNING,
  DEBUGGING_LAYER_SELECT,

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



};// 


#define EISU LALT(KC_GRV)

//#define SHIFT_TAB_MOD LT(MOD, KC_SFTAB)
//#define TAB_SHIFT LSFT_T(KC_TAB)
//#define ENTER_SHIFT LSFT_T(KC_ENT)
//#define SHORTCUTS_WIN LT(SHORTCUTS, KC_LGUI)
#//define CTRL_ESCAPE LCTL_T(KC_ESC)
//#define ALT_WIN LALT_T(KC_LGUI)
//#define CAPS_ALT LALT_T(KC_CAPS)


