#include "navigation.h"

void UI::Navigation::setKey(char key) {
	_key = key;
	if (key == 72) {
		if (activeVerticalIndex > 0) {
			activeVerticalIndex--;
		}
	}
	else if (key == 80) {
		if (activeVerticalIndex < activeVerticalLength) {
			activeVerticalIndex++;
		}
	}
	else if (key == 75) {
		if (activeHorizontalIndex > 1) {
			activeHorizontalIndex--;
		}
	}
	else if (key == 77) {
		if (activeHorizontalIndex < activeHorizontalLength) {
			activeHorizontalIndex++;
		}
	}
	else if (key == '\r') {
		onNavigationItemSelect();
	}
	if (GetAsyncKeyState(VK_ESCAPE)) {
		onEscape();
	}
};