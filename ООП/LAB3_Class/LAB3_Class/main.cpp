#include "Pair.h"


int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Создание 3 объектов класса." << endl;
    Pair a, b, c;

    cout << "Введите пару чисел (int) (double): ";
    cin >> a;
    cout << "Введите пару чисел (int) (double): ";
    cin >> b;

    cout << "Объекта а = " << a << endl;
    cout << "Объекта b = " << b << endl;

    cout << "В объект \"с\" присвоим: (a++)+b" << endl;
    c = (a++) + b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl << endl;
    cout << "В объект \"с\" присвоим: a - b" << endl;
    c = a - b;
    cout << "c = " << c << endl << endl;

    cout << "c + 1 = " << c + 1 << endl;
    cout << "1 + c = " << 1 + c << endl;
    cout << "c + 2.34 = " << c + 2.34 << endl;
    cout << "2.34 + c = " << 2.34 + c << endl << endl;

    cout << "++c = " << ++c << endl;
    cout << "c = " << c << endl << endl;

    cout << "c++ = " << c++ << endl;
    cout << "c = " << c << endl << endl;

    return 0;
}
