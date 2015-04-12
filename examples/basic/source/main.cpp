/*
	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
				EXAMPLE 1 "Basic"
			 © Filiph Sandström 2015

		   SEE "LICENSE" FOR THE LICENSE
*/

//Required classes for 3DS_UI
#include <3ds.h>
#include <iostream>
#include <vector>
#include <3DS_UI.h>
#include <3DS_UI/Fonts/OpenSans_Regular.h>

#include "img.h"
//#include "img_png.h"

int main() {
	//Initialize services
	srvInit();
	aptInit();
	hidInit(NULL);
	
	//Init 3DS_UI
	uiInit();

	//Enable 3D
	uiSet3D(true);

	//Creates two windows, one for the upper screen and one for the bottom screen
	uiWindow windowTop = uiWindow(true);
	uiWindow windowBottom = uiWindow(false);
	windowTop.set3D(true);

	//Creates a new Rect
	uiImage* image = new uiImage("Img1");
	image->configure({ 0, 0 }, 240, 240, uiCreateTexture((u8*)img.pixel_data, "RAW", img.width, img.height), { 1,1 });

	//Create a copy of the default font & set the size
	uiTtfFont Font = OpenSansFont;

	//Creates a textBlock
	uiTextBlock* textBlock = new uiTextBlock("TextBlock1");
	textBlock->configure({ 5, 20 }, Font, "Hello World!", Colors::Green);
	
	//Adds the elements to the selected windows
	windowTop.addElement(image);
	windowBottom.addElement(textBlock);

	//Sets the windowTop's navbar header
	windowTop.setNavbarHeader("Example 1");

	while (aptMainLoop())
	{
		//Return to the launcher if we press 'A'
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_A)
			break;

		//Renders both windows
		
		windowTop.render();
		windowBottom.render();

		//Call this when you have rendered the window(s)
		uiFinishRendering();
	}

	//Removes the elements
	windowTop.removeElement("Img1");
	windowBottom.removeElement("TextBlock1");

	//Exit UI
	uiExit();

	//Deinitialize services
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
