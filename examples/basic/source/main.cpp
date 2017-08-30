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

int main () {
	//Initialize services
	srvInit();
	aptInit();
	hidInit();
	
	//Initialize 3DS_UI
	uiInit("Example Application 1");

	//Enable 3D
	uiSet3D(true);

	//Creates two windows, one for the upper screen and one for the bottom screen
	uiWindow* windowTop = new uiWindow(true);
	uiWindow* windowBottom = new uiWindow(false);

	//Creates a new Rectangle
	uiRect* rect = new uiRect("Rect1");
	rect->configure({ 50, 50 }, 72, 72, Colors::Crimson);

	//Create a new uiTextBlock
	uiTextBlock* textBlock = new uiTextBlock("TextBlock1");
	textBlock->configure({ 0, 0 }, OpenSansFont, 22, "FPS: ", Colors::Black);
	
	//Adds all the elements to the selected windows
	windowTop->addElement(rect);
	windowBottom->addElement(textBlock);

	float x = 0; bool x_back = true;
	while (aptMainLoop()) {
		//Return to the launcher if we press 'A'
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_A)
			break;

		//Set textBlock content to FPS
		textBlock->setContent("FPS: " + std::to_string((s16)sf2d_get_fps()));

		if (x_back == false && x >= (SCREEN_TOP_WIDTH - 50))
			x_back = true;
		else if (x_back == true && x <= 0)
			x_back = false;
		rect->configure({x_back ? --x : ++x, x/2}, 72, 72, {x, 255 - x, x, 0xFF});

		//Renders both windows
		windowTop->render();
		windowBottom->render();

		//Call this when you have rendered the window(s)
		uiFinishRendering();
	}

	//Removes the elements
	windowTop->removeElement("Rect1");
	windowBottom->removeElement("TextBlock1");

	//Deinitialize 3DS_UI
	uiExit();

	//Deinitialize services
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
