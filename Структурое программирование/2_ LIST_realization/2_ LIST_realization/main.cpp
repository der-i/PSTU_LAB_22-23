#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

class MyClass
{
public:
	void setData() { cin >> str; }
	string getData() { return str; }
private:
	string str;
	friend ostream& operator << (std::ostream& os, MyClass& cl);
	friend istream& operator >> (std::istream& in, MyClass& cl);
};

ostream& operator << (std::ostream& os, MyClass& cl)			//перегруженный оператор вывода для моего класса
{
	return os << cl.str;		//запись данных в поток
}

istream& operator >> (std::istream& in, MyClass& cl)			//перегруженный оператор ввода для моего класса
{
	in >> cl.str;											//что и куда читать из потока
	return in;
}

template <typename T>
class List
{
private:
	template<typename T>	//минимальная ячейка памяти
	class Node				//вложенный класс - ячейка памяти
	{
	public:
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)		//используется параметр по умолчанию, то есть если мы не передаем указатель, то он автоматически присваивается nullptr
		{									//для поля data также используется параметр по умолчанию, выглядит он как вызов конструктора по умолчанию
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
		Node* pNext;		//хранит указатель на следующий элемент
		Node* pPrev;		//хранит указатель на предыдущий элемент
		T data;				//хранит наши данные

	};

	Node<T>* head;			//указатель на первый элемент в списке
	Node<T>* tail;			//указатель на последний элемент в списке
	int size;				//количество элементов в списке.
public:
	List();								//Конструктор
	~List();							//Деструктор
	void push_back(T data);				//добавляет элемент в конец списка
	int GetSize() { return size; }		//так как инкапсуляция не дает нам доступ к количеству элементов в списке, то нам необходимо происать геттер
	T& operator[](const int index);		//перегрузка оператора [] для того, чтобы мы могли взаимодействовать со списком как с массивом
	void pop_front();					//удаляет элемент из начала списка	
	void clear();						//удаляет все элементы списка (логика как у pop_front, деструктор основан на этой штуке)
	void push_front(T data);			//добавляет элемент в начало списка
	void insert(T value, int index);	//добавление элемента по индексу
	void removeAt(int index);			//удаление элемента по указаному индексу
	void pop_back();					//удаление из конца списка
	
	void writeFile(string path);		//запись в файл
	void readFile(string path);			//чтение из файла
	void removeFewAt(int index_start, int index_finish);	//удаление нескольких элементов
	//Node<T>*& searchPriveousIndex(const int index); //поиск предыдущего элемента для реализации методов insert и removeAt
	//void insertFewElem(int index)

};




