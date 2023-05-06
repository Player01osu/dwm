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
	"-h", "25",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};
static const char *termcmd[]    = { "alacritty", NULL };
static const char *upvol[]      = { "pactl", "set-sink-volume", "0", "+2%", NULL };
static const char *downvol[]    = { "pactl", "set-sink-volume", "0", "-2%", NULL };
static const char *mutevol[]    = { "pactl", "set-sink-mute", "0", "toggle", NULL };
static const char *brightup[]   = { "brightnessctl", "s", "+2%", NULL };
static const char *brightdown[] = { "brightnessctl", "s", "2-%", NULL };
static const char *maimcopy[]   = { "screencopy", NULL };
static const char *maimsave[]   = { "screensave", NULL };
static const char *maimname[]   = { "screenname", NULL };
static const char *killcomp[]   = { "compositorp", NULL };
static const char *unkeym[]     = { "unkeym", NULL };

#include "movestack.c"
static Key keys[] = {
	/* modifier                     key                          function        argument */
	{ 0,                            XF86XK_AudioRaiseVolume,     spawn,          {.v = upvol   } },
	{ 0,                            XF86XK_AudioLowerVolume,     spawn,          {.v = downvol } },
	{ 0,                            XF86XK_AudioMute,            spawn,          {.v = mutevol } },
	{ 0,                            XF86XK_MonBrightnessUp,      spawn,          {.v = brightup } },
	{ 0,                            XF86XK_MonBrightnessDown,    spawn,          {.v = brightdown } },
	{ 0,                            XK_Print,                    spawn,          {.v = maimcopy } },
	{ ControlMask,                  XK_semicolon,                spawn,          {.v = unkeym } },
	{ MODKEY,                       XK_Print,                    spawn,          {.v = maimsave } },
	{ MODKEY|ShiftMask,             XK_Print,                    spawn,          {.v = maimname } },
	{ MODKEY|ShiftMask,             XK_v,                        spawn,          {.v = killcomp } },
	{ MODKEY,                       XK_o,                        spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,                   spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,                        togglebar,      {0} },
	{ MODKEY,                       XK_j,                        focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,                        focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,                        incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,                        incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,                        setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,                        setmfact,       {.f = +0.05} },
	{ MODKEY|Mod1Mask,              XK_u,                        incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,                        incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,                        incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,                        incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,                        incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,                        incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,                        incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,                        incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,                        incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,                        incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,                        incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,                        incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,                        incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,                        incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,                        togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,                        defaultgaps,    {0} },
	{ MODKEY|ShiftMask,             XK_h,                        setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,                        setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,                        setcfact,       {.f =  0.00} },
	{ MODKEY,                       XK_Return,                   zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_c,                        killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_j,                        movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,                        movestack,      {.i = -1 } },
	{ MODKEY,                       XK_t,                        setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,                        setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,                        setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,                    setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,                    togglefloating, {0} },
	{ MODKEY,                       XK_0,                        view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                        tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,                    focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,                   focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,                    tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                   tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_n,                        viewnext,       {0} },
	{ MODKEY,                       XK_p,                        viewprev,       {0} },
	{ MODKEY,                       XK_grave,                    togglescratch,  {.ui = 0 } },
	{ MODKEY,                       XK_Tab,	                     togglescratch,  {.ui = 1 } },
	{ MODKEY,                       XK_x,                        togglescratch,  {.ui = 2 } },
	{ MODKEY,                       XK_y,                        togglescratch,  {.ui = 3 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
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
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button2,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signum>"` */
static Signal signals[] = {
	/* signum       function        argument  */
	{ 1,            setlayout,      {.v = 0} },
};
