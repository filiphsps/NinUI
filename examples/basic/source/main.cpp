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

int main() {
	//Initialize services
	srvInit();
	aptInit();
	hidInit(NULL);
	gfxSet3D(true);

	//Init 3DS_UI
	uiInit();
	
	//Creates two windows, one for the upper screen and one for the bottom screen
	uiWindow windowTop =  new uiWindow(true);
	uiWindow windowBottom =  new uiWindow(false);
	windowTop.set3D(true);

	//Creates a new Rect
	uiRect* rect = new uiRect("Rect1");
	RGB bg = {255, 0 , 0};
	rect->configure(50, 50, 40, 40, bg);

	//Adds the element to the window
	windowTop.addElement(rect);

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
		
		//Call when you have rendred the window(s)
		uiFinishRendering();
	}

	//Removes the element
	windowTop.removeElement("Rect1");

	//Exit UI
	uiExit();

	//Deinitialize services
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
