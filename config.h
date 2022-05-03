/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 11;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 11;       /* vert inner gap between windows */
static const unsigned int gappoh    = 13;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 13;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 3;        /* horizontal padding for statusbar */
static const int vertpadbar         = 10;        /* vertical padding for statusbar */
static const int user_bh            = 27;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]          = { "Source Code Pro Bold:size=8:style=Bold:antialias=true:autohint=true",
                                        "Font Awesome 6 Free:size=10:style=Regular:antialias=true:autohint=true",
                                        "Font Awesome 6 Free:size=10:style=Solid:antialias=true:autohint=true",
					"Noto Serif CJK JP:size=10:antialias=true:autohint=true",
                                        "Material Design Icons-Regular:antialias=true:size=8" };
//static const char *fonts[]          = { "JetBrains Mono:size=9:style=Bold:antialias=true:autohint=true",
//                                        "Font Awesome 6 Free:size=10:style=Regular:antialias=true:autohint=true",
//                                        "Font Awesome 6 Free:size=10:style=Solid:antialias=true:autohint=true",
//					"Noto Serif CJK JP:size=10:antialias=true:autohint=true",
//                                        "Material Design Icons-Regular:antialias=true:size=8" };
static const char dmenufont[]       =  "JetBrains Mono:size=9:style=Bold:antialias=true:autohint=true";

#include "scheme.h"

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"alacritty", "--class", "spterm", NULL };
const char *spcmd2[] = {"alacritty", "--class", "spfm", "-e", "todon", NULL };
const char *spcmd3[] = {"keepassxc", NULL };
const char *spcmd4[] = {"alacritty", "--class", "spirc", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spranger",    spcmd2},
	{"keepassxc",   spcmd3},
	{"spirc",       spcmd4},
};

/* tagging */
static const char *tags[] = { "󰝥", "󰝥", "󰝥", "󰝥", "󰝥", "󰝥" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class       instance       title         tags mask     isfloating   monitor */
	{ "Gimp",      NULL,          NULL,         0,             1,          -1 },
	{ "Alacritty", NULL,          "pulsemixer", 0,             1,          -1 },
	{ "Firefox",   NULL,          NULL,         1 << 8,        0,          -1 },
	{ NULL,        "spterm",      NULL,         SPTAG(0),      1,          -1 },
	{ NULL,        "spfm",        NULL,         SPTAG(1),      1,          -1 },
	{ NULL,        "keepassxc",   NULL,         SPTAG(2),      1,          -1 },
	{ NULL,        "spirc",       NULL,         SPTAG(3),      1,          -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int decorhints  = 1;    /* 1 means respect decoration hints */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",        tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "",        monocle },
};

#include "binds.h"
