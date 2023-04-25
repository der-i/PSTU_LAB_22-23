#pragma once
#include "List.h"


class MyException :public exception
{
public:
	MyException(const char* msg, int dataState) :exception(msg)
	{
		this->dataState = dataState;
		errors = "(-1) ����� �� ������� �������. \n(-2) �������� �� ��������� �� �������\n(-3) ������� ������� ������. \n(-4) ����� �� �������. ���������� �������� ��������.\n";
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