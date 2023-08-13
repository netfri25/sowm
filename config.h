#ifndef CONFIG_H
#define CONFIG_H

#include <X11/Xlib.h>
#include <X11/XF86keysym.h>
#include <X11/keysym.h>
#include <X11/XKBlib.h>

#include "sowm.h"

#define MOD Mod4Mask

#define WORKSPACE_COUNT 10
#define CENTER_FIX 3

#define BORDER_WIDTH 3
#define BORDER_NORMAL "#7a8478"
#define BORDER_SELECT "#d3c6aa"


const unsigned int gappx          = 10;       /* gap pixel */
float splitrat                    = 0.6;     /* split ratio */

#define SAVE_SCREENSHOT "tee $HOME/Pictures/Screenshots/$(date +'Screenshot-from-%Y-%m-%d-%H-%M-%S').png | xclip -selection clipboard -t image/png"

const char* sel_scrot[] = {"maim -s | " SAVE_SCREENSHOT};
const char*     scrot[] = {"maim | "    SAVE_SCREENSHOT};

const char* menu[]    = {"rofi", "-show", "drun", "-theme", "gruvbox-dark", 0};
const char* term[]    = {"alacritty", 0};
const char* briup[]   = {"brightnessctl", "set", "2%+", "-n", 0};
const char* bridown[] = {"brightnessctl", "set", "2%-", "-n", 0};
const char* voldown[] = {"amixer", "sset", "Master", "5%-",         0};
const char* volup[]   = {"amixer", "sset", "Master", "5%+",         0};
const char* volmute[] = {"amixer", "sset", "Master", "toggle",      0};
const char* colors[]  = {"bud", "/home/goldie/Pictures/Wallpapers", 0};

const char* browser[] = {"firefox", 0};

const char* media_toggle[] = {"playerctl", "play-pause", 0};
const char* media_prev[]   = {"playerctl", "previous",   0};
const char* media_next[]   = {"playerctl", "next",       0};

struct key keys[] = {
    {MOD,      XK_q,   win_kill,   {0}},
    {MOD,      XK_c,   win_center, {0}},
    {MOD,      XK_f,   win_fs,     {0}},

    {Mod1Mask,           XK_Tab, win_next,   {0}},
    {Mod1Mask|ShiftMask, XK_Tab, win_prev,   {0}},
    {MOD,                XK_m, win_maximize,    {0}},
    {MOD,                XK_k, win_snap,        {.i = 1}},
    {MOD,                XK_l, win_snap,        {.i = 2}},
    {MOD,                XK_j, win_snap,        {.i = 3}},
    {MOD,                XK_h, win_snap,        {.i = 4}},
    {MOD|ShiftMask,      XK_i, modify_splitr,   {.i = 1}},
    {MOD,                XK_i, modify_splitr,   {.i = 2}},


    // additional apps
    {MOD, XK_b, run, {.com = browser}},

    // screenshot
    {0,         XK_Print,  run_raw, {.com = sel_scrot}},
    {ShiftMask, XK_Print,  run_raw, {.com =     scrot}},

    {MOD, XK_s,      run, {.com = menu}},
    // {MOD, XK_w,      run, {.com = colors}},
    {MOD, XK_Return, run, {.com = term}},

    // volume controls
    {0,   XF86XK_AudioRaiseVolume,  run, {.com = volup}},
    {0,   XF86XK_AudioLowerVolume,  run, {.com = voldown}},
    {0,   XF86XK_AudioMute,         run, {.com = volmute}},

    // additional volume controls
    {MOD, XK_F2, run, {.com = volup}},
    {MOD, XK_F1, run, {.com = voldown}},

    // media controls
    {Mod1Mask, XK_F1, run, {.com = media_toggle}},
    {Mod1Mask, XK_F2, run, {.com = media_prev}},
    {Mod1Mask, XK_F3, run, {.com = media_next}},

    // brightness controls
    {0,   XF86XK_MonBrightnessUp,   run, {.com = briup}},
    {0,   XF86XK_MonBrightnessDown, run, {.com = bridown}},

    // additional brightness controls
    {MOD, XK_F4, run, {.com = briup}},
    {MOD, XK_F3, run, {.com = bridown}},

    // workspace switching
    {MOD, XK_a, ws_prev, {0}},
    {MOD|ShiftMask, XK_a, win_to_prev_ws, {0}},

    {MOD, XK_d, ws_next, {0}},
    {MOD|ShiftMask, XK_d, win_to_next_ws, {0}},

    {MOD,           XK_1, ws_go,     {.i = 1}},
    {MOD|ShiftMask, XK_1, win_to_ws, {.i = 1}},

    {MOD,           XK_2, ws_go,     {.i = 2}},
    {MOD|ShiftMask, XK_2, win_to_ws, {.i = 2}},

    {MOD,           XK_3, ws_go,     {.i = 3}},
    {MOD|ShiftMask, XK_3, win_to_ws, {.i = 3}},

    {MOD,           XK_4, ws_go,     {.i = 4}},
    {MOD|ShiftMask, XK_4, win_to_ws, {.i = 4}},

    {MOD,           XK_5, ws_go,     {.i = 5}},
    {MOD|ShiftMask, XK_5, win_to_ws, {.i = 5}},

    {MOD,           XK_6, ws_go,     {.i = 6}},
    {MOD|ShiftMask, XK_6, win_to_ws, {.i = 6}},
};

#endif
