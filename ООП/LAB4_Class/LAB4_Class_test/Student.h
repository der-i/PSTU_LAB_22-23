#pragma once
#include "Person.h"

class Student : public Person		//дочерний класс от класса родителя, наследование
{
private:
	string academSub;		//доп поля класса, относительно класса родителя
	int grade;

	friend istream& operator >> (istream& is, Student& per);			//операторы ввода/вывода
	friend ostream& operator << (ostream& os, const Student& st);
public:
	Student();													//конструкторы и деструктор
	Student(string name, int age, string academSub, int grade);
	Student(const Student& copy);
	~Student();

	void SetSubject(string subj) { this->academSub = subj; }		//сеттеры и геттеры
	void SetGrade(int grade) { this->grade = grade; }
	string GetSubj() { return this->academSub; }
	int GetGrade() { return this->grade; }
	bool CheckGrade();						//проверка оценки на положительная/отрицательная

	Student& operator =(const Student& other);		//оператор присваивания


};

