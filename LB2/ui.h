#pragma once

#include <iostream>
#include <string>
#include "locale.h"

#include <conio.h>
#include <cstdarg>
#include "navigation.h"
#include "QualifyingManager.h"
#include "table.h"
#include "helpers.h"

using namespace std;
namespace UI {
	/// <summary>
	/// ������� ��� ����������� �������� ������
	/// </summary>
	class Controller: public UI::Navigation {
	public:
		Controller();

		/// <summary>
		/// ����� ���������� ����
		/// </summary>
		void drawMenu();
		/// <summary>
		/// �������� �������
		/// </summary>
		void clear();
		/// <summary>
		/// ����� ���������
		/// </summary>
		/// <param name="title">���������</param>
		void drawHeader(string title);
		/// <summary>
		/// ������ ����������� ����
		/// </summary>
		/// <param name="x">��������� ���������� x</param>
		/// <param name="y">��������� ���������� y</param>
		/// <param name="arg">������ ����</param>
		void drawVerticalNavigation(int x, int y, const char* arg, ...);
		/// <summary>
		/// ������ ������������� ����
		/// </summary>
		/// <param name="x">��������� ���������� x</param>
		/// <param name="y">��������� ���������� y</param>
		/// <param name="arg">������ ����</param>
		void drawHorizontalNavigation(int x, int y, const char* arg, ...);
		/// <summary>
		/// ����� ������
		/// </summary>
		/// <param name="list"></param>
		void drawList(vector<map<string,string>> list);
		/// <summary>
		/// ³��������� �������
		/// </summary>
		/// <param name="head">������</param>
		/// <param name="body">������ ������ �������</param>
		void drawTable(vector<UI::Cell> head, vector<map<string, string>> body);
		/// <summary>
		/// ������� ���� �� ����������� ��������
		/// </summary>
		/// <param name="content"></param>
		/// <param name="color"></param>
		void print(string content, UI::ConsoleColor color) {
			setColor(color);
			cout << content;
		};
		/// <summary>
		/// �������� ����� ����
		/// </summary>
		/// <returns></returns>
		UI::MenuIndex getActiveMenu() {
			return selectedMenuIndex;
		};
		/// <summary>
		/// ������ ���� ����� ����� ����
		/// </summary>
		void onNavigationItemSelect() override;
		/// <summary>
		/// ������ ���� ��������� ������ ESC
		/// </summary>
		void onEscape() override;
		int getXScreenOffset() {
			return xScreenOffset;
		};
		int getYScreenOffset() {
			return yScreenOffset;
		};
		/// <summary>
		/// ��������������� ����� �������
		/// </summary>
		vector<UI::Cell> defaultTableHead = {
			{18,"teacher","ϲ� �������"},
			{18,"student","ϲ� ������"},
			{24,"title","���� ������"},
			{18,"group","��������� ������"},
			{6,"year","г�"},
		};
	private:
		MenuIndex selectedMenuIndex = MenuIndex::Home;
	protected:
		int xScreenOffset = 1;
		int yScreenOffset = 1;
	};
};