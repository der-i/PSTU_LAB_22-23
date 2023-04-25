#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;
#include "myexception.h"

class List
{
private:
	void removeAt(int index);
		//����������� ������ ������
	class Node				//��������� ����� - ������ ������
	{
	public:
		Node(int data = int(), Node* pNext = nullptr)		//������������ �������� �� ���������, �� ���� ���� �� �� �������� ���������, �� �� ������������� ������������� nullptr
		{									//��� ���� data ����� ������������ �������� �� ���������, �������� �� ��� ����� ������������ �� ���������
			this->data = data;
			this->pNext = pNext;
		}
		Node* pNext;		//������ ��������� �� ��������� �������
		int data;				//������ ���� ������

	};

	Node* head;			//��������� �� ������ ������� � ������int
	int size;				//���������� ��������� � ������.
public:
	class iterator			//�������� ��������
	{
	private:
		friend class List;		
		Node* head;			//��������� �� node
		Node* current;
		
	public:
		iterator();			//������������ ��������� / �����������
		~iterator();
		iterator(List& lst);
		void reset();
		void operator +(int index);	//��������� ���������
		void operator ++(int);
		void operator ++();
		int& operator *();
		bool operator ==(iterator it);
		bool operator !=(iterator it);
	};
	List();								//�����������
	List(List& copy);//!!!!!!
	~List();							//����������

	List& operator=(const List& other);//!!!!!!!!!!
	
	Node* push_back(int data);				//��������� ������� � ����� ������
	int GetSize() { return size; }		//��� ��� ������������ �� ���� ��� ������ � ���������� ��������� � ������, �� ��� ���������� �������� ������
	int& operator[](const int index);		//���������� ��������� [] ��� ����, ����� �� ����� ����������������� �� ������� ��� � ��������
	void pop_front();					//������� ������� �� ������ ������
	void clear();						//������� ��� �������� ������ (������ ��� � pop_front, ���������� ������� �� ���� �����)
	void push_front(int data);			//��������� ������� � ������ ������
	void removeAt(List::iterator& iter);			//�������� �������� �� ��������� �������
	void pop_back();					//�������� �� ����� ������
	
	iterator begin();
	iterator end();
	
	void removeFewAt(int index_start, int index_finish);	//�������� ���������� ���������
	friend class iterator;

	void insert(int value, List::iterator& it);
	List operator*(const List& other);
};
