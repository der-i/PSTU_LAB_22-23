#pragma once
#include"header.h"

//тут все коментарии аналогичны файлу number2.h

void plus_mid(multiset<double>& mlst)
{
	double midl = 0;
	for (auto& i : mlst)
		midl += i;
	mlst.insert(midl / mlst.size());
}

void searchAndDel(multiset<double>& mlst)
{
	double min, max;
	cout << "Введите диапазон для поиска:\n" << "min: "; cin >> min;
	cout << "max: "; cin >> max;
	auto left = mlst.lower_bound(min);
	auto right = mlst.upper_bound(max);
	mlst.erase(left, right);
}

void plusMinMax(multiset<double>& mlst)
{
	multiset<double> temp;
	double min = *mlst.begin(), max = *mlst.begin();
	for (auto& i : mlst)
	{
		if (i < min) min = i;
		if (i > max) max = i;
	}
	for (auto& i : mlst)
		temp.insert(i + min + max);
	mlst.swap(temp);
}

void number1()
{
	multiset<double> mlst;
	int n;
	cout << "Введите какое количество записей сгенерировать: "; cin >> n;
	for (int i = 0; i < n; i++)
		mlst.insert((double((rand() % 10000)))/100 - 50);
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Найдем среднее арифмитическое значение и добавим его в контейнер." << endl;
	plus_mid(mlst);
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Зададим диапазон и удалим данные из контейнера в данном диапазоне." << endl;
	searchAndDel(mlst);
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
	cout << endl << "К каждому элементу контейнера добавим max и min элемент контейнера." << endl;
	plusMinMax(mlst);
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
}


