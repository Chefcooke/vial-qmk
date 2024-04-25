/* Copyright 2021 Shulin Huang <mumu@x-bows.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

 #ifdef RGB_MATRIX_ENABLE
const is31fl3731_led_t PROGMEM g_is31fl3731_leds[IS31FL3731_LED_COUNT] = {

    {0, C3_3, C2_3, C1_3},  // L01
    {0, C3_4, C2_4, C1_4},  // L02
    {0, C3_5, C2_5, C1_5},  // L03
    {0, C3_6, C2_6, C1_6},  // L04
    {0, C3_7, C2_7, C1_7},  // L05
    {0, C3_8, C2_8, C1_8},  // L06
    {1, C3_3, C2_3, C1_3},  // L07
    {1, C3_4, C2_4, C1_4},  // L08
    {1, C3_5, C2_5, C1_5},  // L09
    {1, C3_6, C2_6, C1_6},  // L10
    {1, C3_7, C2_7, C1_7},  // L11
    {1, C3_8, C2_8, C1_8},  // L12
    {2, C3_4, C2_4, C1_4},  // L13
    {2, C3_5, C2_5, C1_5},  // L14
    {2, C3_6, C2_6, C1_6},  // L15
    {2, C3_7, C2_7, C1_7},  // L16

    {0, C6_1, C5_1, C4_1},  // L17
    {0, C6_2, C5_2, C4_2},  // L18
    {0, C6_3, C5_3, C4_3},  // L19
    {0, C6_6, C5_6, C4_6},  // L20
    {0, C6_7, C5_7, C4_7},  // L21
    {0, C6_8, C5_8, C4_8},  // L22
    {1, C6_1, C5_1, C4_1},  // L23
    {1, C6_2, C5_2, C4_2},  // L24
    {1, C6_3, C5_3, C4_3},  // L25
    {1, C6_6, C5_6, C4_6},  // L26
    {1, C6_7, C5_7, C4_7},  // L27
    {1, C6_8, C5_8, C4_8},  // L28
    {2, C6_1, C5_1, C4_1},  // L29
    {2, C6_3, C5_3, C4_3},  // L31
    {2, C6_6, C5_6, C4_6},  // L32
    {2, C6_7, C5_7, C4_7},  // L33

    {0, C9_1, C8_1, C7_1},  // L34
    {0, C9_2, C8_2, C7_2},  // L35
    {0, C9_3, C8_3, C7_3},  // L36
    {0, C9_4, C8_4, C7_4},  // L37
    {0, C9_5, C8_5, C7_5},  // L38
    {0, C9_6, C8_6, C7_6},  // L39
    {1, C9_1, C8_1, C7_1},  // L40
    {1, C9_2, C8_2, C7_2},  // L41
    {1, C9_3, C8_3, C7_3},  // L42
    {1, C9_4, C8_4, C7_4},  // L43
    {1, C9_5, C8_5, C7_5},  // L44
    {1, C9_6, C8_6, C7_6},  // L45
    {2, C9_1, C8_1, C7_1},  // L46
    {2, C9_3, C8_3, C7_3},  // L48
    {2, C9_4, C8_4, C7_4},  // L49
    {2, C9_6, C8_6, C7_6},  // L50

    {0, C3_11, C2_11, C1_11},  // L51
    {0, C3_12, C2_12, C1_12},  // L52
    {0, C3_13, C2_13, C1_13},  // L53
    {0, C3_14, C2_14, C1_14},  // L54
    {0, C3_15, C2_15, C1_15},  // L55
    {0, C3_16, C2_16, C1_16},  // L56
    {1, C3_11, C2_11, C1_11},  // L57
    {1, C3_12, C2_12, C1_12},  // L58
    {1, C3_13, C2_13, C1_13},  // L59
    {1, C3_14, C2_14, C1_14},  // L60
    {1, C3_15, C2_15, C1_15},  // L61
    {1, C3_16, C2_16, C1_16},  // L62
    {2, C3_14, C2_14, C1_14},  // L63
    {2, C6_2, C5_2, C4_2},     // L30

    {0, C6_9, C5_9, C4_9},     // L64
    {0, C6_10, C5_10, C4_10},  // L65
    {0, C6_11, C5_11, C4_11},  // L66
    {0, C6_14, C5_14, C4_14},  // L67
    {0, C6_15, C5_15, C4_15},  // L68
    {0, C6_16, C5_16, C4_16},  // L69
    {1, C6_10, C5_10, C4_10},  // L70
    {1, C6_11, C5_11, C4_11},  // L71
    {1, C6_14, C5_14, C4_14},  // L72
    {1, C6_15, C5_15, C4_15},  // L73
    {1, C6_16, C5_16, C4_16},  // L74
    {2, C3_15, C2_15, C1_15},  // L75
    {2, C9_2, C8_2, C7_2},     // L47
    {2, C9_14, C8_14, C7_14},  // L76

    {0, C9_9, C8_9, C7_9},     // L77
    {0, C9_10, C8_10, C7_10},  // L78
    {0, C9_11, C8_11, C7_11},  // L79
    {1, C6_9, C5_9, C4_9},     // L80
    {1, C9_13, C8_13, C7_13},  // L81
    {1, C9_14, C8_14, C7_14},  // L82
    {2, C9_9, C8_9, C7_9},     // L83
    {2, C9_10, C8_10, C7_10},  // L84
    {2, C9_11, C8_11, C7_11},  // L85
    {2, C9_12, C8_12, C7_12},  // L86
    {2, C9_13, C8_13, C7_13},  // L87
};

// clang-format off
led_config_t g_led_config = { {
        {  0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13,     14,     15      },
        {  16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29,     30,     31      },
        {  32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     44,     45,     46,     47      },
        {  48,     49,     50,     51,     52,     53,     54,     55,     56,     57,     58,     59,     60,     61,   NO_LED,   NO_LED  },
        {  62,     63,     64,     65,     66,     67,     68,     69,     70,     71,     72,   NO_LED,   73,     74,     75,     NO_LED },
        {  76,     77,     78,   NO_LED, NO_LED,   79,   NO_LED, NO_LED, NO_LED,   80,     81,     82,     83,     84,     85,     86     }
    }, {
        {0,0},  {24,0},  {36,0},  {48,0},  {60,0},  {78,0},  {90,0},   {102,0},  {114,0},  {132,0},  {144,0},  {156,0},  {168,0},  {182,0},  {194,0}, {206,0},
        {0,15}, {12,15}, {24,15}, {36,15}, {48,15}, {60,15}, {72,15},  {84,15},  {96,15},  {108,15}, {120,15}, {132,15}, {144,15}, {182,15}, {194,15},{206,15},
        {3,27}, {18,27}, {30,27}, {42,27}, {54,27}, {66,27}, {78,27},  {90,27},  {102,27}, {114,27}, {126,27}, {138,27}, {150,27}, {182,27}, {194,27},{206,27},
        {4,39}, {20,39}, {32,39}, {44,39}, {56,39}, {68,39}, {80,39},  {92,39},  {104,39}, {116,39}, {128,39}, {140,39}, {162,39}, {162,15},
        {6,51}, {26,51}, {38,51}, {50,51}, {62,51}, {74,51}, {86,51},  {98,51},  {110,51}, {122,51}, {134,51}, {155,51}, {165,27}, {210,51},
        {1,63}, {16,63}, {31,63}, {64,63}, {121,63},{136,63}, {151,63}, {166,63},{182,63}, {194,63}, {206,63}
    }, {
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4, 4,
        4, 4, 4,       4,          4, 4, 4, 4, 4, 4, 4
    }
};
// clang-format on

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(48, 0xFF, 0xFF, 0xFF);
    }
    return true;
}

#endif
