#include "ui.h"

namespace UI {

	Controller::Controller() : UI::Navigation() {

	};

	void Controller::drawMenu() {
		clear();
		switch (selectedMenuIndex) {
		case UI::Home:
			drawHeader("������� ����");
			drawVerticalNavigation(
				xScreenOffset,
				4,
				"����� ����� ������������� ������",
				"��������� ���� �����",
				"�������� ���� ����� �������",
				"������ ������ �����",
				"����� ���� �� �������� ������",
				"����� ���� �� �������� ��������"
				, NULL);
			resetColor();
			UI::placeCursorAt(xScreenOffset, yScreenOffset+1);
			UI::setColor(UI::WhiteOnBlue);
			cout << "[������ ����� - ����]";
			UI::setColor(UI::Gray);
			cout << " - �������� �� ���� ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::Gray);
			cout << " - ������� �� ������ ����";
			break;
		case UI::Analize:
			drawHeader("����� ����� ������������� ������");
			UI::placeCursorAt(xScreenOffset, yScreenOffset + 1);
			resetColor();
			break;
		case UI::ManageDb:
		case UI::AddRecordForm:
			drawHeader("��������� ���� �����");
			UI::placeCursorAt(xScreenOffset, yScreenOffset + 1);
			resetColor();
			break;
		case UI::ViewDb:
			drawHeader("�������� ���� ����� �������");
			UI::placeCursorAt(xScreenOffset, yScreenOffset + 1);
			UI::setColor(UI::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::Gray);
			cout << " - ����������� �� ��������� ���� ";
			resetColor();
			break;
		case UI::SearchByManager:
			drawHeader("����� ���� �� �������� ��������");
			resetColor();
			break;
		case UI::SearchByStudent:
			drawHeader("����� ���� �� �������� ������");
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
		print(title, UI::LightBlue);
	};

	void Controller::drawVerticalNavigation(int x, int y, const char* arg, ...) {
		va_list args;
		placeCursorAt(x, y);
		int i = 0;
		for (va_start(args, arg); arg != NULL; arg = va_arg(args, const char*)) {
			placeCursorAt(x, y + i);
			if (getNavigationVerticalIndex() == i) {
				setColor(UI::Red);
			}
			else {
				setColor(UI::White);
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
				setColor(UI::Red);
			}
			else {
				setColor(UI::White);
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
		if (selectedMenuIndex == UI::Home) {
			int index = getNavigationVerticalIndex();
			selectedMenuIndex = UI::MenuIndex(index+1);
		}
		else if (selectedMenuIndex == UI::ManageDb) {
			selectedMenuIndex = UI::MenuIndex::AddRecordForm;
		}
	};

	void Controller::onEscape() {
		if (selectedMenuIndex != UI::Home) {
			selectedMenuIndex = UI::Home;
		}
	};
}