#include "table.h"

namespace UI {
	void Table::render(vector<Cell> head, vector<map<string, string>> body) {
		//Дізнаємось загальну ширину всіх комірок
		int width = -1;
		for (UI::Cell cell : head) {
			width += cell.width+1;
		}

		drawDivider(width);
		for (UI::Cell cell : head) {
			drawCell(cell.label, cell.width, UI::ConsoleColor::Gray);
		}

		setColor(UI::ConsoleColor::Gray);
		cout << "|" << endl;
		drawDivider(width);
		
		// Для кожного рядка надрукуємо кожну комірку шапки
		for (const auto& row : body) {
			for (UI::Cell cell : head) {
				string value = "";
				if (row.find(cell.key) != row.end()) {
					value = row.at(cell.key);
				}
				drawCell(value, cell.width, UI::ConsoleColor::White);
			}
			setColor(UI::ConsoleColor::Gray);
			cout << "|" << endl;
			drawDivider(width);
		}
	};

	void Table::drawCell(string value, int width, UI::ConsoleColor color) {
		setColor(UI::ConsoleColor::Gray);
		cout << "|";
		setColor(color);
		cout << " " << value;
		
		//Додамо пробіли щоб "добити" ширину комірки
		int dif = width - value.length();
		if (dif > 0) {
			int i = 0;
			while (i < (dif - 1)) {
				cout << " ";
				i++;
			}
		}
	};

	void Table::drawDivider(int width) {
		setColor(UI::ConsoleColor::Gray);
		cout << " "; 
		int i = 0;
		while (i < width && width >= 0) {
			cout << "-";
			i++;
		}
		cout << endl;
	};
};