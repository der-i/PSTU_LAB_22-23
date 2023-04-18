#pragma once
#include "Person.h"
class Student : public Person		//Наследование от класса person
{
private:
	string academSub;			//дополнительные поля класса
	int grade;					

	friend istream& operator >> (istream& is, Student& per);		//операторы ввода/вывода
	friend ostream& operator << (ostream& os, const Student& st);
public:
	Student();											//конструкторы / деструкторы
	Student(string name, int age, string academSub, int grade);
	Student(const Student& copy);
	~Student();
	void Show() override;			//переопределенный метод
	void SetSubject(string subj) { this->academSub = subj; }	//сеттеры / геттеры
	void SetGrade(int grade) { this->grade = grade; }
	string GetSubj() { return this->academSub; }
	int GetGrade() { return this->grade; }
	bool CheckGrade();
	Student& operator =(const Student& other);		//оператор присваиваняия
};

