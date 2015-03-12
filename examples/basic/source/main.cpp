#include <3ds.h>
#include <3DS_UI.h>

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
