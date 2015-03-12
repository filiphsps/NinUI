#include "3DS_UI.h"
/* Init & Exit Related */
int uiInit(){
	return 0;
}
int uiExit(){
	return 0;
}

/* Window Related */
uiWindow createWindow() {
	uiWindow window;
	return window;
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

/* Elements */
uiElement createElement() {
	uiElement element;
	return element;
}
uiElement createElement(short x, short y) {
	uiElement element;
	element.X = x;
	element.Y = y;
	return element;
}

/* Misc */
RGB convertHexToRGB(int hexValue) {
	RGB rgbColor;
	rgbColor.R = ((hexValue >> 16) & 0xFF) / 255.0;
	rgbColor.G = ((hexValue >> 8) & 0xFF) / 255.0;
	rgbColor.B = ((hexValue)& 0xFF) / 255.0;

	return rgbColor;
}