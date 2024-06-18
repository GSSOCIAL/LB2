#pragma once
#include <string>
#include <iostream>
#include <map>

using namespace std;

namespace Models {
	/// <summary>
	/// Кваліфікаційна робота
	/// </summary>
	struct QualifyingWork {
		/// <summary>
		/// ПІБ викладача
		/// </summary>
		string teacherName;
		int year;
		/// <summary>
		/// Академічна група
		/// </summary>
		string group;
		/// <summary>
		/// ПІБ Автора
		/// </summary>
		string studentName;
		/// <summary>
		/// Назва роботи
		/// </summary>
		string title;

		int primaryKey;

		map<string, string> getPair() {
			map<string, string> pair;
			pair.insert(make_pair("teacher", teacherName));
			pair.insert(make_pair("student", studentName));
			pair.insert(make_pair("title", title));
			pair.insert(make_pair("group", group));
			pair.insert(make_pair("year", to_string(year)));
			return pair;
		};
	};
};