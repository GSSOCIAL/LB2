#include "main.h"

int main(){
	setLanguageSupport();
	UI::Controller ui;
	Controllers::QualifyingManager qfManager("db.txt");

	char key;
	for (int i = 0;;) {
		ui.drawMenu();
		//std::cin.ignore();

		if (ui.getActiveMenu() == UI::MenuIndex::ManageDb) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);
			
			UI::setColor(UI::Gray);
			cout << " � ����� ����� ����� ������ ������������� ������ �� ���� ������." << endl;
			cout << " ��������� ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::Gray);
			cout << " - ��� �������� ����� �����, ��� ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::Gray);
			cout << " - ��� ����������� � ������� ����" << endl;
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
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::ViewDb) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);
			ui.drawTable(ui.defaultTableHead,qfManager.toMap(qfManager.getList()));
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::SearchByStudent) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);

			UI::setColor(UI::Gray);
			cout << " � ����� ����� ����� ������ ������������� ������ �� ϲ� ������" << endl;
			cout << " ��������� ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::Gray);
			cout << " - ��� ������ �����, ��� ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::Gray);
			cout << " - ��� ����������� � ������� ����" << endl;
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::SearchStudentForm) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);

			string query;
			cout << " ������ ϲ� ������ ��� ������ ����: ";
			getline(cin, query);

			vector<Models::QualifyingWork> results = qfManager.searchByStudent(query);
			if (results.empty()) {
				UI::setColor(UI::Red);
				cout << " �������� �� ��������.";
			}
			else {
				ui.drawTable(ui.defaultTableHead, qfManager.toMap(results));
			}
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::SearchByTeacher) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);

			UI::setColor(UI::Gray);
			cout << " � ����� ����� ����� ������ ������������� ������ �� ϲ� ��������" << endl;
			cout << " ��������� ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::Gray);
			cout << " - ��� ������ �����, ��� ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::Gray);
			cout << " - ��� ����������� � ������� ����" << endl;
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::SearchTeacherForm) {
			string query;
			cout << " ������ ϲ� �������� ��� ������ ����: ";
			getline(cin, query);

			vector<Models::QualifyingWork> results = qfManager.searchByTeacher(query);
			if (results.empty()) {
				UI::setColor(UI::Red);
				cout << " �������� �� ��������.";
			}
			else {
				ui.drawTable(ui.defaultTableHead, qfManager.toMap(results));
			}
		}

		key = _getch();
		ui.setKey(key);
	}

	return 0;
};