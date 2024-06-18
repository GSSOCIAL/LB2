#include "ui.h"

namespace UI {

	Controller::Controller() : UI::Navigation() {

	};

	void Controller::drawMenu() {
		clear();
		
		//В залежності від обраного розділу меню - будемо виводити різний зміст
		switch (selectedMenuIndex) {
		//Головне меню
		case UI::MenuIndex::Home:
			drawHeader("Головне меню");
			drawVerticalNavigation(
				xScreenOffset,
				4,
				"Аналіз назви кваліфікаційної роботи",
				"Поповнити базу даних",
				"Перегляд бази даних кафедри",
				"Додати ключові слова",
				"Пошук робіт за прізвищем автора",
				"Пошук робіт за прізвищем керівника"
				, NULL);
			resetColor();

			UI::placeCursorAt(xScreenOffset, yScreenOffset+1);
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[Стрілки вгору - вниз]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - Навігація по меню ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - Перехід до розділу меню";
			break;
		//Розділ аналізу назви
		case UI::MenuIndex::Analize:
			drawHeader("Аналіз назви кваліфікаційної роботи");
			UI::placeCursorAt(xScreenOffset, yScreenOffset + 1);
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - Повернутись до головного меню ";
			resetColor();
			break;
		//Розділ створення ключових слів
		case UI::MenuIndex::ManageKeywords:
		case UI::MenuIndex::ManageKeywordsForm:
			drawHeader("Додати ключові слова");
			UI::placeCursorAt(xScreenOffset, yScreenOffset + 1);
			resetColor();
			break;
		//Розділ створення записів бази кваліфікаційних робіт
		case UI::MenuIndex::ManageDb:
		case UI::MenuIndex::AddRecordForm:
			drawHeader("Поповнити базу даних");
			UI::placeCursorAt(xScreenOffset, yScreenOffset + 1);
			resetColor();
			break;
		//Перегляд бази квал. робіт
		case UI::MenuIndex::ViewDb:
			drawHeader("Перегляд бази даних кафедри");
			UI::placeCursorAt(xScreenOffset, yScreenOffset + 1);
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - Повернутись до головного меню ";
			resetColor();
			break;
		//Пошук робіт за ПІБ керівника
		case UI::MenuIndex::SearchByTeacher:
		case UI::MenuIndex::SearchTeacherForm:
			drawHeader("Пошук робіт за прізвищем керівника");
			resetColor();
			break;
		//Пошук робіт за ПІБ студента
		case UI::MenuIndex::SearchByStudent:
		case UI::MenuIndex::SearchStudentForm:
			drawHeader("Пошук робіт за прізвищем автора");
			resetColor();
			break;
		default:
			break;
		};
	};

	void Controller::clear() {
		cout << "\033c";
	};

	void Controller::drawHeader(string title) {
		placeCursorAt(xScreenOffset, yScreenOffset);
		print(title, UI::ConsoleColor::LightBlue);
	};

	void Controller::drawVerticalNavigation(int x, int y, const char* arg, ...) {
		va_list args;
		placeCursorAt(x, y);
		int i = 0;
		for (va_start(args, arg); arg != NULL; arg = va_arg(args, const char*)) {
			placeCursorAt(x, y + i);
			if (getNavigationVerticalIndex() == i) {
				setColor(UI::ConsoleColor::Red);
			}
			else {
				setColor(UI::ConsoleColor::White);
			}
			cout << "|" << arg;
			i++;
		};
		setVerticalLength(i);
		va_end(args);
	};

	void Controller::drawHorizontalNavigation(int x, int y, const char* arg, ...) {
		va_list args;
		placeCursorAt(x, y);
		int width = 0;
		int i = 0;
		for (va_start(args, arg); arg != NULL; arg = va_arg(args, const char*)) {
			placeCursorAt(x + width, y);
			if (getNavigationHorizontalIndex() == i) {
				setColor(UI::ConsoleColor::Red);
			}
			else {
				setColor(UI::ConsoleColor::White);
			}
			cout << "|" << arg;
			i++;
			width += String::getCharLength(arg);
		};
		setHorizontalLength(i);
		va_end(args);
	};

	void Controller::drawList(vector<map<string, string>> list) {
		for (const auto& row : list) {
			for (const auto& pair : row) {
				cout << pair.second;
			};
		};
	}; 
	
	void Controller::drawTable(vector<UI::Cell> head, vector<map<string, string>> body) {
		Table table;
		table.render(head, body);
	};


	void Controller::onNavigationItemSelect() {
		if (selectedMenuIndex == UI::MenuIndex::Home) {
			int index = getNavigationVerticalIndex();
			selectedMenuIndex = UI::MenuIndex(index+1);
		}
		else if (selectedMenuIndex == UI::MenuIndex::ManageDb) {
			selectedMenuIndex = UI::MenuIndex::AddRecordForm;
		}
		else if (selectedMenuIndex == UI::MenuIndex::SearchByStudent) {
			selectedMenuIndex = UI::MenuIndex::SearchStudentForm;
		}
		else if (selectedMenuIndex == UI::MenuIndex::SearchByTeacher) {
			selectedMenuIndex = UI::MenuIndex::SearchTeacherForm;
		}
		else if (selectedMenuIndex == UI::MenuIndex::ManageKeywords) {
			selectedMenuIndex = UI::MenuIndex::ManageKeywordsForm;
		}
	};

	void Controller::onEscape() {
		if (selectedMenuIndex != UI::MenuIndex::Home) {
			selectedMenuIndex = UI::MenuIndex::Home;
		}
	};
}