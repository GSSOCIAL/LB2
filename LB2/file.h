#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class FileManager {
public:
	FileManager(const char* path) {
		_path = path;
	};

	vector<map<string,string>> read();
	bool write(vector<map<string, string>> data);

	void setDelimiter(string delimiter) {
		componentDelimiter = delimiter;
	};
	void setKeyDelimiter(string delimiter) {
		keyPairDelimiter = delimiter;
	};

	const char* getFilePath();

	bool isInitialized() {
		return initialized;
	};
private:
	string componentDelimiter = ";";
	string keyPairDelimiter = ":";
protected:
	const char* _path;
	bool initialized = false;
};