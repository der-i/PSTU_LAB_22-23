#pragma once
#include "Magazin.h"
#include "Object.h"

class Tree {
public:
	Tree();			//конструкторы деструкторы
	Tree(int n);
	~Tree();

	void Add();			//добавление элемента в вектор
	void Del();			//удаление элемента из вектора
	void Show();		//вывод всего вектора
	void GetName();	//получение имени каждого элемента
	int operator()();	//получение позиции, на которую указывает вектор
protected:
	Object** beg;
	int size;
	int cur;
};