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
#include "3DS_UI.h"

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
	//TODO: Figure out the GPU
}

/* ----------------Window Related---------------- */
uiWindow createWindow() {
	return uiWindow();
}
void clearWindow(uiWindow &window) {
	window = uiWindow();
}

void setAppbarColor(uiWindow &window, RGB appbarColor) {
	window.settings.appbarColor = appbarColor;
}
void setNavbarColor(uiWindow &window, RGB navbarColor) {
	window.settings.navbarColor = navbarColor;
}

/* ----------------Elements---------------- */
uiElement createElement() {
	return uiElement();
}
uiElement createElement(short x, short y) {
	uiElement element;
	element.X = x;
	element.Y = y;
	return element;
}
void setElementCallback(uiElement element, void (*callback)(void)) {
	element.callback = callback;
}
/* ----------------Misc---------------- */
RGB convertHexToRGB(int hexValue) {
	//Thx Stackoverflow
	RGB rgbColor;
	rgbColor.R = ((hexValue >> 16) & 0xFF) / 255.0;
	rgbColor.G = ((hexValue >> 8) & 0xFF) / 255.0;
	rgbColor.B = ((hexValue)& 0xFF) / 255.0;

	return rgbColor;
}
std::string errorCodeToMsg(Result error) {
	//TODO
	return "";
}