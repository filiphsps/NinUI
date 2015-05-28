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

int main() {
	//Initialize services
	srvInit();
	aptInit();
	hidInit(NULL);
	
	//Initialize 3DS_UI
	uiInit("Example Application 1");

	//Enable 3D
	uiSet3D(true);

	//Creates two windows, one for the upper screen and one for the bottom screen
	uiWindow* windowTop = new uiWindow(true);
	uiWindow* windowBottom = new uiWindow(false);

	//Creates a new Rectangle
	uiRect* rect = new uiRect("Rect1");
	rect->configure({ 50, 70 }, 172, 72, Colors::Green);

	//Create a new font object from the Open Sans font
	uiTtfFont Font = OpenSansFont;

	//Create a new uiTextBlock
	uiTextBlock* textBlock = new uiTextBlock("TextBlock1");
	textBlock->configure({ 0, 10 }, Font, "Hello World!", Colors::Black);
	
	//Adds all the elements to the selected windows
	windowTop->addElement(rect);
	windowBottom->addElement(textBlock);

	//Sets the windowTop's navbar header
	windowTop->setNavbarHeader("Example 1");

	while (aptMainLoop())
	{
		//Return to the launcher if we press 'A'
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_A)
			break;

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
