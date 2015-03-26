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
	uiWindow windowBottom =  uiWindow(false);
	windowTop.set3D(true);

	//Creates a few new Rects
	uiRect* rect = new uiRect("Rect1");
	rect->configure(50, 70, 40, 40, Colors::Magenta);
	uiRect* rect2 = new uiRect("Rect2");
	rect2->configure(50, 120, 40, 40, Colors::Red);
	uiRect* rect3 = new uiRect("Rect3");
	rect3->configure(50, 170, 40, 40, Colors::Black);

	//Adds the elements to the window
	windowBottom.addElement(rect);
	windowBottom.addElement(rect2);
	windowBottom.addElement(rect3);

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

	//Removes the elements
	windowBottom.removeElement("Rect1");
	windowBottom.removeElement("Rect2");
	windowBottom.removeElement("Rect3");

	//Exit UI
	uiExit();

	//Deinitialize services
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
