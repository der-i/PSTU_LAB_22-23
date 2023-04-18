#pragma once
#include "Object.h"

class Vector
{
private:
	Object** arr;			//указатель на указатель, для того, чтобы хранить любые данные
	int size;				//дллина вектора
	friend ostream& operator <<(ostream& os, const Vector& vec);	//оператор вывода всего вектора  в консоль
public:
	int length() { return this->size; }				//Метод возвращаюзий длину вектора
	Vector();			//конструкторы / деструкторы
	Vector(int size);
	~Vector();
	void add(Object* obj);		//добавление элемента в вектор
	Object*& operator[](const int index);		//оператор индексирования по вектору
};

