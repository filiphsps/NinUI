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
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "defines.h"

/**
* @brief Converts HEX to RGB
* @param hexValue the HEX code
* @return the colour in RGB format
* 
* Example Usage:
* @code
*   RGB colour = convertHexToRGB(0xFFFFFF);
* @endcode
*/
RGB convertHexToRGB(int hexValue);

void drawStatusbar(RGB color);
void drawNavbar(RGB color);

/**
* @brief Finishes drawing the current frame
*/
void uiFinishRendering();

/**
* @brief Sets the background colour
* @param color the colour
*
* Example Usage:
* @code
*   setBackgroundColor(Colours::Red);
* @endcode
*/
void setBackgroundColor(RGB color);