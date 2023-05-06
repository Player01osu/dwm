static const Rule rules[] = {
	/* xprop (1):
	 *	WM_CLASS (STRING)= instance, class
	 *	WM_NAME  (STRING)= title
	 */
	/* class      instance       title             tags mask      isfloating   monitor */
	{ "osu!.exe", NULL,          NULL,              0,                1,       -1 },
	{ "wine",     NULL,          NULL,              0,                1,       -1 },
	{ "Gimp",     NULL,          NULL,              0,                1,       -1 },
	{ "Pcmanfm",  "pcmanfm",     NULL,              0,                1,       -1 },
	{ "Firefox",  NULL,          NULL,              1 << 8,           0,       -1 },
	{ "TEST",     "TEST",        "TEST",            0,                1,       -1 },
	{ NULL,       NULL,          "Discord Updater", 0,                1,       -1 },
	{ NULL,       NULL,          "TEST",            0,                1,       -1 },
	{ NULL,       "TEST",        NULL,              0,                1,       -1 },
	{ NULL,       "pulsemixer",  NULL,              0,                1,       -1 },
	{ NULL,       "btop",        NULL,              0,                1,       -1 },
	{ NULL,       "float_me",    NULL,              0,                1,       -1 },
	{ NULL,       "spterm",      NULL,              SPTAG            (0),   1, -1 },
	{ NULL,       "spfm",        NULL,              SPTAG            (1),   1, -1 },
	{ NULL,       "keepassxc",   NULL,              SPTAG            (2),   1, -1 },
	{ NULL,       "spirc",       NULL,              SPTAG            (3),   1, -1 },
};

