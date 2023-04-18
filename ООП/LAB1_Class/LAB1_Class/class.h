#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class MyClass
{
private:
	double first_el;				//������ ����
	unsigned int second_attitude;	//������ ����

public:
	MyClass() { first_el = second_attitude = 0; }		//����������� �� ���������
	MyClass(const MyClass& copy);						//����������� �����������
	MyClass(double first_el, int second_attitude);		//����������� � �����������
	~MyClass() {}										//���������� ������
	double element(int j) { return first_el * pow(second_attitude, j); }	//����� ���������� �� ����� ������
	void Read();															//������ � �������
	void Init(double first_el, int second_attitude);						//�������������
	void Show();															//����� �� �������
};
