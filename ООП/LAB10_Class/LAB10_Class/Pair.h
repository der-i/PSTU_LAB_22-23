#pragma once
#include <iostream>
#include <fstream>
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

	Pair operator -(const Pair& other);			//операции сравнения
	bool operator <(const Pair& other) const;
	bool operator >(const Pair& other);
	bool operator ==(const Pair& other);

	Pair& operator =(const Pair& other);		//оператор присваивания
	Pair& operator ++();						//остальные математические операции 
	Pair operator ++(int);
	Pair operator +(const Pair& other);			//оператор сложения с типом данных Pair
	friend const Pair operator +(const Pair& left, const int& right);		//Математические операции
	friend const Pair operator +(const int& left, const Pair& right);
	friend const Pair operator +(const Pair& left, const double& right);
	friend const Pair operator +(const double& left, const Pair& right);
	Pair operator /(const Pair& other);					//операция деления
	Pair operator /(const int other);
	Pair operator *(const Pair& other);			//умножение pair на pair

	friend ostream& operator <<(ostream& os,const Pair& val);		//операция ввода/вывода
	friend istream& operator >> (istream& is, Pair& val);
	Pair randomGener();			//метод рандомной генерации
private:
	//friend fstream& operator <<(fstream& fin, const Pair& pr);
	friend fstream& operator >>(fstream& fout, Pair& pr);
	int first;					//поля класса
	double second;
};

