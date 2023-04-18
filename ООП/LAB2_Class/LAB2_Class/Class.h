#pragma once
#include <iostream>

using namespace std;


class Salary
{
private:
	string name;				//имя 
	double salary;				//зарплата
	int percent;				//процент премии относительно зарплаты
public:
	Salary();					//конструктор
	Salary(const Salary& copy);	//конструткто копирования
	Salary(string name, double salary, int percent);	//конструктор с параметрами
	~Salary();					//деструктор
	void SetName(string name) { this->name = name; }	//сеттер имени
	void SetSalary(double salary) { this->salary = salary; }	//сеттер зарплаты
	void SetPercent(int percent) { this->percent = percent; }	//сеттер премии
	string GetName() { return this->name; }						//геттер имени
	double GetSalary() { return this->salary + this->salary * (float(this->percent) / 100); } //геттер зарплаты
	int GetPercent() { return this->percent; }					//геттер премии 
};