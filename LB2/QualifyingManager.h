#pragma once

#include <vector>
#include "models/QualifyingWork.h"
#include "file.h"

using namespace std;
namespace Controllers {
	/// <summary>
	/// ��������� ���� �������������� ����
	/// </summary>
	class QualifyingManager : public FileManager {
	public:
		QualifyingManager(const char* path);
		/// <summary>
		/// ������ ����� ����� �� ����
		/// </summary>
		/// <param name="item">�����</param>
		/// <param name="overrideFile">�� ������� ������������ ���� ����</param>
		/// <returns></returns>
		int addItem(Models::QualifyingWork& item, bool overrideFile);
		int getPrimaryKey() {
			return primaryIndex;
		};
		int increasePrimaryKey() {
			primaryIndex++;
			return primaryIndex;
		};
		vector<Models::QualifyingWork> getList();
		vector<map<string, string>> toMap(vector<Models::QualifyingWork> input);
		/// <summary>
		/// ����� �������� ���� �� ���������� ϲ� ���������
		/// </summary>
		/// <param name="query">��������� �����</param>
		/// <returns></returns>
		vector<Models::QualifyingWork> searchByTeacher(string query);
		/// <summary>
		/// ����� ������ �� ϲ� ������
		/// </summary>
		/// <param name="query">��������� �����</param>
		/// <returns></returns>
		vector<Models::QualifyingWork> searchByStudent(string query);
	private:
		vector<Models::QualifyingWork> list;
		/// <summary>
		/// ������� ���� ����
		/// </summary>
		/// <returns></returns>
		bool override();
	protected:
		int primaryIndex = 0;
	};
};