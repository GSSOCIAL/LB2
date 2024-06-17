#pragma once
#include <string>
#include <iostream>
#include <map>

using namespace std;

namespace Models {
	struct QualifyingWork {
		string teacherName;
		int year;
		string group;
		string studentName;
		string title;

		int primaryKey;

		friend ostream& operator<<(ostream& stream, const QualifyingWork& row) {
			stream << "";
			return stream;
		};

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