void
loadxrdb()
{
	Display *display;
	char * resm;
	XrmDatabase xrdb;
	char *type;
	XrmValue value;

	display = XOpenDisplay(NULL);

	if (display != NULL) {
		resm = XResourceManagerString(display);

		if (resm != NULL) {
			xrdb = XrmGetStringDatabase(resm);

			if (xrdb != NULL) {
				XRDB_LOAD_COLOR("color7", normfgcolor);
				XRDB_LOAD_COLOR("color0", normbgcolor);
				XRDB_LOAD_COLOR("color8", normbordercolor);
				XRDB_LOAD_COLOR("color8", normfloatcolor);
				XRDB_LOAD_COLOR("color7", selfgcolor);
				XRDB_LOAD_COLOR("color2", selbgcolor);
				XRDB_LOAD_COLOR("color7", selbordercolor);
				XRDB_LOAD_COLOR("color7", selfloatcolor);
				XRDB_LOAD_COLOR("color0", titlenormfgcolor);
				XRDB_LOAD_COLOR("color0", titlenormbgcolor);
				XRDB_LOAD_COLOR("color8", titlenormbordercolor);
				XRDB_LOAD_COLOR("color13", titlenormfloatcolor);
				XRDB_LOAD_COLOR("color0", titleselfgcolor);
				XRDB_LOAD_COLOR("color14", titleselbgcolor);
				XRDB_LOAD_COLOR("color7", titleselbordercolor);
				XRDB_LOAD_COLOR("color0", titleselfloatcolor);
				XRDB_LOAD_COLOR("color7", tagsnormfgcolor);
				XRDB_LOAD_COLOR("color0", tagsnormbgcolor);
				XRDB_LOAD_COLOR("color8", tagsnormbordercolor);
				XRDB_LOAD_COLOR("color13", tagsnormfloatcolor);
				XRDB_LOAD_COLOR("color0", tagsselfgcolor);
				XRDB_LOAD_COLOR("color14", tagsselbgcolor);
				XRDB_LOAD_COLOR("color7", tagsselbordercolor);
				XRDB_LOAD_COLOR("color2", tagsselfloatcolor);
				XRDB_LOAD_COLOR("color2", hidnormfgcolor);
				XRDB_LOAD_COLOR("color5", hidnormbgcolor);
				XRDB_LOAD_COLOR("color0", hidselfgcolor);
				XRDB_LOAD_COLOR("color0", hidselbgcolor);
				XRDB_LOAD_COLOR("color7", urgfgcolor);
				XRDB_LOAD_COLOR("color0", urgbgcolor);
				XRDB_LOAD_COLOR("color1", urgbordercolor);
				XRDB_LOAD_COLOR("color13", urgfloatcolor);

				XrmDestroyDatabase(xrdb);
			}
		}
	}

	XCloseDisplay(display);
}

void
xrdb(const Arg *arg)
{
	loadxrdb();
	int i;
	for (i = 0; i < LENGTH(colors); i++)
		scheme[i] = drw_scm_create(drw, colors[i],
		alphas[i],
		ColCount
		);
	focus(NULL);
	arrange(NULL);
}

