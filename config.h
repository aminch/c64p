// Copyright 2023 retromin (@aminch)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Can't find this in the info.json
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_SHOULD_TRIGGER

// Only way to support legacy PCB pinout and current while keeping shared files
#ifdef LEGACY_PINOUT
    #define MATRIX_ROW_PINS { GP8,  GP9,  GP10, GP11, GP12, GP13, GP14, GP15, GP6 }
    #define MATRIX_COL_PINS { GP26, GP22, GP21, GP20, GP16, GP17, GP18, GP19, GP5 }
#else // current pinout
    // Pinout introduced to support both Pi Pico and RP2040 from same build
    #define MATRIX_ROW_PINS { GP10, GP9, GP8, GP7, GP6, GP5, GP4, GP3, GP1 }
    #define MATRIX_COL_PINS { GP28, GP27, GP26, GP15, GP14, GP13, GP12, GP11, GP0 }
#endif

#define MATRIX_HAS_GHOST   true

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
