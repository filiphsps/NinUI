#pragma once

#include <functional>
#include <iostream>
#include <vector>
#include "uiFont.h"
#include "../defines.h"

enum uiElement_Types {
	null,
	TextBlock,
	TextBox,
	Button,
	Rectangle
};

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

		/**
		* @brief sets the position of the element
		* @param cords the position
		*/
		void setPosition(Vector2 cords);

		/**
		* @brief sets the size of the element
		* @param size the size
		*/
		void setSize(Vector2 size);

		/**
		* @brief sets the color of the element
		* @param c the color
		*/
		void setColor(RGB c);

		/**
		* @brief sets the callback for onclick
		* @param callback a pointer to the callback function
		*/
		void onClick(std::function<void()>);

		std::function<void()> e_onclick;

		s16 x, y, h, w;
		RGB color;
		u16 size;
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
		void configure(Vector2 cords, uiTtfFont font, s16 size, std::string text, RGB c);

		void setContent(std::string content);

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
* @brief the uiButton class
* @details uiImage is used to render a clickable button.
*          It can be worth noting that its a child of the class uiElement
*/
class uiButton : public uiElement {
	private:
		std::string content;
		uiTtfFont font;

	public:
		/**
		* @brief creates a uiButton
		* @param cname the name of the element
		*
		* Example Usage:
		* @code
		*  uiButton* butn = new uiButton("Button1");
		* @endcode
		*/
		uiButton(std::string cname);

		void configure(Vector2 cords, s16 w, s16 h, uiTtfFont cfont, s16 size, std::string text, RGB c);
		
		/**
		* @brief used by a uiWindow to render the element
		*/
		void render(bool isTopScreen, bool isLeft);
};