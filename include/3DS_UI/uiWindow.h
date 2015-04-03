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

/**
* @brief the uiWindow class
* @details uiWindows are used as scenes in 3DS_UI which means
*          that each window will have their own set of elements,
*          settings, etc.
*/
class uiWindow {
public:
	uiWindow();
	uiWindow(bool isTopScreen);
	~uiWindow();


	/**
	* @brief render the current window
	*/
	void render();
	

	/**
	* @brief adds an element to the window
	* @param element the element
	*
	* Example Usage:
	* @code
	*  window.addElement(element);
	* @endcode
	*/
	void addElement(uiElement* element);

	/**
	* @brief removes an element from the window
	* @param elementName the name of the element
	* @return the error code (0 if successful)
	*
	* Example Usage:
	* @code
	*  window.removeElement("Rect1");
	* @endcode
	*/
	Result removeElement(std::string elementName);

	/**
	* @brief disables or enables 3D for the current window as long as it's set to the upper screen.
	* @param enable3D true to enable, false to disable
	*
	* Example Usage:
	* @code
	*  window.set3D(true); //Enables the 3D
	* @endcode
	*/
	void set3D(bool enable3D);

	/**
	* @brief sets which screen to render to.
	* @param isTop true for the top screen, false for the bottom
	*
	* Example Usage:
	* @code
	*  window.setScreen(false); //Render to the bottom screen
	* @endcode
	*/
	void setScreen(bool isTop);
	
	/**
	* @brief sets the window's appbar colour
	* @param appbarColor the colour
	*
	* Example Usage:
	* @code
	*  window.setAppbarColor({0,0,0}); //Sets the appbar colour to black
	* @endcode
	*/
	void setAppbarColor(RGB appbarColor);

	/**
	* @brief sets the window's statusbar colour
	* @param statusbarColor the colour
	*
	* Example Usage:
	* @code
	*  window.setStatusbarbarColor({0,0,0}); //Sets the statusbar colour to black
	* @endcode
	*/
	void setStatusbarColor(RGB statusbarColor);

	/**
	* @brief sets the window's navbar colour
	* @param navbarColor the colour
	*
	* Example Usage:
	* @code
	*  window.setNavbarColor({0,0,0}); //Sets the navbar colour to black
	* @endcode
	*/
	void setNavbarColor(RGB navbarColor);

	/**
	* @brief sets the header for the navbar
	* @param header the header text
	*
	* Example Usage:
	* @code
	*  window.setNavbarHeader("PageName");
	* @endcode
	*/
	void setNavbarHeader(std::string header);

private:
	uiWindowSettings settings;
	uiNavbar navbar;
	std::vector<uiElement*> elements;
};