#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;


class MyClass
{
public:
	void setData()
	{
		cin >> str;
	}
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
	in >> cl.str;				//что и куда читать из потока
	return in;
}

template <typename T>
class List
{
private:
	//template<typename T>	//минимальная ячейка памяти
	class Node				//вложенный класс - ячейка памяти
	{
	public:
		Node(T data = T(), Node * pNext = nullptr)		//используется параметр по умолчанию, то есть если мы не передаем указатель, то он автоматически присваивается nullptr
		{									//для поля data также используется параметр по умолчанию, выглядит он как вызов конструктора по умолчанию
			this->data = data;
			this->pNext = pNext;
		}
		Node* pNext;		//хранит указатель на следующий элемент
		T data;				//хранит наши данные
		
	};

	Node *head;			//указатель на первый элемент в списке
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
	//Node*& searchPriveousIndex(const int index); //поиск предыдущего элемента для реализации методов insert и removeAt
	//void insertFewElem( int index)

};


template<typename T>
void List<T>::writeFile(string path)	//запись в файл
{
	fstream fs;					
	fs.open(path, fstream::out);
	Node* temp = head;
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

//template<typename T>
//List<T>::Node*& List<T>::searchPriveousIndex(const int index)
//{
//
//
//}

















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
Односвязный/однонаправленный список:

Предназначен для удобства хранения и манипулирования данными.
Односвязный список - совокупность элементов, в котором каждый элемент знает адрес следующего элемента.
Односввязный список - динамическая структура данных, у которой есть 2 основные характеристики:
* Быстрая работа с изменением количества элементов в этой структуре.
* Меделенная работа при доступе к данным (если сравнивать его с массивом)
*/

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
	while(size)
	{
		temp = head;
		head = head->pNext;
		delete temp;
		size--;
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
	Node *current = this->head;	//указатель, для того, чтобы итерироваться по нашему списку
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
void List<T>::pop_front()			//удаление из начала
{
	Node *temp = head;			//делай временный указатель на объект head
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
		Node* previous = this-> head;	//создаем указатель на головной элемент для поиска нужного элемента
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