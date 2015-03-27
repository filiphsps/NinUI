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
#include "3DS_UI/defines.h"

/**
* @brief font struct
*/
struct uiFont {
	sf2d_texture* bitmap;
	s16 cellHeight, cellWidth, gridSize;
	RGB color;
};

uiFont readFont(u8* bitmap, s16 cellHeight, s16 cellWidth, s16 gridSize, s16 texWidthAndHeight, RGB color);
uiFont removeFont(uiFont &font);
void renderText(std::string text, Vector2 cords, uiFont &font);