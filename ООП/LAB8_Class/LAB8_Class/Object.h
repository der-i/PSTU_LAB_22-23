#pragma once
#include <iostream>
#include <string>
using namespace std;

class Object		//����� ����������� �����
{			
public:
	Object() {}	
	~Object() {}
	virtual void Show() = 0;		//����� ����������� ������ ������
	virtual void Input() = 0;		
	virtual string GetName() = 0;
};