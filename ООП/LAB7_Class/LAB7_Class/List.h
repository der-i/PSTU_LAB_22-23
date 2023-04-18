#pragma once

template <typename T>
class List
{
private:
	void removeAt(int index);			//�������� �������� �� ��������� �������
							//����������� ������ ������
	class Node				//��������� ����� - ������ ������
	{
	public:
		Node(T data = T(), Node* pNext = nullptr)		//������������ �������� �� ���������, �� ���� ���� �� �� �������� ���������, �� �� ������������� ������������� nullptr
		{									//��� ���� data ����� ������������ �������� �� ���������, �������� �� ��� ����� ������������ �� ���������
			this->data = data;
			this->pNext = pNext;
		}
		Node* pNext;		//������ ��������� �� ��������� �������
		T data;				//������ ���� ������

	};

	Node* head;			//��������� �� ������ ������� � ������
	int size;			//���������� ��������� � ������.
	
public:

	class iterator			//�������� ��� ������
	{
	private:
		friend class List;
		Node* head;			//��������� �� node
		Node* current;

	public:
		iterator();			//������������ � ���������� 
		~iterator();
		iterator(List<T>& lst);
		void reset();
		void operator +(int index);		//��������� ��� ��������������
		void operator ++(int);
		void operator ++();
		T& operator *();
		bool operator ==(iterator it);		//��������� ��������� ����������
		bool operator !=(iterator it);
	};

public:
	List();								//�����������
	~List();							//����������
	List(List<T>& copy);
	void push_back(T data);				//��������� ������� � ����� ������
	int GetSize() { return size; }		//��� ��� ������������ �� ���� ��� ������ � ���������� ��������� � ������, �� ��� ���������� �������� ������
	T& operator[](const int index);		//���������� ��������� [] ��� ����, ����� �� ����� ����������������� �� ������� ��� � ��������
	List<T>& operator=(const List<T>& other);
	void pop_front();					//������� ������� �� ������ ������
	void clear();						//������� ��� �������� ������ (������ ��� � pop_front, ���������� ������� �� ���� �����)
	void push_front(T data);			//��������� ������� � ������ ������
	void removeAt(List::iterator& iter);
	void insert(T value, int index);	//���������� �������� �� �������
	void pop_back();					//�������� �� ����� ������
	
	iterator begin();
	iterator end();

	void removeFewAt(int index_start, int index_finish);	//�������� ���������� ���������
	void insert(T value, List::iterator& it);				//���������� ��������� �� ���������

	List<T> operator*(const List& other);					//�������� �������� ������ �� ������

};


