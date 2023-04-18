#include "class.h"


MyClass::MyClass(double first_el, int second_attitude)
{
	this->first_el = first_el;
	this->second_attitude = second_attitude;
}

MyClass::MyClass(const MyClass& copy)
{
	this->first_el = copy.first_el;
	this->second_attitude = copy.second_attitude;
}


void MyClass::Read()
{
	cout << "Enter the first element of the sequence (double): ";
	cin >> first_el;
	cout << "Enter constant sequence ratio (unsigned int): ";
	cin >> second_attitude;
}

void MyClass::Init(double first_el, int second_attitude)
{
	this->first_el = first_el;
	this->second_attitude = second_attitude;
}

void MyClass::Show()
{
	cout << "aj = " << first_el << " * " << second_attitude << "^j" << endl;
}



