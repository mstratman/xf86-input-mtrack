/***************************************************************************
 *
 * Multitouch X driver
 * Copyright (C) 2008 Henrik Rydberg <rydberg@euromail.se>
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

#ifndef GESTURES_H
#define GESTURES_H

#include "common.h"
#include "mconfig.h"
#include "hwstate.h"
#include "mtstate.h"

#define GS_TAP 0
#define GS_BUTTON 1

#define GS_NONE 0
#define GS_MOVE 1
#define GS_SCROLL 2
#define GS_SWIPE 3
#define GS_SCALE 4
#define GS_ROTATE 5
#define GS_DRAG_READY 6
#define GS_DRAG_ACTIVE 7

struct Gestures {
	/* Taps, physical buttons, and gestures will trigger
	 * button events. If a bit is set, the button is down.
	 * If a bit is not set, the button is up.
	 * Bit 0 is button 1.
	 */
	bitmask_t buttons;

	/* Pointer movement is tracked here.
	 */
	int move_dx, move_dy;

	/* Internal state tracking. Not for direct access.
	 */
	int button_emulate;
	int button_delayed;
	mstime_t button_delayed_time;
	int button_delayed_ms;

	mstime_t tap_time_down;
	int tap_touching;
	int tap_released;
	int move_type;
	int move_dist;
	int move_dir;
	int move_drag;
	mstime_t move_wait;
	mstime_t move_drag_expire;
};


void gestures_init(struct Gestures* gs);
void gestures_extract(struct Gestures* gs,
			const struct MConfig* cfg,
			const struct HWState* hs,
			struct MTState* ms);
int gestures_delayed(struct Gestures* gs,
			struct mtdev* dev, int fd);

#endif

