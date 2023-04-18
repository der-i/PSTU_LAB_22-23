#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class MyClass
{
private:
	double first_el;				//первое поле
	unsigned int second_attitude;	//второе поле

public:
	MyClass() { first_el = second_attitude = 0; }		//конструктор по умолчанию
	MyClass(const MyClass& copy);						//конструктор копирования
	MyClass(double first_el, int second_attitude);		//конструктор с параметрами
	~MyClass() {}										//деструктор класса
	double element(int j) { return first_el * pow(second_attitude, j); }	//метод отвечающий за вывод ответа
	void Read();															//чтение с консоли
	void Init(double first_el, int second_attitude);						//инициализация
	void Show();															//вывод на консоль
};
