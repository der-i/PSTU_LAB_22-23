#include "Print.h"

Print::~Print() {}

Print::Print() 
{
	name = "";
	author = "";
}

Print::Print(string naem, string author)
{
	this->name = name;
	this->author = author;
}

Print::Print(const Print& copy) 
{
	this->name = copy.name;
	this->author = copy.author;
}


void Print::Show()
{
	cout << "\nName: " << name;
	cout << "\nAuthor: " << author << endl;
}

void Print::Input() 
{
	cin.get();
	cout << "Enter name: "; getline(cin, name);
	cout << "Enter author: "; getline(cin, author);
}

Print& Print::operator=(const Print& copy) 
{
	if (&copy == this) return *this;
	name = copy.name;
	author = copy.author;
	return *this;
}