#include "Pair.h"
#include "file_work.h"



int main()
{
	system("chcp 1251 >> null");
	int menu;
	bool f = true;
	system("chcp 1251 >> null");
	string path;
	cout << "������� ��� ����� ��� ������ � ���: "; cin >> path;
	if (path[path.size() - 4] != '.')			//������, ����� � ����� ������ ���� ���������� txt
		path += ".txt";							//��� ����, ����� ������ ����� �������
	do
	{
		cout << "-------------����-------------" << endl << endl
			<< "1. ������� ���� � �������� ������." << endl
			<< "2. ������� ���� � �������." << endl
			<< "3. ������ �������� � ������� ��� ������ � ������� ���������." << endl
			<< "4. ����� ������ �� �������� � ��������� �� �� N." << endl
			<< "5. �������� � ������� � ����� �����." << endl 
			<< "6. �������� ��� �����." << endl
			<< "0. �����." << endl << "> ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "\033[2J\033[1;1H";
			make_file(path);
			cout << "\033[2J\033[1;1H";
			cout << "������." << endl << endl;
			break;
		}
		case 2:
		{
			cout << "\033[2J\033[1;1H";
			print_file(path);
			cout << "������." << endl << endl;
			break;
		}
		case 3:
		{
			cout << "\033[2J\033[1;1H";
			del_elem(path);
			cout << "\033[2J\033[1;1H";
			cout << "������." << endl << endl;
			break;
		}
		case 4:
		{
			cout << "\033[2J\033[1;1H";
			plus_elem(path);
			cout << "\033[2J\033[1;1H";
			cout << "������." << endl << endl;
			break;
		}
		case 5:
		{
			cout << "\033[2J\033[1;1H";
			add_node(path);
			cout << "\033[2J\033[1;1H";
			cout << "������." << endl << endl;
			break;
		}
		case 6:
		{
			cout << "\033[2J\033[1;1H";
			cout << "������� ��� ����� ��� ������ � ���: "; cin >> path;
			if (path[path.size() - 4] != '.')
				path += ".txt";
			cout << "\033[2J\033[1;1H";
			cout << "������." << endl << endl;
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
			cout << "������ ������� ���. ���������� �����." << endl;
			break;
		}
		}
	} while (f);
	return 0;
}