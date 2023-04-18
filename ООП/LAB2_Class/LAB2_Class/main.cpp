#include "Class.h"




int main()
{
	system("chcp 1251 >> null");
	string name;
	double salary;
	int percent;
	Salary sal;
	cout << "1 объект: " << "\nИмя: " << sal.GetName() << "\nЗаработная плата: " << sal.GetSalary() << "\nПроцент премии: " << sal.GetPercent() << endl << endl;		//вывод объекта
	cout << "Введите имя: "; cin >> name;		//установка объекту новых полей
	cout << "Введите оклад: "; cin >> salary;
	cout << "Введите процент премии: "; cin >> percent;
	Salary sal2(name, salary, percent);		//конструктор с параметрами
	cout << "2 объект: " << "\nИмя: " << sal2.GetName() << "\nЗаработная плата: " << sal2.GetSalary() << "\nПроцент премии: " << sal2.GetPercent() << endl << endl;		//вывод объекта
	Salary sal3(sal2);		//отработка конструктора копирования
	cout << "3 объект: " << "\nИмя: " << sal3.GetName() << "\nЗаработная плата: " << sal3.GetSalary() << "\nПроцент премии: " << sal3.GetPercent() << endl << endl;		//вывод объекта
	

    return 0;
}
