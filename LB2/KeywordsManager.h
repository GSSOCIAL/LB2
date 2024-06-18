#pragma once

#include <vector>
#include "file.h"
#include "models/Keyword.h"
#include "models/AnalizeResult.h"
#include "models/QualifyingWork.h"

using namespace std;
namespace Controllers {
	/// <summary>
	/// �������� �������� ���
	/// </summary>
	class KeywordsManager : public FileManager {
	public:
		KeywordsManager(const char* path);
		/// <summary>
		/// ������ ����� �� ����
		/// </summary>
		/// <param name="item">������� �����</param>
		/// <param name="overrideFile">�� ������� ������������ ���� ����</param>
		/// <returns></returns>
		int addItem(Models::Keyword& item, bool overrideFile);
		int getPrimaryKey() {
			return primaryIndex;
		};
		int increasePrimaryKey() {
			primaryIndex++;
			return primaryIndex;
		};
		/// <summary>
		/// ���� ����
		/// </summary>
		/// <returns></returns>
		vector<Models::Keyword> getList();
		/// <summary>
		/// ���������� ������ �������� ��� � ������ �����������
		/// </summary>
		/// <param name="input"></param>
		/// <returns></returns>
		vector<map<string, string>> toMap(vector<Models::Keyword> input);
		/// <summary>
		/// ��������� ����� ����. ����
		/// </summary>
		/// <param name="input"></param>
		/// <returns></returns>
		vector<map<string, string>> analize(vector<Models::QualifyingWork> input);
	private:
		vector<Models::Keyword> list;
		/// <summary>
		/// ��������� ����
		/// </summary>
		/// <returns></returns>
		bool override();
	protected:
		/// <summary>
		/// ������ ���������� �������� ������
		/// </summary>
		int primaryIndex = 0;
	};
};