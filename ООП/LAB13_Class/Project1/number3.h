#pragma once
#include"header.h"

static int shet = 0;		//��������� ������

void print(map<int, Pair>& mp)		//������� ������ �������
{
	cout << endl << "���������� map:" << endl;
	for (auto& i : mp)
		cout << i.first << ". " << i.second << endl;
}

void plus_mid(map<int, Pair>& mp)	//������� ��������� ������� ��������������
{
	Pair midl(0, 0);				//��!!!
	for (auto& i : mp)				//��� ��� � ����������� map �� �������� ���������� algorithm, ������ ����������� �������
		midl = midl + i.second;		//��� �� ��� ������ ������� ����� ������� �����
	mp.emplace(++shet, midl / mp.size());	//��������� ��� � ������ 3 �����
}

void searchAndDel(map<int, Pair>& mp)		//�������� �� �����
{											//������ �����������, ������ ����� ������
	int y;
	cout << "������� ���� ��� �������� (int): "; cin >> y;
	mp.erase(y);
}

void plusMinMax(map<int, Pair>& mp)			//���������� � ������� �������� ������������ � ������������� ��������
{
	Pair min = min_element(mp.begin(), mp.end())->second;		//������� ����������� � ������������ �������
	Pair max = max_element(mp.begin(), mp.end())->second;		//��������� ������� ���������� algorithm
	cout << "min: " << min << endl << "max: " << max << endl;	//� ������ ������ ������ �������� � ���������
	for (auto& i : mp)
		i.second = i.second + max + min;			//��������� �����, ������ ��� += � pair �� ����������
}

void myfind(map<int, Pair>& mp)			//��� �����. ������ ����� �� ����� ����� ����� ���������� map 
{
	int a;
	cout << "������� ���� ��� ������: "; cin >> a;
	auto it = mp.find(a);
	if (it != mp.end())
		cout << "����: " << a << "   ��������:" << it->second << endl;
	else cout << "�������� � ����� ������ ��� � �������." << endl;
}

void printsortup(map<int, Pair>& mp)		//����� ����������, �� �� ���.
{											//map - �������� ������ � ����� ��� �������������, ������� �� ������ ������� ������ pair � ������� ��� ���������
	int a = 0;
	map<Pair, int> temp;
	for (auto i = mp.begin(); i != mp.end(); ++i)
		temp.emplace(i->second, i->first);
	for (auto& i : temp)
		cout << ++a <<".\t" << i.first << "  \t����: " << i.second << endl;
}

void printsortdown(map<int, Pair>& mp)		//����� ���� ����� ��� � ������, ������ ������� ��������� ��������
{
	int a = 0;
	map<Pair, int> temp;	
	for (auto i = mp.begin(); i != mp.end(); ++i)
		temp.emplace(i->second, i->first);
	for (auto i = temp.crbegin(); i != temp.crend(); i++)
		cout << ++a << ".\t" << i->first << "  \t����: " << i->second << endl;

	

}

void number3()		//�������, ������� ��������� ����
{					//�������� ������� ���� � ����� ���������.
	Pair p;			//����� �� ������� � main
	map<int, Pair> mp;
	int n;
	cout << "������� ����� ���������� ������� �������������: "; cin >> n;
	for (int i = 0; i < n; i++)
		mp.emplace(++shet, p.randomGener());
	cout << "��� ������:\n����. ��������" << endl;
	print(mp);
	cout << endl << "������ ������� �������������� �������� � ������� ��� � ���������." << endl;
	plus_mid(mp);
	print(mp);
	cout << endl << "������� �������� � ������ ������ �� ���������� � ������ ���������." << endl;
	searchAndDel(mp);
	print(mp);
	cout << endl << "� ������� �������� ���������� ������� max � min ������� ����������." << endl;
	plusMinMax(mp);
	print(mp);
	cout << endl << "������ � ������ ���������� ������� �� ��� �����." << endl;
	myfind(mp);
	cout << endl << "����������� ��������� �� ����������� ��������." << endl;
	printsortup(mp);
	cout << endl << "����������� ��������� �� �������� ��������." << endl;
	printsortdown(mp);
}