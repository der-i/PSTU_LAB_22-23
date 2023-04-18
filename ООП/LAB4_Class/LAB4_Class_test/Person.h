#pragma once
#include <iostream>
using namespace std;


class Person				//класс родитель
{
private:
	friend ostream& operator <<(ostream& os, const Person& per);		//операторы ввода/вывода
	friend istream& operator >> (istream& is, Person& per);
protected:
	string name;				//поля класса, которые будут унаследованы
	int age;
public:
	Person();					//конструкторы и деструкторы
	Person(string name, int age);
	Person(const Person& copy);
	~Person();

	void SetName(string name) { this->name = name; }		//сеттеры и геттеры
	void SetAge(int age) { this->age = age; }
	string GetName() { return this->name; }
	int GetAge() { return this->age; }

	Person& operator =(const Person& other);			//оператор присваивания

};

