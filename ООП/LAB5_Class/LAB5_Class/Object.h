#pragma once
#include <iostream>
using namespace std;

class Object			//����������� �����
{
public:
	Object() { cout << "����������� ������ Object." << endl; }
	~Object() { cout << "���������� ������ Object" << endl; }
	virtual void Show() = 0;			//����� ����������� �������, ������� ������� ����������� � ������� �����������
};

