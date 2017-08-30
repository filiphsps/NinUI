#pragma once

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
		* @brief sets the callback for onclick
		* @param callback a pointer to the callback function
		*/
		void onClick(void (*event)());

		void(*callback)(void);
		void(*e_onclick)();

		s16 x, y, h, w;
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
		u16 size;

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

/**
* @brief the uiButton class
* @details uiImage is used to render a clickable button.
*          It can be worth noting that its a child of the class uiElement
*/
class uiButton : public uiElement {
	private:
		s16 W, H;
		Vector2 scale = {1,1};
		sf2d_texture* tex;
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

		void configure(Vector2 cords, s16 w, s16 h, void (*onClick)(void));
		void setCallback(void (*callback)(void));
		void(*callback)(void);
		
		/**
		* @brief used by a uiWindow to render the element
		*/
		void render(bool isTopScreen, bool isLeft);
};