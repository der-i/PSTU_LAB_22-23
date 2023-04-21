
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

	cout << "Вывод с помощью оператора []:" << endl;

	try					//блок попытки
	{
		for (int i = 0; i < lst.GetSize() + 2; i++)
		{
			cout << lst[i] << endl;
		}
	}
	catch (const std::exception& ex)	//если выброшено исключение, то отрабатывает этот блок
	{
		cout << endl<< "---------" << endl << ex.what() << endl << "---------" << endl << endl;
	}
	
	cout << "Создание итератора и удаление элемента из списка с помощью него" << endl;

	try					//блок попытки
	{
		List::iterator i;
		lst.removeAt(i);
	}
	catch (const std::exception& ex)	//если выброшено исключение, то отрабатывает этот блок
	{
		cout<< endl << "---------" << endl << ex.what() << endl << "---------" << endl ;
	}
	List::iterator i = lst.begin(); i++;
	lst.removeAt(i);
	
	try					//блок попытки
	{
		i++; i++;
	}
	catch (const std::exception& ex)	//если выброшено исключение, то отрабатывает этот блок
	{
		cout << endl << "---------" << endl << ex.what() << endl << "---------" << endl << endl;
		i.reset();
	}


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
	try					//блок попытки
	{
		list2 = (list2 * lst);
	}
	catch (const std::exception& ex)	//если выброшено исключение, то отрабатывает этот блок
	{
		cout << "---------" << endl << ex.what() << endl << "---------" << endl;
		list2 = lst;
	}
	return 0;
}




