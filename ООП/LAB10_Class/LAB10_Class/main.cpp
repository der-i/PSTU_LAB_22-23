#include "Pair.h"
#include "file_work.h"



int main()
{
	system("chcp 1251 >> null");
	int menu;
	bool f = true;
	system("chcp 1251 >> null");
	string path;
	cout << "Введите имя файла для работы с ним: "; cin >> path;
	if (path[path.size() - 4] != '.')			//логика, чтобы у файла всегда было расширение txt
		path += ".txt";							//для того, чтобы читать через блокнот
	do
	{
		cout << "-------------МЕНЮ-------------" << endl << endl
			<< "1. Создать файл с заданным именем." << endl
			<< "2. Вывести файл в консоль." << endl
			<< "3. Задать значение и удалить все записи с меньшим значением." << endl
			<< "4. Найти запись по значению и увеличить ее на N." << endl
			<< "5. Добавить К записей в любое место." << endl 
			<< "6. Изменить имя файла." << endl
			<< "0. Выход." << endl << "> ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "\033[2J\033[1;1H";
			make_file(path);
			cout << "\033[2J\033[1;1H";
			cout << "Готово." << endl << endl;
			break;
		}
		case 2:
		{
			cout << "\033[2J\033[1;1H";
			print_file(path);
			cout << "Готово." << endl << endl;
			break;
		}
		case 3:
		{
			cout << "\033[2J\033[1;1H";
			del_elem(path);
			cout << "\033[2J\033[1;1H";
			cout << "Готово." << endl << endl;
			break;
		}
		case 4:
		{
			cout << "\033[2J\033[1;1H";
			plus_elem(path);
			cout << "\033[2J\033[1;1H";
			cout << "Готово." << endl << endl;
			break;
		}
		case 5:
		{
			cout << "\033[2J\033[1;1H";
			add_node(path);
			cout << "\033[2J\033[1;1H";
			cout << "Готово." << endl << endl;
			break;
		}
		case 6:
		{
			cout << "\033[2J\033[1;1H";
			cout << "Введите имя файла для работы с ним: "; cin >> path;
			if (path[path.size() - 4] != '.')
				path += ".txt";
			cout << "\033[2J\033[1;1H";
			cout << "Готово." << endl << endl;
			break;
		}
		case 0:
		{
			cout << "\033[2J\033[1;1H";
			f = false;
			break;
		}
		default:
		{
			cout << "\033[2J\033[1;1H";
			cout << "Данной команды нет. Попробуйте снова." << endl;
			break;
		}
		}
	} while (f);
	return 0;
}