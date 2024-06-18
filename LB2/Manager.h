#pragma once

#include <vector>
#include <map>
#include <string>
#include "file.h"
#include "models/QualifyingWork.h"

using namespace std;
namespace Controllers {
	template <typename Model>
	class Manager : public FileManager {
	public:
		Manager(const char* path);

		int addItem(Model& item, bool overrideFile);

		vector<Model> getList();

		vector<map<string, string>> toMap(vector<Model> input);

		vector<Models::QualifyingWork> searchByTeacher(string query) {
			vector<Models::QualifyingWork> out;
			return out;
		};
		vector<Models::QualifyingWork> searchByStudent(string query) {
			vector<Models::QualifyingWork> out;
			return out;
		};

		int getPrimaryKey() {
			return primaryIndex;
		};
		int increasePrimaryKey() {
			primaryIndex++;
			return primaryIndex;
		};

		Model processInputData(map<string, string> input);

		map<string, string> decodeModel(Model input);
	protected:
		int primaryIndex = 0;
		vector<Model> list;
		bool override();
	};
};