#include <string.h>
#include <3ds.h>
#include <3DS_UI.h>

int main()
{
	srvInit();
	aptInit();
	hidInit(NULL);
	gfxInitDefault();
	fsInit();
	sdmcInit();
	//gfxSet3D(true);
	uiInit();
	gspWaitForVBlank();
	
	uiWindow windowTop =  createWindow();
	uiWindow windowBottom =  createWindow();
	setWindowMode(true, false, windowTop);
	setWindowMode(false, false, windowBottom);
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
