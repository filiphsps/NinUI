#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "3DS_UI/defines.h"
#include "3DS_UI/GUI/uiElement.h"
#include "3DS_UI/GUI/uiFont.h"
#include "3DS_UI/GUI/uiWindow.h"

/* uiElement */
	uiElement::uiElement() {
		type = uiElement_Types::null;
	}
	void uiElement::render(bool isTopScreen, bool isLeft) {
		//Override me
	}
	void uiElement::setPosition(Vector2 cords) {
		x = cords.x;
		y = cords.y;
	}
	void uiElement::setSize(Vector2 size) {
		w = size.x;
		h = size.y;
	}
	void uiElement::setColor(RGB c) {
		color = c;
	}
	void uiElement::onClick(std::function<void()> func) {
		e_onclick = func;
	}

/* uiTextBlock */
	uiTextBlock::uiTextBlock(std::string cname) {
		type = uiElement_Types::TextBlock;
		name = cname;
	}
	void uiTextBlock::configure(Vector2 cords, uiTtfFont cfont, s16 csize, std::string text, RGB c) {
		x = cords.x;
		y = cords.y;
		font = cfont;
		size = csize;
		content = text;
		color = c;
	}
	void uiTextBlock::setContent(std::string text) {
		content = text;
	}
	void uiTextBlock::render(bool isTopScreen, bool isLeft) {
		sftd_draw_text(font.font, x, y,  RGBA8(color.R, color.G, color.B, color.A), size, content.c_str());
	}

/* uiRect */
	uiRect::uiRect(std::string cname) {
		name = cname;
		type = uiElement_Types::Rectangle;
	}
	void uiRect::configure(Vector2 cords, s16 ww, s16 hh, RGB c) {
		x = cords.x;
		y = cords.y;
		w = ww;
		h = hh;
		color = c;
	}
	void uiRect::render(bool isTopScreen, bool isLeft) {
		sf2d_draw_rectangle(x, y, w, h, RGBA8(color.R, color.G, color.B, color.A));
	}

/* uiButton */
	uiButton::uiButton(std::string cname) {
		name = cname;
		type = Button;
	}
	void uiButton::configure(Vector2 cords, s16 cw, s16 ch, uiTtfFont cfont, s16 csize, std::string text, RGB c) {
		x = cords.x;
		y = cords.y;
		h = ch;
		w = cw;
		font = cfont;
		size = csize;
		content = text;
		color = c;
	}
	void uiButton::render(bool isTopScreen, bool isLeft) {
		sf2d_draw_rectangle(x, y, w, h, RGBA8(color.R, color.G, color.B, color.A));
		//TODO: Center text
		sftd_draw_text(font.font, x, (y + (h/2 - size/2)),  RGBA8(0xFF, 0xFF, 0xFF, 0xFF), size, content.c_str());
	}