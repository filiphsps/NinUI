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
	void uiElement::setCallback(void(*ccallback)(void)) {
		callback = ccallback;
	}
	void uiElement::setPosition(Vector2 cords) {
		x = cords.x;
		y = cords.y;
	}
	void uiElement::setSize(Vector2 size) {
		w = size.x;
		h = size.y;
	}
	void uiElement::onClick(void (*ccallback)()) {
		e_onclick = ccallback;
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
	void uiRect::configure(Vector2 cords, s16 ww, s16 hh, RGB color) {
		x = cords.x;
		y = cords.y;
		w = ww;
		h = hh;
		BackgroundColor = color;
	}
	void uiRect::render(bool isTopScreen, bool isLeft) {
		sf2d_draw_rectangle(x, y, w, h, RGBA8(BackgroundColor.R, BackgroundColor.G, BackgroundColor.B, BackgroundColor.A));
	}

/* uiImage */
	uiImage::uiImage(std::string cname) {
		name = cname;
		type = Rectangle;
	}
	void uiImage::configure(Vector2 cords, s16 w, s16 h, sf2d_texture* texture, Vector2 texScale) {
		x = cords.x;
		y = cords.y;
		W = w;
		H = h;
		tex = texture;
		scale = texScale;
	}
	void uiImage::render(bool isTopScreen, bool isLeft) {
		sf2d_draw_texture(tex,x,y);
	}

/* uiButton */
	uiButton::uiButton(std::string cname) {
		name = cname;
		type = Rectangle;
	}
	void uiButton::configure(Vector2 cords, s16 w, s16 h, void (*onClick)(void)) {
		x = cords.x;
		y = cords.y;
		W = w;
		H = h;
		callback = onClick;
	}
	void uiButton::render(bool isTopScreen, bool isLeft) {
		/*
			TODO
		*/
	}