/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 11;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 11;       /* vert inner gap between windows */
static const unsigned int gappoh    = 13;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 13;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 20;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]          = { "JetBrains Mono:size=9:style=Bold:antialias=true:autohint=true", "Font Awesome 6 Free:size=10:style=Solid:antialias=true:autohint=true" };
static const char dmenufont[]       =  "JetBrains Mono:size=9:style=Bold:antialias=true:autohint=true";

static const char ncolor[]          = "#000000";

static const char normfgcolor[]     = "#af4faf";
static const char normbgcolor[]     = "#323232";
static const char normbordercolor[] = "#444444";
static const char normfloatcolor[]  = "#db8fd9";

static const char selfgcolor[]      = "#eeeeee";
static const char selbgcolor[]      = "#812B81";
static const char selbordercolor[]  = "#6E236E";
static const char selfloatcolor[]   = "#6E236E";

static const char infonormfgcolor[]           = "#323232"; //#bbbbbb
static const char infonormbgcolor[]           = "#323232"; //#222222

static const char infoselfgcolor[]            = "#323232"; //#222222
static const char infoselbgcolor[]            = "#323232"; //#222222

static const char tagsnormfgcolor[]            = "#bbbbbb"; //#323232
static const char tagsnormbgcolor[]            = "#323232"; //#222222

static const char tagsselfgcolor[]             = "#a62ca6";
static const char tagsselbgcolor[]             = "#323232"; //#222222

static const char *colors[][4]      = {
	/*                   fg                bg               border           float */
	[SchemeNorm]     = { normfgcolor,      normbgcolor,     normbordercolor, normfloatcolor },
	[SchemeSel]      = { selfgcolor,       selbgcolor,      selbordercolor,  selfloatcolor },
	[SchemeTagsSel]  = { tagsselfgcolor,   tagsselbgcolor,  ncolor,          ncolor   }, // Tagbar left selected {text,background,not used but cannot be empty}
  [SchemeTagsNorm] = { tagsnormfgcolor,  tagsnormbgcolor, ncolor,          ncolor   }, // Tagbar left unselected {text,background,not used but cannot be empty}
  [SchemeStatus]   = { tagsselfgcolor,   tagsselbgcolor,  ncolor,          ncolor}, // Statusbar right {text,background,not used but cannot be empty}
  [SchemeInfoSel]  = { infoselfgcolor,   infoselbgcolor,  ncolor,          ncolor   }, // infobar middle  selected {text,background,not used but cannot be empty}
  [SchemeInfoNorm] = { infonormfgcolor,  infonormbgcolor, ncolor,          ncolor   }, // infobar middle  unselected {text,background,not used but cannot be empty}

};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"alacritty", "--class", "spterm", NULL };
const char *spcmd2[] = {"alacritty", "--class", "spfm", "-e", "lfub", NULL };
const char *spcmd3[] = {"keepassxc", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spranger",    spcmd2},
	{"keepassxc",   spcmd3},
};

/* tagging */
/*static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };*/
static const char *tags[] = { "●", "●", "●", "●", "●", "●" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance     title       tags mask     isfloating   monitor */
	{ "Gimp",	    NULL,		   	 NULL,	   	0,			      	1,			    -1 },
	{ "Firefox",  NULL,		  	 NULL,	   	1 << 8,			    0,			    -1 },
	{ NULL,		    "spterm",		 NULL,	   	SPTAG(0),		    1,			    -1 },
	{ NULL,		    "spfm",		   NULL,	   	SPTAG(1),		    1,			    -1 },
	{ NULL,		    "keepassxc", NULL,	   	SPTAG(2),		    0,			    -1 },
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

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
#include <X11/XF86keysym.h>
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]   = {
  "dmenu_run",
  "-m", dmenumon,
  "-fn", dmenufont,
  "-nb", normbgcolor,
  "-nf", normfgcolor,
  "-sb", selbgcolor,
  "-sf", selfgcolor,
  NULL
};
static const char *termcmd[]    = { "alacritty", NULL };
static const char *upvol[]      = { "pactl", "set-sink-volume", "0", "+5%", NULL };
static const char *downvol[]    = { "pactl", "set-sink-volume", "0", "-5%", NULL };
static const char *mutevol[]    = { "pactl", "set-sink-mute", "0", "toggle", NULL };
static const char *brightup[]   = { "brightnessctl", "s", "+5%", NULL };
static const char *brightdown[] = { "brightnessctl", "s", "5-%", NULL };
static const char *maimcopy[]   = { "screencopy", NULL };
static const char *maimsave[]   = { "screensave", NULL };
static const char *killcomp[]   = { "compositorp", NULL };
static const char *compo[]      = {"pkill", "picom", NULL};
static const char *compi[]      = {"picom", "--experimental-backends", NULL};


#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_o,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_y,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrohgaps,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,            			XK_y,  	   togglescratch,  {.ui = 0 } },
	{ MODKEY,            			XK_u,	   togglescratch,  {.ui = 1 } },
	{ MODKEY,            			XK_x,	   togglescratch,  {.ui = 2 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button1,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signum>"` */
static Signal signals[] = {
	/* signum       function        argument  */
	{ 1,            setlayout,      {.v = 0} },
};
