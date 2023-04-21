#pragma once
#include <string>

void make_file(std::string path)		//создает и заполняет файл рандомными значчениями
{
	Pair pr;
	int n;
	fstream fs(path, fstream::out);		//созждание и открыытие файла
	if (!fs.is_open()) exit(-1);		//если не смогли создать
	cout << "Введите количество записей для генерации: "; cin >> n;
	fs << n << "\n";
	for (int i = 0; i < n; i++)			//генерация записей
		fs << pr.randomGener() << "\n";
	fs.close();
}

void print_file(std::string path)		//распечатать содержимое файла в консоль
{
	Pair pr;
	int size;
	fstream fs(path, fstream::in | fstream::app);
	fs >> size;		
	cout << endl << "SIZE: " << size << endl << endl;
	for (int i = 0; i < size; i++)		//читаем весь файл и печатаем
	{
		fs >> pr;
		cout << i + 1<< ". " << pr << endl;
	}
	fs.close();
}

void del_elem(std::string path)			//удаление элементов ментше заданного из файла
{
	Pair pr;			//переменные 
	Pair pr_min;
	cout << "Введите Pair, меньше которого, необходимо удалить данные (int : double): "; cin >> pr_min;
	int size;
	int size_temp = 0;
	fstream fs(path, fstream::in | fstream::app);	//потоки
	fstream fs1("temp.txt", fstream::out);
	fs >> size;
	for (int i = 0; i < size; i++)		//перезаписываем из одного файл а во временный все что подходит по д условие
	{
		fs >> pr;				
		if (!(pr < pr_min))
		{
			fs1 << pr << "\n";
			++size_temp;				//изменеяем длину нового файла
		}
	}
	fs.close(); fs1.close();
	fs.open(path, fstream::out);		//переоткрываем потоки
	fs1.open("temp.txt", fstream::in | fstream::app);
	fs << size_temp << "\n";			//переносим все из временного файла, обратно, для того, чтобы сохранялось оформление
	for (int i = 0; i < size_temp; i++)
	{
		fs1 >> pr;
		fs << pr << "\n";
	}
	fs.close(); fs1.close();	
	remove("temp.txt");			//удаление временного файла
}

void plus_elem(std::string path)		//добавление к элементу с заданным значением
{
	Pair pr;
	Pair pr_plus, pr_key;
	cout << "Введите ключ для поиска элемента: "; cin >> pr_key;		//задаем элемент
	cout << "Введите Pair, для добавление к элементу "; cin >> pr_plus;	//добавляемое значение
	int size;
	fstream fs(path, fstream::in | fstream::app);
	fstream fs1("temp.txt", fstream::out);
	fs >> size;
	fs1 << size << "\n";
	for (int i = 0; i < size; i++)		//проходим по всему файлу в поисках заданного значение
	{
		fs >> pr;
		if (pr == pr_key)
		{
			pr = pr + pr_plus;
		}
		fs1 << pr << "\n";
	}
	fs.close(); fs1.close();

	char* temp = new char[path.size() + 1];		//создание массива для того, чтобы не перезаписывать файл
	for (int i = 0; i < path.size(); i++)		//необходимо для удаления старого файла и переименования нового
		temp[i] = path[i];
	temp[path.size()] = '\0';

	remove(temp);					//удаление файла
	rename("temp.txt", temp);		//переименование временного
}

void add_node(std::string path)		//добавление группы элементов после элемента с задданым номерром
{
	int k, amount, size, j = 0;
	cout << "После какого элемента добавить запись: "; cin >> k;		//задаем номер
	cout << "Количество записей: "; cin >> amount;				//задаем количество новых элементов
	Pair pr;
	fstream fs(path, fstream::in | fstream::app);
	fstream fs1("temp.txt", fstream::out);
	fs >> size;
	size += amount;			//создаем новую длину
	fs1 << size;
	for (int i = 0; i < size; i++)		//пробегаемся по нашему файлу паралелльно вставляя новые данные
	{
		if (i >= k && j < amount)		//условие, когда необходимо вставлять новые данные.
		{
			fs1 << pr.randomGener() << "\n"; ++j;
		}
		else							//простое переписсывание файла из одного в другой
		{
			fs >> pr;
			fs1 << pr << "\n";
		}
	}
	fs.close(); fs1.close();

	char* temp = new char[path.size() + 1];		//создание массива для того, чтобы не перезаписывать файл
	for (int i = 0; i < path.size(); i++)		//необходимо для удаления старого файла и переименования нового
		temp[i] = path[i];
	temp[path.size()] = '\0';

	remove(temp);		//удаление старого файла
	rename("temp.txt", temp);		//переиенование нового файла
}