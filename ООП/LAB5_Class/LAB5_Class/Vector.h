#pragma once
#include "Object.h"

class Vector
{
private:
	Object** arr;			//��������� �� ���������, ��� ����, ����� ������� ����� ������
	int size;				//������ �������
	friend ostream& operator <<(ostream& os, const Vector& vec);	//�������� ������ ����� �������  � �������
public:
	int length() { return this->size; }				//����� ������������ ����� �������
	Vector();			//������������ / �����������
	Vector(int size);
	~Vector();
	void add(Object* obj);		//���������� �������� � ������
	Object*& operator[](const int index);		//�������� �������������� �� �������
};

