#include "KeywordsManager.h"

namespace Controllers {
	KeywordsManager::KeywordsManager(const char* path) : FileManager(path) {
		vector<map<string, string>> data = read();

		for (const auto& row : data) {
			Models::Keyword item;
			if (row.find("value") != row.end()) {
				item.value = row.at("value");
			}
			addItem(item, false);
		};
	};

	int KeywordsManager::addItem(Models::Keyword& item, bool overrideFile) {
		int primaryKey = getPrimaryKey() + 1;
		item.primaryKey = primaryKey;
		list.push_back(item);
		increasePrimaryKey();

		if (overrideFile) {
			override();
		}
		return primaryKey;
	};
	
	bool KeywordsManager::override() {
		vector<map<string, string>> data;
		for (Models::Keyword row : list) {
			data.push_back(row.getPair());
		};
		return write(data);
	};

	vector<Models::Keyword> KeywordsManager::getList() {
		return list;
	};

	vector<map<string, string>> KeywordsManager::toMap(vector<Models::Keyword> input) {
		vector<map<string, string>> output;
		for (Models::Keyword row : input) {
			map<string, string> pair = row.getPair();
			output.push_back(pair);
		}
		return output;
	};

	vector<map<string, string>> KeywordsManager::analize(vector<Models::QualifyingWork> input) {
		vector<Models::AnalizeResult> results;

		for (Models::QualifyingWork row : input) {
			string title = row.title;
			
			Models::AnalizeResult record;
			record.value = row;
			//Для аналізу переріримо співпадіня назви за записами у базі ключових слів
			for (Models::Keyword keyword : getList()) {
				size_t result = title.find(keyword.value);
				if (result != string::npos) {
					record.keyword = keyword.value;
					record.result = true;
				}
			}
			results.push_back(record);
		};

		//Трансформуємо у формат для відображення
		vector<map<string, string>> output;
		for (Models::AnalizeResult result : results) {
			output.push_back(result.getPair());
		}
		return output;
	};
};