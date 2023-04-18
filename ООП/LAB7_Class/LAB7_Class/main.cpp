#include <iostream>
#include <Windows.h>
#include <fstream>
#include "List.h"
#include "Pair.h"
using namespace std;

int main()
{
	system("chcp 1251 >> null");
	//system("color F0");
	List<Pair>lst;
	Pair p;
	cout << "Добавление элементов." << endl;
	lst.push_back(p.randomGener());
	lst.push_front(p.randomGener());
	lst.push_back(p.randomGener());
	lst.push_back(p.randomGener());
	lst.push_back(p.randomGener());
	lst.push_back(p.randomGener());
	lst.push_back(p.randomGener());
	cout << "Вывод с помощью оператора []:" << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << "Создание итератора и удаление элемента из списка с помощью него" << endl;
	auto i = lst.begin();
	i + 3;
	lst.removeAt(i);
	cout << "Вывод с помощью итератора и цикла for" << endl;
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Добавление элемента в список с помощью итератора" << endl;
	lst.insert(p.randomGener(), i);
	cout << "Вывод с помощью цикла for each\n";
	for (auto& it : lst)
	{
		cout << it << endl;
	}
	List<Pair> list2;
	list2 = lst;
	list2.pop_front();
	list2.pop_back();
	list2.pop_front();
	cout << endl << "Новый список:" << endl;
	for (auto& it : list2)
	{
		cout << it << endl;
	}
	cout << endl << "Старый список:" << endl;

	for (auto& it : lst)
	{
		cout << it << endl;
	}
	cout << "\n<новый список> * <старый список>" << endl;
	list2 = (list2 * lst);
	for (auto& it : list2)
	{
		cout << it << endl;
	}
	return 0;
}