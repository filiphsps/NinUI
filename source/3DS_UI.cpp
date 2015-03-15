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
		* Unify cord system for everything
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
#include "3DS_UI/3DS_UI.h"
#include "3DS_UI/3DS_UI_DRAW.h"
#include "3DS_UI/uiElement.h"
#include "3DS_UI/keyboardImage.h"

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
		for (uiElement* &element : window.elements)
		{
			//Ugly
			switch (element->type)
			{
				case 1: //TextBlock
				{
					uiTextBlock* textBlock = (uiTextBlock*)element;
					textBlock->render(window);
					break;
				}
				case 2: //TextBox
				{
					uiTextBox* textBox = (uiTextBox*)element;
					textBox->render(window);
					break;
				}
				case 4:
				{
					uiPopUp* popUp = (uiPopUp*)element;
					popUp->render(window);
					break;
				}
			}
				
		}
		if (window.settings.isTopScreen) {
			//Lets draw the statusbar
			drawStatusbar(window.framebuf1, window);
			drawNavbar(window, true);
			if (window.settings.is3DEnabled) {
				drawStatusbar(window.framebuf2, window);
				drawNavbar(window, false);
			}
		}

		if (window.settings.is3DEnabled)
			window.framebuf2 = window.framebuf1;
		gfxFlushBuffers();
		gfxSwapBuffers();
	}
}
void drawStatusbar(u8* &fb, uiWindow &window) {
	drawFillRect(0, 1, 399, STATUSBAR_H,window.settings.statusbarColor.R, 
			window.settings.statusbarColor.G, window.settings.statusbarColor.B, fb);

	//TODO: clock, appname
}
void drawNavbar(uiWindow &window, bool isLeft){
	if (isLeft) {
		drawFillRect(0, STATUSBAR_H, SCREEN_TOP_WIDTH -1, NAVBAR_H + STATUSBAR_H, window.navbar.navbarColor.R,
			window.navbar.navbarColor.G, window.navbar.navbarColor.B, window.framebuf1);

		gfxDrawText(GFX_TOP, GFX_LEFT, &robootoWhite, (char*)window.navbar.header.c_str(), 10, NAVBAR_HEADER_Y);
	}
	else{
		drawFillRect(0, STATUSBAR_H, SCREEN_TOP_WIDTH -1, NAVBAR_H + STATUSBAR_H, window.navbar.navbarColor.R,
			window.navbar.navbarColor.G, window.navbar.navbarColor.B, window.framebuf2);

		gfxDrawText(GFX_TOP, GFX_RIGHT, &robootoWhite, (char*)window.navbar.header.c_str(), 10, NAVBAR_HEADER_Y);
	}
}

//Begin Temp
void renderKeyboardInput(std::string input) {
	gfxDrawText(GFX_TOP, GFX_LEFT, &robootoBlackSmall, (char*)input.c_str(), 0, 48);
	gfxDrawText(GFX_TOP, GFX_RIGHT, &robootoBlackSmall, (char*)input.c_str(), 0, 48);
}
//End Temp

std::string doKeyboard(uiKeyboard &kb, uiWindow &window) {
	//TODO: Second thread, better code, fix bugs, support special keys, ui, etc
	std::string input;
	bool keyPressed;
	touchPosition tp;
	touchPosition dtp;
	while (true) {
		gspWaitForVBlank();
		setWindowFB(window);
		gfxDrawSprite(GFX_BOTTOM, GFX_LEFT, keyboardImage, KEYBOARD_WIDTH, KEYBOARD_HEIGHT, KEYBOARD_X, KEYBOARD_Y);
		hidScanInput();
		hidTouchRead(&tp);
		for (uiKey &key : kb.keys) {
			if (((tp.px > key.x1 && tp.px < key.x2) && (tp.py > key.y1 && tp.py < key.y2))) {
				drawFillRect(key.x1, key.y1, key.x2, key.y2, 207, 209, 211, window.framebuf1);
				key.isPressed = true;
				if (!key.isSpecial && dtp.px == 0 ) {
					char tmp[256];
					snprintf(tmp, 255, "%c", key.key);
					input = input.append(tmp);
				}
				else if (dtp.px == 0)
					switch (key.key) {
					case '#':
						input.substr(0, input.size() - 1);
						break;
					}
				renderKeyboardInput(input);
			}
		}
		dtp = tp;
		gfxFlushBuffers();
		gfxSwapBuffers();
	}
	return input;
}

