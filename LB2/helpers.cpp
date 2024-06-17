#include "helpers.h"

namespace UI {
	void placeCursorAt(int x, int y) {
		COORD c;
		c.X = x;
		c.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	};

	void setColor(UI::ConsoleColor color) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(color));
	};

	void resetColor() {
		setColor(UI::White);
	};
}

namespace String {
	int getCharLength(const char* input) {
		int length = 0;
		while (input[length] != '\0') length++;
		return length;
	};
}