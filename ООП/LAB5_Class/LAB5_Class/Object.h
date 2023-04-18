#pragma once
#include <iostream>
using namespace std;

class Object			//абстрактный класс
{
public:
	Object() { cout << "Конструктор класса Object." << endl; }
	~Object() { cout << "Деструктор класса Object" << endl; }
	virtual void Show() = 0;			//чисто виртуальная функция, которая требует определения в классах наследниках
};