int main()
{
	setlocale(LC_ALL, "ru");
	system("color F0");
	SetConsoleCP(1251);
	int a = 2;
	MyClass mc;
	List<MyClass> lst;
	bool f = true;
	string path;
	while (f)
	{
		cout << "---------------------МЕНЮ---------------------" << endl << endl;
		cout << "1.  Добавить элемент в конец списка." << endl
			<< "2.  Добавить элемент в начало списка" << endl
			<< "3.  Добавить элемент в середину списка." << endl
			<< "4.  Добавить k элементов в конец списка." << endl
			<< "5.  Добавить k элементов в начало списка." << endl
			<< "6.  Добавить k элементов в середину списка." << endl
			<< "7.  Удалить элемент из конца списка." << endl
			<< "8.  Удалить элемент из начала списка." << endl
			<< "9.  Удалить элемент из середины списка." << endl
			<< "10. Удалить k элементов из конца списка." << endl
			<< "11. Удалить k элементов из начала списка." << endl
			<< "12. Удалить k элементов из середины списка." << endl
			<< "13. Вывести список в консоль." << endl
			<< "14. Удалить все данные из списка." << endl
			<< "15. Записать в файл." << endl
			<< "16. Считать из файла." << endl
			<< "0.  Выход." << endl << endl;


		cin >> a;


		switch (a)
		{
		case 1:
		{
			cout << "Введите данные: " << endl;
			mc.setData();
			lst.push_back(mc);
			cout << "DONE" << endl;
			break;
		}
		case 2:
		{
			cout << "Введите данные: " << endl;
			mc.setData();
			lst.push_front(mc);
			cout << "DONE" << endl;
			break;
		}
		case 3:
		{
			int b;
			cout << "Введите данные: " << endl;
			mc.setData();
			do
			{
				cout << "На какую позицию записать данные? (Введите индекс) "; cin >> b;

			} while (b > lst.GetSize());
			lst.insert(mc, b);
			cout << "DONE" << endl;
			break;
		}
		case 4:
		{
			int b;
			cout << "Введите количество элементов для добавления: "; cin >> b;
			for (int i = 0; i < b; i++)
			{
				cout << "Введите данные: " << endl;
				mc.setData();
				lst.push_back(mc);
				cout << "DONE" << endl;
			}
			break;
		}
		case 5:
		{
			int b;
			cout << "Введите количество элементов для добавления: "; cin >> b;
			cout << "Введите данные: " << endl;
			mc.setData();
			lst.push_front(mc);
			cout << "DONE" << endl;
			for (int i = 1; i < b; i++)
			{
				cout << "Введите данные: " << endl;
				mc.setData();
				lst.insert(mc, i);
				cout << "DONE" << endl;
			}
			break;
		}
		case 6:
		{
			int b, c;
			cout << "Введите количество элементов для добавления: "; cin >> b;
			do
			{
				cout << "На какую позицию записать данные? (Введите индекс) "; cin >> c;

			} while (c > lst.GetSize());
			for (int i = 0; i < b; i++)
			{
				cout << "Введите данные: " << endl;
				mc.setData();
				lst.insert(mc, c + i);
				cout << "DONE" << endl;
			}
			break;
		}
		case 7:
		{
			lst.pop_back();
			cout << "DONE" << endl;
			break;
		}
		case 8:
		{
			lst.pop_front();
			cout << "DONE" << endl;
			break;
		}
		case 9:
		{
			int b;
			cout << "Введите индекс элемента для удаления: "; cin >> b;
			lst.removeAt(b);
			cout << "DONE" << endl;
			break;
		}
		case 10:
		{
			int b;
			cout << "Введите количество элементов для удаления: "; cin >> b;
			for (int i = 0; i < b; i++)
			{
				lst.pop_back();
			}
			cout << "DONE" << endl;
			break;
		}
		case 11:
		{
			int b;
			cout << "Введите количество элементов для удаления: "; cin >> b;
			for (int i = 0; i < b; i++)
			{
				lst.pop_front();
			}
			cout << "DONE" << endl;
			break;
		}
		case 12:
		{
			int b, c;
			cout << "Введите начальный индекс: "; cin >> b;
			cout << "Введите конечный  индекс: "; cin >> c;
			lst.removeFewAt(b, c);
			cout << "DONE" << endl;
			break;
		}
		case 13:
		{
			for (int i = 0; i < lst.GetSize(); i++)
			{
				cout << lst[i] << "   ";
			}
			cout << endl << endl;
			system("pause");
			break;
		}
		case 14:
		{
			lst.clear();
			cout << "DONE" << endl;
			break;
		}
		case 15:
		{
			if (path == "")
			{
				cout << "Введите название файла для записи: ";
				cin >> path;
				path = path + ".txt";
			}
			lst.writeFile(path);
			break;
		}
		case 16:
		{
			if (path == "")
			{
				cout << "Введите название файла для чтения: ";
				cin >> path;
				path = path + ".txt";
			}
			lst.readFile(path);
			break;
		}
		case 0: {f = false; break;}
		default:
		{
			cout << "Неверный параметр, попробуйте снова." << endl;
			break;
		}
		}
		cout << "\033[2J\033[1;1H";
	}
	SetConsoleCP(866);
	return 0;
}

/*
Двусвязный список / двунаправленный список

Имеет head и tail.

* хранит в каждой ячейке указатель на следующий и предыдущий элемент.
* более быстрый по сравнению с односвязным списком, при выполнении действий ближе к концу списку.

*/

template<typename T>
void List<T>::writeFile(string path)	//запись в файл
{
	fstream fs;
	fs.open(path, fstream::out);
	Node<T>* temp = head;
	fs << GetSize() << "\n";			//запись в файл размера списка
	for (int i = 0; i < GetSize(); i++)	//запись данных в файл
	{
		fs << temp->data << " ";
		temp = temp->pNext;
	}
	fs.close();
}

template<typename T>
void List<T>::readFile(string path)		//чтение из файла
{
	T buf;
	fstream fs;
	fs.open(path, fstream::in | fstream::app);
	int length;
	fs >> length;						//чтение длины (сколько данных в файле)
	for (int i = 0; i < length; i++)
	{
		fs >> buf;
		push_back(buf);				//полученные данные добавляем в конец списка
	}
	fs.close();
}

template<typename T>
void List<T>::pop_back()		//удаление с конца файла
{
	removeAt(size - 1);			//вызов функции удаления по индексу
}

