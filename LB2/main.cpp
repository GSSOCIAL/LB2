#include "main.h"

int main(){
	setLanguageSupport();

	UI::Controller ui;
	Controllers::QualifyingManager qfManager("db.txt");
	Controllers::KeywordsManager keywords("keywords.txt");

	for (int i = 0;;) {
		ui.drawMenu();

		//� ��������� �� �������� ������ ���� - ���������� �������� ����
		if (ui.getActiveMenu() == UI::MenuIndex::ManageDb) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);
			
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " � ����� ����� ����� ������ ������������� ������ �� ���� ������." << endl;
			cout << " ��������� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� �������� ����� �����, ��� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� ����������� � ������� ����" << endl;
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::Analize) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);

			vector<map<string, string>> results = keywords.analize(qfManager.getList());

			if (results.empty()) {
				UI::setColor(UI::ConsoleColor::Red);
				cout << "������ ��� ������ �� ��������.";
			}
			else {
				vector<UI::Cell> head = {
					{18,"title","���� ������"},
					{13,"result","���������"},
					{18,"teacher","ϲ� �������"},
					{18,"student","ϲ� ������"},
					{18,"keyword","������� �����"},
				};
				ui.drawTable(head, results);
			}
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::AddRecordForm) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);
			Models::QualifyingWork item;
			UI::resetColor();

			cout << " ������ ϲ� �������: ";
			getline(cin, item.teacherName);
			cout << " ������ ϲ� ���������: ";
			getline(cin, item.studentName);
			cout << " ������ ��������� �����: ";
			getline(cin, item.group);
			cout << " ������ ���� ������������� ������: ";
			getline(cin, item.title);
			string year;
			cout << " ������ ��: ";
			getline(cin, year);
			item.year = stoi(year);

			qfManager.addItem(item, true);

			UI::setColor(UI::ConsoleColor::Green);
			cout << endl << " ����� ��������! " << endl;
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " ��������� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� �������� ����� �����, ��� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� ����������� � ������� ����" << endl;
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::ViewDb) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);
			ui.drawTable(ui.defaultTableHead,qfManager.toMap(qfManager.getList()));
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::ManageKeywords) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);

			UI::setColor(UI::ConsoleColor::Gray);
			cout << " � ����� ����� ����� ������ ������ ����� �� ���� ������." << endl;
			cout << " ��������� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� �������� ����� �����, ��� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� ����������� � ������� ����" << endl;
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::ManageKeywordsForm) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);
			Models::Keyword item;
			UI::resetColor();

			cout << " ������ ������� ����� ��� ������� ������: ";
			getline(cin, item.value);

			keywords.addItem(item, true);

			UI::setColor(UI::ConsoleColor::Green);
			cout << endl << " ����� ��������! " << endl;
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " ��������� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� �������� ����� �����, ��� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� ����������� � ������� ����" << endl;
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::SearchByStudent) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);

			UI::setColor(UI::ConsoleColor::Gray);
			cout << " � ����� ����� ����� ������ ������������� ������ �� ϲ� ������" << endl;
			cout << " ��������� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� ������ �����, ��� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� ����������� � ������� ����" << endl;
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::SearchStudentForm) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);

			string query;
			cout << " ������ ϲ� ������ ��� ������ ����: ";
			getline(cin, query);

			vector<Models::QualifyingWork> results = qfManager.searchByStudent(query);
			if (results.empty()) {
				UI::setColor(UI::ConsoleColor::Red);
				cout << " �������� �� ��������.";
			}
			else {
				ui.drawTable(ui.defaultTableHead, qfManager.toMap(results));
			}
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::SearchByTeacher) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);

			UI::setColor(UI::ConsoleColor::Gray);
			cout << " � ����� ����� ����� ������ ������������� ������ �� ϲ� ��������" << endl;
			cout << " ��������� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� ������ �����, ��� ";
			UI::setColor(UI::ConsoleColor::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::ConsoleColor::Gray);
			cout << " - ��� ����������� � ������� ����" << endl;
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::SearchTeacherForm) {
			string query;
			cout << " ������ ϲ� �������� ��� ������ ����: ";
			getline(cin, query);

			vector<Models::QualifyingWork> results = qfManager.searchByTeacher(query);
			if (results.empty()) {
				UI::setColor(UI::ConsoleColor::Red);
				cout << " �������� �� ��������.";
			}
			else {
				ui.drawTable(ui.defaultTableHead, qfManager.toMap(results));
			}
		}

		ui.setKey(_getch());
	}

	return 0;
};