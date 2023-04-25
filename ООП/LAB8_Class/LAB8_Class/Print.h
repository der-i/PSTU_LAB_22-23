#pragma once
#include "Object.h"
class Print :
    public Object
{
public:
    Print();                        //�����������/�����������
    Print(string name, string author);
    Print(const Print& copy);
    virtual ~Print();

    void Show();                //���������������� ������ �����/������
    void Input();               

    string GetName() { return name; }           //������� � �������
    string GetAuthor() { return author; }          
    void SetName(string name) { this->name = name; }
    void SetAuthor(string author) { this->author = author; }
    
    Print& operator=(const Print& copy);        //�������� ������������

protected:
    string name;
    string author;
};

