#include "ergodox.h"
#include "led.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"

#define BASE   0 // default layer
#define FN     1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/******* Base Layer ****************************************************************************************************
 *
 * ,------------------------------------------------------.       ,------------------------------------------------------.
 * | `          |   1  |   2  |   3  |   4  |   5  | =    |       |  ]   |   6  |   7  |   8  |   9  |   0  |     -      |
 * |------------+------+------+------+------+-------------|       |------+------+------+------+------+------+------------|
 * | Escape     |   Q  |   W  |   E  |   R  |   T  | Tab  |       |BackSp|   Y  |   U  |   I  |   O  |   P  |     [      |
 * |------------+------+------+------+------+------|      |       |      |------+------+------+------+------+------------|
 * | Caps (Mod3)|   A  |   S  |   D  |   F  |   G  |------|       |------|   H  |   J  |   K  |   L  |  ;   |     \      |
 * |------------+------+------+------+------+------| Ins  |       | Del  |------+------+------+------+------+------------|
 * |  Shift     |   Z  |   X  |   C  |   V  |   B  |      |       |      |   N  |   M  |   ,  |   .  |  /   |   OSL(FN)  |
 * `------------+------+------+------+------+-------------'       `-------------+------+------+------+------+------------'
 *      |       |      | Alt  | Ctrl | Win  |                                   | Mod3 | Alt  | Ctrl |      |       |
 *      `-----------------------------------'                                   `-----------------------------------'
 *                                          ,-------------.       ,-------------.
 *                                          | Left | Right|       | Home | End  |
 *                                   ,------|------|------|       |------+------+------.
 *                                   | Space| AltGr|  Up  |       | PgUp |      | Ret  |
 *                                   |      |(Mod4)|------|       |------| Mod4 |      |
 *                                   |      |      | Down |       | PgDn |      |      |
 *                                   `--------------------'       `--------------------'
 */
[BASE] = KEYMAP(
// left hand
 KC_GRV    ,KC_1   ,KC_2   ,KC_3   ,KC_4  ,KC_5  ,KC_EQL
,KC_ESC    ,KC_Q   ,KC_W   ,KC_E   ,KC_R  ,KC_T  ,KC_TAB
,KC_CAPS   ,KC_A   ,KC_S   ,KC_D   ,KC_F  ,KC_G
,KC_LSFT   ,KC_Z   ,KC_X   ,KC_C   ,KC_V  ,KC_B  ,KC_INS
,KC_NO     ,KC_NO  ,KC_LALT,KC_LCTL,KC_LGUI
                                         ,KC_LEFT,KC_RGHT
                                                 ,KC_UP
                                 ,KC_SPC ,KC_RALT,KC_DOWN
                                                                  // right hand
                                                                 ,KC_RBRC ,KC_6   ,KC_7   ,KC_8   ,KC_9    ,KC_0     ,KC_MINS
                                                                 ,KC_BSPC ,KC_Y   ,KC_U   ,KC_I   ,KC_O    ,KC_P     ,KC_LBRC
                                                                          ,KC_H   ,KC_J   ,KC_K   ,KC_L    ,KC_SCLN  ,KC_QUOT
                                                                 ,KC_DEL  ,KC_N   ,KC_M   ,KC_COMM,KC_DOT  ,KC_SLSH  ,OSL(FN)
                                                                                  ,KC_CAPS,KC_LALT,KC_RCTL ,KC_NO    ,KC_NO
                                                                 ,KC_HOME ,KC_END
                                                                 ,KC_PGUP
                                                                 ,KC_PGDN ,KC_RALT,KC_ENT
    ),

/******* Fn Layer ******************************************************************************************************
 *
 * ,-----------------------------------------------------.       ,-----------------------------------------------------.
 * |           |  F1  |  F2  |  F3  |  F4  |  F5  |      |       |      |  F6  |  F7  |  F8  |  F9  |  F10 |           |
 * |-----------+------+------+------+------+-------------|       |------+------+------+------+------+------+-----------|
 * |           |  F11 |  F12 |      |      |      |      |       |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+------|      |       |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |------|       |------|      |      |      |      |      |           |
 * |-----------+------+------+------+------+------|      |       |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |       |      |      |      |      |      |      |           |
 * `-----------+------+------+------+------+-------------'       `-------------+------+------+------+------+-----------'
 *     |       |      |      |      |      |                                   |      |      |      |      |       |
 *     `-----------------------------------'                                   `-----------------------------------'
 *                                          -------------.        -------------.
 *                                         |      |      |       |      |      |
 *                                   ------|------|------|       |------+------+------.
 *                                  |      |      |      |       |      |      |      |
 *                                  |      |      |------|       |------|      |      |
 *                                  |      |      |      |       |      |      |      |
 *                                  `--------------------'       `--------------------'
 */
