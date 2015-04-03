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
#include <3ds.h>
#include <sf2d.h>
#include <sftd.h>
#include "3DS_UI/defines.h"

/**
* @brief bitmapfont struct
*/
struct uiBitmapFont {
	sf2d_texture* bitmap;
	s16 cellSize, offset, gridSize;
	float scale;
	RGB color;
};


/**
* @brief bitmapfont struct
*/
struct uiTtfFont {
	sftd_font* font;
	s16 fontSize; //The font size
	u32 ttfSize; //Size of the ttf file
};

extern uiTtfFont OpenSansFont;

uiBitmapFont readBitmapFont(u8* bitmap, s16 cellSize, s16 offset, s16 gridSize, s16 texWidthAndHeight, RGB color, float scale = 1.0f);
uiBitmapFont removeBitmapFont(uiBitmapFont &font);
void renderBitmapText(std::string text, Vector2 cords, uiBitmapFont &font);
uiTtfFont readTtfFont(u8* fontData, u32 fontSize);
void renderTtfText(std::string text, Vector2 cords, uiTtfFont &font, RGB color);