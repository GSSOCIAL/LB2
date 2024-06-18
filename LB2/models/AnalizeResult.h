#pragma once
#include <string>
#include <iostream>
#include <map>
#include "QualifyingWork.h"

using namespace std;

namespace Models {
	/// <summary>
	/// Результат аналізу робіт
	/// </summary>
	struct AnalizeResult {
		Models::QualifyingWork value;
		bool result = false;
		string keyword;

		/// <summary>
		/// Трансформує модель у формат пари ключ-значення для відображення та запису
		/// </summary>
		/// <returns></returns>
		map<string, string> getPair() {
			map<string, string> pair;
			pair.insert(make_pair("title", value.title));
			pair.insert(make_pair("student", value.studentName));
			pair.insert(make_pair("teacher", value.teacherName));
			if (result) {
				pair.insert(make_pair("result", "Знайдено"));
			}
			else {
				pair.insert(make_pair("result", "Не знайдено"));
			}
			pair.insert(make_pair("keyword", keyword));
			return pair;
		};
	};
};