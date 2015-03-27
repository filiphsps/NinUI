/*
	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
			 © Filiph Sandström 2015

		TODO(In this file):
		* Colour support for fonts (sf2dlib needs to att functionality for that)
		CONTRIBUTORS(In this file):
		* Filiph Sandström (filfat)

		   SEE "LICENSE" FOR THE LICENSE
*/
#include <iostream>
#include <sf2d.h>
#include "3DS_UI/defines.h"
#include "3DS_UI/uiFont.h"
#include "3DS_UI/Utils.h"

uiFont readFont(u8* bitmap, s16 cellHeight, s16 cellWidth, s16 gridSize, s16 texWidthAndHeight, RGB color) {
	uiFont font;
	font.cellHeight = cellHeight;
	font.cellWidth = cellWidth;
	font.gridSize = gridSize;
	font.bitmap = sf2d_create_texture(texWidthAndHeight, texWidthAndHeight, GPU_RGBA8, SF2D_PLACE_RAM);
	sf2d_fill_texture_from_RGBA8(font.bitmap, bitmap, texWidthAndHeight, texWidthAndHeight);
	sf2d_texture_tile32(font.bitmap);
	font.color = color;
	return font;
}
void renderText(std::string text, Vector2 cords, uiFont &font) {
	int bitmapX, bitmapY, tcX, tcY, count = 0;
	for (char &c : text) {
		bitmapX = (c % font.gridSize) * font.gridSize;
		bitmapY = (int)(c / font.gridSize) * font.gridSize;
		tcX = (int)(bitmapX);
		tcY = (int)(bitmapY);
		sf2d_draw_texture_part(font.bitmap, count >= 1 ? cords.x + font.cellWidth * count : cords.x, cords.y, tcX, tcY, font.cellWidth, font.cellHeight);
		count++;
	}
}