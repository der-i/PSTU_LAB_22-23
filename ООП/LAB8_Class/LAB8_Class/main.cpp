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
	cout << "m: Создать группу\n";
	cout << "+: Добавить элемент\n";
	cout << "-: Удалить элемент\n";
	cout << "s: Информация о членах группы\n";
	cout << "z: Информация о названиях элементов группы\n";
	cout << "q: Конец работы\n";
	Dialog D;
	D.Execute();
	return 0;
}