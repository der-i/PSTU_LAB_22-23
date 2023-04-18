#pragma once
#include <iostream>
using namespace std;

class Pair
{
public:
	Pair();							//конструкторы и деструктор класса pair
	Pair(int first, double second);
	Pair(int val);
	Pair(const Pair& copy);
	~Pair() {}
	int GetFirst() { return this->first; }		//геттеры и сеттеры
	double GetSecond() { return this->second; }
	void SetFirst(int first) { this->first = first; }
	void SetSecond(double second) { this->second = second; }
	Pair& operator =(const Pair& other);		//оператор присваивания
	Pair operator +(const Pair& other);			//оператор сложения с типом данных Pair
	Pair operator *(const Pair& other);			//умножение pair на pair
	Pair& operator ++();						//остальные математические операции 
	Pair operator ++(int);
	Pair operator -(const Pair& other);			//операции сравнения
	bool operator <(const Pair& other) const;
	bool operator >(const Pair& other);
	bool operator ==(const Pair& other);
	friend const Pair operator +(const Pair& left, const int& right);		//Математические операции
	friend const Pair operator +(const int& left, const Pair& right);
	friend const Pair operator +(const Pair& left, const double& right);
	friend const Pair operator +(const double& left, const Pair& right);
	Pair operator /(const Pair& other);					//операция деления
	Pair operator /(const int other);
	friend ostream& operator <<(ostream& os,const Pair& str);		//операция ввода/вывода
	friend istream& operator >> (istream& is, Pair& str);
	Pair randomGener();			//метод рандомной генерации
private:
	int first;					//поля класса
	double second;
};

