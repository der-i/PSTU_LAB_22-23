#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;


class MyClass
{
private:
	string str;
	friend ostream& operator << (std::ostream& os, const MyClass& cl);
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
	void setData()
	{
		cin >> str;
	}
	string getData() { return str; }
};

MyClass& MyClass::operator=(const MyClass& other)
{
	this->str = other.str;
	return *this;
}

ostream& operator << (std::ostream& os, const MyClass& cl)			//перегруженный оператор вывода для моего класса
{
	return os << cl.str;		//запись данных в поток
}

istream& operator >> (std::istream& in, MyClass& cl)			//перегруженный оператор ввода для моего класса
{
	in >> cl.str;				//что и куда читать из потока
	return in;
}


template <typename T>
class Stek
{
private:
	template<typename T>	//минимальная ячейка памяти
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

	Node<T>* head;			//указатель на заглавный элемент в стеке
	int size;				//количество элементов в стеке.
public:
	Stek();								//Конструктор
	~Stek();							//Деструктор
	int GetSize() { return size; }		//так как инкапсуляция не дает нам доступ к количеству элементов в списке, то нам необходимо прописать геттер
	T del();							//удаляет элемент из стека
	T getData() { return head->data; }
	void clear();						//удаляет все элементы их стека 
	void add(T data);			//добавляет элемент в стек
	void writeFile(string path);		//запись в файл
	void readFile(string path);			//чтение из файла

};






int main()
{
	setlocale(LC_ALL, "ru");
	system("color F0");
	SetConsoleCP(1251);
	int a = 2;
	MyClass mc;
	Stek<MyClass> stk;
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
			<< "6. Вывести в консоль." << endl
			<< "7. Записать в файл." << endl
			<< "8. Считать из файла." << endl
			<< "0. Выход." << endl << endl;


		cin >> a;


		switch (a)
		{
		case 1:
		{
			cout << "Введите данные: " << endl;
			mc.setData();
			stk.add(mc);
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
				stk.add(mc);
				cout << "DONE" << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Удаленный элемент: " << stk.del() << endl;
			
			cout << "DONE" << endl;
			break;
		}
		case 4:
		{
			int c;
			do
			{
				cout << "Введите количество элементов для удаления: "; cin >> c;

			} while (c > stk.GetSize());
			for (int i = 0; i < c; i++)
			{
				cout << "Удаленный элемент" << stk.del();
				cout << "DONE" << endl;
			}
			break;
		}
		case 5:
		{
			stk.clear();
			break;
		}
		case 6:
		{
			cout << stk.getData() << endl;
			system("pause");
			break;
		}
		case 7:
		{
			if (path == "")
			{
				cout << "Введите название файла для записи: ";
				cin >> path;
				path = path + ".txt";
			}
			stk.writeFile(path);
			cout << "DONE" << endl;
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
			stk.readFile(path);
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
}







/*
СТЕК
Динамическая структура данных, работающая по принципу последний вошел, первый вышел. (LIFO).
Представить можно в виде стопки тарелок.

По сути стек - урезанная версия односвзного списка (подходит под метод - LIFO), нам необходимо оставить только операции, которые подходят под это.
* Удаление первого элемента, при удалении (извлечении из стека, нам необходимо получать данные, которые там хранились)
* Добавление первого элемента
* Метод просмотра элемента из вершины стека
* 




*/

template <typename T>
Stek<T>::Stek()				//мы создаем пустой стек, а следствено, в нем лежит 0 элементов, а следственно указывать некуда.
{
	size = 0;
	head = nullptr;
}

template <typename T>
Stek<T>::~Stek()			//деструктор освобождает динамическую память по приципу метода clear,
{							//мы можем делегировать ему эти обязаности
	clear();
}

template<typename T>
void Stek<T>::add(T data)
{
	head = new Node<T>(data, head);	//вместо головного элемента создаем новый элемент, указатель в котором будет на старый головной элемент
	size++;							//увеличиваем длину на 1
}

template<typename T>
T Stek<T>::del()			//удаление из начала
{
	Node<T>* temp = head;			//делай временный указатель на объект head
	head = head->pNext;				//Указательь head переносим на следующую ячейку
	T ret = temp->data;
	delete temp;					//удаляем первый объект
	size--;							//уменьшаем длину на 1
	return ret;
}

template<typename T>
void Stek<T>::clear()
{
	while (size)
	{						//вызываем pop_front столько раз, пока size != 0
		del();				//логика основывается на pop_front поэтому мы делегируем ей эти обязанности
	}
}

template<typename T>
void Stek<T>::writeFile(string path)	//запись в файл
{
	fstream fs;
	fs.open(path, fstream::out);
	Node<T>* temp = head;
	fs << GetSize() << "\n";			//запись в файл размера списка
	for (int i = 0; i < GetSize(); i++)	//запись данных в файл
	{
		fs << temp->data << " ";
		temp = temp->pNext;
		fs.ate;
	}
	fs.close();
}

template<typename T>
void Stek<T>::readFile(string path)		//чтение из файла
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