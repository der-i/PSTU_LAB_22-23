#pragma once
#include "Event.h"
#include "Tree.h"

class Dialog : public Tree
{
public:
	Dialog();							//конструктор/деструктор
	~Dialog();

	void HandleEvent (TEvent& event);	//обработчик 
	void GetEvent(TEvent& event);		//получить событие 
	void Execute();						//главный цикл обработки событий 
	void ClearEvent (TEvent& event);	//очистить событие 
	bool Valid();						//проверка атрибута EndState
	void EndExec();						//обработка события «конец работы» 
protected:
	string command;
	int EndState;
};