/*
	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
					EXAMPLE 1
			 © Filiph Sandström 2015

		   SEE "LICENSE" FOR THE LICENSE
*/

//Required classes for 3DS_UI
#include <3ds.h>
#include <iostream>
#include <vector>
#include <3DS_UI.h>
#include <uiElement.h>

int main() {
	//Initialize services
	srvInit();
	aptInit();
	hidInit(NULL);
	gfxInitDefault();
	gfxSet3D(true);

	//Init 3DS_UI
	uiInit();
	
	//Creates two windows, one for the upper screen and one for the bottom screen
	uiWindow windowTop =  createWindow();
	uiWindow windowBottom =  createWindow();
	setWindowMode(true, true, windowTop);
	setWindowMode(false, false, windowBottom);

	//Creates a new TextBlock
	uiTextBlock* textBlock = new uiTextBlock("TextBlock1");
	textBlock->configure(0, 0, robootoBlack, "Hello World!");

	//Adds the element(s) to the window(s)
	addElement(windowTop, textBlock);

	//Sets the upper window's header
	windowTop.navbar.header = "Example 1";

	while (aptMainLoop())
	{
		//Return to the launcher if we press 'A'
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_A)
			break;

		//Renders both windows
		renderWindow(windowTop);
		renderWindow(windowBottom);
	}

	//Removes the element
	removeElement(windowTop, "TextBlock1");

	//Frees up the memory used by the windows
	deleteWindow(windowTop);
	deleteWindow(windowBottom);

	//Exit UI
	uiExit();

	//Deinitialize services
	gfxExit();
	return 0;
}
