#pragma once

#include "Manager.h"
#include "models/QualifyingWork.h"

using namespace std;
namespace Controllers {
	class KeywordManager: public Manager<Models::QualifyingWork>{
	public:
		KeywordManager(const char* path);
		Models::QualifyingWork processInputData(map<string, string> input);

		map<string, string> decodeModel(Models::QualifyingWork input);
	};
};