#include "Tree.h"
#include "Dialog.h"
#include "Event.h"
#include "Magazin.h"
#include "Object.h"
#include "Print.h"
#include <Windows.h>

int main() 
{
	system("chcp 1251 >> null");
	cout << "m: ������� ������\n";
	cout << "+: �������� �������\n";
	cout << "-: ������� �������\n";
	cout << "s: ���������� � ������ ������\n";
	cout << "z: ���������� � ��������� ��������� ������\n";
	cout << "q: ����� ������\n";
	Dialog D;
	D.Execute();
	return 0;
}