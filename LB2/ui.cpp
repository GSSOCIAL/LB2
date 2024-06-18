#include "ui.h"

namespace UI {

	Controller::Controller() : UI::Navigation() {

	};

	void Controller::drawMenu() {
		clear();
		
		//� ��������� �� �������� ������ ���� - ������ �������� ����� ����
		switch (selectedMenuIndex) {
		//������� ����
		case UI::MenuIndex::Home:
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
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[������ ����� - ����]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - �������� �� ���� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ������� �� ������ ����";
			break;
		//����� ������ �����
		case UI::MenuIndex::Analize:
			drawHeader("����� ����� ������������� ������");
			UI::placeCursorAt(xScreenOffset, yScreenOffset + 1);
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ����������� �� ��������� ���� ";
			resetColor();
			break;
		//����� ��������� �������� ���
		case UI::MenuIndex::ManageKeywords:
		case UI::MenuIndex::ManageKeywordsForm:
			drawHeader("������ ������ �����");
			UI::placeCursorAt(xScreenOffset, yScreenOffset + 1);
			resetColor();
			break;
		//����� ��������� ������ ���� �������������� ����
		case UI::MenuIndex::ManageDb:
		case UI::MenuIndex::AddRecordForm:
			drawHeader("��������� ���� �����");
			UI::placeCursorAt(xScreenOffset, yScreenOffset + 1);
			resetColor();
			break;
		//�������� ���� ����. ����
		case UI::MenuIndex::ViewDb:
			drawHeader("�������� ���� ����� �������");
			UI::placeCursorAt(xScreenOffset, yScreenOffset + 1);
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ����������� �� ��������� ���� ";
			resetColor();
			break;
		//����� ���� �� ϲ� ��������
		case UI::MenuIndex::SearchByTeacher:
		case UI::MenuIndex::SearchTeacherForm:
			drawHeader("����� ���� �� �������� ��������");
			resetColor();
			break;
		//����� ���� �� ϲ� ��������
		case UI::MenuIndex::SearchByStudent:
		case UI::MenuIndex::SearchStudentForm:
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