#pragma once
#include"header.h"

//единственное нормальное задание во всей лабе

void plus_mid(list<Pair>& lst)		//добавление среднее в конец
{
	Pair midl(0,0);
	for_each(lst.begin(), lst.end(), [&midl](Pair this_el)	//перебираем весь список с помощью функции
		{midl = midl + this_el;});			//это анонимная функция, которая все складывает в переменую midl, которую перетаскивает по ссылке из тела функции
	lst.push_back(midl / lst.size());		//просто пушим назаж
}

void searchAndDel(list<Pair>& lst)			//ищем и удаляем
{
	Pair y;
	cout << "Введите данные для удаления: "; cin >> y;
	int min, max;
	cout << "Введите диапазон для поиска:\n" << "min: "; cin >> min;
	cout << "max: "; cin >> max;					//можно задать диапазон, работает с индексами
	auto left = lst.begin(); auto right = lst.begin();
	advance(left, min);			//смещаем итераторы, чтобы установит диапазон 
	advance(right, max);
	lst.erase(remove_if(left, right, [&y](Pair& x)	//удалем если введенное число совпадает с тем, на которое мы указываем
		{return x == y;}));		//анонимная функция
}

void plusMinMax(list<Pair>& lst)		//добавление к каждому элементу мин и макс значения
{
	Pair min = *min_element(lst.begin(), lst.end());		//находим мин и макс 
	Pair max = *max_element(lst.begin(), lst.end());
	cout << "min: " << min << endl << "max: " << max << endl;
	for_each(lst.begin(), lst.end(),		//проходим по всему списку
		[&min, &max](Pair& this_el) {this_el = this_el + max + min; });		//лямбда-выражение - которое добавляет к каждому элементу мин и макс
}

void number1()			//функция для управления, здест ничего особенного, только в конце коммы
{
	Pair p;
	list<Pair> lst;
	int n;
	cout << "Введите какое количество записей сгенерировать: "; cin >> n;
	for (int i = 0; i < n; i++)
		lst.push_back(p.randomGener());
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Найдем среднее арифмитическое значение и добавим его в контейнер." << endl;
	plus_mid(lst);
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Зададим диапазон и удалим данные из контейнера в данном диапазоне." << endl;
	searchAndDel(lst);
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "К каждому элементу контейнера добавим max и min элемент контейнера." << endl;
	plusMinMax(lst);
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Найдем в данном контейнере елемент и его индекс." << endl;
	cout << "Введите элемент для поиска: "; cin >> p;
	auto it = find(lst.begin(), lst.end(), p);
	if (it != lst.end())
		cout << "Номер элемента: " << distance(lst.begin(), it) + 1 << "\tЭлемент: " << p;
	else
		cout << "Элемент не найден." << endl;
	cout << endl << "Отсортируем контейнер по возрастанию." << endl;
	lst.sort();								//sort не работает бля списка, но есть встроенный метод
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Отсортируем контейнер по убыванию." << endl;
	lst.sort(greater<Pair>());				//здесь мы меняем порядок сортировки на обратный с помощью объекта, который инвертирует
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
}


