/*
	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|

	  EXAMPLE 1 "Basic
	  © Filiph Sandström 2015-2017
	  SEE "LICENSE" FOR THE LICENSE
*/

//Required classes for 3DS_UI
#include <3ds.h>
#include <iostream>
#include <vector>
#include <3DS_UI.h>

//Button clicks
int clicks = 0;

int main () {
	//Initialize services
	srvInit();
	aptInit();
	hidInit();
	
	//Initialize 3DS_UI
	uiInit("Example Application 1");

	//Enable 3D
	uiSet3D(false);

	//Creates two windows, one for the upper screen and one for the bottom screen
	uiWindow* windowTop = new uiWindow(true);
	uiWindow* windowBottom = new uiWindow(false);

	//Creates a new uiRect
	uiRect* rect = new uiRect("Rect1");
	rect->configure({ 50, 50 }, 72, 72, Colors::Crimson);

	//Create a new uiTextBlock
	uiTextBlock* textBlock = new uiTextBlock("TextBlock1");
	textBlock->configure({ 0, 0 }, OpenSansFont, 22, "FPS: ", Colors::Black);

	//Create a new uiButton
	uiButton* button = new uiButton("Button1");
	button->configure({ 20, SCREEN_BOTTOM_HEIGHT - (35 + 20) }, SCREEN_BOTTOM_WIDTH - 40, 35, OpenSansFont, 16, "A button will center the text", Colors::Red);
	button->onClick([=](){
		button->setColor(Colors::Purple);
		button->setContent(std::to_string(++clicks));
	});
	
	//Adds all the elements to the selected windows
	windowTop->addElement(rect);
	windowBottom->addElement(textBlock);
	windowBottom->addElement(button);

	float x = 65; bool x_back = true;
	while (aptMainLoop()) {
		//Return to the launcher if we press 'A'
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_A)
			break;

		//Set textBlock content to the FPS
		textBlock->setContent("FPS: " + std::to_string((s16)sf2d_get_fps()));

		//Make the rectangle bounce and change color
		if (x_back == false && x >= 255)
			x_back = true;
		else if (x_back == true && x <= 65)
			x_back = false;
		rect->configure({x_back ? --x : ++x, x/2}, 72, 72, {(u8)x, (u8)(255 - x), (u8)(255 - x), 0xFF});

		//Render both windows
		windowTop->render();
		windowBottom->render();

		//Complete the rendering
		uiFinishRendering();
	}

	//Remove the elements
	windowTop->removeElement("Rect1");
	windowBottom->removeElement("TextBlock1");
	windowBottom->removeElement("Button1");

	//Deinitialize 3DS_UI
	uiExit();

	//Deinitialize services
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
