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

uiBitmapFont readBitmapFont(u8* bitmap, s16 cellSize, s16 offset, s16 gridSize, s16 texWidthAndHeight, RGB color, float scale) {
	uiBitmapFont font;
	font.cellSize = cellSize;
	font.gridSize = gridSize;
	font.offset = offset;
	font.scale = scale;
	font.bitmap = sf2d_create_texture(texWidthAndHeight, texWidthAndHeight, GPU_RGBA8, SF2D_PLACE_RAM);
	sf2d_fill_texture_from_RGBA8(font.bitmap, bitmap, texWidthAndHeight, texWidthAndHeight);
	sf2d_texture_tile32(font.bitmap);
	font.color = color;
	return font;
}
void renderBitmapText(std::string text, Vector2 cords, uiBitmapFont &font) {
	int bitmapX, bitmapY, tcX, tcY, count = 0;
	for (char &c : text) {
		bitmapX = ((int)c % font.gridSize);
		bitmapY = ((int)c / font.gridSize);
		tcX = (int)(bitmapX * font.cellSize);
		tcY = (int)(bitmapY * font.cellSize);
		//sf2d_draw_texture_part(font.bitmap, count >= 1 ? cords.x + (font.cellSize - font.offset) * count : cords.x, cords.y, tcX, tcY, font.cellSize - font.offset, font.cellSize);
		sf2d_draw_texture_rotate_cut_scale(font.bitmap, count >= 1 ? cords.x + (font.cellSize - font.offset) * count : cords.x, cords.y, 0.0f, tcX, tcY, font.cellSize - font.offset, font.cellSize, font.scale, font.scale);
		count++;
	}
}