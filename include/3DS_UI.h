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
#include <3ds.h>
#include <vector>
#include "defines.h"
#include "3DS_UI_DRAW.h"
class uiElement;

/* ----------------Declarations---------------- */
struct RGB {
	u8 R, G, B;											//Colour codes in RGB format
};
struct uiNavbar {
	RGB navbarColor =  {52,152,219};					//The navbar colour								Default = Cyan
	std::string header = "";							//The navbar header								Default = ""
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
	std::vector<uiElement*> elements;					//List of elements
	uiWindowSettings settings;							//Settings

	uiNavbar navbar;									//Navbar
};

/* ----------------Functions---------------- */
//Init
Result uiInit();										//Initializes 3DS_GUI
Result uiExit();										//Prepares 3DS_GUI for app termination

//Rendering Related
void renderWindow(uiWindow &window);					//Render the passed uiWindow
void drawStatusbar(u8* &fb, uiWindow &window);
void drawNavbar(uiWindow &window, bool isLeft);

//Window Related
uiWindow createWindow();								//Creates an empty window
void clearWindow(uiWindow &window);						//Resets all the window values to default
void deleteWindow(uiWindow &window);					//Deletes the window
void setAppbarColor(uiWindow &window, RGB appbarColor);	//Sets the appbar colour
void setNavbarColor(uiWindow &window, RGB navbarColor);	//Sets the navbar colour
void setWindowFB(uiWindow &window);						//Sets the framebuffers
void setWindowMode(bool isTopScreen,					//Sets the window mode
	bool enable3D, uiWindow &window);
Result addElement(uiWindow &window,						//Adds an element to the window
	uiElement *element);
Result removeElement(uiWindow &window,					//Removes an element from the window
	std::string elementName);

//Misc
RGB convertHexToRGB(int hexValue);						//Converts the HEX colour format to RGB
std::string errorCodeToMsg(Result error);				//Translates error codes to human readable text