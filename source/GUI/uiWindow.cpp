#include "3DS_UI/GUI/uiWindow.h"
#include "3DS_UI/GUI/uiElement.h"

uiWindow::uiWindow() {
	
}
uiWindow::uiWindow(bool isTopScreen) {
	settings.isTopScreen = isTopScreen;
}

uiWindow::~uiWindow() {

}

void uiWindow::render() {
	bool isLeft = true;

	sf2d_start_render();
	sf2d_set_render_screen(settings.isTopScreen ? GFX_TOP : GFX_BOTTOM, GFX_LEFT);

	if (settings.isTopScreen) {
		//TODO
	} else {
		//touchPosition tp;

		//hidScanInput();
		//hidTouchRead(&tp);
		//u32 kDown = hidKeysDown();

		/*if (kDown & KEY_TOUCH) {
			for (auto element : elements) {
				auto x = tp.px;
				auto y = 240 - tp.py;

				if (x >= element->x && x <= (x + element->w))
					if (y >= element->y && y <= (y + element->h))
						element->e_onclick();
			}
		}*/
	}
	
	//Render all the elements
	for (auto element : elements) {
		switch (element->type) {
			case uiElement_Types::TextBlock: {
				uiTextBlock* textBlock = (uiTextBlock*)element;
				textBlock->render(settings.isTopScreen, isLeft);
				break;
			}
			case uiElement_Types::Rectangle: {
				uiRect* rect = (uiRect*)element;
				rect->render(settings.isTopScreen, isLeft);
				break;
			}
			default:
				break;
		}
	}
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
			delete element;
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

void uiWindow::setScreen(bool isTop) {
	settings.isTopScreen = isTop;
}
