#pragma once
#include <string>

void make_file(std::string path)		//������� � ��������� ���� ���������� �����������
{
	Pair pr;
	int n;
	fstream fs(path, fstream::out);		//��������� � ��������� �����
	if (!fs.is_open()) exit(-1);		//���� �� ������ �������
	cout << "������� ���������� ������� ��� ���������: "; cin >> n;
	fs << n << "\n";
	for (int i = 0; i < n; i++)			//��������� �������
		fs << pr.randomGener() << "\n";
	fs.close();
}

void print_file(std::string path)		//����������� ���������� ����� � �������
{
	Pair pr;
	int size;
	fstream fs(path, fstream::in | fstream::app);
	fs >> size;		
	cout << endl << "SIZE: " << size << endl << endl;
	for (int i = 0; i < size; i++)		//������ ���� ���� � ��������
	{
		fs >> pr;
		cout << i + 1<< ". " << pr << endl;
	}
	fs.close();
}

void del_elem(std::string path)			//�������� ��������� ������ ��������� �� �����
{
	Pair pr;			//���������� 
	Pair pr_min;
	cout << "������� Pair, ������ ��������, ���������� ������� ������ (int : double): "; cin >> pr_min;
	int size;
	int size_temp = 0;
	fstream fs(path, fstream::in | fstream::app);	//������
	fstream fs1("temp.txt", fstream::out);
	fs >> size;
	for (int i = 0; i < size; i++)		//�������������� �� ������ ���� � �� ��������� ��� ��� �������� �� � �������
	{
		fs >> pr;				
		if (!(pr < pr_min))
		{
			fs1 << pr << "\n";
			++size_temp;				//��������� ����� ������ �����
		}
	}
	fs.close(); fs1.close();
	fs.open(path, fstream::out);		//������������� ������
	fs1.open("temp.txt", fstream::in | fstream::app);
	fs << size_temp << "\n";			//��������� ��� �� ���������� �����, �������, ��� ����, ����� ����������� ����������
	for (int i = 0; i < size_temp; i++)
	{
		fs1 >> pr;
		fs << pr << "\n";
	}
	fs.close(); fs1.close();	
	remove("temp.txt");			//�������� ���������� �����
}

void plus_elem(std::string path)		//���������� � �������� � �������� ���������
{
	Pair pr;
	Pair pr_plus, pr_key;
	cout << "������� ���� ��� ������ ��������: "; cin >> pr_key;		//������ �������
	cout << "������� Pair, ��� ���������� � �������� "; cin >> pr_plus;	//����������� ��������
	int size;
	fstream fs(path, fstream::in | fstream::app);
	fstream fs1("temp.txt", fstream::out);
	fs >> size;
	fs1 << size << "\n";
	for (int i = 0; i < size; i++)		//�������� �� ����� ����� � ������� ��������� ��������
	{
		fs >> pr;
		if (pr == pr_key)
		{
			pr = pr + pr_plus;
		}
		fs1 << pr << "\n";
	}
	fs.close(); fs1.close();

	char* temp = new char[path.size() + 1];		//�������� ������� ��� ����, ����� �� �������������� ����
	for (int i = 0; i < path.size(); i++)		//���������� ��� �������� ������� ����� � �������������� ������
		temp[i] = path[i];
	temp[path.size()] = '\0';

	remove(temp);					//�������� �����
	rename("temp.txt", temp);		//�������������� ����������
}

void add_node(std::string path)		//���������� ������ ��������� ����� �������� � �������� ��������
{
	int k, amount, size, j = 0;
	cout << "����� ������ �������� �������� ������: "; cin >> k;		//������ �����
	cout << "���������� �������: "; cin >> amount;				//������ ���������� ����� ���������
	Pair pr;
	fstream fs(path, fstream::in | fstream::app);
	fstream fs1("temp.txt", fstream::out);
	fs >> size;
	size += amount;			//������� ����� �����
	fs1 << size;
	for (int i = 0; i < size; i++)		//����������� �� ������ ����� ����������� �������� ����� ������
	{
		if (i >= k && j < amount)		//�������, ����� ���������� ��������� ����� ������.
		{
			fs1 << pr.randomGener() << "\n"; ++j;
		}
		else							//������� �������������� ����� �� ������ � ������
		{
			fs >> pr;
			fs1 << pr << "\n";
		}
	}
	fs.close(); fs1.close();

	char* temp = new char[path.size() + 1];		//�������� ������� ��� ����, ����� �� �������������� ����
	for (int i = 0; i < path.size(); i++)		//���������� ��� �������� ������� ����� � �������������� ������
		temp[i] = path[i];
	temp[path.size()] = '\0';

	remove(temp);		//�������� ������� �����
	rename("temp.txt", temp);		//������������� ������ �����
}