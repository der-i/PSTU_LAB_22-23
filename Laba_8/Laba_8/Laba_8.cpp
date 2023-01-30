#include <iostream> //24 вариант
#include <stdio.h>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Student          //объявление структуры
{
    /*Student()
    {
        sname = "###";
        name = "###";
        patr = "###";
        pnum = "###";
        math = 0; inf = 0; UIR = 0;
    }
    void identif()
    {
        cout << "Введите фамилию cтудента.";  cin >> sname;
        cout << "Введите имя cтудента.";  cin >> name;
        cout << "Введите отчество cтудента.";  cin >> patr;
        cout << "Введите номер группы";  cin >> pnum;
        cout << "Введите оценку по матетематике";  cin >> math;
        cout << "Введите оценку по информатике";  cin >> inf;
        cout << "Введите оценку по УИР";  cin >> UIR;
    }*/


    string sname, name, patr;       //поля структуры
    string pnum, group;
    int math, inf, UIR;
};

void input(int n, string path)      //функция добавления в файл
{
    fstream fs;                     //создание потока ввода/вывода
    Student st;                     //создание структуры для шаблонного заполнения
    fs.open(path, fstream::out);    //открытие/создание файла для записи туда значений
    if (!fs.is_open())              //проверка на открытие
    {
        cout << "ERROR open file" << endl;
    }
    SetConsoleCP(1251);             //изменение кодировки консоли для коректной записи в файл
    for (int i = 0; i < n; i++)     //получение данных и запись в файл
    {
        cout << "Введите фамилию cтудента: ";  cin >> st.sname;
        cout << "Введите имя cтудента: ";  cin >> st.name;
        cout << "Введите отчество cтудента: ";  cin >> st.patr;
        cout << "Введите номер телефона: ";  cin >> st.pnum;
        cout << "Введите номер группы: ";  cin >> st.group;
        cout << "Введите оценку по матетематике: ";  cin >> st.math;
        cout << "Введите оценку по информатике: ";  cin >> st.inf;
        cout << "Введите оценку по УИР: ";  cin >> st.UIR;
        fs << st.name << " " << st.sname << " " << st.patr << " " << st.pnum << " " << st.group << " " << st.math << " " << st.inf << " " << st.UIR << "\n";
    }
    fs.close();                     //закрытие файла
    SetConsoleCP(866);              //изменение кодировки консоли
}

void clear_stud(string path, int& n)    //функция для отсеивания стужентов по срежнему баллу
{
    fstream fs, fs1;
    Student st;
    double sr, sr_st;
    cout << "Введите среднюю арифмитическую оценку для студента: "; cin >> sr;
    fs.open(path, fstream::in | fstream::out | fstream::app);   //открытие файла без удаления, для считывания и записи
    if (!fs.is_open())          //блок проверки
    {
        cout << "ERROR open first file" << endl;
    }
    fs1.open("new.txt", fstream::out);                          //открытие файла для записи
    if (!fs1.is_open())     //блок проверки на правильность открытия файла
    {
        cout << "ERROR open second file" << endl;
    }
    SetConsoleCP(1251);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        fs >> st.name >> st.sname >> st.patr >> st.pnum >> st.group >> st.math >> st.inf >> st.UIR;     //получение данных из файла
        sr_st = (double)(st.math + st.inf + st.UIR) / 3;            //вычисление ср. оценки
        if (sr_st >= sr)
        {
            fs1 << st.name << " " << st.sname << " " << st.patr << " " << st.pnum << " " << st.group << " " << st.math << " " << st.inf << " " << st.UIR << "\n";
        j++;                                        //запись в другой файл
        }
    }
    n = j;
    fs.close(); fs1.close();                        //закрытие файлов для дальнейшего корректного открытия
    fs1.open("new.txt", fstream::in | fstream::app);        //открытие файла без удаления для считывания
    fs.open(path, fstream::out);                        //открытие пустого файла для хаписи
    if (!fs.is_open())                              //блок проверки на корректность открытия
    {
        cout << "ERROR open first file" << endl;
    }
    if (!fs1.is_open())
    {
        cout << "ERROR open second file" << endl;
    }
    for (int i = 0; i < n; i++)     //блок переписывания файлов
    {
        fs1 >> st.name >> st.sname >> st.patr >> st.pnum >> st.group >> st.math >> st.inf >> st.UIR;
        fs << st.name << " " << st.sname << " " << st.patr << " " << st.pnum << " " << st.group << " " << st.math << " " << st.inf << " " << st.UIR << "\n";
    }
    fs.close();             //закрытие файлов
    fs1.close();
    SetConsoleCP(866);
}

