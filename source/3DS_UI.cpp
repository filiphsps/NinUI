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
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "3DS_UI.h"
#include "3DS_UI_DRAW.h"

/* ----------------Init & Exit Related---------------- */
Result uiInit(){
	//TODO
	return 0;
}
Result uiExit(){
	//TODO
	return 0;
}

/* ----------------Rendering Related---------------- */
void renderWindow(uiWindow &window) {
	for (int x = 0; x < 2; x++) {
		gspWaitForVBlank();
		setWindowFB(window);

		//Clear screen with white colour
		if (window.settings.isTopScreen) {
			clearScreen(window.framebuf1, GFX_TOP);
			clearScreen(window.framebuf2, GFX_TOP);
		}
		else
			clearScreen(window.framebuf1, GFX_BOTTOM);

		//Render Elements
		for (auto &element : window.elements)
		{
			drawElement(element);
		}
		if (window.settings.isTopScreen) {
			//Lets draw the statusbar
			drawStatusbar(window.framebuf1, window);
			drawNavbar(window.framebuf1, window);
			if (window.settings.is3DEnabled) {
				drawStatusbar(window.framebuf2, window);
				drawNavbar(window.framebuf2, window);
			}
		}
		if (window.settings.is3DEnabled)
			window.framebuf2 = window.framebuf1;
		gfxFlushBuffers();
		gfxSwapBuffers();
	}
}
void drawElement(uiElement &element) {
	//ToDo
}
void drawStatusbar(u8* &fb, uiWindow &window) {
	drawFillRect(0, 1, 399, STATUSBAR_H,window.settings.statusbarColor.R, 
			window.settings.statusbarColor.G, window.settings.statusbarColor.B, fb);

	//TODO: clock, appname
}
void drawNavbar(u8* &fb, uiWindow &window){
	drawFillRect(0, STATUSBAR_H, 399, NAVBAR_H + STATUSBAR_H, window.navbar.navbarColor.R,
			window.navbar.navbarColor.G, window.navbar.navbarColor.B, fb);

	//TODO: header
}
/* ----------------Window Related---------------- */
uiWindow createWindow() {
	return uiWindow();
}
void clearWindow(uiWindow &window) {
	window = uiWindow();
}
void setWindowFB(uiWindow &window) {
	window.framebuf1 = (u8*)malloc(sizeof(u8*));
	window.framebuf2 = (u8*)malloc(sizeof(u8*));
	if (window.settings.isTopScreen) {
		window.framebuf1 = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
		window.framebuf2 = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL);
	}
	else {
		window.framebuf1 = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL);
		window.framebuf2 = NULL;
	}
}
void setWindowMode(bool isTopScreen, bool enable3D, uiWindow &window) {
	window.settings.is3DEnabled = isTopScreen ? enable3D : false; //Lets make sure we cant set 3D to true on the bottom screen
	window.settings.isTopScreen = isTopScreen;
}

void setAppbarColor(uiWindow &window, RGB appbarColor) {
	window.settings.appbarColor = appbarColor;
}
void setNavbarColor(uiWindow &window, RGB navbarColor) {
	window.navbar.navbarColor = navbarColor;
}

/* ----------------Elements---------------- */
uiElement createElement() {
	return uiElement();
}
uiElement createElement(u8 x, u8 y) {
	uiElement element;
	element.X = x;
	element.Y = y;
	return element;
}
void setElementCallback(uiElement element, void (*callback)(uiElement element)) {
	element.callback = callback;
}
/* ----------------Misc---------------- */
RGB convertHexToRGB(int hexValue) {
	//Thx Stackoverflow
	RGB color;
	color.R = ((hexValue >> 16) & 0xFF) / 255.0;
	color.G = ((hexValue >> 8) & 0xFF) / 255.0;
	color.B = ((hexValue)& 0xFF) / 255.0;

	return color;
}
std::string errorCodeToMsg(Result error) {
	//TODO
	return "";
}