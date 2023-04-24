#pragma once
#include"header.h"

template<typename T>
class List {
public:
    List() { _size = mlst.size(); } //конструктор
    void add(T value);              //метод добавлени€ элементов
    void print();                   //метод вывода списка в консоль
    void plus_mid();                //добавить в список элемент со средним арифмитическим значением
    void searchAndDel();            //поиск и удаление данных в заданном диапазоне
    void plusMinMax();              //добавлениек каждому элементу максимального и минимального элементов
    int size() { return _size; }    //размер
private:
    int _size;
    multiset<T> mlst;
};




template<typename T>
void List<T>::add(T value) {
    mlst.insert(value);
    ++_size;
}

template<typename T>
void List<T>::print() {
    int n = 0;
    for (const auto& elem : mlst) {
        cout << ++n << ". " <<  elem << endl;
    }
    cout << endl;
}

template<typename T>
inline void List<T>::plus_mid()
{
    T midl = 0;
    for (auto& i : mlst)
        midl = midl + i;
    mlst.insert(midl / mlst.size());
    ++_size;
}

template<typename T>
inline void List<T>::searchAndDel()
{
    T min, max;
    cout << "¬ведите диапазон дл€ поиска:\n" << "min: "; cin >> min;
    cout << "max: "; cin >> max;
    auto left = mlst.lower_bound(min);
    auto right = mlst.upper_bound(max);
    mlst.erase(left, right);
    _size = mlst.size();
}

template<typename T>
inline void List<T>::plusMinMax()
{
    multiset<T> temp;
    T min = *mlst.begin(), max = *mlst.begin();
    for (auto& i : mlst)
    {
        if (i < min) min = i;
        if (!(i < max)) max = i;
    }
    for (auto& i : mlst)
        temp.insert(i + min + max);
    mlst.swap(temp);
}