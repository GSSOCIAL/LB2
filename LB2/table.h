#pragma once

#include <iostream>
#include <string>

#include <conio.h>
#include <cstdarg>
#include <map>
#include <vector>
#include "helpers.h"

using namespace std;
namespace UI {
	struct Cell {
		int width;
		string key;
		string label;
	};

	class Table {
	public:
		Table() {};

		void render(vector<Cell> head, vector<map<string, string>> body);
		void drawCell(string value, int width, UI::ConsoleColor color);
		void drawDivider(int width);
	};
};