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
	/// Помічник для відображення елементів консолі
	/// </summary>
	class Controller: public UI::Navigation {
	public:
		Controller();

		/// <summary>
		/// Друкує навігаційне меню
		/// </summary>
		void drawMenu();
		/// <summary>
		/// Очистити консоль
		/// </summary>
		void clear();
		/// <summary>
		/// Друкує заголовок
		/// </summary>
		/// <param name="title">Заголовок</param>
		void drawHeader(string title);
		/// <summary>
		/// Додати вертикальне меню
		/// </summary>
		/// <param name="x">Початкова координата x</param>
		/// <param name="y">Початкова координата y</param>
		/// <param name="arg">Розділи меню</param>
		void drawVerticalNavigation(int x, int y, const char* arg, ...);
		/// <summary>
		/// Додати горизонтальне меню
		/// </summary>
		/// <param name="x">Початкова координата x</param>
		/// <param name="y">Початкова координата y</param>
		/// <param name="arg">Розділи меню</param>
		void drawHorizontalNavigation(int x, int y, const char* arg, ...);
		/// <summary>
		/// Друкує список
		/// </summary>
		/// <param name="list"></param>
		void drawList(vector<map<string,string>> list);
		/// <summary>
		/// Відобразити таблицю
		/// </summary>
		/// <param name="head">Комірки</param>
		/// <param name="body">Список записів таблиці</param>
		void drawTable(vector<UI::Cell> head, vector<map<string, string>> body);
		/// <summary>
		/// Вивести вміст із зазначенним кольором
		/// </summary>
		/// <param name="content"></param>
		/// <param name="color"></param>
		void print(string content, UI::ConsoleColor color) {
			setColor(color);
			cout << content;
		};
		/// <summary>
		/// Активний розділ меню
		/// </summary>
		/// <returns></returns>
		UI::MenuIndex getActiveMenu() {
			return selectedMenuIndex;
		};
		/// <summary>
		/// Колбек коли обран розділ меню
		/// </summary>
		void onNavigationItemSelect() override;
		/// <summary>
		/// Колбек коли натиснута кнопка ESC
		/// </summary>
		void onEscape() override;
		int getXScreenOffset() {
			return xScreenOffset;
		};
		int getYScreenOffset() {
			return yScreenOffset;
		};
		/// <summary>
		/// Превстановленна шапка таблиці
		/// </summary>
		vector<UI::Cell> defaultTableHead = {
			{18,"teacher","ПІБ керівніка"},
			{18,"student","ПІБ автора"},
			{24,"title","Тема роботи"},
			{18,"group","Академічна группа"},
			{6,"year","Рік"},
		};
	private:
		MenuIndex selectedMenuIndex = MenuIndex::Home;
	protected:
		int xScreenOffset = 1;
		int yScreenOffset = 1;
	};
};