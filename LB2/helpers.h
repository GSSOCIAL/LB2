#pragma once

#include <iostream>
#include "windows.h"

using namespace std;
namespace UI {
	/// <summary>
	/// 
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
		SearchTeacherForm = 9
	};
	/// <summary>
	/// 
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
		/// 
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
	void placeCursorAt(int x, int y);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="color"></param>
	void setColor(UI::ConsoleColor color);

	/// <summary>
	/// 
	/// </summary>
	void resetColor();
};

namespace String {
	int getCharLength(const char* input);
};