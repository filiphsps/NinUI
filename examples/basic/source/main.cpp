#include <3ds.h>
#include <3DS_UI.h>
#include <iostream>
#include <vector>
#include <uiElement.h>
#include <uiFonts.h>

int main() {
	srvInit();
	aptInit();
	hidInit(NULL);
	gfxInitDefault();
	gfxSet3D(true);
	uiInit(); //Init
	
	uiWindow windowTop =  createWindow();
	uiWindow windowBottom =  createWindow();
	setWindowMode(true, true, windowTop);
	setWindowMode(false, false, windowBottom);

	uiTextBlock* textBlock = new uiTextBlock("TextBlock1");
	textBlock->configure(0, 0, robootoBlack, "Hello World!");
	windowTop.elements.push_back(textBlock);

	windowTop.navbar.header = "Example 1";

	while (aptMainLoop())
	{
		hidScanInput();

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

		renderWindow(windowTop);
		renderWindow(windowBottom);
	}
	
	uiExit();
	gfxExit();
	return 0;
}
