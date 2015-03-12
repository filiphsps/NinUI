/*

				3DS GUI (WIP NAME)
			 © Filiph Sandström 2015

		TODO(In this file):
		* Alot
		CONTRIBUTORS(In this file):
		* Filiph Sandström (filfat)

		   SEE "LICENSE" FOR THE LICENSE
*/
#pragma once

#include <iostream>
#include <3ds.h>
#include <vector>
#include "defines.h"

/* ----------------Declarations---------------- */
struct RGB {
	u8 R, G, B;											//Colour codes in RGB format
};
struct uiNavbar {
	RGB navbarColor =  {52,152,219};					//The navbar colour								Default = Cyan
	std::string header = "";							//The navbar header								Default = ""
};
struct uiElementSettings {
	bool isInteractable = false;						//True if the element is interactable			Default = false
	bool isEnabled = true;
};
struct uiElement {
	u8 type = 0;										//See "types.txt"
	u8 X = 0, Y = 0;									//Cordinates at where the element should be rendered
	void(*callback)(void);								//If "isInteractable" is set to true so will this function get called when the element is touched
	uiElementSettings settings;							//Settings
};
struct uiWindowSettings {
	bool fullscreen = false;							//True if statusbar should be disabled			Default = false
	bool isTopScreen = true;							//True if window is placed on the topscreen		Default = true
	bool is3DEnabled = true;							//True if the window supports 3D				Default = true

	//Colours
	RGB statusbarColor = {41,128,185};					//The statusbar colour.							Default = Dark Cyan
	RGB appbarColor;									//The appbar colour.							
	RGB statusbarFontColor = {255,255,255};				//The statusbar font Colour.					Default = White
};
struct uiWindow {
	u8* framebuf1, *framebuf2, *tempfb;					//Framebuffers (framebuf2 is only used for 3D)
	std::vector<uiElement> elements;					//List of elements
	uiWindowSettings settings;							//Settings

	uiNavbar navbar;									//
};

/* ----------------Functions---------------- */
//Init
Result uiInit();										//Initializes 3DS_GUI
Result uiExit();										//Prepares 3DS_GUI for app termination

//Rendering Related
void renderWindow(uiWindow &window);					//Render the passed uiWindow
void drawElement(uiElement &element);					//Render the passed uiElement
void drawStatusbar(u8* &fb, uiWindow &window);
void drawNavbar(u8* &fb, uiWindow &window);	

//Window Related
uiWindow createWindow();								//Creates an empty window
void clearWindow(uiWindow &window);						//Resets all the window values to default
void setAppbarColor(uiWindow &window, RGB appbarColor);	//Set appbar colour
void setNavbarColor(uiWindow &window, RGB navbarColor);	//Set navbar colour
void setWindowFB(uiWindow &window);
void setWindowMode(bool isTopScreen,
	bool enable3D, uiWindow &window);

//Elements
uiElement createElement();								//Creates an empty element
uiElement createElement(u8 x, u8 y);					//Creates an element with X & Y set at creation

//Misc
RGB convertHexToRGB(int hexValue);						//Converts the HEX colour format to RGB
std::string errorCodeToMsg(Result error);				//Translates error codes to human readable text