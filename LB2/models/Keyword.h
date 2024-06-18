#pragma once
#include <string>
#include <iostream>
#include <map>

using namespace std;

namespace Models {
	/// <summary>
	/// ������� �����
	/// </summary>
	struct Keyword {
		/// <summary>
		/// ��������
		/// </summary>
		string value;
		int primaryKey;
		/// <summary>
		/// ���������� ������ � ������ ���� ����-�������� ��� ����������� �� ������
		/// </summary>
		/// <returns></returns>
		map<string, string> getPair() {
			map<string, string> pair;
			pair.insert(make_pair("value", value));
			return pair;
		};
	};
};