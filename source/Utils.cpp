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
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "3DS_UI/defines.h"
#include "3DS_UI/Utils.h"
#include "3DS_UI/uiFont.h"

RGB convertHexToRGB(int hexValue) {
	//Thx Stackoverflow
	RGB color;
	color.R = ((hexValue >> 16) & 0xFF) / 255.0;
	color.G = ((hexValue >> 8) & 0xFF) / 255.0;
	color.B = ((hexValue)& 0xFF) / 255.0;

	return color;
}

void drawStatusbar(RGB color) {
	sf2d_draw_rectangle(0, 0, SCREEN_TOP_WIDTH, STATUSBAR_H, RGBA8(color.R, color.G, color.B, 0xFF));
	//TODO: clock, appname
}
void drawNavbar(RGB color) {
	sf2d_draw_rectangle(0, STATUSBAR_H, SCREEN_TOP_WIDTH, NAVBAR_H + STATUSBAR_H, RGBA8(color.R, color.G, color.B, 0xFF));
}

void uiFinishRendering() {
	sf2d_swapbuffers();
}

void setBackgroundColor(RGB color) {
	sf2d_set_clear_color(RGBA8(color.R, color.G, color.B, 0xFF));
}