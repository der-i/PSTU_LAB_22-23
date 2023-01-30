//#include <stdio.h>
//
//#include <iostream>
//
//#include <iomanip>
//
//#include <conio.h>
//
//#include <windows.h>
//
//using namespace std;
//
///*
//
//Структура "Информация":
//
//носитель;
//
//объем;
//
//название;
//
//автор.
//
//Удалить первый элемент с заданным объемом информации, добавить элемент перед элементом с указанным номером.
//
//*/
//
//char* Rus(const char* text);
//
//struct inform //структура
//
//{
//
//	char nos[20];
//
//	int obyom;
//
//	char nazv[12];
//
//	char autor[15];
//
//};
//
//void input(int n);
//
//void add(int n);
//
//void del(int n);
//
//void output();
//
//int main(int argc, char** argv)
//
//{
//
//	int kol;
//
//	cout << Rus("Сколько элементов запишем? ");
//
//	cin >> kol;
//
//	cout << endl;
//
//	input(kol); //вводим элементы
//
//	output(); //печатаем
//
//	cout << endl << Rus("Введите объем носителя, который хотите удалить: ");
//
//	int k;
//
//	cin >> k;
//
//	clrscr(); //очищаем экран
//
//	del(k); //удаляем нужный элемент
//
//	output(); //печатаем
//
//	cout << endl << Rus("Āāåäčņå ķīģåš, ļåšåä źīņīšūģ äīįąāčņü ķīāūé żėåģåķņ: ");
//
//	cin >> k;
//
//	add(k); //добавляем элемент на нужную позицию
//
//	output(); //печатаем
//
//	getch();
//
//	return 0;
//
//}
//
////функция для добавления элемента перед элементом с заданным номером
//
//void add(int n)
//
//{
//
//	FILE* f, * f1;
//
//	inform b; //создаем структуру
//
//	f = fopen("data.txt", "r"); //открываем файл для чтения˙
//
//	f1 = fopen("data2.txt", "w"); //открываем файл для записи
//
//	for (int i = 0; fread(&b, sizeof(b), 1, f);i++)
//
//	{
//
//		// fread(&b,sizeof(b),1,f);
//
//		if (i == n - 1) //встаем на нужную позицию
//
//		{
//
//			inform k; //создаем структуру
//
//			cout << Rus("Введите носитель: "); cin >> k.nos;
//
//			cout << Rus("Введите объем: "); cin >> k.obyom;
//
//			cout << Rus("Введите название: "); cin >> k.nazv;
//
//			cout << Rus("Введите автора: "); cin >> k.autor;
//
//			cout << endl;
//
//			fwrite(&k, sizeof(k), 1, f1); //заносим структуру в файл
//
//		}
//
//		fwrite(&b, sizeof(b), 1, f1);
//
//	}
//
//	fclose(f);
//
//	fclose(f1);
//
//	f = fopen("data.txt", "w");
//
//	f1 = fopen("data2.txt", "r");
//
//	while (fread(&b, sizeof(b), 1, f1))
//
//	{
//
//		fwrite(&b, sizeof(b), 1, f);
//
//	}
//
//	fclose(f);
//
//	fclose(f1);
//
//}
//
////функция для заполнения структур
//
//void input(int n)
//
//{
//
//	inform b; //создаем структуру
//
//	FILE* f;
//
//	f = fopen("data.txt", "w"); //открываем файл для записи
//
//	for (int i = 0; i < n; i++) //заполняем нужное количество раз
//
//	{
//
//		cout << Rus("Вводим структуру: ") << i + 1 << endl;
//
//		cout << Rus("Введите носитель: "); cin >> b.nos;
//
//		cout << Rus("Введите объем: "); cin >> b.obyom;
//
//		cout << Rus("Введите название: "); cin >> b.nazv;
//
//		cout << Rus("Введите автора: "); cin >> b.autor;
//
//		cout << endl;
//
//		fwrite(&b, sizeof(b), 1, f); //заносим структуру в файл
//
//	}
//
//	fclose(f);
//
//}
//
////функция для удаления элемента с нужным объемом
//
//void del(int n)
//
//{
//
//	FILE* f, * f1;
//
//	inform b;
//
//	f = fopen("data.txt", "r"); //открываем файл для чтения
//
//	f1 = fopen("data2.txt", "w"); //открываем файл для записи
//
//	for (int i = 0; fread(&b, sizeof(b), 1, f);i++) //начинаем двигаться по файлу
//
//	{
//
//		//fread(&b,sizeof(b),1,f);
//
//		if (b.obyom == n) continue; //находим нужный элемент, не записываем его, пропускаем
//
//		fwrite(&b, sizeof(b), 1, f1); //переписываем элемент
//
//	}
//
//	fclose(f);
//
//	fclose(f1);
//
//	f = fopen("data.txt", "w");
//
//	f1 = fopen("data2.txt", "r");
//
//	while (fread(&b, sizeof(b), 1, f1))
//
//	{
//
//		fwrite(&b, sizeof(b), 1, f);
//
//	}
//
//	fclose(f);
//
//	fclose(f1);
//
//}
//
////функция для печати на экран
//
//void output()
//
//{
//
//	inform b;
//
//	FILE* f;
//
//	f = fopen("data.txt", "r"); //открываем файл для чтения
//
//	//оформляем вывод таблицей
//
//	cout << setw(3) << Rus("Номер");
//
//	cout << setw(10) << Rus("носитель");
//
//	cout << setw(7) << Rus("объем");
//
//	cout << setw(10) << Rus("название");
//
//	cout << setw(10) << Rus("автор");
//
//	cout << endl;
//
//	for (int i = 0; fread(&b, sizeof(b), 1, f); i++)
//
//	{
//
//		cout << setw(3) << i + 1;
//
//		cout << setw(10) << b.nos;
//
//		cout << setw(7) << b.obyom;
//
//		cout << setw(10) << b.nazv;
//
//		cout << setw(10) << b.autor;
//
//		cout << endl;
//
//	}
//
//	fclose(f);
//
//}
//
//char bufrus[256];
//
//char* Rus(const char* text)
//
//{
//
//	CharToOem(text, bufrus);
//
//	return bufrus;
//
//}