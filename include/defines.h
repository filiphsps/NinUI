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

/* Screen */
#define SCREEN_TOP_HEIGHT 240
#define SCREEN_TOP_WIDTH 400
#define SCREEN_BOTTOM_HEIGHT 240
#define SCREEN_BOTTOM_WIDTH 320

 /* Standard UI */
#define STATUSBAR_H 12
#define NAVBAR_H 36
#define NAVBAR_HEADER_Y ((STATUSBAR_H + (NAVBAR_H/4)*3)+2)
#define APPBAR_H 18
#define SHADOW_ANGLE 135
#define AVAILABLE_SCREEN_TOP_HEIGHT (SCREEN_TOP_HEIGHT - (STATUSBAR_H + NAVBAR_H))
#define AVAILABLE_SCREEN_TOP_WIDTH 400
#define UIPOPUP_HEADER_X 41
#define UIPOPUP_HEADER_Y 83

/* Colours */
#define WHITE	0xFFFFFF
#define BLACK	0x000000
#define GRAY	0x95a5a6
#define BLUE	0x3498db
#define RED		0xe74c3c
#define PURPLE	0x9b59b6
#define ORANGE	0xe67e22
#define GREEN	0x2ecc71
#define YELLOW	0xf1c40f

#define DEBUG