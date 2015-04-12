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
#include "uiFont.h"
#include "defines.h"

enum uiElement_Types { Default, TextBlock, TextBox, Button, PopUp, Rectangle };

/**
* @brief the uiElement class
* @details uiElement is the base class of all the elements.
*          uiElement should only be used when extending the set of available elements.
*/
class uiElement {
public:
	uiElement();

	void render(bool isTopScreen, bool isLeft);
	/**
	* @brief sets the callback for the element
	* @param callback a pointer to the callback function
	*/
	void setCallback(void (*callback)(void));
	void(*callback)(void);
	s16 x, y;
	uiElement_Types type;
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
	uiTtfFont font;
	RGB color;
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
	void configure(Vector2 cords, uiTtfFont font, std::string text, RGB c);

	/**
	* @brief used by a uiWindow to render the element
	*/
	void render(bool isTopScreen, bool isLeft);
};

/**
* @brief the uiTextBox class
* @details uiTextBox is used to create intractable textboxes.
*          It can be worth noting that its a child of the class uiElement
*/
class uiTextBox : public uiElement {
private:
	std::string placeholder;
	uiTtfFont font;
	RGB background;
	RGB border;
public:
	uiTextBox(std::string cname);
	void configure(Vector2 cords, uiTtfFont font, std::string placeholderText, RGB bg, RGB borderColor);
	void render(bool isTopScreen, bool isLeft);
};

/**
* @brief the uiPopUp class
* @details uiPopUp is used to create intractable popups.
*          It can be worth noting that its a child of the class uiElement
*/
class uiPopUp : public uiElement {
private:
	std::string header, message, button1, button2;
	uiBitmapFont font;
	uiBitmapFont headerFont;
	RGB border;
	RGB background;
	RGB headerBackground;
	RGB button1Color;
	RGB button2Color;
public:
	uiPopUp(std::string cname);
	void configure(std::string title, std::string msg, std::string b1, std::string b2, uiBitmapFont titleFont, uiBitmapFont cfont, RGB cborder, RGB bg, RGB titleBg, RGB cb1, RGB cb2);

	/**
	* @brief used by a uiWindow to render the element
	*/
	void render(bool isTopScreen, bool isLeft);
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
	void render(bool isTopScreen, bool isLeft);
};

/**
* @brief the uiImage class
* @details uiImage is used to show a image on screen.
*          It can be worth noting that its a child of the class uiElement
*/
class uiImage : public uiElement {
private:
	s16 W, H;
	Vector2 scale = {1,1};
	sf2d_texture* tex;
public:
	/**
	* @brief creates a uiImage
	* @param cname the name of the element
	*
	* Example Usage:
	* @code
	*  uiImage* image = new uiImage("Image1");
	* @endcode
	*/
	uiImage(std::string cname);

	void configure(Vector2 cords, s16 w, s16 h, sf2d_texture* texture, Vector2 texScale = { 1,1 });

	/**
	* @brief used by a uiWindow to render the element
	*/
	void render(bool isTopScreen, bool isLeft);
};