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
		type = null;
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
	void uiElement::onClick(void (*ccallback)()) {
		e_onclick = ccallback;
	}

/* uiTextBlock */
	uiTextBlock::uiTextBlock(std::string cname) {
		type = TextBlock;
		name = cname;
	}
	void uiTextBlock::configure(Vector2 cords, uiTtfFont cfont, std::string text, RGB c) {
		x = cords.x;
		y = cords.y;
		font = cfont;
		content = text;
		color = c;
	}
	void uiTextBlock::render(bool isTopScreen, bool isLeft) {
		renderTtfText(content, { (float)x,(float)y }, font, color);
	}

/* uiRect */
	uiRect::uiRect(std::string cname) {
		name = cname;
		type = Rectangle;
	}
	void uiRect::configure(Vector2 cords, s16 ww, s16 hh, RGB color) {
		x = cords.x;
		y = cords.y;
		w = ww;
		h = hh;
		BackgroundColor = color;
	}
	void uiRect::render(bool isTopScreen, bool isLeft) {
		sf2d_draw_rectangle(x, y, w, h, RGBA8(BackgroundColor.R, BackgroundColor.G, BackgroundColor.B, 0xFF));
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