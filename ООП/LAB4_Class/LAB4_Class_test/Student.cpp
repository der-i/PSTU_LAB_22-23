#include "Student.h"


Student::Student() :Person()
{
	cout << "����������� ��� ���������� ������ Student" << endl;
	academSub = "TEMP";
	grade = 0;
}
Student::Student(string name, int age, string academSub, int grade) :Person(name, age)
{
	cout << "����������� � ����������� ������ Student" << endl;
	this->academSub = academSub;
	this->grade = grade;
}
Student::Student(const Student& copy) :Person(copy)
{
	cout << "����������� ����������� ������ Student" << endl;
	this->academSub = copy.academSub;
	this->grade = copy.grade;
}

ostream& operator<<(ostream& os, const Student& st)
{
	os << "Name: " << st.name << "\nAge: " << st.age << "\nAcademic subject: " << st.academSub << "\nGrade: " << st.grade;
	return os;
}

istream& operator>>(istream& is, Student& per)
{
	is >> per.name >> per.age >> per.academSub >> per.grade;
	return is;
}

Student& Student::operator=(const Student& other)
{
	this->academSub = other.academSub;
	this->age = other.age;
	this->grade = other.grade;
	this->name = other.name;
	return *this;
}

Student::~Student()
{ 
	cout << "���������� ������ Student" << endl;
	grade = 0;
	academSub = "";
}

bool Student::CheckGrade()
{
	if (this->grade <=2)
	{
		return false;
	}
	return true;
}