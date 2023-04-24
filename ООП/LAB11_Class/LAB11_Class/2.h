#pragma once
#include "Header.h"

void number_2()
{
	list<Pair> lst;
	Pair temp;
	int size;
	cout << "Введите количество элементов в списке: "; cin >> size;
	for (int i = 0; i < size; i++)
		lst.push_back(temp.randomGener());
	cout << "Полученный список:" << endl;
	Show(lst);
	cout << "Добавим среднее арифмитическое значение списка в конец файла:" << endl;
	lst.push_back(SearchMidVal(lst));
	cout << "Полученный список:" << endl;
	Show(lst);
	cout << "Удалим элемент по значению в заданном диапазоне." << endl;
	DelElem(lst);
	cout << "Полученный список:" << endl;
	Show(lst);
	cout << "Добавим сумму min и max элементов к каждому элементу." << endl;
	plusMinMax(lst);
	cout << "Полученный список:" << endl;
	Show(lst);
	return;
}



