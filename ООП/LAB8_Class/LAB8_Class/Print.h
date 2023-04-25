#pragma once
#include "Object.h"
class Print :
    public Object
{
public:
    Print();                        //конструктор/деструкторы
    Print(string name, string author);
    Print(const Print& copy);
    virtual ~Print();

    void Show();                //переопределенные методы ввода/вывода
    void Input();               

    string GetName() { return name; }           //сеттеры и геттеры
    string GetAuthor() { return author; }          
    void SetName(string name) { this->name = name; }
    void SetAuthor(string author) { this->author = author; }
    
    Print& operator=(const Print& copy);        //оператор присваивания

protected:
    string name;
    string author;
};

