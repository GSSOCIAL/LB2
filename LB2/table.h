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
	/// UI ������� ����������� ������� � ������
	/// </summary>
	class Table {
	public:
		Table() {};
		/// <summary>
		/// ����� ������� �� ������
		/// </summary>
		/// <param name="head">������ ������� �� ����� ����������</param>
		/// <param name="body">������ ������ �������</param>
		void render(vector<Cell> head, vector<map<string, string>> body);
		/// <summary>
		/// ����� ������ �������
		/// </summary>
		/// <param name="value">�������� ������</param>
		/// <param name="width">ʳ������ ������� (������) ������</param>
		/// <param name="color">���� ������</param>
		void drawCell(string value, int width, UI::ConsoleColor color);
		/// <summary>
		/// ����� ������������� �������� ���
		/// </summary>
		/// <param name="width">ʳ������ ������� (������) ����</param>
		void drawDivider(int width);
	};
};