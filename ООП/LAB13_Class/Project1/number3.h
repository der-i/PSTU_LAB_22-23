#pragma once
#include"header.h"

static int shet = 0;		//генератор ключей

void print(map<int, Pair>& mp)		//функция вывода словаря
{
	cout << endl << "Полученный map:" << endl;
	for (auto& i : mp)
		cout << i.first << ". " << i.second << endl;
}

void plus_mid(map<int, Pair>& mp)	//функция добавляет среднее арифмитическое
{
	Pair midl(0, 0);				//НО!!!
	for (auto& i : mp)				//так как с контейнером map не работает библилтека algorithm, точнее большинство методов
		midl = midl + i.second;		//тут мы все делаем ручками через обычные циклы
	mp.emplace(++shet, midl / mp.size());	//впринципе так в номере 3 везде
}

void searchAndDel(map<int, Pair>& mp)		//удаление по ключу
{											//ничего интересного, просто вызов метода
	int y;
	cout << "Введите ключ для удаления (int): "; cin >> y;
	mp.erase(y);
}

void plusMinMax(map<int, Pair>& mp)			//добавление к каждому элементу минимального и максимального значения
{
	Pair min = min_element(mp.begin(), mp.end())->second;		//находим минимальный и максимальный элемент
	Pair max = max_element(mp.begin(), mp.end())->second;		//использую функцию библиотеки algorithm
	cout << "min: " << min << endl << "max: " << max << endl;	//а дальше просто циклом проходим и добавляем
	for (auto& i : mp)
		i.second = i.second + max + min;			//синтаксис такой, потому что += у pair не перегружен
}

void myfind(map<int, Pair>& mp)			//мой поиск. Просто поиск по ключу через метод контейнера map 
{
	int a;
	cout << "Введите ключ для поиска: "; cin >> a;
	auto it = mp.find(a);
	if (it != mp.end())
		cout << "Ключ: " << a << "   Значение:" << it->second << endl;
	else cout << "Элемента с таким ключом нет в словаре." << endl;
}

void printsortup(map<int, Pair>& mp)		//Якобы сортировка, но не так.
{											//map - бинарное дерево и файлы там отсортированы, поэтому мы просто ключами делаем pair и выводим наш контейнер
	int a = 0;
	map<Pair, int> temp;
	for (auto i = mp.begin(); i != mp.end(); ++i)
		temp.emplace(i->second, i->first);
	for (auto& i : temp)
		cout << ++a <<".\t" << i.first << "  \tКлюч: " << i.second << endl;
}

void printsortdown(map<int, Pair>& mp)		//здесь тоже самое что и сверху, только выводим контейнер наоборот
{
	int a = 0;
	map<Pair, int> temp;	
	for (auto i = mp.begin(); i != mp.end(); ++i)
		temp.emplace(i->second, i->first);
	for (auto i = temp.crbegin(); i != temp.crend(); i++)
		cout << ++a << ".\t" << i->first << "  \tКлюч: " << i->second << endl;

	

}

void number3()		//функция, которая управляет всем
{					//вызывает функции выше и пишет сообщения.
	Pair p;			//чтобы не спамить в main
	map<int, Pair> mp;
	int n;
	cout << "Введите какое количество записей сгенерировать: "; cin >> n;
	for (int i = 0; i < n; i++)
		mp.emplace(++shet, p.randomGener());
	cout << "Тип вывода:\nКлюч. Значение" << endl;
	print(mp);
	cout << endl << "Найдем среднее арифмитическое значение и добавим его в контейнер." << endl;
	plus_mid(mp);
	print(mp);
	cout << endl << "Зададим диапазон и удалим данные из контейнера в данном диапазоне." << endl;
	searchAndDel(mp);
	print(mp);
	cout << endl << "К каждому элементу контейнера добавим max и min элемент контейнера." << endl;
	plusMinMax(mp);
	print(mp);
	cout << endl << "Найдем в данном контейнере елемент по его ключу." << endl;
	myfind(mp);
	cout << endl << "Отсортируем контейнер по возрастанию значений." << endl;
	printsortup(mp);
	cout << endl << "Отсортируем контейнер по убыванию значений." << endl;
	printsortdown(mp);
}