#pragma once

template <typename T>
class List
{
private:
	void removeAt(int index);			//удаление элемента по указаному индексу
							//минимальная ячейка памяти
	class Node				//вложенный класс - ячейка памяти
	{
	public:
		Node(T data = T(), Node* pNext = nullptr)		//используется параметр по умолчанию, то есть если мы не передаем указатель, то он автоматически присваивается nullptr
		{									//для поля data также используется параметр по умолчанию, выглядит он как вызов конструктора по умолчанию
			this->data = data;
			this->pNext = pNext;
		}
		Node* pNext;		//хранит указатель на следующий элемент
		T data;				//хранит наши данные

	};

	Node* head;			//указатель на первый элемент в списке
	int size;			//количество элементов в списке.
	
public:

	class iterator			//итератор для списка
	{
	private:
		friend class List;
		Node* head;			//указатель на node
		Node* current;

	public:
		iterator();			//конструкторы и деструктор 
		~iterator();
		iterator(List<T>& lst);
		void reset();
		void operator +(int index);		//операторы для взаимодействия
		void operator ++(int);
		void operator ++();
		T& operator *();
		bool operator ==(iterator it);		//операторы сравнения итераторов
		bool operator !=(iterator it);
	};

public:
	List();								//Конструктор
	~List();							//Деструктор
	List(List<T>& copy);
	void push_back(T data);				//добавляет элемент в конец списка
	int GetSize() { return size; }		//так как инкапсуляция не дает нам доступ к количеству элементов в списке, то нам необходимо происать геттер
	T& operator[](const int index);		//перегрузка оператора [] для того, чтобы мы могли взаимодействовать со списком как с массивом
	List<T>& operator=(const List<T>& other);
	void pop_front();					//удаляет элемент из начала списка
	void clear();						//удаляет все элементы списка (логика как у pop_front, деструктор основан на этой штуке)
	void push_front(T data);			//добавляет элемент в начало списка
	void removeAt(List::iterator& iter);
	void insert(T value, int index);	//добавление элемента по индексу
	void pop_back();					//удаление из конца списка
	
	iterator begin();
	iterator end();

	void removeFewAt(int index_start, int index_finish);	//удаление нескольких элементов
	void insert(T value, List::iterator& it);				//добавление элементов по итератору

	List<T> operator*(const List& other);					//оператор умнжения списка на список

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
List<T>::List()				//мы создаем пустой список, а следствено, в нем лежит 0 элементов, а следственно указывать некуда.
{
	size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()			//деструктор освобождает динамическую память по приципу метода clear,
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
	if (head == nullptr)			//создание первого элемента
	{
		head = new Node(data);	//создаем элемент и помещаем его в голову
	}
	else							//создание последующих элементов, создаем указатель на первый элемент 
	{								//и идем по элементам, пока не наткнемся на тот, что указывает на nullptr
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	size++;						//количество элементов увеличиваем на 1
}

template<typename T>
T& List<T>::operator[](const int index)		//мы не можем просто вернуть данные из списка, для этого сначала необходимо перейти в нужную ячейку
{
	int counter = 0;				//счетчик
	Node* current = this->head;	//указатель, для того, чтобы итерироваться по нашему списку
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
void List<T>::pop_front()			//удаление из начала
{
	Node* temp = head;			//делай временный указатель на объект head
	head = head->pNext;				//Указательь head переносим на следующую ячейку
	delete temp;					//удаляем первый объект
	size--;							//уменьшаем длину на 1
}

template<typename T>
void List<T>::clear()
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
}

template<typename T>
void List<T>::push_front(T data)	//добавление элемента в начало
{
	head = new Node(data, head);	//вместо головного элемента создаем новый элемент, указатель в котором будет на старый головной элемент
	size++;							//увеличиваем длину на 1
}

template<typename T>
void List<T>::insert(T value, int index)	//вставка элемента по индексу
{
	if (index > size) return;			//если индекс больше size, то вставить невозможно
	if (index == 0)						//если индекс 0 то вызываем вставку в начало списка
	{
		push_front(value);
	}
	else if (index == size)				//если индекс равен длине, вызываем вставку в конец списка
	{
		push_back(value);
	}
	else
	{
		Node* previous = this->head;	//создаем указатель на головной элемент для поиска нужного элемента
		for (int i = 0; i < index - 1; i++)	//поиск предыдущего элемента, перед индексом, чтобы поменять в нем указатель
		{
			previous = previous->pNext;
		}
		previous->pNext = new Node(value, previous->pNext);	//создание нового элемента с переданным значением и установка указателя на элемент с переданным индексом	
		size++;													//Предыдущая строка "вклинивает" новый элемент между старыми
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
void List<T>::removeFewAt(int index_start, int index_finish)		//удаление нескольких элементов
{
	if (index_start + (index_finish - index_start) >= size) return; //условие невыхода за границы
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
