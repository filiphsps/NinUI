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
#include "3DS_UI/3DS_UI.h"
#include "3DS_UI/3DS_UI_DRAW.h"

class uiElement {
public:
	uiElement();

	void render(uiWindow &window);
	void setCallback(void (*callback)(void));
	void(*callback)(void);
	s16 x, y;
	s16 type;
	std::string name;
};

class uiTextBlock : public uiElement {
private:
	std::string content;
	font_s font;
public:
	uiTextBlock(std::string cname);
	void configure(s16 x, s16 y, font_s font, std::string text);
	void render(uiWindow &window);
};

class uiTextBox : public uiElement {
private:
	std::string placeholder;
	font_s font;
	RGB background;
	RGB border;
public:
	uiTextBox(std::string cname);
	void configure(s16 x, s16 y, font_s font, std::string placeholderText, RGB bg, RGB borderColor);
	void render(uiWindow &window);
};

class uiPopUp : public uiElement {
private:
	std::string header, message, button1, button2;
	font_s font;
	font_s headerFont;
	RGB border;
	RGB background;
	RGB headerBackground;
	RGB button1Color;
	RGB button2Color;
public:
	uiPopUp(std::string cname);
	void configure(std::string title, std::string msg, std::string b1, std::string b2, font_s titleFont, font_s cfont, RGB cborder, RGB bg, RGB titleBg, RGB cb1, RGB cb2);
	void render(uiWindow &window);
};