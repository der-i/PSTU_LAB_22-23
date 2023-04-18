#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int shet(int(*arr)[4], int size)
{
    int max = arr[0][0], k = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i][i] > max)
            max = arr[i][i];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                if (arr[i][j] > max)
                {
                    k++;
                }
            }
        }
    }
    return k;
}

void fill(int (*arr) [4], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            arr[i][j] = rand() % 100;
        }
    }
}


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    const int SIZE = 4;
    int arr[SIZE][SIZE];
    fill(arr, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Элементов двумерного массива больше max элемента главное диагонали: " << shet(arr, SIZE) << endl;
    return 0;
}
