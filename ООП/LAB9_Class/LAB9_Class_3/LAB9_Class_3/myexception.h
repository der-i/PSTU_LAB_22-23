#pragma once
#include "List.h"


class MyException :public exception
{
public:
	MyException(const char* msg, int dataState) :exception(msg)
	{
		this->dataState = dataState;
		errors = "(-1) Выход за пределы массива. \n(-2) Итератор не указывает на элемент\n(-3) Размеры списков разные. \n(-4) Выход за границы. Невозмонжо получить значение.\n";
	}
	int GetDataState() const
	{
		return dataState;
	}
	string GetErrors() const
	{
		return errors;
	}
private:
	int dataState;
	string errors;
};