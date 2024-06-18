#pragma once

#include "windows.h"
namespace UI {
	/// <summary>
	/// ��������� ���������
	/// </summary>
	class Navigation {
	public:
		Navigation() {};

		/// <summary>
		/// ���������� ������� ��� ����������� ���������
		/// </summary>
		/// <param name="index"></param>
		void setVerticalIndex(int index) {
			activeVerticalIndex = index;
		};
		/// <summary>
		/// ���������� ������� ��� ������������� ���������
		/// </summary>
		/// <param name="index"></param>
		void setHorizontalIndex(int index) {
			activeHorizontalIndex = index;
		};
		/// <summary>
		/// ���������� ������� �������� ����������� ���������
		/// </summary>
		void setVerticalLength(int length) {
			activeVerticalLength = length;
		};
		/// <summary>
		/// ���������� ������� �������� ������������� ���������
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
		/// ������ ���� ����� �����
		/// </summary>
		virtual void onNavigationItemSelect() = 0;
		/// <summary>
		/// ������ ���� ������ ������ "ESC"
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