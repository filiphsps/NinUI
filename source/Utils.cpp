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
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "3DS_UI/defines.h"
#include "3DS_UI/Utils.h"
#include "3DS_UI/GUI/uiFont.h"

RGB convertHexToRGB(int hexValue) {
	//Thx Stackoverflow
	RGB color;
	color.R = ((hexValue >> 16) & 0xFF) / 255.0;
	color.G = ((hexValue >> 8) & 0xFF) / 255.0;
	color.B = ((hexValue)& 0xFF) / 255.0;

	return color;
}
void uiFinishRendering() {
	sf2d_end_render();
}

void uiSetBackgroundColor(RGB color) {
	sf2d_set_clear_color(RGBA8(color.R, color.G, color.B, color.A));
}
void uiSet3D(bool enable) {
	sf2d_set_3D(enable);
}