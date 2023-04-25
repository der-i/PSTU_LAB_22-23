#pragma once
#include "Magazin.h"
#include "Object.h"

class Tree {
public:
	Tree();			//������������ �����������
	Tree(int n);
	~Tree();

	void Add();			//���������� �������� � ������
	void Del();			//�������� �������� �� �������
	void Show();		//����� ����� �������
	void GetName();	//��������� ����� ������� ��������
	int operator()();	//��������� �������, �� ������� ��������� ������
protected:
	Object** beg;
	int size;
	int cur;
};