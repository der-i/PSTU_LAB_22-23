#include <iostream>
#include <string>
using namespace std;

int* Delete(int* arr, int& size)        //Функция удаления четных элементов из массива целых чисел.
{
    size /= 2;                          //Уменьшение длины массива в 2 раза
    int* new_arr = new int[size];       //Создание нового динамического массива.
    for (int i = 0; i < size; i++)      //Выбор четных элементов
    {
        new_arr[i] = arr[2 * i + 1];
    }
    delete[]arr;                        //Очищение динамической памяти из под старого массива.
    return new_arr;                     //Возвращение нового указателя на массив
}

string* Delete(string* str, int &size)  //Функция удаления четных слов из строки.
{
    size /= 2;                          //Логика полностью аналогична логике с массивом целых чисел.
    string* new_txt = new string[size];
    for (int i = 0; i < size; i++)
    {
        new_txt[i] = str[2 * i + 1];
    }
    delete[]str;
    return new_txt;
}

int main()
{
    int n = 6;
    int* arr = new int[n];              //Создание динамического массива для целых чисел
    for (int i = 0; i < n; i++)         
    {
        arr[i] = rand();                //заполнение рандомными элементами
        cout << arr[i] << "\t";
    }
    cout << endl;
    arr = Delete(arr, n);               //вызов функции
    for (int i = 0; i < n; i++)         //вывод
    {
        cout << arr[i] << "\t";
    }
    delete[]arr;                        //очищение памяти из под динамического массива
    cout << endl << "--------------------" << endl;

    int length = 6;             
    //string* text = new string[length]{ "Hello", "my", "name", "is", "Ilya" };
    string* text = new string[length]{ "Hello", "my", "name", "is", "Ilya", "!!!"};  //создание строки, сразу с заполнением
    for (int i = 0; i < length; i++)    //вывод
    {
        cout << text[i] << " ";
    }
    cout << endl;
    text = Delete(text, length);        //вызов функции
    for (int i = 0; i < length; i++)    //вывод
    {
        cout << text[i] << " ";
    }
    delete[]text;                       //очищение памяти из под динамического массива
	return 0;
}
