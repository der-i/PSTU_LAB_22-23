#include "Student.h"



int main()
{
	system("chcp 1251 >> null");

	cout << "�������� Person ��� ����������" << endl;
	Person pers;
	cout << "\n�������� Person � �����������" << endl;
	Person pers2("Ilya", 19);

	cout << "\n�������� Student ��� ����������" << endl;
	Student st;
	cout << "\n�������� Student � �����������" << endl;
	Student st2("Andrew", 20, "Math", 3);
	cout << "\n����������� ����������� ������� � �����." << endl;
	Student st3(st2);

	cout << "\n�������� ���� ������� ������� ������ Student" << endl;
	string str;
	int a;
	cout << "������� ���: "; cin >> str;
	cout << "������� �������: "; cin >> a;
	st.SetAge(a); st.SetName(str);
	cout << "������� ������� �������: "; cin >> str;
	cout << "������� ������ �� ��������: "; cin >> a;
	st.SetGrade(a); st.SetSubject(str);

	cout << endl << "������� �������: " << endl;
	cout << "1 o����� ������ Student: " << st << endl << endl;
	cout << "2 o����� ������ Student: " << st2 << endl << endl;
	cout << "3 o����� ������ Student: " << st3 << endl << endl;

	cout << "�������� ������ ���������: " << endl << endl;
	if (st.CheckGrade()) str = "�������������";
	else str = "�������������";
	cout << "������� 1: " << endl << st << endl << "������: " << str << endl << endl;
	if (st2.CheckGrade()) str = "�������������";
	else str = "�������������";
	cout << "������� 2: " << endl << st2 << endl << "������: " << str << endl << endl;
	if (st3.CheckGrade()) str = "�������������";
	else str = "�������������";
	cout << "������� 3: " << endl << st3 << endl << "������: " << str << endl << endl;

	cout << endl << "������� ��������, ��� ����������� ���������� ������� �������������." << endl;

	return 0;
}