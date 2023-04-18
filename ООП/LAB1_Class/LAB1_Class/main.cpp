#include "class.h"

MyClass Make_MyClass(double first, int second)
{
	if (second < 0)
		exit(-1);
	MyClass temp(first, second);
	return temp;
}


int main()
{
	int b; double a;
	cout << "Enter the first element of the sequence (double): ";
	cin >> a;
	cout << "Enter constant sequence ratio (unsigned int): ";
	cin >> b;
	MyClass mc = Make_MyClass(a, b);
	mc.Show();
	int j;
	cout << "Enter index (j) the sequence "; cin >> j;
	cout << "Value j-element " << mc.element(j) << endl;
	cout << "Set new data for sequence" << endl;
	mc.Read();
	mc.Show();
	cout << "Enter index (j) the sequence "; cin >> j;
	cout << "Value j-element " << mc.element(j) << endl;


	cout << "Good luck" << endl;

	return 0;
}