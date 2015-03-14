/*

				3DS GUI (WIP NAME)
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
uiTextBlock::uiTextBlock() {
	type = 1;
}
void uiTextBlock::configure(s16 nx, s16 ny, font_s cfont, std::string text) {
	content = text;
	font = cfont;
	x = nx;
	y = ny + (STATUSBAR_H + NAVBAR_H);
}
void uiTextBlock::render(uiWindow &window) {
#ifdef DEBUG
	svcOutputDebugString("rendering uiTextBlock", 255);
#endif
	gfxDrawText(window.settings.isTopScreen ? GFX_TOP : GFX_BOTTOM, GFX_LEFT, &font, (char*)content.c_str(), y, x);
	if(window.settings.is3DEnabled)
		gfxDrawText(GFX_TOP, GFX_RIGHT, &font, (char*)content.c_str(), x, y);
}
