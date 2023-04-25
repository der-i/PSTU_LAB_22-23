#include "List.h"


List::iterator::iterator()
{
	this->head = nullptr;
	this->current = nullptr;
}

List::iterator::~iterator()
{
	this->head = nullptr;
	this->current = nullptr;
}

List::iterator::iterator(List& lst)
{
	this->head = lst.head;
	this->current = lst.head;
}

void List::iterator::operator+(int index)
{
	for (int i = 0; i < index; i++)
	{
		this->current = this->current->pNext;
	}
}

void List::iterator::operator++(int)
{			//���� �������� �������� ����� �� ������� ������, �� ������������� ����������
	if (current == nullptr) { throw std::exception("����� �� �������. ���������� �������� ��������."); }	
	this->current = this->current->pNext;
}

void List::iterator::operator++()
{			//���� �������� �������� ����� �� ������� ������, �� ������������� ����������
	if (current == nullptr) { throw std::exception("����� �� �������. ���������� �������� ��������."); }
	this->current = this->current->pNext;
}

void List::iterator::reset()
{
	this->current = this->head;
}

int& List::iterator::operator*()
{
	return this->current->data;
}

bool List::iterator::operator==(iterator it)
{
	return this->current == it.current;
}

bool List::iterator::operator!=(iterator it)
{
	return !(*this == it);
}
