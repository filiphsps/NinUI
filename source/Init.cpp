#include <iostream>
#include <sf2d.h>
#include <sftd.h>
#include "3DS_UI/Init.h"
#include "3DS_UI/Utils.h"
#include "3DS_UI/GUI/uiFont.h"
#include "OpenSans_Regular_ttf.h"

uiTtfFont OpenSansFont;
Result uiInit(std::string appname) {
	//Let's start by initing sf2dlib
	sf2d_init();

	//Then, lets init the font system
	sftd_init();

	//And of course limit the framerate
	sf2d_set_fps(60);

	//After that, let's set the background color to white
	uiSetBackgroundColor({255,255,255,255});

	//Init fonts
	OpenSansFont = readTtfFont((u8*)OpenSans_Regular_ttf, OpenSans_Regular_ttf_size);
	
	return 0;
}
Result uiExit() {
	//
	sftd_fini();
	//And lastly let's exit sf2dlib
	sf2d_fini();
	return 0;
}