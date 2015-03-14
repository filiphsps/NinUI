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
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "3DS_UI.h"
#include "3DS_UI_DRAW.h"
#include "uiElement.h"

/* uiElement */
uiElement::uiElement() {
	type = 0;
}
uiElement::~uiElement() {

}

void uiElement::render(uiWindow &window) { }

/* uiTextBlock */
uiTextBlock::uiTextBlock(std::string cname) {
	type = 1;
	name = cname;
}
void uiTextBlock::configure(s16 nx, s16 ny, font_s cfont, std::string text) {
	content = text;
	font = cfont;
	x = nx;
	y = (ny + (STATUSBAR_H + NAVBAR_H)) + font.height;
}
void uiTextBlock::render(uiWindow &window) {
#ifdef DEBUG
	svcOutputDebugString("rendering uiTextBlock", 255);
#endif
	gfxDrawText(window.settings.isTopScreen ? GFX_TOP : GFX_BOTTOM, GFX_LEFT, &font, (char*)content.c_str(), x, y);
	if(window.settings.is3DEnabled)
		gfxDrawText(GFX_TOP, GFX_RIGHT, &font, (char*)content.c_str(), x, y);
}