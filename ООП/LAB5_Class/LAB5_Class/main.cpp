#include "Student.h"
#include "Vector.h"

int main()
{
	system("chcp 1251 >> null");
	Person pers("Ilya", 19);
	Student stud("Andrew", 20, "Math", 3), stud2;
	cin >> stud2;
	Vector v(2);
	Object* a = &pers; v.add(a);
	a = &stud; v.add(a);
	a = &stud2; v.add(a);
	

	cout << endl;
	cout << v;
	

	cout << endl << endl << endl;
	cout << "Итерирование с помощью оператора []" << endl;
	for (int i = 0; i <v.length(); i++)
	{
		v[i]->Show(); cout << endl;
	}
	return 0;
}