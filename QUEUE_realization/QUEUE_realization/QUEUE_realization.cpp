#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

class MyClass
{
private:
	string str;
	friend ostream& operator << (std::ostream& os, MyClass& cl);
	friend istream& operator >> (std::istream& in, MyClass& cl);
public:
	MyClass()
	{
		this->str = "";
	}
	MyClass(string str)
	{
		this->str = str;
	}
	MyClass& operator =(const MyClass& other);
	void setData() { cin >> str; }
	string getData() { return str; }
};

MyClass& MyClass::operator=(const MyClass& other)
{
	this->str = other.str;
	return *this;
}

ostream& operator << (std::ostream& os, MyClass& cl)			//перегруженный оператор вывода для моего класса
{
	return os << cl.str;		//запись данных в поток
}

istream& operator >> (std::istream& in, MyClass& cl)			//перегруженный оператор ввода для моего класса
{
	in >> cl.str;				//что и куда читать из потока
	return in;
}

template <typename T>
class Queue
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

	Node<T>* head;			//указатель на первый элемент в очереди
	Node<T>* tail;			//указатель на последний элемент в очереди
	int size;				//количество элементов в очереди.
public:
	Queue();							//Конструктор
	~Queue();							//Деструктор
	int GetSize() { return size; }		//так как инкапсуляция не дает нам доступ к количеству элементов в списке, то нам необходимо прописать геттер
	void clear();						//удаляет все элементы очереди 
	void add(T data);					//добавляет элемент в очередь
	void del();							//удаление элемента из очереди
	void writeFile(string path);		//запись в файл
	void readFile(string path);			//чтение из файла
	T& getDataEnd() { return tail->data; }	//получение данных из конца очереди
	T& getDataStart() { return head->data; }	//получение данных из начала очереди
};


int main()
{
	setlocale(LC_ALL, "ru");
	setlocale(LC_ALL, "ru");
	system("color F0");
	SetConsoleCP(1251);
	int a = 2;
	MyClass mc;
	Queue<MyClass> que;
	bool f = true;
	string path;
	while (f)
	{
		cout << "---------------------МЕНЮ---------------------" << endl << endl;
		cout << "1. Добавить элемент." << endl
			<< "2. Добавить k элементов." << endl
			<< "3. Удалить элемент." << endl
			<< "4. Удалить k элементов." << endl
			<< "5. Удалить все данные." << endl
			<< "6. Вывести первый элемент." << endl
			<< "7. Вывести последний элемент." << endl
			<< "8. Записать в файл." << endl
			<< "9. Считать из файла." << endl
			<< "0. Выход." << endl << endl;


		cin >> a;


		switch (a)
		{
		case 1:
		{
			cout << "Введите данные: " << endl;
			mc.setData();
			que.add(mc);
			cout << "DONE" << endl;
			break;
		}
		case 2:
		{
			int b;
			cout << "Введите количество элементов для добавления: "; cin >> b;
			for (int i = 0; i < b; i++)
			{
				cout << "Введите данные: " << endl;
				mc.setData();
				que.add(mc);
				cout << "DONE" << endl;
			}
			break;
		}
		case 3:
		{
			que.del();
			cout << "DONE" << endl;
			break;
		}
		case 4:
		{
			int b, c;
			do
			{
				cout << "Введите количество элементов для удаления: "; cin >> c;

			} while (c > que.GetSize());
			for (int i = 0; i < c; i++)
			{
				que.del();
				cout << "DONE" << endl;
			}
			break;
		}
		case 5:
		{
			que.clear();
			break;
		}
		case 6:
		{
			cout << que.getDataStart() << endl;
			system("pause");
			break;
		}
		case 7:
		{
			cout << que.getDataEnd() << endl;
			system("pause");
			break;
		}
		case 8:
		{
			if (path == "")
			{
				cout << "Введите название файла для записи: ";
				cin >> path;
				path = path + ".txt";
			}
			que.writeFile(path);
			cout << "DONE" << endl;
			break;
		}
		case 9:
		{
			if (path == "")
			{
				cout << "Введите название файла для записи: ";
				cin >> path;
				path = path + ".txt";
			}
			que.readFile(path);
			cout << "DONE" << endl;
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




	return 0;
}

/*
Очередь как динамическая структура данных

При взаимодействии с очередья мы можем взаимодействовать толко с 1 и последним элементами, остальные нам не доступны.

Не можем:
* Перебрать все элементы очереди
* Не можем вставить или убрать элемент из середины очереди
* Не можем добавить элемент в начало очереди, только в конец можно
* Нельзя удалить элемент из конца очереди
 
Можем:
* Посмотреть что находится в начале очереди и в конце очереди
* Добавить элемент в начало очереди.
* Можно удалить/извлечь элемент из начала очереди


*/


template<typename T>
Queue<T>::Queue()		//конструктор, который создает пустую очередь
{
	head = tail = nullptr;
	size = 0;
}

template<typename T>
Queue<T>::~Queue()		//деструктор, при выходе из области видимости уничтожает все объекты списка
{
	clear();
}

template<typename T>
void Queue<T>::add(T data)		//добавление элемента
{
	if (head == nullptr)		//исключения
	{
		head = new Node<T>(data);	//создание объекта
		tail = head;
	}
	else
	{
		Node<T>* current = new Node<T>(data, nullptr, tail);	//создание объекта с указанием предыдущего элемента
		tail->pNext = current;	//смена указателей
		tail = current;			//смена хвоста
	}
	size++;
}

template<typename T>
void Queue<T>::del()
{
	Node<T>* toDelete = head;	//установка указателя на голову
	if (size == 1)				//проверка исключения
	{
		head = head->pNext;		//смена указателей
		tail = tail->pPrev;
		delete toDelete;
	}
	else
	{
		head = head->pNext;		//смена указателей
		head->pPrev = nullptr;
		delete toDelete;
	}
	size--;
}

template<typename T>
void Queue<T>::clear()			//полное очищение очереди
{
	while (size)				//пока длина !=0
	{
		del();					//удаляем элемент
	}
}

template<typename T>
void Queue<T>::writeFile(string path)	//запись в файл
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
void Queue<T>::readFile(string path)		//чтение из файла
{
	T buf;
	fstream fs;
	fs.open(path, fstream::in | fstream::app);
	int length;
	fs >> length;						//чтение длины (сколько данных в файле)
	for (int i = 0; i < length; i++)
	{
		fs >> buf;
		add(buf);				//полученные данные добавляем в конец списка
	}
	fs.close();
}
