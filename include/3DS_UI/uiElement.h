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
#include "uiFont.h"
#include "defines.h"

/**
* @brief the uiElement class
* @details uiElement is the base class of all the elements.
*          uiElement should only be used when extending the set of available elements.
*/
class uiElement {
public:
	uiElement();

	void render();
	/**
	* @brief sets the callback for the element
	* @param callback a pointer to the callback function
	*/
	void setCallback(void (*callback)(void));
	void(*callback)(void);
	s16 x, y;
	s16 type;
	std::string name;
};

/**
* @brief the uiTextBlock class
* @details uiTextBlock is used to create text blocks.
*          It can be worth noting that its a child of the class uiElement
*/
class uiTextBlock : public uiElement {
private:
	std::string content;
	uiFont font;
public:

	/**
	* @brief creates a uiTextBlock
	* @param cname the name of the element
	*
	* Example Usage:
	* @code
	*  uiTextBlock* textBlock = new uiTextBlock("TextBlock1");
	* @endcode
	*/
	uiTextBlock(std::string cname);

	/**
	* @brief configures the uiTextBlock
	* @param cords the coordinates
	* @param font the font to use
	* @param text the content of the uiTextBlock
	*
	* Example Usage:
	* @code
	*  textBlock.configure(0, 0, myFont, "Hello World!");
	* @endcode
	*/
	void configure(Vector2 cords, uiFont font, std::string text);

	/**
	* @brief used by a uiWindow to render the element
	*/
	void render();
};

/**
* @brief the uiTextBox class
* @details uiTextBox is used to create intractable textboxes.
*          It can be worth noting that its a child of the class uiElement
*/
class uiTextBox : public uiElement {
private:
	std::string placeholder;
	uiFont font;
	RGB background;
	RGB border;
public:
	uiTextBox(std::string cname);
	void configure(Vector2 cords, uiFont font, std::string placeholderText, RGB bg, RGB borderColor);
	void render();
};

/**
* @brief the uiPopUp class
* @details uiPopUp is used to create intractable popups.
*          It can be worth noting that its a child of the class uiElement
*/
class uiPopUp : public uiElement {
private:
	std::string header, message, button1, button2;
	uiFont font;
	uiFont headerFont;
	RGB border;
	RGB background;
	RGB headerBackground;
	RGB button1Color;
	RGB button2Color;
public:
	uiPopUp(std::string cname);
	void configure(std::string title, std::string msg, std::string b1, std::string b2, uiFont titleFont, uiFont cfont, RGB cborder, RGB bg, RGB titleBg, RGB cb1, RGB cb2);

	/**
	* @brief used by a uiWindow to render the element
	*/
	void render();
};

/**
* @brief the uiRect class
* @details uiRect is used to create rectangles.
*          It can be worth noting that its a child of the class uiElement
*/
class uiRect : public uiElement {
private:
	s16 W, H;
	RGB BackgroundColor;
public:
	/**
	* @brief creates a uiRect
	* @param cname the name of the element
	*
	* Example Usage:
	* @code
	*  uiRect* rect = new uiRect("Rect1");
	* @endcode
	*/
	uiRect(std::string cname);

	void configure(Vector2 cords, s16 w, s16 h, RGB color);

	/**
	* @brief used by a uiWindow to render the element
	*/
	void render();
};