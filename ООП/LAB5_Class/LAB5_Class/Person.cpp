#include "Person.h"



Person::Person()
{
	cout << "����������� ��� ���������� Person" << endl;
	name = "TEMP";
	age = 0;
}
Person::Person(string name, int age)
{
	cout << "����������� � ����������� Person" << endl;
	this->name = name;
	this->age = age;
}
Person::Person(const Person& copy)
{
	cout << "����������� ����������� Person" << endl;
	this->name = copy.name;
	this->age = copy.age;
}

ostream& operator<<(ostream& os, const Person& per)
{
	os << "Name: " << per.name << "\nAge: " << per.age;
	return os;
}

istream& operator>>(istream& is, Person& per)
{
	is >> per.name >> per.age;
	return is;
}

Person& Person::operator=(const Person& other)
{
	this->name = other.name;
	this->age = other.age;
	return *this;
}

Person::~Person()
{
	cout << "���������� ������ Person" << endl;
	age = -1;
	name = "";
}

void Person::Show()
{
	cout << "NAME: " << name << "\nAge: " << age << endl;
}