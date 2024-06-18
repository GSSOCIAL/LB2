#include "Manager.h"

namespace Controllers {
	template <typename Model>
	Manager<Model>::Manager(const char* path) : FileManager(path) {
		vector<map<string, string>> data = read();
		for (const auto& row : data) {
			cout << "row fiund";
			Model item = this->processInputData(row);
			addItem(item, false);
		}
	};

	template <typename Model>
	int Manager<Model>::addItem(Model& item, bool overrideFile) {
		int primaryKey = getPrimaryKey() + 1;
		//item.primaryKey = primaryKey;
		list.push_back(item);
		increasePrimaryKey();

		if (overrideFile) {
			override();
		}
		return primaryKey;
	};

	template <typename Model>
	vector<Model> Manager<Model>::getList() {
		return list;
	};

	template <typename Model>
	vector<map<string, string>> Manager<Model>::toMap(vector<Model> input) {
		vector<map<string, string>> output;
		
		for (Model row : input) {
			map<string, string> pair = decodeModel(row);
			output.push_back(pair);
		}
		return output;
	};

	template <typename Model>
	bool Manager<Model>::override() {
		return true;
	};

	template <typename Model>
	Model Manager<Model>::processInputData(map<string, string> input) {
		Model output;
		return output;
	};
	
	template <typename Model>
	map<string, string> Manager<Model>::decodeModel(Model input) {
		map<string, string> result;
		return result;
	};
};

// No need to call this TemporaryFunction() function,
// it's just to avoid link error.
void TemporaryFunction() {
	Controllers::Manager<Models::QualifyingWork> t("");
	Models::QualifyingWork sample;
	vector<Models::QualifyingWork> list = t.getList();
	t.toMap(list);
	t.decodeModel(sample);
}