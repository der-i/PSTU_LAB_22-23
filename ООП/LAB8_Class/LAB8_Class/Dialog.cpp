#include "Dialog.h"


Dialog::Dialog() :Tree()
{
	command = "m: ������� ������\n+: �������� �������\n-: ������� �������\ns: ���������� � ������ ������\nz: ���������� � ��������� ��������� ������\nq: ����� ������\n\n";
	EndState = 0;
}

Dialog::~Dialog() {}

void Dialog::GetEvent(TEvent& event) 
{
	string OpInt = "m+-szq"; //������ �������� ���� �������� 
	string s;
	char code;
	cout << '>';
	cin >> s; code = s[0];		
	if (OpInt.find(code) >= 0)		//�������� �� ������ ����� ��������
	{ 
		event.what = evMessage;
		switch (code) 
		{
		case 'm': event.command = Event::cmMake; break;		//������� ������
		case '+': event.command = Event::cmAdd; break;		//�������� ������ � ������ 
		case '-': event.command = Event::cmDel; break;		//������� ������ �� ������ 
		case 's': event.command = Event::cmShow; break;		//�������� ������ 
		case 'z': event.command = Event::cmGet; break;
		case 'q': event.command = Event::cmQuit; break;		//����� ������
		}
	}
	else event.what = evNothing;//������ ������� 
}

void Dialog::Execute() 
{
	TEvent event;
	do 
	{
		EndState = 0;
		GetEvent(event); //�������� ������� 
		HandleEvent(event); //���������� �������
	} while (Valid()); 
}

bool Dialog::Valid()
{
	return EndState == 0;
}

void Dialog::ClearEvent(TEvent & event) 
{
	event.what = evNothing;//������ ������� 
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
		case Event::cmMake:				//�������� ������ 
			cout << "Enter size: ";
			cin >> size;
			beg = new Object * [size];	//�������� ������ ��� ������ ���������� 
			cur = 0;					//������� �������
			ClearEvent(event);			//������� ������� 
			break;
		case Event::cmAdd:				//���������� 
			Add();
			ClearEvent(event);
			break;
		case Event::cmDel:
			Del();						//�������� 
			ClearEvent(event);
			break;
		case Event::cmShow:
			Show();						//�������� 
			system("pause");
			ClearEvent(event);
			break;
		case Event::cmQuit:
			EndExec();					//����� 
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

