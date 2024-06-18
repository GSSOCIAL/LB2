#pragma once

#include <iostream>
#include "windows.h"

using namespace std;
namespace UI {
	/// <summary>
	/// Індекси розділів програми
	/// </summary>
	enum MenuIndex {
		Home = 0,
		Analize = 1,
		ManageDb = 2,
		ViewDb = 3,
		ManageKeywords = 4,
		SearchByStudent = 5,
		SearchByTeacher = 6,
		AddRecordForm = 7,
		SearchStudentForm = 8,
		SearchTeacherForm = 9,
		ManageKeywordsForm = 10
	};
	/// <summary>
	/// Індекси кольорів консолі
	/// </summary>
	enum ConsoleColor {
		LightGray = 7,
		Gray = 8,
		Green = 10,
		LightBlue = 11,
		Red = 12,
		White = 15,
		WhiteOnBlue = 23
	};
	/// <summary>
	/// Встановлює курсор консолі на заданий рядок, колонку
	/// </summary>
	/// <param name="x">Координата x (знак)</param>
	/// <param name="y">Координата y (рядок)</param>
	void placeCursorAt(int x, int y);
	/// <summary>
	/// Встановлює колір консолі
	/// </summary>
	/// <param name="color">Колір</param>
	void setColor(UI::ConsoleColor color);
	/// <summary>
	/// Повертає колір консолі до стандартного
	/// </summary>
	void resetColor();
};

namespace String {
	/// <summary>
	/// Кількість символів char*
	/// </summary>
	/// <param name="input"></param>
	/// <returns>Кількість символів</returns>
	int getCharLength(const char* input);
};