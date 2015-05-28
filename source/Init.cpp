/*
	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
			 � Filiph Sandstr�m 2015

		TODO(In this file):
		* Alot
		CONTRIBUTORS(In this file):
		* Filiph Sandstr�m (filfat)

		   SEE "LICENSE" FOR THE LICENSE
*/
#include <iostream>
#include <sf2d.h>
#include <sftd.h>
#include "3DS_UI/Init.h"
#include "3DS_UI/Utils.h"
#include "3DS_UI/uiFont.h"
#include "OpenSans_Regular_ttf.h"

uiTtfFont OpenSansFont;

Result uiInit(std::string appname) {
	//Let's start by initing sf2dlib
	sf2d_init();
	//Then, lets init the font system
	sftd_init();
	//After that, let's set the background colour to white
	uiSetBackgroundColor({255,255,255});

	//Init fonts
	OpenSansFont = readTtfFont((u8*)OpenSans_Regular_ttf, OpenSans_Regular_ttf_size);
	OpenSansFont.fontSize = 28;
	return 0;
}
Result uiExit() {
	//
	sftd_fini();
	//And lastly let's exit sf2dlib
	sf2d_fini();
	return 0;
}