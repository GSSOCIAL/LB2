#include "locale.h"

void setLanguageSupport() {
	setlocale(LC_ALL, "Ukr");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
};