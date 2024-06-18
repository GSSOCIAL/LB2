#pragma once

#include <vector>
#include "models/QualifyingWork.h"
#include "file.h"

using namespace std;
namespace Controllers {
	/// <summary>
	/// Контролер бази кваліфікаційних робіт
	/// </summary>
	class QualifyingManager : public FileManager {
	public:
		QualifyingManager(const char* path);
		/// <summary>
		/// Додати новий запис до бази
		/// </summary>
		/// <param name="item">Запис</param>
		/// <param name="overrideFile">Чи потрібно перезаписати файл бази</param>
		/// <returns></returns>
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
		/// <summary>
		/// Пошук єлементів бази за параметром ПІБ викладача
		/// </summary>
		/// <param name="query">Пошуковий запит</param>
		/// <returns></returns>
		vector<Models::QualifyingWork> searchByTeacher(string query);
		/// <summary>
		/// Пошук записів за ПІБ автора
		/// </summary>
		/// <param name="query">Пошуковий запит</param>
		/// <returns></returns>
		vector<Models::QualifyingWork> searchByStudent(string query);
	private:
		vector<Models::QualifyingWork> list;
		/// <summary>
		/// Оновити файл бази
		/// </summary>
		/// <returns></returns>
		bool override();
	protected:
		int primaryIndex = 0;
	};
};