template<typename T>
void List<T>::removeAt(int index)		//удаление по индксу
{
	if (index == 0)	pop_front();		//если 0 индекс, то удаляем с конца
	else if (index == size - 1)			//если последний элемент
	{
		Node<T>* previous = tail;		//устанавливаем указатель на хвост
		for (int i = size - 1; i > index - 1; i--)	//идем на предыдущий элемент
		{											//(относительно удаляемого элемента
			previous = previous->pPrev;				//итерируемся по списку
		}
		Node<T>* toDelete = previous->pNext;		//создаем указатель на ячейку для удаления
		previous->pNext = nullptr;				//меняем указатели на следующий элемент у предшествющего
		delete toDelete;					//удаляем элемент
		tail = previous;					//меняем уазатель на хвост
		size--;
	}
	else
	{
		if (size - index < size / 2)		//условие с какой стороны меньше итерироваться до предыдущего элемента
		{
			Node<T>* previous = tail;
			for (int i = size - 1; i > index - 1; i--)
			{
				previous = previous->pPrev;
			}
			Node<T>* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;	//замена указателя на следующий элемент
			toDelete->pNext->pPrev = previous;	//замена указателя на предыдущий элемент
			delete toDelete;					
			size--;
		}
		else
		{
			Node<T>* previous = head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}
			Node<T>* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;
			toDelete->pNext->pPrev = previous;
			delete toDelete;
			size--;
		}
	}
}

template<typename T>
void List<T>::insert(T data, int index)		//добавление элемента по индексу
{
	if (index > size)  return;			//проверки на исключения
	if (index == 0) push_front(data);
	else if (index == size) push_back(data);
	else
	{
		if (size - index < size / 2)		//условие с какой стороны меньше итерироваться до предыдущего элемента
		{
			Node<T>* previous = this->tail;
			for (int i = size - 1; i > index - 1; i--)
			{
				previous = previous->pPrev;			//нахождение предшествующего элемента
			}
			previous->pNext = new Node<T>(data, previous->pNext, previous);	//добавление элемента
			previous->pNext->pPrev = previous;		//смена указателей
		}
		else
		{
			Node<T>* previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;			//нахождение предшествующего элемента
			}
			previous->pNext = new Node<T>(data, previous->pNext, previous);	//добавление элемента
			previous->pNext->pPrev = previous;//смена указателей
		}
		size++;
	}
}

template<typename T>
void List<T>::push_front(T data)		//добавление в начало
{
	if (head == nullptr)		//исключение
	{
		head = new Node<T>(data);	//создание объекта
		tail = head;			//установка хвоста
	}
	else
	{
		Node<T>* temp = new Node<T>(data, head);	//создание объекта с параметрами, чтобы сразу установить предществущий 
		head->pPrev = temp;			//смена указателей
		head = temp;
	}
	size++;
}


template<typename T>
List<T>::List()			//конструктор
{
	head = tail = nullptr;
	size = 0;
}

template<typename T>
List<T>::~List()	//деструктор
{
	clear();
}



template<typename T>
void List<T>::clear()	//очищение всего списка
{
	while (size)		//пока длина != 0
	{
		pop_front();
	}
}

template<typename T>
void List<T>::pop_front()	//удаление первого элемента
{
	Node<T>* toDelete = head;	//установка указателя на голову
	if (size == 1)			//проверка исключения
	{
		head = head->pNext;	//смена указателей
		tail = tail->pPrev;
		delete toDelete;
	}
	else
	{
		head = head->pNext;	//смена указателей
		head->pPrev = nullptr;
		delete toDelete;
	}
	size--;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter_prev = size - 1;	//счетчик для того, чтобы идти с конца
	int counter_next = 0;			//счетчик для того, чтобы идти с начала
	Node<T>* elem;					//указатель для итерации по списку
	if (size - index <= size / 2)	//условие с какой стороны лучще идти по списку
	{
		elem = this->tail;			//установка отсчета
		while (elem != nullptr)		//цикл с условием окончания списка
		{
			if (counter_prev == index)	
			{
				return elem->data;	//возврат данных, когда находимся в нужно ячейке
			}
			elem = elem->pPrev;		//переход на следующую ячейку
			counter_prev--;
		}
	}
	else
	{
		elem = this->head;
		while (elem != nullptr)		//цикл с условием, что мы не вылетим за границы нашего списка
		{
			if (counter_next == index)
			{
				return elem->data;	//если мы находимся в нужной ячейке то получаем оттуда данные
			}
			elem = elem->pNext;	//меняем наш временный указатель на следующую ячейку
			counter_next++;
		}
	}
}

template<typename T>
void List<T>::push_back(T data)		//добавление в конец
{
	if (head == nullptr)		//исключения
	{
		head = new Node<T>(data);	//создание объекта
		tail = head;		
	}
	else
	{
		Node<T> *current = new Node<T>(data);	//создание объекта
		tail->pNext = current;	//смена указателей
		current->pPrev = tail;
		tail = current;			
	}
	size++;
}

template<typename T>
void List<T>::removeFewAt(int index_start, int index_finish)	//удаление нескольких элементов
{
	if (index_start + (index_finish - index_start) >= size) return;		//условие невыхода за границу
	for (int i = 0; i < index_finish - index_start + 1; i++)
	{
		removeAt(index_start);
	}
}