[FN] = KEYMAP(
// left hand
 KC_TRNS ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_TRNS
,KC_TRNS ,KC_F11  ,KC_F12  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                             ,KC_TRNS ,KC_TRNS
                                                      ,KC_TRNS
                                    ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                                 // right hand
                                                                 ,KC_TRNS ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_TRNS
                                                                 ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                                          ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                                 ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                                                   ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                                 ,KC_TRNS ,KC_TRNS
                                                                 ,KC_TRNS
                                                                 ,KC_TRNS ,KC_TRNS ,KC_TRNS
),

/******* Media Layer *******************************************************************************************************
 *
 * ,---------------------------------------------------------------.    ,---------------------------------------------------------------.
 * |      |   F11   |   F12   |   F13   |   F14   |   F15   | Esc  |    |      |   F16   |   F17   |   F18   |   F19   |   F20   |      |
 * |------+---------+---------+---------+---------+----------------|    |------+---------+---------+---------+---------+---------+------|
 * |      |Shut Down|MouseUpLf|Mouse Up |MouseUpRg|Volume Up|Scroll|    |Scroll|PrintScrn|   Home  |    Up   |   PgUp  |   Mail  |      |
 * |------+---------+---------+---------+---------+---------|  Up  |    |  Up  |---------+---------+---------+---------+---------+------|
 * |      |  Sleep  |MouseLeft|MouseDown|MouseRght|Volume Dn|------|    |------| Num Lock|   Left  |   Down  |   Right | MyComp  |      |
 * |------+---------+---------+---------+---------+---------|Scroll|    |Scroll|---------+---------+---------+---------+---------+------|
 * |      |         |MouseDnLf|MouseDown|MouseDnRg|  Mute   | Down |    | Down |         |   End   |   Down  |   PgDn  |         |      |
 * `------+---------+---------+---------+---------+----------------'    `----------------+---------+---------+---------+---------+------'
 *  |LCtrl|   Meh   |  MClick | LClick  |  R Click|                                      |Cmd/Insrt|Optn/Del | Hyper   |  Meh    |RCtrl|
 *  `---------------------------------------------'                                      `---------------------------------------------'
 *                                                   ,-------------.    ,-------------.
 *                                                   | Stop |Refrsh|    | Prev | Next |
 *                                            ,------|------|------|    |------+------+------.
 *                                            |Brwser|Brwser|Search|    |VolUp |      |      |
 *                                            |Back  | Fwd  |------|    |------| Stop | Play-|
 *                                            |      |      | Home |    |VolDn |      | Pause|
 *                                            `--------------------'    `--------------------'
[FN] = KEYMAP(
// left hand
 KC_TRNS ,KC_F11   ,KC_F12  ,KC_F13   ,KC_F14  ,KC_F15  ,KC_ESC
,KC_TRNS ,KC_POWER ,M(MUL)  ,KC_MS_U  ,M(MUR)  ,KC_VOLU ,KC_WH_U
,KC_TRNS ,KC_SLEP  ,KC_MS_L ,KC_MS_D  ,KC_MS_R ,KC_VOLD
,KC_TRNS ,KC_NO    ,M(MDL)  ,KC_MS_D  ,M(MDR)  ,KC_MUTE ,KC_WH_D
,KC_LCTL ,KC_MEH   ,KC_BTN3 ,KC_BTN1  ,KC_BTN2
                                               ,KC_WSTP ,KC_WREF
                                                        ,KC_WSCH
                                      ,KC_WBAK ,KC_NO   ,KC_WHOM
                                                                     // right hand
                                                                     ,KC_NO    ,KC_F16  ,KC_F17       ,KC_F18       ,KC_F19  ,KC_F20  ,KC_TRNS
                                                                     ,KC_WH_U  ,KC_PSCR ,KC_HOME      ,KC_UP        ,KC_PGUP ,KC_MAIL ,KC_TRNS
                                                                               ,KC_NLCK ,KC_LEFT      ,KC_DOWN      ,KC_RIGHT,KC_MYCM ,KC_TRNS
                                                                     ,KC_WH_D  ,KC_NO   ,KC_END       ,KC_DOWN      ,KC_PGDN ,KC_NO   ,KC_TRNS
                                                                                        ,GUI_T(KC_INS),ALT_T(KC_DEL),KC_HYPR ,KC_MEH  ,KC_RCTL
                                                                     ,KC_MPRV  ,KC_MNXT
                                                                     ,KC_VOLU
                                                                     ,KC_VOLD  ,KC_MSTP ,KC_MPLY
),
*/

};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};
