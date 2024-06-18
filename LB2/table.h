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

	/// <summary>
	/// UI помічник відображення таблиць у консолі
	/// </summary>
	class Table {
	public:
		Table() {};
		/// <summary>
		/// Друкує таблицю до консолі
		/// </summary>
		/// <param name="head">Список колонок які треба відобразити</param>
		/// <param name="body">Список записів таблиці</param>
		void render(vector<Cell> head, vector<map<string, string>> body);
		/// <summary>
		/// Друкує комірку таблиці
		/// </summary>
		/// <param name="value">Значення комірки</param>
		/// <param name="width">Кількість символів (ширина) комірки</param>
		/// <param name="color">Колір комірки</param>
		void drawCell(string value, int width, UI::ConsoleColor color);
		/// <summary>
		/// Друкує горизонтальну розділову лінію
		/// </summary>
		/// <param name="width">Кількість символів (ширина) лішії</param>
		void drawDivider(int width);
	};
};