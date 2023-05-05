#pragma once
#include"header.h"

//������������ ���������� ������� �� ���� ����

void plus_mid(list<Pair>& lst)		//���������� ������� � �����
{
	Pair midl(0,0);
	for_each(lst.begin(), lst.end(), [&midl](Pair this_el)	//���������� ���� ������ � ������� �������
		{midl = midl + this_el;});			//��� ��������� �������, ������� ��� ���������� � ��������� midl, ������� ������������� �� ������ �� ���� �������
	lst.push_back(midl / lst.size());		//������ ����� �����
}

void searchAndDel(list<Pair>& lst)			//���� � �������
{
	Pair y;
	cout << "������� ������ ��� ��������: "; cin >> y;
	int min, max;
	cout << "������� �������� ��� ������:\n" << "min: "; cin >> min;
	cout << "max: "; cin >> max;					//����� ������ ��������, �������� � ���������
	auto left = lst.begin(); auto right = lst.begin();
	advance(left, min);			//������� ���������, ����� ��������� �������� 
	advance(right, max);
	lst.erase(remove_if(left, right, [&y](Pair& x)	//������ ���� ��������� ����� ��������� � ���, �� ������� �� ���������
		{return x == y;}));		//��������� �������
}

void plusMinMax(list<Pair>& lst)		//���������� � ������� �������� ��� � ���� ��������
{
	Pair min = *min_element(lst.begin(), lst.end());		//������� ��� � ���� 
	Pair max = *max_element(lst.begin(), lst.end());
	cout << "min: " << min << endl << "max: " << max << endl;
	for_each(lst.begin(), lst.end(),		//�������� �� ����� ������
		[&min, &max](Pair& this_el) {this_el = this_el + max + min; });		//������-��������� - ������� ��������� � ������� �������� ��� � ����
}

void number1()			//������� ��� ����������, ����� ������ ����������, ������ � ����� �����
{
	Pair p;
	list<Pair> lst;
	int n;
	cout << "������� ����� ���������� ������� �������������: "; cin >> n;
	for (int i = 0; i < n; i++)
		lst.push_back(p.randomGener());
	cout << endl << "���������� list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "������ ������� �������������� �������� � ������� ��� � ���������." << endl;
	plus_mid(lst);
	cout << endl << "���������� list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "������� �������� � ������ ������ �� ���������� � ������ ���������." << endl;
	searchAndDel(lst);
	cout << endl << "���������� list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "� ������� �������� ���������� ������� max � min ������� ����������." << endl;
	plusMinMax(lst);
	cout << endl << "���������� list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "������ � ������ ���������� ������� � ��� ������." << endl;
	cout << "������� ������� ��� ������: "; cin >> p;
	auto it = find(lst.begin(), lst.end(), p);
	if (it != lst.end())
		cout << "����� ��������: " << distance(lst.begin(), it) + 1 << "\t�������: " << p;
	else
		cout << "������� �� ������." << endl;
	cout << endl << "����������� ��������� �� �����������." << endl;
	lst.sort();								//sort �� �������� ��� ������, �� ���� ���������� �����
	cout << endl << "���������� list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "����������� ��������� �� ��������." << endl;
	lst.sort(greater<Pair>());				//����� �� ������ ������� ���������� �� �������� � ������� �������, ������� �����������
	cout << endl << "���������� list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
}


