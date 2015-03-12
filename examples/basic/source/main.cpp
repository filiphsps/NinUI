#include <string.h>

#include <3ds.h>
#include <3DS_UI.h>

int main()
{
	gfxInitDefault();
	gfxSet3D(true);
	uiInit();
	
	uiWindow window1 =  createWindow();
	
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		hidScanInput();
		
		

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
		
		gfxFlushBuffers();
		gfxSwapBuffers();
	}
	
	uiExit();
	gfxExit();
	return 0;
}
