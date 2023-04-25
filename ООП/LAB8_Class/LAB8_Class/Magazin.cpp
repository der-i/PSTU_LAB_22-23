#include "Magazin.h"

Magazin::~Magazin() {}

Magazin::Magazin(){
	pages = 0;
}

Magazin::Magazin(string name, string author, int pages) : Print(name, author) 
{
	this->pages = pages;
}

Magazin::Magazin(const Magazin& copy) 
{
	name = copy.name;
	author = copy.author;
	pages = copy.pages;
}


void Magazin::Show() 
{
	cout << "\nName: " << name;
	cout << "\nAuthor: " << author;
	cout << "\nPages: " << pages << endl;
}

void Magazin::Input() 
{
	cin.get();
	cout << "Enter name: "; getline(cin, name);
	cout << "Enter author: "; getline(cin, author);
	cout << "Enter pages: "; cin >> pages;
}

Magazin& Magazin::operator=(const Magazin& other)
{
	if (&other == this) return *this;
	name = other.name;
	author = other.author;
	pages = other.pages;
	return *this;
}