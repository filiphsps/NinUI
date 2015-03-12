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

/* Declarations */
struct RGB {
	short R, G, B;										//Colour codes in RGB format
};
struct uiElement {
	short X, Y;											//Where the element should be rendered
};
struct uiWindowSettings {
	bool fullscreen;									//True if statusbar should be disabled
	bool isTopScreen;									//True if window is placed on the topscreen
	bool is3DEnabled;									//True if the window supports 3D

	RGB appbarColor;									//The appbar colour
	RGB navbarColor;									//The navbar colour
};
struct uiWindow {
	u8* framebuf1, *framebuf2;							//Framebuffers (framebuf2 is only used for 3D)
	std::vector<uiElement> elements;					//List of elements
	uiWindowSettings settings;							//Settings
};

/* Functions */
//Init
int uiInit();
int uiExit();
//Window Related
uiWindow createWindow();								//Creates an empty window
void clearWindow(uiWindow &window);						//Resets all the window values to default

void setAppbarColor(uiWindow &window, RGB appbarColor);	//Set appbar colour
void setNavbarColor(uiWindow &window, RGB navbarColor);	//Set navbar colour
//Elements
uiElement createElement();								//Creates an empty element
uiElement createElement(short x, short y);				//Creates an element with X & Y set at creation
//Misc
RGB convertHexToRGB(int hexValue);