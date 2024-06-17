#pragma once

#include "windows.h"
namespace UI {
	class Navigation {
	public:
		Navigation() {};

		void setVerticalIndex(int index) {
			activeVerticalIndex = index;
		};

		void setHorizontalIndex(int index) {
			activeHorizontalIndex = index;
		};

		void setVerticalLength(int length) {
			activeVerticalLength = length;
		};

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

		virtual void onNavigationItemSelect() = 0;
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