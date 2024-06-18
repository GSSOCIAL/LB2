#pragma once
#include <string>
#include <iostream>
#include <map>

using namespace std;

namespace Models {
	/// <summary>
	/// Ключове слово
	/// </summary>
	struct Keyword {
		/// <summary>
		/// Значення
		/// </summary>
		string value;
		int primaryKey;
		/// <summary>
		/// Трансформує модель у формат пари ключ-значення для відображення та запису
		/// </summary>
		/// <returns></returns>
		map<string, string> getPair() {
			map<string, string> pair;
			pair.insert(make_pair("value", value));
			return pair;
		};
	};
};