template<typename T>
List<T> List<T>::operator*(const List<T>& other)
{
	List<T> temp;
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

template<typename T>
typename List<T>::iterator List<T>::begin()
{
	iterator it;
	it.current = this->head;
	it.head = this->head;
	return it;
}

template<typename T>
typename List<T>::iterator List<T>::end()
{
	iterator it(*this);
	it.current = nullptr;
	return iterator();
}

template<typename T>
void List<T>::insert(T value, List::iterator& it)
{
	if (it.current == nullptr) { return; }
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

template <typename T>
List<T>::List()				//�� ������� ������ ������, � ����������, � ��� ����� 0 ���������, � ����������� ��������� ������.
{
	size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()			//���������� ����������� ������������ ������ �� ������� ������ clear,
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

template <typename T>
List<T>::List(List<T>& copy)
{
	this->size = 0;
	this->head = nullptr;
	Node* temp = copy.head;
	while (temp != nullptr) {
		push_back(temp->data);
		temp = temp->pNext;
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)			//�������� ������� ��������
	{
		head = new Node(data);	//������� ������� � �������� ��� � ������
	}
	else							//�������� ����������� ���������, ������� ��������� �� ������ ������� 
	{								//� ���� �� ���������, ���� �� ��������� �� ���, ��� ��������� �� nullptr
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	size++;						//���������� ��������� ����������� �� 1
}

template<typename T>
T& List<T>::operator[](const int index)		//�� �� ����� ������ ������� ������ �� ������, ��� ����� ������� ���������� ������� � ������ ������
{
	int counter = 0;				//�������
	Node* current = this->head;	//���������, ��� ����, ����� ������������� �� ������ ������
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

template<typename T>
List<T>& List<T>::operator=(const List<T>& other)
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


template<typename T>
void List<T>::pop_front()			//�������� �� ������
{
	Node* temp = head;			//����� ��������� ��������� �� ������ head
	head = head->pNext;				//���������� head ��������� �� ��������� ������
	delete temp;					//������� ������ ������
	size--;							//��������� ����� �� 1
}

template<typename T>
void List<T>::clear()
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
}

template<typename T>
void List<T>::push_front(T data)	//���������� �������� � ������
{
	head = new Node(data, head);	//������ ��������� �������� ������� ����� �������, ��������� � ������� ����� �� ������ �������� �������
	size++;							//����������� ����� �� 1
}

template<typename T>
void List<T>::insert(T value, int index)	//������� �������� �� �������
{
	if (index > size) return;			//���� ������ ������ size, �� �������� ����������
	if (index == 0)						//���� ������ 0 �� �������� ������� � ������ ������
	{
		push_front(value);
	}
	else if (index == size)				//���� ������ ����� �����, �������� ������� � ����� ������
	{
		push_back(value);
	}
	else
	{
		Node* previous = this->head;	//������� ��������� �� �������� ������� ��� ������ ������� ��������
		for (int i = 0; i < index - 1; i++)	//����� ����������� ��������, ����� ��������, ����� �������� � ��� ���������
		{
			previous = previous->pNext;
		}
		previous->pNext = new Node(value, previous->pNext);	//�������� ������ �������� � ���������� ��������� � ��������� ��������� �� ������� � ���������� ��������	
		size++;													//���������� ������ "����������" ����� ������� ����� �������
	}
}

template<typename T>
void List<T>::removeAt(int index)
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

template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
}


template<typename T>
void List<T>::removeFewAt(int index_start, int index_finish)		//�������� ���������� ���������
{
	if (index_start + (index_finish - index_start) >= size) return; //������� �������� �� �������
	for (int i = 0; i < index_finish - index_start + 1; i++)
	{
		removeAt(index_start);
	}
}

template<typename T>
void List<T>::removeAt(List::iterator& iter)
{
	if (iter.current == nullptr) return;
	Node* temp = iter.head;
	while (temp->pNext != iter.current)
		temp = temp->pNext;
	temp->pNext = iter.current->pNext;
	delete iter.current;
	iter.current = temp->pNext;
	--size;
}







template<typename T>
List<T>::iterator::iterator()
{
	this->head = nullptr;
	this->current = nullptr;
}

template<typename T>
List<T>::iterator::~iterator()
{
	this->head = nullptr;
	this->current = nullptr;
}

template<typename T>
List<T>::iterator::iterator(List<T>& lst)
{
	this->head = lst.head;
	this->current = lst.head;
}


template<typename T>
void List<T>::iterator::operator+(int index)
{
	for (int i = 0; i < index; i++)
	{
		this->current = this->current->pNext;
	}
}

template<typename T>
void List<T>::iterator::operator++(int)
{
	this->current = this->current->pNext;
}

template<typename T>
void List<T>::iterator::operator++()
{
	this->current = this->current->pNext;
}

template<typename T>
void List<T>::iterator::reset()
{
	this->current = this->head;
}

template<typename T>
T& List<T>::iterator::operator*()
{
	return this->current->data;
}

template<typename T>
bool List<T>::iterator::operator==(iterator it)
{
	if (this->current == it.current) return true;
	return false;
}

template<typename T>
bool List<T>::iterator::operator!=(iterator it)
{
	return !(*this == it);
}
