#pragma once

enum Event
{
	evNothing = 0,	//������ ������� 
	evMessage = 100,//�������� ������� 
	cmAdd = 1,		// + 
	cmDel = 2,		// -
	cmGet = 3,		// z 
	cmShow = 4,		// s
	cmMake = 5,		// m
	cmQuit = 101	// q
};

struct TEvent {
	int what;    //������� ������� 
	int command; //��� ��������
};