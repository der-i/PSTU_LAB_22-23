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
{
	this->current = this->current->pNext;
}

void List::iterator::operator++()
{
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
	if (this->current == it.current) return true;
	return false;
}

bool List::iterator::operator!=(iterator it)
{
	return !(*this == it);
}
