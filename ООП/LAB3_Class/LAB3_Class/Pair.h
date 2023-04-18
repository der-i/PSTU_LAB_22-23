#pragma once
#include <iostream>
using namespace std;

class Pair
{
public:
	Pair();					//конструктор
	Pair(int first, double second);	//конструктор с параметрами
	Pair(const Pair& copy);		//конструктор без параметров
	~Pair() {}			//деструктор
	int GetFirst() { return this->first; }	//геттеры и сеттеры для первого и второго поля.
	double GetSecond() { return this->second; }
	void SetFirst(int first) { this->first = first; }
	void SetSecond(double second) { this->second = second; }
	Pair& operator =(const Pair& other);		//перегрузка оператора присваивания
	Pair operator +(const Pair& other);			//перегрузка оператора сложения 2-х пар чисел
	Pair& operator ++();						//инкремент префиксный
	Pair operator ++(int);						//инкремент постфиксный
	Pair operator -(const Pair& other);			//оператор вычитания 2-х пар чисел
	friend const Pair operator +(const Pair& left, const int& right);	//добавление int константы справа и слева
	friend const Pair operator +(const int& left, const Pair& right);	
	friend const Pair operator +(const Pair& left, const double& right);//добавление double константы справа и слева
	friend const Pair operator +(const double& left, const Pair& right);
	friend ostream& operator <<(ostream& os,const Pair& str);			//перегрузка оператора вывода
	friend istream& operator >> (istream& is, Pair& str);				//перегрузка оператора ввода
private:
	int first;															//поле 1
	double second;														//поле 2
};

