#pragma once
#include "Print.h"
class Magazin :
    public Print
{
public:
    Magazin();                                      //������������ � ����������
    Magazin(string name, string author, int pages);
    Magazin(const Magazin& copy);
    ~Magazin();

    int GetPages() { return pages; }          //�������/�������
    void SetPages(int P) { pages = P; }

    string GetName() { return name; }       //���������������� ������
    void Show();
    void Input();

    Magazin& operator=(const Magazin& other);  //�������� ������������

protected:
    int pages;
};