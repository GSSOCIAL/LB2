#pragma once

#include <vector>
#include "models/QualifyingWork.h"
#include "file.h"

using namespace std;
namespace Controllers {
	class QualifyingManager : public FileManager {
	public:
		QualifyingManager(const char* path);

		int addItem(Models::QualifyingWork& item, bool overrideFile);
		int getPrimaryKey() {
			return primaryIndex;
		};
		int increasePrimaryKey() {
			primaryIndex++;
			return primaryIndex;
		};
		vector<Models::QualifyingWork> getList();
		vector<map<string, string>> toMap(vector<Models::QualifyingWork> input);
		vector<Models::QualifyingWork> searchByTeacher(string query);
		vector<Models::QualifyingWork> searchByStudent(string query);
	private:
		vector<Models::QualifyingWork> list;

		bool override();
	protected:
		int primaryIndex = 0;
	};
};