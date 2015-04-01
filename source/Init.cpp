/*
	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
			 © Filiph Sandström 2015

		TODO(In this file):
		* Alot
		CONTRIBUTORS(In this file):
		* Filiph Sandström (filfat)

		   SEE "LICENSE" FOR THE LICENSE
*/
#include <iostream>
#include <sf2d.h>
#include "3DS_UI/Init.h"
#include "3DS_UI/Utils.h"
#include "3DS_UI/Fonts/OpenSans.h"

uiBitmapFont OpenSansFont_Large;

Result uiInit() {
	//Let's start by initing sf2dlib
	sf2d_init();
	//Then, let's set the background colour to white
	setBackgroundColor({255,255,255});

	//Init fonts
	OpenSansFont_Large = readBitmapFont((u8*)OpenSansFont_LargeTex.pixel_data, 32, 7, 16, 512, {0,0,0});
	return 0;
}
Result uiExit() {
	//And lastly let's exit sf2dlib
	sf2d_fini();
	return 0;
}