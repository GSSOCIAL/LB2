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
			cout << " У цьому розділі можна додати кваліфікаційну роботу до бази данних." << endl;
			cout << " Натиснить ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::Gray);
			cout << " - щоб створити новий запис, або ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::Gray);
			cout << " - щоб повернутись в головне меню" << endl;
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::AddRecordForm) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);
			Models::QualifyingWork item;
			UI::resetColor();

			cout << " Вкажіть ПІБ керівніка: ";
			getline(cin, item.teacherName);
			cout << " Вкажіть ПІБ здобувача: ";
			getline(cin, item.studentName);
			cout << " Вкажіть академічну групу: ";
			getline(cin, item.group);
			cout << " Вкажіть тему кваліфакаційної роботи: ";
			getline(cin, item.title);
			string year;
			cout << " Вкажіть рік: ";
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
			cout << " У цьому розділі можна знайти кваліфікаційну роботу за ПІБ автора" << endl;
			cout << " Натиснить ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::Gray);
			cout << " - щоб почати пошук, або ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::Gray);
			cout << " - щоб повернутись в головне меню" << endl;
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::SearchStudentForm) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);

			string query;
			cout << " Введіть ПІБ автора для пошука робіт: ";
			getline(cin, query);

			vector<Models::QualifyingWork> results = qfManager.searchByStudent(query);
			if (results.empty()) {
				UI::setColor(UI::Red);
				cout << " Співпадінь не знайдено.";
			}
			else {
				ui.drawTable(ui.defaultTableHead, qfManager.toMap(results));
			}
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::SearchByTeacher) {
			UI::placeCursorAt(0, ui.getYScreenOffset() + 4);

			UI::setColor(UI::Gray);
			cout << " У цьому розділі можна знайти кваліфікаційну роботу за ПІБ керівника" << endl;
			cout << " Натиснить ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[Enter]";
			UI::setColor(UI::Gray);
			cout << " - щоб почати пошук, або ";
			UI::setColor(UI::WhiteOnBlue);
			cout << "[ESC]";
			UI::setColor(UI::Gray);
			cout << " - щоб повернутись в головне меню" << endl;
		}
		else if (ui.getActiveMenu() == UI::MenuIndex::SearchTeacherForm) {
			string query;
			cout << " Введіть ПІБ керівника для пошука робіт: ";
			getline(cin, query);

			vector<Models::QualifyingWork> results = qfManager.searchByTeacher(query);
			if (results.empty()) {
				UI::setColor(UI::Red);
				cout << " Співпадінь не знайдено.";
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