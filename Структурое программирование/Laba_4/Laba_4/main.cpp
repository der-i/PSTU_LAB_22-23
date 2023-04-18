#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void num(int& number, int size)             //Функция которая отвечает за то, чтобы массив сделать кольцом
{
    number = number % size;
}

void print(int* arr, int size, int k)       //Функция распечтывания масива с К-ого элемента
{
    num(k, size);                           //вызов функции приведения массива к кольцу
    int j;
    for (int i = 0, j = k; i < size; i++)   //массив начинается с 0 индекса, поэтому такая логика тут. К - может быть нулем.
    { 
        cout << arr[j] << endl;
        if (j + 1 == size)
            j = 0;
        else j++;
    }
}

void Sort(int* arr, int size)               //функция сортировки массива пузырьком
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 1; i < size; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);   //функция смены двух значений
                swapped = true;
            }
    
        }
    }
}

void Delete(int* arr, int& size)            //функция для удаления четных элементов из массива
{
    int j = 0;
    for (int i = 0; i < size; i+=2, ++j)
    {
        arr[j] = arr[i];
    }
    size = (size + 1) / 2;
}

void fill(int* arr,const int size)          //функция заполнения массива случайным числами до 100
{

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");            
    srand(time(NULL));                      //функция обнуляющая случайные числа
    int size, k;
    const int SIZE = 100;
    int arr[SIZE];                          //создание массива с запасом
    fill(arr, SIZE);                        //вызов функции заоплнения массива
    cout << "Определите длину массива кольца." << endl;
    cin >> size;
    cout << "Массив создан. С какого элемента его вывести?" << endl;
    cin >> k;
    cout << "Массив:" << endl;
    print(arr, size, k);                    //вывод массива
    cout << "Массив отсортирован." << endl;
    Sort(arr, size);                        //сортировка массива
    print(arr, size, k);                    //вывод массива
    cout << "Из массива удалены четные элементы." << endl;
    Delete(arr, size);                      //удаление четных эдементов масиива
    print(arr, size, k);                    //вывод
}
