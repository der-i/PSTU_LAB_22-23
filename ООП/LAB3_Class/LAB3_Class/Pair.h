#pragma once
#include <iostream>
using namespace std;

class Pair
{
public:
	Pair();					//�����������
	Pair(int first, double second);	//����������� � �����������
	Pair(const Pair& copy);		//����������� ��� ����������
	~Pair() {}			//����������
	int GetFirst() { return this->first; }	//������� � ������� ��� ������� � ������� ����.
	double GetSecond() { return this->second; }
	void SetFirst(int first) { this->first = first; }
	void SetSecond(double second) { this->second = second; }
	Pair& operator =(const Pair& other);		//���������� ��������� ������������
	Pair operator +(const Pair& other);			//���������� ��������� �������� 2-� ��� �����
	Pair& operator ++();						//��������� ����������
	Pair operator ++(int);						//��������� �����������
	Pair operator -(const Pair& other);			//�������� ��������� 2-� ��� �����
	friend const Pair operator +(const Pair& left, const int& right);	//���������� int ��������� ������ � �����
	friend const Pair operator +(const int& left, const Pair& right);	
	friend const Pair operator +(const Pair& left, const double& right);//���������� double ��������� ������ � �����
	friend const Pair operator +(const double& left, const Pair& right);
	friend ostream& operator <<(ostream& os,const Pair& str);			//���������� ��������� ������
	friend istream& operator >> (istream& is, Pair& str);				//���������� ��������� �����
private:
	int first;															//���� 1
	double second;														//���� 2
};

