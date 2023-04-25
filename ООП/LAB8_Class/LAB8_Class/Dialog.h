#pragma once
#include "Event.h"
#include "Tree.h"

class Dialog : public Tree
{
public:
	Dialog();							//�����������/����������
	~Dialog();

	void HandleEvent (TEvent& event);	//���������� 
	void GetEvent(TEvent& event);		//�������� ������� 
	void Execute();						//������� ���� ��������� ������� 
	void ClearEvent (TEvent& event);	//�������� ������� 
	bool Valid();						//�������� �������� EndState
	void EndExec();						//��������� ������� ������ ������� 
protected:
	string command;
	int EndState;
};