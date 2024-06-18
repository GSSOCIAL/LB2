#include "KeywordManager.h"

namespace Controllers {
	KeywordManager::KeywordManager(const char* path): Manager(path){
	};

	Models::QualifyingWork KeywordManager::processInputData(map<string, string> input) {
		cout << "input processed";
		Models::QualifyingWork item;
		if (input.find("teacher") != input.end()) {
			item.teacherName = input.at("teacher");
		}
		if (input.find("student") != input.end()) {
			item.studentName = input.at("student");
		}
		if (input.find("title") != input.end()) {
			item.title = input.at("title");
		}
		if (input.find("group") != input.end()) {
			item.group = input.at("group");
		}
		if (input.find("year") != input.end()) {
			item.year = stoi(input.at("year"));
		}
		return item;
	};

	map<string, string> KeywordManager::decodeModel(Models::QualifyingWork input) {
		cout << input.studentName;
		return input.getPair();
	};
};