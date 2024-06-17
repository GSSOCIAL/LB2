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
	/// 
	/// </summary>
	class Controller: public UI::Navigation {
	public:
		Controller();

		/// <summary>
		/// 
		/// </summary>
		void drawMenu();

		/// <summary>
		/// 
		/// </summary>
		void clear();

		/// <summary>
		/// 
		/// </summary>
		/// <param name="title"></param>
		void drawHeader(string title);

		/// <summary>
		/// 
		/// </summary>
		void drawVerticalNavigation(int x, int y, const char* arg, ...);
		void drawHorizontalNavigation(int x, int y, const char* arg, ...);

		void drawList(vector<map<string,string>> list);
		void drawTable(vector<UI::Cell> head, vector<map<string, string>> body);

		void print(string content, UI::ConsoleColor color) {
			setColor(color);
			cout << content;
		};

		UI::MenuIndex getActiveMenu() {
			return selectedMenuIndex;
		};
		void onNavigationItemSelect() override;
		void onEscape() override;

		int getXScreenOffset() {
			return xScreenOffset;
		};

		int getYScreenOffset() {
			return yScreenOffset;
		};

		vector<UI::Cell> defaultTableHead = {
			{18,"teacher","ПІБ керівніка"},
			{18,"student","ПІБ здобувача"},
			{24,"title","Тема"},
			{18,"group","Группа"},
			{6,"year","Рік"},
		};
	private:
		/// <summary>
		/// 
		/// </summary>
		MenuIndex selectedMenuIndex = MenuIndex::Home;
	protected:
		int xScreenOffset = 1;
		int yScreenOffset = 1;
	};
};