/***************************************************************************
 *
 * Multitouch X driver
 * Copyright (C) 2011 Ryan Bourgeois <bluedragonx@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 **************************************************************************/

#ifndef MCONFIG_H
#define MCONFIG_H

#include "capabilities.h"

#define DEFAULT_TOUCH_DOWN 5
#define DEFAULT_TOUCH_UP 5
#define DEFAULT_IGNORE_THUMB 1
#define DEFAULT_IGNORE_PALM 1
#define DEFAULT_DISABLE_ON_THUMB 0
#define DEFAULT_DISABLE_ON_PALM 1
#define DEFAULT_THUMB_RATIO 70
#define DEFAULT_THUMB_SIZE 25
#define DEFAULT_PALM_SIZE 40
#define DEFAULT_BUTTON_ENABLE 1
#define DEFAULT_BUTTON_INTEGRATED 1
#define DEFAULT_BUTTON_1TOUCH 3
#define DEFAULT_BUTTON_2TOUCH 2
#define DEFAULT_TAP_1TOUCH 1
#define DEFAULT_TAP_2TOUCH 3
#define DEFAULT_TAP_3TOUCH 2
#define DEFAULT_TAP_TIMEOUT 120
#define DEFAULT_TAP_HOLD 100
#define DEFAULT_TAP_DIST 400
#define DEFAULT_GESTURE_HOLD 10
#define DEFAULT_GESTURE_WAIT 100
#define DEFAULT_SCROLL_DIST 400
#define DEFAULT_SCROLL_UP_BTN 4
#define DEFAULT_SCROLL_DN_BTN 5
#define DEFAULT_SCROLL_LT_BTN 6
#define DEFAULT_SCROLL_RT_BTN 7
#define DEFAULT_SWIPE_DIST 700
#define DEFAULT_SWIPE_UP_BTN 8
#define DEFAULT_SWIPE_DN_BTN 9
#define DEFAULT_SWIPE_LT_BTN 10
#define DEFAULT_SWIPE_RT_BTN 11
#define DEFAULT_SCALE_DIST 150
#define DEFAULT_SCALE_UP_BTN 12
#define DEFAULT_SCALE_DN_BTN 13
#define DEFAULT_ROTATE_DIST 150
#define DEFAULT_ROTATE_LT_BTN 14
#define DEFAULT_ROTATE_RT_BTN 15
#define DEFAULT_DRAG_ENABLE 1
#define DEFAULT_DRAG_TIMEOUT 200

#define MCFG_NONE 0
#define MCFG_SCALE 1
#define MCFG_SIZE 2
#define MCFG_PRESSURE 3

struct MConfig {
	/* Used by MTState */

	// Set by caps.
	int touch_type;		// How to determine touch? 0 for none, 1 for scale, 2 for size, 3 for pressure
	int touch_minor;	// Does the touchpad report touches as ellipses? 0 or 1
	int touch_min;		// Minimum touch value.
	int touch_max;		// Maximum touch value.
	int pad_width;		// Width of the touchpad.
	int pad_height;		// Height of the touchpad.

	// Set by config.
	int touch_down;		// When is a finger touching? 0 - 100 (percentage)
	int touch_up;		// When is a finger released? 0 - 100 (percentage)
	int ignore_thumb;	// Whether or not to ignore thumbs. 0 or 1
	int ignore_palm;	// Whether or not to ignore palms. 0 or 1
	int disable_on_thumb;	// Disable the touchpad if thumb detected. 0 or 1
	int disable_on_palm;	// Disable the touchpad if palm detected. 0 or 1
	int thumb_ratio;	// Ratio of width to length that makes a touch a thumb. 0 - 100
	int thumb_size;		// Minimum touch size for a thumb. 0 - 100
	int palm_size;		// Minimum touch size for a palm. 0 - 100

	/* Used by Gestures */

	// Set by config.
	int button_enable;		// Enable physical buttons? 0 or 1
	int button_integrated;	// Is the button under the touchpad? 0 or 1
	int button_1touch;		// What button to emulate when one (extra) finger is on the pad? 0, 1, 2, or 3
	int button_2touch;		// What button to emulate when two (extra) fingers are on the pad? 0, 1, 2, or 3
	int tap_1touch;			// What button to emulate for one touch taps? 0, 1, 2, or 3
	int tap_2touch;			// What button to emulate for two touch taps? 0, 1, 2, or 3
	int tap_3touch;			// What button to emulate for three touch taps? 0, 1, 2, or 3
	int tap_timeout;		// Window for touches when counting for the button. > 0
	int tap_hold;			// How long to "hold down" the emulated button on tap. > 0
	int tap_dist;			// How far to allow a touch to move before it's a moving touch. > 0
	int gesture_hold;		// How long to "hold down" the emulated button for gestures. > 0
	int gesture_wait;		// How long after a gesture to wait before movement is allowed. >= 0
	int scroll_dist;		// Distance needed to trigger a button. >= 0, 0 disables
	int scroll_up_btn;		// Button to use for scroll up. >= 0, 0 is none
	int scroll_dn_btn;		// Button to use for scroll down. >= 0, 0 is none
	int scroll_lt_btn;		// Button to use for scroll left. >= 0, 0 is none
	int scroll_rt_btn;		// Button to use for scroll right. >= 0, 0 is none
	int swipe_dist;			// Distance needed to trigger a button. >= 0, 0 disables
	int swipe_up_btn;		// Button to use for swipe up. >= 0, 0 is none
	int swipe_dn_btn;		// Button to use for swipe down. >= 0, 0 is none
	int swipe_lt_btn;		// Button to use for swipe left. >= 0, 0 is none
	int swipe_rt_btn;		// Button to use for swipe right. >= 0, 0 is none
	int scale_dist;			// Distance needed to trigger a button. >= 0, 0 disables
	int scale_up_btn;		// Button to use for scale up. >= 0, 0 is none
	int scale_dn_btn;		// Button to use for scale down. >= 0, 0 is none
	int rotate_dist;		// Distance needed to trigger a button. >= 0, 0 disables
	int rotate_lt_btn;		// Button to use for rotate left. >= 0, 0 is none
	int rotate_rt_btn;		// Button to use for rotate right. >= 0, 0 is none
	int drag_enable;		// Enable tap-to-drag? 0 or 1
	int drag_timeout;		// How long to wait for a move after tapping? > 0
};

/* Load the MConfig struct with its defaults.
 */
void mconfig_defaults(struct MConfig* cfg);

/* Initialize the MConfig struct.
 */
void mconfig_init(struct MConfig* cfg,
			const struct Capabilities* caps);

void mconfig_configure(struct MConfig* cfg,
			pointer opts);

#endif

