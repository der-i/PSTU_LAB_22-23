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
		//минимальна€ €чейка пам€ти
	class Node				//вложенный класс - €чейка пам€ти
	{
	public:
		Node(int data = int(), Node* pNext = nullptr)		//используетс€ параметр по умолчанию, то есть если мы не передаем указатель, то он автоматически присваиваетс€ nullptr
		{									//дл€ пол€ data также используетс€ параметр по умолчанию, выгл€дит он как вызов конструктора по умолчанию
			this->data = data;
			this->pNext = pNext;
		}
		Node* pNext;		//хранит указатель на следующий элемент
		int data;				//хранит наши данные

	};

	Node* head;			//указатель на первый элемент в спискеint
	int size;				//количество элементов в списке.
public:
	class iterator			//вложнный итератор
	{
	private:
		friend class List;		
		Node* head;			//указатель на node
		Node* current;
		
	public:
		iterator();			//конструкторы итератора / деструкторы
		~iterator();
		iterator(List& lst);
		void reset();
		void operator +(int index);	//операторы итератора
		void operator ++(int);
		void operator ++();
		int& operator *();
		bool operator ==(iterator it);
		bool operator !=(iterator it);
	};
	List();								// онструктор
	List(List& copy);//!!!!!!
	~List();							//ƒеструктор

	List& operator=(const List& other);//!!!!!!!!!!
	
	Node* push_back(int data);				//добавл€ет элемент в конец списка
	int GetSize() { return size; }		//так как инкапсул€ци€ не дает нам доступ к количеству элементов в списке, то нам необходимо происать геттер
	int& operator[](const int index);		//перегрузка оператора [] дл€ того, чтобы мы могли взаимодействовать со списком как с массивом
	void pop_front();					//удал€ет элемент из начала списка
	void clear();						//удал€ет все элементы списка (логика как у pop_front, деструктор основан на этой штуке)
	void push_front(int data);			//добавл€ет элемент в начало списка
	void removeAt(List::iterator& iter);			//удаление элемента по указаному индексу
	void pop_back();					//удаление из конца списка
	
	iterator begin();
	iterator end();
	
	void removeFewAt(int index_start, int index_finish);	//удаление нескольких элементов
	friend class iterator;

	void insert(int value, List::iterator& it);
	List operator*(const List& other);
};
