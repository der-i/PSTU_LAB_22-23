#pragma once
#include "Person.h"
class Student : public Person		//������������ �� ������ person
{
private:
	string academSub;			//�������������� ���� ������
	int grade;					

	friend istream& operator >> (istream& is, Student& per);		//��������� �����/������
	friend ostream& operator << (ostream& os, const Student& st);
public:
	Student();											//������������ / �����������
	Student(string name, int age, string academSub, int grade);
	Student(const Student& copy);
	~Student();
	void Show() override;			//���������������� �����
	void SetSubject(string subj) { this->academSub = subj; }	//������� / �������
	void SetGrade(int grade) { this->grade = grade; }
	string GetSubj() { return this->academSub; }
	int GetGrade() { return this->grade; }
	bool CheckGrade();
	Student& operator =(const Student& other);		//�������� �������������
};

