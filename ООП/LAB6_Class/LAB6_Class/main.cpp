#include <iostream>
#include <Windows.h>
#include <fstream>
#include "List.h"
using namespace std;




int main()
{
	system("chcp 1251 >> null");
	//system("color F0");
	List lst;
	
	cout << "Добавление элементов." << endl;
	lst.push_back(22);
	lst.push_front(11);
	lst.push_back(33);
	lst.push_back(44);
	lst.push_back(55);
	lst.push_back(66);
	lst.push_back(77);
	cout << "Вывод с помощью оператора []:" << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << "Создание итератора и удаление элемента из списка с помощью него" << endl;
	auto i = lst.begin();
	i + 6;
	lst.removeAt(i);
	cout << "Вывод с помощью итератора и цикла for" << endl;
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Добавление элемента в список с помощью итератора" << endl;
	lst.insert(99, i);
	cout << "Вывод с помощью цикла for each\n";
	for (auto& it : lst)
	{
		cout << it << endl;
	}
	List list2;
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




