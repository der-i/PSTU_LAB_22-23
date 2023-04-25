#pragma once
#include "Print.h"
class Magazin :
    public Print
{
public:
    Magazin();                                      //конструкторы и деструктор
    Magazin(string name, string author, int pages);
    Magazin(const Magazin& copy);
    ~Magazin();

    int GetPages() { return pages; }          //сеттеры/геттеры
    void SetPages(int P) { pages = P; }

    string GetName() { return name; }       //переопределенные методы
    void Show();
    void Input();

    Magazin& operator=(const Magazin& other);  //оператор присваивания

protected:
    int pages;
};