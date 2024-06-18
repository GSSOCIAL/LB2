#pragma once

#include <vector>
#include "file.h"
#include "models/Keyword.h"
#include "models/AnalizeResult.h"
#include "models/QualifyingWork.h"

using namespace std;
namespace Controllers {
	/// <summary>
	/// Менеджер ключових слів
	/// </summary>
	class KeywordsManager : public FileManager {
	public:
		KeywordsManager(const char* path);
		/// <summary>
		/// Додати запис до бази
		/// </summary>
		/// <param name="item">Ключове слово</param>
		/// <param name="overrideFile">Чи потрібно перезаписати файл бази</param>
		/// <returns></returns>
		int addItem(Models::Keyword& item, bool overrideFile);
		int getPrimaryKey() {
			return primaryIndex;
		};
		int increasePrimaryKey() {
			primaryIndex++;
			return primaryIndex;
		};
		/// <summary>
		/// Вміст бази
		/// </summary>
		/// <returns></returns>
		vector<Models::Keyword> getList();
		/// <summary>
		/// Трансформує список ключових слів у формат відображення
		/// </summary>
		/// <param name="input"></param>
		/// <returns></returns>
		vector<map<string, string>> toMap(vector<Models::Keyword> input);
		/// <summary>
		/// Проводить аналіз квал. робіт
		/// </summary>
		/// <param name="input"></param>
		/// <returns></returns>
		vector<map<string, string>> analize(vector<Models::QualifyingWork> input);
	private:
		vector<Models::Keyword> list;
		/// <summary>
		/// Оновлення бази
		/// </summary>
		/// <returns></returns>
		bool override();
	protected:
		/// <summary>
		/// Індекс останнього доданого запису
		/// </summary>
		int primaryIndex = 0;
	};
};