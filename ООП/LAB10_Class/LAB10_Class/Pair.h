#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Pair
{
public:
	Pair();							//������������ � ���������� ������ pair
	Pair(int first, double second);
	Pair(int val);
	Pair(const Pair& copy);
	~Pair() {}

	int GetFirst() { return this->first; }		//������� � �������
	double GetSecond() { return this->second; }
	void SetFirst(int first) { this->first = first; }
	void SetSecond(double second) { this->second = second; }

	Pair operator -(const Pair& other);			//�������� ���������
	bool operator <(const Pair& other) const;
	bool operator >(const Pair& other);
	bool operator ==(const Pair& other);

	Pair& operator =(const Pair& other);		//�������� ������������
	Pair& operator ++();						//��������� �������������� �������� 
	Pair operator ++(int);
	Pair operator +(const Pair& other);			//�������� �������� � ����� ������ Pair
	friend const Pair operator +(const Pair& left, const int& right);		//�������������� ��������
	friend const Pair operator +(const int& left, const Pair& right);
	friend const Pair operator +(const Pair& left, const double& right);
	friend const Pair operator +(const double& left, const Pair& right);
	Pair operator /(const Pair& other);					//�������� �������
	Pair operator /(const int other);
	Pair operator *(const Pair& other);			//��������� pair �� pair

	friend ostream& operator <<(ostream& os,const Pair& val);		//�������� �����/������
	friend istream& operator >> (istream& is, Pair& val);
	Pair randomGener();			//����� ��������� ���������
private:
	//friend fstream& operator <<(fstream& fin, const Pair& pr);
	friend fstream& operator >>(fstream& fout, Pair& pr);
	int first;					//���� ������
	double second;
};

