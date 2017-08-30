/*
	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
			 � Filiph Sandstr�m 2015

		TODO(In this file):
		* Alot
		CONTRIBUTORS(In this file):
		* Filiph Sandstr�m (filfat)

		   SEE "LICENSE" FOR THE LICENSE
*/
#pragma once

#include <iostream>
#include <vector>
#include <sf2d.h>
#include "uiElement.h"
#include "../Utils.h"

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

	private:
		uiWindowSettings settings;
		std::vector<uiElement*> elements;
};