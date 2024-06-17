#include "file.h"

const char* FileManager::getFilePath() {
	return _path;
};

vector<map<string, string>> FileManager::read() {
	ifstream file(getFilePath());
	vector<map<string, string>> output;

	if (!file.is_open()) {
		initialized = false;
		return output;
	}
	initialized = true;

	string line;
	
	while (getline(file, line)) {
		remove_if(line.begin(), line.end(), isspace);
		string clone = line;
		size_t index = 0;
		string component;
		map<string, string> pair;
		while ((index = clone.find(componentDelimiter)) != string::npos) {
			component = clone.substr(0, index);
			size_t valueIndex = component.find(keyPairDelimiter);

			if (valueIndex != string::npos) {
				string key = component;
				string value = component;
				key.erase(valueIndex);
				value.erase(0, valueIndex + 1);
				
				pair.insert(make_pair(key, value));
			};

			clone.erase(0, index + componentDelimiter.length());
		};
		output.push_back(pair);
	};

	file.close();

	return output;
};

bool FileManager::write(vector<map<string, string>> data) {
	ofstream file(getFilePath());
	if (!file.is_open()) {
		return false;
	};

	for (const auto& row : data) {
		for (const auto& pair : row) {
			file << pair.first << keyPairDelimiter << pair.second << componentDelimiter;
		};
		file << endl;
	};

	file.close();

	return true;
};