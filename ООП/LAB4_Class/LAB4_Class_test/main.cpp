#include "Student.h"



int main()
{
	system("chcp 1251 >> null");

	cout << "Создание Person без параметров" << endl;
	Person pers;
	cout << "\nСоздание Person с параметрами" << endl;
	Person pers2("Ilya", 19);

	cout << "\nСоздание Student без параметров" << endl;
	Student st;
	cout << "\nСоздание Student с параметрами" << endl;
	Student st2("Andrew", 20, "Math", 3);
	cout << "\nКопирование предудущего объекта в новый." << endl;
	Student st3(st2);

	cout << "\nЗаполним поля первого объекта класса Student" << endl;
	string str;
	int a;
	cout << "Введите имя: "; cin >> str;
	cout << "Введите возраст: "; cin >> a;
	st.SetAge(a); st.SetName(str);
	cout << "Введите учебный предмет: "; cin >> str;
	cout << "Введите оценку по предмету: "; cin >> a;
	st.SetGrade(a); st.SetSubject(str);

	cout << endl << "Объекты классов: " << endl;
	cout << "1 oбъект класса Student: " << st << endl << endl;
	cout << "2 oбъект класса Student: " << st2 << endl << endl;
	cout << "3 oбъект класса Student: " << st3 << endl << endl;

	cout << "Проверим оценки студентов: " << endl << endl;
	if (st.CheckGrade()) str = "Положительная";
	else str = "Отрицательная";
	cout << "Студент 1: " << endl << st << endl << "Оценка: " << str << endl << endl;
	if (st2.CheckGrade()) str = "Положительная";
	else str = "Отрицательная";
	cout << "Студент 2: " << endl << st2 << endl << "Оценка: " << str << endl << endl;
	if (st3.CheckGrade()) str = "Положительная";
	else str = "Отрицательная";
	cout << "Студент 3: " << endl << st3 << endl << "Оценка: " << str << endl << endl;

	cout << endl << "Обратим внимание, что деструкторы вызываются обратно конструкторам." << endl;

	return 0;
}