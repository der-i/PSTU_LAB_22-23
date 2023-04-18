#include "Vector.h"

Vector::Vector()
{
	arr = nullptr;
	size = 0;
}

Vector::Vector(int size)
{
	this->size = size;
	this->arr = new Object* [size];
	for (int i = 0; i < size; i++)
		arr[i] = nullptr;
}

Vector::~Vector()
{
	delete[]arr;
}

void Vector::add(Object* obj)
{
	int i = 0;
	while (arr[i] != nullptr && i < size) ++i;
	if (i < size) arr[i] = obj;
	else
	{
		Object** temp = new Object* [size + 1];
		for (int j = 0; j < size; j++)
			temp[j] = arr[j];
		temp[size] = obj;
		++size;
		delete[]arr;
		arr = temp;
		temp = nullptr;
	}
}

Object*& Vector::operator[](const int index)
{
	return arr[index];
}

ostream& operator<<(ostream& os, const Vector& vec)
{
	for (int i = 0; i < vec.size && vec.arr[i] != nullptr; ++i)
	{
		 vec.arr[i]->Show();
		 cout << endl;
	}
	return os;
}
