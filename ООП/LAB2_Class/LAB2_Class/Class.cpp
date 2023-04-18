#include "Class.h"

Salary::Salary()
{
	cout << endl << "����������� ��� ����������." << endl << endl;
	name = "��������";
	salary = 0;
	percent = 0;
}
Salary::Salary(const Salary& copy)
{
	cout << endl << "����������� �����������." << endl << endl;
	this->name = copy.name + "_copy";
	this->salary = copy.salary;
	this->percent = copy.percent;
}

Salary::Salary(string name, double salary, int percent)
{
	cout << endl << "����������� � �����������." << endl << endl;
	this->name = name;
	this->salary = salary;
	this->percent = percent;
}

Salary::~Salary()
{
	cout << endl << "����������." << name << endl << endl;
	name = "";
	salary = 0;
	percent = 0;
}