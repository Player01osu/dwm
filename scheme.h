static const char ncolor[]          = "#000000";

static const char normfgcolor[]     = "#af4faf";
static const char normbgcolor[]     = "#111111";
static const char normbordercolor[] = "#292f36";
static const char normfloatcolor[]  = "#db8fd9";

static const char selfgcolor[]      = "#eeeeee";
static const char selbgcolor[]      = "#812B81";
static const char selbordercolor[]  = "#9b1c9b";
static const char selfloatcolor[]   = "#9b1c9b";

static const char infonormfgcolor[] = "#111111";
static const char infonormbgcolor[] = "#111111";

static const char infoselfgcolor[]  = "#111111";
static const char infoselbgcolor[]  = "#111111";

static const char tagsnormfgcolor[] = "#bbbbbb";
static const char tagsnormbgcolor[] = "#111111";

static const char tagsselfgcolor[]  = "#a62ca6";
static const char tagsselbgcolor[]  = "#111111";

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