void add(string path, int &n)       //функция для добавления после заданной фамилии.
{
    string surname;                 
    SetConsoleCP(1251);
    cout << "Введите фамилию для поиска: "; cin >> surname;
    fstream fs, fs1;                //создание потоков для работы с файлами
    Student st;                     //создание структуры как шаблона
    fs.open(path, fstream::in | fstream::app);      //открытие файла для считывания без удаления
    if (!fs.is_open())
    {
        cout << "ERROR open first file" << endl;
    }
    fs1.open("new.txt", fstream::out);              //открытие файла для записи
    if (!fs1.is_open()) 
    {
        cout << "ERROR open second file" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        fs >> st.name >> st.sname >> st.patr >> st.pnum >> st.group >> st.math >> st.inf >> st.UIR;  //считывание из исходного файла
        fs1 << st.name << " " << st.sname << " " << st.patr << " " << st.pnum << " " << st.group << " " << st.math << " " << st.inf << " " << st.UIR << "\n";
        if (st.sname == surname)        //записывание в файл (сверху)
        {                               //это блок добавления нового студента в файл
            cout << "Фамилия найдена, введите данные студента." << endl;
            cout << "Введите фамилию cтудента: ";  cin >> st.sname;
            cout << "Введите имя cтудента: ";  cin >> st.name;
            cout << "Введите отчество cтудента: ";  cin >> st.patr;
            cout << "Введите номер телефона: ";  cin >> st.pnum;
            cout << "Введите номер группы: ";  cin >> st.group;
            cout << "Введите оценку по матетематике: ";  cin >> st.math;
            cout << "Введите оценку по информатике: ";  cin >> st.inf;
            cout << "Введите оценку по УИР: ";  cin >> st.UIR;
            fs1 << st.name << " " << st.sname << " " << st.patr << " " << st.pnum << " " << st.group << " " << st.math << " " << st.inf << " " << st.UIR << "\n";
            n++;
        }
    }
    fs.close(); fs1.close();            //закрытие файлов для дальнейшего коректного открытия
    fs1.open("new.txt", fstream::in | fstream::app);        //открытие файла для чтения без удаления
    fs.open(path, fstream::out);                            //открытие чистого файла для записи
    if (!fs.is_open())
    {
        cout << "ERROR open first file" << endl;
    }
    if (!fs1.is_open())
    {
        cout << "ERROR open second file" << endl;
    }
    for (int i = 0; i < n; i++)         //переписывание данных из одного файла в другой
    {
        fs1 >> st.name >> st.sname >> st.patr >> st.pnum >> st.group >> st.math >> st.inf >> st.UIR;
        fs << st.name << " " << st.sname << " " << st.patr << " " << st.pnum << " " << st.group << " " << st.math << " " << st.inf << " " << st.UIR << "\n";
    }
    fs.close();                     //закрытие файлов
    fs1.close();
    SetConsoleCP(866);

}

int main()
{
    setlocale(LC_ALL, "ru"); 
    int kol;                    
    string path = "test.txt";           //задание названия исходного файла
    cout << "Введите какое количество элементов внести: ";
    cin >> kol;
    //input(kol, path);                 //вызов функции заполнения
    clear_stud(path, kol);              //вызов функции сортировки
    //add(path, kol);                   //вызов функции добавления
}

    