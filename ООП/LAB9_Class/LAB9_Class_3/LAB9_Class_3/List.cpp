#include"List.h"
#include <iostream>

List::List()				//мы создаем пустой список, а следствено, в нем лежит 0 элементов, а следственно указывать некуда.
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
	


List::~List()			//деструктор освобождает динамическую память по приципу метода clear,
{							//мы можем делегировать ему эти обязаности
	Node* temp;			//но здесь прописана логика удаления
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
	if (head == nullptr)			//создание первого элемента
	{
		head = new Node(data);	//создаем элемент и помещаем его в голову
		size++;
		return head;
	}
	else							//создание последующих элементов, создаем указатель на первый элемент 
	{								//и идем по элементам, пока не наткнемся на тот, что указывает на nullptr
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
		++size;
		return current->pNext;
	}
							//количество элементов увеличиваем на 1
}


int& List::operator[](const int index)		//мы не можем просто вернуть данные из списка, для этого сначала необходимо перейти в нужную ячейку
{
	if (index < 0 || index >= this->size)
	{
		throw MyException("Выход за границы списка.", -1);	//если индекс выходит за список, то выбрасывается исключение
	}
	int counter = 0;				//счетчик
	Node* current = this->head;		//указатель, для того, чтобы итерироваться по нашему списку
	while (current != nullptr)		//цикл с условием, что мы не вылетим за границы нашего списка
	{
		if (counter == index)
		{
			return current->data;	//если мы находимся в нужной ячейке то получаем оттуда данные
		}
		current = current->pNext;	//меняем наш временный указатель на следующую ячейку
		counter++;
	}
}


void List::pop_front()			//удаление из начала
{
	Node* temp = head;			//делай временный указатель на объект head
	head = head->pNext;				//Указательь head переносим на следующую ячейку
	delete temp;					//удаляем первый объект
	size--;							//уменьшаем длину на 1
}


void List::clear()
{
	//Node<T>* temp;
	while (size)
	{
		//temp = head;				//вызываем pop_front столько раз, пока size != 0
		//head = head->pNext;		//логика основывается на pop_front поэтому мы делегируем ей эти обязанности
		//delete temp;
		//size--;
		pop_front();
	}
	this->head = nullptr;

}


void List::push_front(int data)	//добавление элемента в начало
{
	head = new Node(data, head);	//вместо головного элемента создаем новый элемент, указатель в котором будет на старый головной элемент
	size++;							//увеличиваем длину на 1
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
	if (iter.head == nullptr) { throw MyException("Итератор не указывает на элемент", -2); }	//проходит проверка указывает ли итератор, на какой-либо элемент списка
	if (iter.current == nullptr) { throw MyException("Итератор не указывает на элемент", -2); }	//если итератор никуда не указывает, то выбрасывается исключение
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


void List::removeFewAt(int index_start, int index_finish)		//удаление нескольких элементов
{
	if (index_start + (index_finish - index_start) >= size) return; //условие невыхода за границы
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
		throw MyException("Размеры списков разные", -3);
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

