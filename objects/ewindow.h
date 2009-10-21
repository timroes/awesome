/*
 * ewindow.h - Extended window object header
 *
 * Copyright © 2009 Julien Danjou <julien@danjou.info>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef AWESOME_OBJECTS_EWINDOW_H
#define AWESOME_OBJECTS_EWINDOW_H

#include "strut.h"
#include "objects/window.h"
#include "objects/button.h"
#include "common/luaclass.h"

#define EWINDOW_OBJECT_HEADER \
    WINDOW_OBJECT_HEADER \
    /** Opacity */ \
    double opacity; \
    /** Strut */ \
    strut_t strut; \
    /** Border color */ \
    xcolor_t border_color; \
    /** Border width */ \
    uint16_t border_width; \
    /** Window tags */ \
    tag_array_t tags; \
    /** True if the window is sticky */ \
    bool sticky; \
    /** True if the client is minimized */ \
    bool minimized; \
    /** True if the client is fullscreen */ \
    bool fullscreen; \
    /** True if the client is maximized horizontally */ \
    bool maximized_horizontal; \
    /** True if the client is maximized vertically */ \
    bool maximized_vertical; \
    /** True if the client is above others */ \
    bool above; \
    /** True if the client is below others */ \
    bool below; \
    /** True if the client is modal */ \
    bool modal; \
    /** True if the client is on top */ \
    bool ontop; \
    /** Window it is transient for */ \
    ewindow_t *transient_for;

typedef struct ewindow_t ewindow_t;
/** Window structure */
struct ewindow_t
{
    EWINDOW_OBJECT_HEADER
};

lua_interface_window_t ewindow_class;

void ewindow_class_setup(lua_State *);

bool ewindow_isvisible(ewindow_t *);

void ewindow_set_opacity(lua_State *, int, double);
void ewindow_set_border_width(lua_State *, int, int);
void ewindow_set_sticky(lua_State *, int, bool);
void ewindow_set_above(lua_State *, int, bool);
void ewindow_set_below(lua_State *, int, bool);
void ewindow_set_modal(lua_State *, int, bool);
void ewindow_set_ontop(lua_State *, int, bool);
void ewindow_set_fullscreen(lua_State *, int, bool);
void ewindow_set_maximized_horizontal(lua_State *, int, bool);
void ewindow_set_maximized_vertical(lua_State *, int, bool);
void ewindow_set_minimized(lua_State *, int, bool);
void ewindow_set_transient_for(lua_State *, int, int);

int luaA_ewindow_get_transient_for(lua_State *, ewindow_t *);

DO_ARRAY(ewindow_t *, ewindow, DO_NOTHING)

#endif
// vim: filetype=c:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:encoding=utf-8:textwidth=80