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
#pragma once
#include <iostream>
#include <vector>
#include <sf2d.h>

/* Screen */
#define SCREEN_TOP_HEIGHT 240
#define SCREEN_TOP_WIDTH 400
#define SCREEN_BOTTOM_HEIGHT 240
#define SCREEN_BOTTOM_WIDTH 320

 /* Standard UI */
#define STATUSBAR_H 12
#define NAVBAR_H 36
#define NAVBAR_HEADER_Y ((STATUSBAR_H + (NAVBAR_H/4)*3)+2)
#define APPBAR_H 18
#define SHADOW_ANGLE 135
#define AVAILABLE_SCREEN_TOP_HEIGHT (SCREEN_TOP_HEIGHT - (STATUSBAR_H + NAVBAR_H))
#define AVAILABLE_SCREEN_TOP_WIDTH 400
#define UIPOPUP_BORDER_X 34
#define UIPOPUP_BORDER_Y 274
#define UIPOPUP_X 36
#define UIPOPUP_Y 272
#define UIPOPUP_HEADER_X 41
#define UIPOPUP_HEADER_Y 83

/* Keyboard */
#define KEYBOARD_X 0
#define KEYBOARD_Y 240
#define KEYBOARD_WIDTH 320
#define KEYBOARD_HEIGHT 155
#define KEYBOARD_BUTTON_WIDTH 23
#define KEYBOARD_BUTTON_HEIGHT 23
#define KEYBOARD_ROW1_X 3
#define KEYBOARD_ROW1_Y 92
#define KEYBOARD_ROW2_Y (KEYBOARD_ROW1_Y + KEYBOARD_BUTTON_HEIGHT)
#define KEYBOARD_ROW2_X 17
#define KEYBOARD_ROW3_Y (KEYBOARD_ROW2_Y + KEYBOARD_BUTTON_HEIGHT)
#define KEYBOARD_ROW3_X 4
#define KEYBOARD_ROW4_Y (KEYBOARD_ROW3_Y + KEYBOARD_BUTTON_HEIGHT)
#define KEYBOARD_ROW4_X 4
#define KEYBOARD_ROW1_OFFSET 7

/* Debug */
#define DEBUG

/**
* @brief Vector2
*/
struct Vector2 {
	float x;
	float y;
};

/**
* @brief RGB colour
*/
struct RGB {
	u8 R, G, B, A;
};

struct uiKey {
	char key;
	u16 x1, x2, y1, y2;
	s16 pos;
	s16 row;
	bool isPressed, isSpecial;
};
struct uiKeyboard {
	std::vector<uiKey> keys;
	bool inSpecialMode = false;
};
struct uiNavbar {
	RGB navbarColor = { 52,152,219 };					//The navbar colour								Default = Cyan
	RGB navbarFontColor = { 255,255,255 };				//The navbar font colour						Default = White
	std::string header = "";							//The navbar header								Default = ""
};
struct uiWindowSettings {
	bool fullscreen = false;							//True if statusbar should be disabled			Default = false
	bool isTopScreen = true;							//True if window is placed on the topscreen		Default = true
	bool is3DEnabled = true;							//True if the window supports 3D				Default = true

														//Colours
	RGB statusbarColor = { 41,128,185 };				//The statusbar colour.							Default = Dark Cyan
	RGB appbarColor = { 33,33,33 };						//The appbar colour.							Default = Dark Grey	
	RGB statusbarFontColor = { 255,255,255 };			//The statusbar font colour.					Default = White
};