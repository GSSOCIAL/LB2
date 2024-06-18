#pragma once

#include "windows.h"
namespace UI {
	/// <summary>
	/// Створення навигації
	/// </summary>
	class Navigation {
	public:
		Navigation() {};

		/// <summary>
		/// Встановлює позицію для вертикальної навигації
		/// </summary>
		/// <param name="index"></param>
		void setVerticalIndex(int index) {
			activeVerticalIndex = index;
		};
		/// <summary>
		/// Встановлює позицію для горизонтальної навигації
		/// </summary>
		/// <param name="index"></param>
		void setHorizontalIndex(int index) {
			activeHorizontalIndex = index;
		};
		/// <summary>
		/// Встановлює кількість єлементів вертикальної навигації
		/// </summary>
		void setVerticalLength(int length) {
			activeVerticalLength = length;
		};
		/// <summary>
		/// Встановлює кількість єлементів горизонтальної навигації
		/// </summary>
		void setHorizontalLength(int length) {
			activeHorizontalLength = length;
		};
		void setKey(char key);

		int getNavigationVerticalIndex() {
			return activeVerticalIndex;
		}
		int getNavigationHorizontalIndex() {
			return activeHorizontalIndex;
		}
		/// <summary>
		/// Колбек коли обран пункт
		/// </summary>
		virtual void onNavigationItemSelect() = 0;
		/// <summary>
		/// Колбек коли нажата кнопка "ESC"
		/// </summary>
		virtual void onEscape() = 0;
	private:
		int activeVerticalIndex = 0;
		int activeHorizontalIndex = 0;

		int activeVerticalLength = 0;
		int activeHorizontalLength = 0;
	protected:
		char _key;
	};
};