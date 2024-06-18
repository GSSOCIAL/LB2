#include "QualifyingManager.h"

namespace Controllers {
	QualifyingManager::QualifyingManager(const char* path) : FileManager(path) {
		vector<map<string, string>> data = read();
		
		for (const auto& row : data) {
			Models::QualifyingWork item;
			if (row.find("teacher") != row.end()) {
				item.teacherName = row.at("teacher");
			}
			if (row.find("student") != row.end()) {
				item.studentName = row.at("student");
			}
			if (row.find("title") != row.end()) {
				item.title = row.at("title");
			}
			if (row.find("group") != row.end()) {
				item.group = row.at("group");
			}
			if (row.find("year") != row.end()) {
				item.year = stoi(row.at("year"));
			}
			addItem(item, false);
		};
	};

	int QualifyingManager::addItem(Models::QualifyingWork& item, bool overrideFile) {
		int primaryKey = getPrimaryKey() + 1;
		item.primaryKey = primaryKey;
		list.push_back(item);
		increasePrimaryKey();

		if (overrideFile) {
			override();
		}
		return primaryKey;
	};

	bool QualifyingManager::override() {
		vector<map<string, string>> data;
		for (Models::QualifyingWork row : list) {
			data.push_back(row.getPair());
		};
		return write(data);
	};

	vector<Models::QualifyingWork> QualifyingManager::getList(){
		return list;
	};

	vector<map<string, string>> QualifyingManager::toMap(vector<Models::QualifyingWork> input) {
		vector<map<string, string>> output;
		for (Models::QualifyingWork row : input) {
			map<string, string> pair = row.getPair();
			output.push_back(pair);
		}
		return output;
	};

	vector<Models::QualifyingWork> QualifyingManager::searchByTeacher(string query) {
		vector<Models::QualifyingWork> results;
		for (Models::QualifyingWork row : getList()) {
			size_t result = row.teacherName.find(query);
			if (result != string::npos) {
				results.push_back(row);
			}
		}
		return results;
	};

	vector<Models::QualifyingWork> QualifyingManager::searchByStudent(string query) {
		vector<Models::QualifyingWork> results;
		for (Models::QualifyingWork row : getList()) {
			size_t result = row.studentName.find(query);
			if (result != string::npos) {
				results.push_back(row);
			}
		}
		return results;
	};
};