/* ----------------Window Related---------------- */
uiWindow createWindow() {
	return uiWindow();
}
void clearWindow(uiWindow &window) {
	window = uiWindow();
}
void deleteWindow(uiWindow &window) {
	delete &window;
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
Result addElement(uiWindow &window, uiElement *element) {
	window.elements.push_back(element);
	return 0;
}
Result removeElement(uiWindow &window, std::string elementName) {
	s16 x = 0;
	bool elementFound;
	for (uiElement* &element : window.elements){
		x++;
		if (element->name == elementName) {
			window.elements.erase(window.elements.begin() + x);
			elementFound = true;
		}
	}
	return elementFound ? 1 : -99; //TODO: Error codes
}
uiKeyboard createKeyboard() {
	//TODO: Row 2, Row 3, Row 4, Compress the code
	uiKeyboard key;
	int row = 1;
	for (int pos = 0; pos < 35; pos++) {
		uiKey tk;
		char ck = getKey(pos);
		
		if (ck == '\0')
			continue;

		if (pos > 31)
			row = 4;
		else if (pos > 21)
			row = 3;
		else if (pos > 11)
			row = 2;

		tk.key = ck;
		if ((tk.key >= 'a'&& tk.key <= 'z') || (tk.key >= 'A' && tk.key <= 'Z'))
			tk.isSpecial = true;
		else
			tk.isSpecial = false;

		switch (row) {
		case 1:
			tk.x1 = pos > 0 ? (KEYBOARD_ROW1_X + KEYBOARD_BUTTON_WIDTH + KEYBOARD_ROW1_X) * pos + 1 : KEYBOARD_ROW1_X;
			tk.x2 = tk.x1 + KEYBOARD_BUTTON_WIDTH;
			tk.y1 = KEYBOARD_ROW1_Y;
			tk.y2 = KEYBOARD_ROW1_Y + KEYBOARD_BUTTON_HEIGHT;
			break;
		case 2:
			tk.y1 = KEYBOARD_ROW2_Y;
			tk.y2 = KEYBOARD_ROW2_Y + KEYBOARD_BUTTON_HEIGHT;
			break;
		case 3:
			tk.y1 = KEYBOARD_ROW3_Y;
			tk.y2 = KEYBOARD_ROW3_Y + KEYBOARD_BUTTON_HEIGHT;
			break;
		case 4:
			tk.y1 = KEYBOARD_ROW4_Y;
			tk.y2 = KEYBOARD_ROW4_Y + KEYBOARD_BUTTON_HEIGHT;
			break;
		}

		char debug[256];
		snprintf(debug, 255, "Added Key: %c, X: %d Y: %d, X2: %d, Y2: %d", ck, tk.x1, tk.y1, tk.x2, tk.y2);
		svcOutputDebugString(debug, 255);

		key.keys.push_back(tk);
	}
	return key;
}

void setAppbarColor(uiWindow &window, RGB appbarColor) {
	window.settings.appbarColor = appbarColor;
}
void setNavbarColor(uiWindow &window, RGB navbarColor) {
	window.navbar.navbarColor = navbarColor;
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
char getKey(s16 num) {
	switch (num) {
	case 0:
		return 'q';
	case 1:
		return 'w';
	case 2:
		return 'e';
	case 3:
		return 'r';
	case 4:
		return 't';
	case 5:
		return 'y';
	case 6:
		return 'u';
	case 7:
		return 'i';
	case 8:
		return 'o';
	case 9:
		return 'p';
	case 10:
		return '#';
	case 11:
		return 'a';
	case 12:
		return 's';
	case 13:
		return 'd';
	case 14:
		return 'f';
	case 15:
		return 'g';
	case 16:
		return 'h';
	case 17:
		return 'j';
	case 18:
		return 'k';
	case 19:
		return 'l';
	case 22:
		return 'z';
	case 23:
		return 'x';
	case 24:
		return 'c';
	case 25:
		return 'v';
	case 26:
		return 'b';
	case 27:
		return 'n';
	case 28:
		return 'm';
	case 29:
		return '!';
	case 30:
		return '?';
	case 33:
		return '.';
	case 34:
		return ' ';
	default:
		return '\0';
	}
}
