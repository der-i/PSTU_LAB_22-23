#pragma once
#include <iostream>
#include <string>
using namespace std;

class Object		//чисто абстрактный класс
{			
public:
	Object() {}	
	~Object() {}
	virtual void Show() = 0;		//чисто виртуальные методы класса
	virtual void Input() = 0;		
	virtual string GetName() = 0;
};