/*
	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
			 © Filiph Sandström 2015

		TODO(In this file):
		* Alot
		CONTRIBUTORS(In this file):
		* Filiph Sandström (filfat)

		   SEE "LICENSE" FOR THE LICENSE
*/
#include "3DS_UI/uiWindow.h"
#include "3DS_UI/uiElement.h"

uiWindow::uiWindow(bool isTopScreen) {
	settings.isTopScreen = isTopScreen;
}

uiWindow::~uiWindow() { }

void uiWindow::render() {
	sf2d_start_frame(settings.isTopScreen ? GFX_TOP : GFX_BOTTOM, GFX_LEFT);
	if (settings.isTopScreen) {
		drawStatusbar(settings.statusbarColor);
		drawNavbar(navbar.navbarColor);
	}

	//Render all the elements
	for (auto element : elements) {
		switch (element->type) {
		case 5: {
			uiRect* rect = (uiRect*)element;
			rect->render();
		}
		}
	}

	sf2d_end_frame();
}

void uiWindow::addElement(uiElement* element) {
	elements.push_back(element);
}

Result uiWindow::removeElement(std::string elementName) {
	s16 x = 0;
	bool elementFound;
	for (uiElement* &element : elements) {
		x++;
		if (element->name == elementName) {
			elements.erase(elements.begin() + x);
			elementFound = true;
		}
	}
	return elementFound ? 0 : -99; //TODO: Error codes
}

void uiWindow::set3D(bool enable3D) {
	if(settings.isTopScreen)
		settings.is3DEnabled = enable3D;
}

void uiWindow::setAppbarColor(RGB appbarColor) {
	settings.appbarColor = appbarColor;
}

void uiWindow::setStatusbarColor(RGB statusbarColor) {
	settings.statusbarColor = statusbarColor;
}

void uiWindow::setNavbarColor(RGB navbarColor) {
	navbar.navbarColor = navbarColor;
}

void uiWindow::setNavbarHeader(std::string header) {
	navbar.header = header;
}
