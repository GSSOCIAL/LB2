#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/// <summary>
/// Класс читання та запису файлів
/// </summary>
class FileManager {
public:
	FileManager(const char* path) {
		_path = path;
	};
	/// <summary>
	/// Зчитує файл
	/// </summary>
	/// <returns></returns>
	vector<map<string,string>> read();
	/// <summary>
	/// Записує у файл
	/// </summary>
	/// <param name="data">Дані які треба записати</param>
	/// <returns></returns>
	bool write(vector<map<string, string>> data);
	/// <summary>
	/// Встановити розділовий знак для комірок значень
	/// </summary>
	/// <param name="delimiter">Розділовий знак</param>
	void setDelimiter(string delimiter) {
		componentDelimiter = delimiter;
	};
	/// <summary>
	/// Встановити розділовий знак для пари ключ - значення
	/// </summary>
	/// <param name="delimiter">Розділовий знак</param>
	void setKeyDelimiter(string delimiter) {
		keyPairDelimiter = delimiter;
	};
	/// <summary>
	/// Шлях до файлу
	/// </summary>
	/// <returns></returns>
	const char* getFilePath();
	/// <summary>
	/// Показує, чи вдалось успішно прочитати вхідний файл
	/// </summary>
	/// <returns></returns>
	bool isInitialized() {
		return initialized;
	};
private:
	/// <summary>
	/// Розділовий знак для комірки значення
	/// </summary>
	string componentDelimiter = ";";
	/// <summary>
	/// Розділовий знак для пари ключ-значення
	/// </summary>
	string keyPairDelimiter = ":";
protected:
	/// <summary>
	/// Шлях до файлу
	/// </summary>
	const char* _path;
	/// <summary>
	/// Показує чи був успішно прочитан файл
	/// </summary>
	bool initialized = false;
};