#pragma once
#include "Object.h"

class Person : public Object	
{
private:
	friend ostream& operator <<(ostream& os, const Person& per);
	friend istream& operator >> (istream& is, Person& per);
protected:
	string name;		//����������� ���� ������
	int age;
public:
			
	Person();					//������������ / �����������	
	Person(string name, int age);
	Person(const Person& copy);
	~Person();
	void Show() override;		//��������������� ����� ������������ ������
	void SetName(string name) { this->name = name; }		//������� / �������
	void SetAge(int age) { this->age = age; }
	string GetName() { return this->name; }
	int GetAge() { return this->age; }
	Person& operator =(const Person& other);			//�������� �������������

};

