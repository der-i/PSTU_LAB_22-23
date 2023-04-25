#include "Dialog.h"


Dialog::Dialog() :Tree()
{
	command = "m: Создать группу\n+: Добавить элемент\n-: Удалить элемент\ns: Информация о членах группы\nz: Информация о названиях элементов группы\nq: Конец работы\n\n";
	EndState = 0;
}

Dialog::~Dialog() {}

void Dialog::GetEvent(TEvent& event) 
{
	string OpInt = "m+-szq"; //строка содержит коды операций 
	string s;
	char code;
	cout << '>';
	cin >> s; code = s[0];		
	if (OpInt.find(code) >= 0)		//является ли символ кодом операции
	{ 
		event.what = evMessage;
		switch (code) 
		{
		case 'm': event.command = Event::cmMake; break;		//создать группу
		case '+': event.command = Event::cmAdd; break;		//добавить объект в группу 
		case '-': event.command = Event::cmDel; break;		//удалить объект из группы 
		case 's': event.command = Event::cmShow; break;		//просмотр группы 
		case 'z': event.command = Event::cmGet; break;
		case 'q': event.command = Event::cmQuit; break;		//конец работы
		}
	}
	else event.what = evNothing;//пустое событие 
}

void Dialog::Execute() 
{
	TEvent event;
	do 
	{
		EndState = 0;
		GetEvent(event); //получить событие 
		HandleEvent(event); //обработать событие
	} while (Valid()); 
}

bool Dialog::Valid()
{
	return EndState == 0;
}

void Dialog::ClearEvent(TEvent & event) 
{
	event.what = evNothing;//пустое событие 
	cout << "\033[2J\033[1;1H";
	cout << command;
}

void Dialog::EndExec()
{
	EndState = 1;
}

void Dialog::HandleEvent(TEvent& event) 
{
	if (event.what == evMessage) 
	{
		switch (event.command) 
		{
		case Event::cmMake:				//создание группы 
			cout << "Enter size: ";
			cin >> size;
			beg = new Object * [size];	//выделяем память под массив указателей 
			cur = 0;					//текущая позиция
			ClearEvent(event);			//очищаем событие 
			break;
		case Event::cmAdd:				//добавление 
			Add();
			ClearEvent(event);
			break;
		case Event::cmDel:
			Del();						//удаление 
			ClearEvent(event);
			break;
		case Event::cmShow:
			Show();						//просмотр 
			system("pause");
			ClearEvent(event);
			break;
		case Event::cmQuit:
			EndExec();					//выход 
			ClearEvent(event);
			break;
		case Event::cmGet:
			GetName();
			system("pause");
			ClearEvent(event);
			break;
		};
	};
}

