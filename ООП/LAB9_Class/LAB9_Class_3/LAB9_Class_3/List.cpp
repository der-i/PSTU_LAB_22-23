#include"List.h"
#include <iostream>

List::List()				//�� ������� ������ ������, � ����������, � ��� ����� 0 ���������, � ����������� ��������� ������.
{
	size = 0;
	head = nullptr;
}

List::List(List& copy)
{
	this->size = 0;
	this->head = nullptr;
	Node* temp = copy.head;
	while (temp != nullptr) {
		push_back(temp->data);
		temp = temp->pNext;
	}
}
	


List::~List()			//���������� ����������� ������������ ������ �� ������� ������ clear,
{							//�� ����� ������������ ��� ��� ����������
	Node* temp;			//�� ����� ��������� ������ ��������
	while (size)
	{
		temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}


List::Node* List::push_back(int data)
{
	if (head == nullptr)			//�������� ������� ��������
	{
		head = new Node(data);	//������� ������� � �������� ��� � ������
		size++;
		return head;
	}
	else							//�������� ����������� ���������, ������� ��������� �� ������ ������� 
	{								//� ���� �� ���������, ���� �� ��������� �� ���, ��� ��������� �� nullptr
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
		++size;
		return current->pNext;
	}
							//���������� ��������� ����������� �� 1
}


int& List::operator[](const int index)		//�� �� ����� ������ ������� ������ �� ������, ��� ����� ������� ���������� ������� � ������ ������
{
	if (index < 0 || index >= this->size)
	{
		throw MyException("����� �� ������� ������.", -1);	//���� ������ ������� �� ������, �� ������������� ����������
	}
	int counter = 0;				//�������
	Node* current = this->head;		//���������, ��� ����, ����� ������������� �� ������ ������
	while (current != nullptr)		//���� � ��������, ��� �� �� ������� �� ������� ������ ������
	{
		if (counter == index)
		{
			return current->data;	//���� �� ��������� � ������ ������ �� �������� ������ ������
		}
		current = current->pNext;	//������ ��� ��������� ��������� �� ��������� ������
		counter++;
	}
}


void List::pop_front()			//�������� �� ������
{
	Node* temp = head;			//����� ��������� ��������� �� ������ head
	head = head->pNext;				//���������� head ��������� �� ��������� ������
	delete temp;					//������� ������ ������
	size--;							//��������� ����� �� 1
}


void List::clear()
{
	//Node<T>* temp;
	while (size)
	{
		//temp = head;				//�������� pop_front ������� ���, ���� size != 0
		//head = head->pNext;		//������ ������������ �� pop_front ������� �� ���������� �� ��� �����������
		//delete temp;
		//size--;
		pop_front();
	}
	this->head = nullptr;

}


void List::push_front(int data)	//���������� �������� � ������
{
	head = new Node(data, head);	//������ ��������� �������� ������� ����� �������, ��������� � ������� ����� �� ������ �������� �������
	size++;							//����������� ����� �� 1
}

void List::insert(int value, List::iterator& it)
{
	if (it.current == nullptr) { it.current = push_back(value); }							
	else if (it.head == it.current) { push_front(value); it.current = it.head = this->head; }
	else
	{
		Node* temp = it.head;
		while (temp->pNext != it.current)
			temp = temp->pNext;
		temp->pNext = new Node(value, temp->pNext);
		++size;
	}
}


void List::removeAt(List::iterator& iter)
{
	if (iter.head == nullptr) { throw MyException("�������� �� ��������� �� �������", -2); }	//�������� �������� ��������� �� ��������, �� �����-���� ������� ������
	if (iter.current == nullptr) { throw MyException("�������� �� ��������� �� �������", -2); }	//���� �������� ������ �� ���������, �� ������������� ����������
	Node* temp = iter.head;
	while (temp->pNext != iter.current)
		temp = temp->pNext;
	temp->pNext = iter.current->pNext;
	delete iter.current;
	iter.current = temp->pNext;
	--size;
}


void List::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* previous = head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}


void List::pop_back()
{
	removeAt(size - 1);
}


void List::removeFewAt(int index_start, int index_finish)		//�������� ���������� ���������
{
	if (index_start + (index_finish - index_start) >= size) return; //������� �������� �� �������
	for (int i = 0; i < index_finish - index_start + 1; i++)
	{
		removeAt(index_start);
	}
}

List::iterator List::begin()
{
	iterator it;
	it.head = List::head;
	it.current = List::head;
	return it;
}

List::iterator List::end()
{
	iterator temp;
	return temp;
}

List List::operator*(const List& other)
{
	if (this->size != other.size)
	{
		throw MyException("������� ������� ������", -3);
	}
	List temp;
	Node* l1 = this->head;
	Node* l2 = other.head;
	while (l1 != nullptr && l2 != nullptr)
	{
		temp.push_back(l1->data * l2->data);
		l1 = l1->pNext;
		l2 = l2->pNext;
	}
	int sz = abs(this->size - other.size);
	while (sz)
	{
		temp.push_back(0);
		--sz;
	}
	return temp;
}

List& List::operator=(const List& other)
{
	this->clear();
	Node* temp = other.head;
	while (temp != nullptr)
	{
		this->push_back(temp->data);
		temp = temp->pNext;
	}
	return *this;
}

