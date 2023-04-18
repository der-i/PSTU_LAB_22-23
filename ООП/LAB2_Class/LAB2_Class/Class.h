#pragma once
#include <iostream>

using namespace std;


class Salary
{
private:
	string name;				//��� 
	double salary;				//��������
	int percent;				//������� ������ ������������ ��������
public:
	Salary();					//�����������
	Salary(const Salary& copy);	//����������� �����������
	Salary(string name, double salary, int percent);	//����������� � �����������
	~Salary();					//����������
	void SetName(string name) { this->name = name; }	//������ �����
	void SetSalary(double salary) { this->salary = salary; }	//������ ��������
	void SetPercent(int percent) { this->percent = percent; }	//������ ������
	string GetName() { return this->name; }						//������ �����
	double GetSalary() { return this->salary + this->salary * (float(this->percent) / 100); } //������ ��������
	int GetPercent() { return this->percent; }					//������ ������ 
};