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
#include "uiElement.h"
#include "Utils.h"

class uiWindow {
public:
	uiWindow();
	uiWindow(bool isTopScreen);
	~uiWindow();

	void render();
	void clear();
	
	/* Element Related */
	void addElement(uiElement *element);
	Result removeElement(std::string elementName);

	/* Settings Related */
	void set3D(bool enable3D);									//Sets the 3d mode
	void setAppbarColor(RGB appbarColor);						//Sets the appbar colour
	void setStatusbarColor(RGB statusbarColor);					//Sets the statusbar colour
	void setScreen(bool isTop);

	/* Navbar Related */
	void setNavbarColor(RGB navbarColor);
	void setNavbarHeader(std::string header);

private:
	uiWindowSettings settings;
	uiNavbar navbar;
	std::vector<uiElement*> elements;
};