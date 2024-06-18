#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/// <summary>
/// ����� ������� �� ������ �����
/// </summary>
class FileManager {
public:
	FileManager(const char* path) {
		_path = path;
	};
	/// <summary>
	/// ����� ����
	/// </summary>
	/// <returns></returns>
	vector<map<string,string>> read();
	/// <summary>
	/// ������ � ����
	/// </summary>
	/// <param name="data">��� �� ����� ��������</param>
	/// <returns></returns>
	bool write(vector<map<string, string>> data);
	/// <summary>
	/// ���������� ��������� ���� ��� ������ �������
	/// </summary>
	/// <param name="delimiter">��������� ����</param>
	void setDelimiter(string delimiter) {
		componentDelimiter = delimiter;
	};
	/// <summary>
	/// ���������� ��������� ���� ��� ���� ���� - ��������
	/// </summary>
	/// <param name="delimiter">��������� ����</param>
	void setKeyDelimiter(string delimiter) {
		keyPairDelimiter = delimiter;
	};
	/// <summary>
	/// ���� �� �����
	/// </summary>
	/// <returns></returns>
	const char* getFilePath();
	/// <summary>
	/// ������, �� ������� ������ ��������� ������� ����
	/// </summary>
	/// <returns></returns>
	bool isInitialized() {
		return initialized;
	};
private:
	/// <summary>
	/// ��������� ���� ��� ������ ��������
	/// </summary>
	string componentDelimiter = ";";
	/// <summary>
	/// ��������� ���� ��� ���� ����-��������
	/// </summary>
	string keyPairDelimiter = ":";
protected:
	/// <summary>
	/// ���� �� �����
	/// </summary>
	const char* _path;
	/// <summary>
	/// ������ �� ��� ������ �������� ����
	/// </summary>
	bool initialized = false;
};