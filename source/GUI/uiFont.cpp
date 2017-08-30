/*
	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
			 © Filiph Sandström 2015

		TODO(In this file):
		* Colour support for fonts (sf2dlib needs to att functionality for that)
		CONTRIBUTORS(In this file):
		* Filiph Sandström (filfat)

		   SEE "LICENSE" FOR THE LICENSE
*/
#include <iostream>
#include <sf2d.h>
#include <sftd.h>
#include "3DS_UI/defines.h"
#include "3DS_UI/GUI/uiFont.h"
#include "3DS_UI/Utils.h"

uiTtfFont readTtfFont(u8* fontData, u32 fontSize) {
	uiTtfFont font;
	font.ttfSize = fontSize;
	font.font = sftd_load_font_mem(fontData, font.ttfSize);
	return font;
}
void renderTtfText(std::string text, Vector2 cords, uiTtfFont &font, RGB color) { //Wrapper of a wrapper
	sftd_draw_text(font.font, cords.x, cords.y, RGBA8(color.R, color.G, color.B, color.A), font.fontSize, text.c_str());
}
