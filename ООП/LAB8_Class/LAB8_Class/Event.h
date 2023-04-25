#pragma once

enum Event
{
	evNothing = 0,	//пустое событие 
	evMessage = 100,//непустое событие 
	cmAdd = 1,		// + 
	cmDel = 2,		// -
	cmGet = 3,		// z 
	cmShow = 4,		// s
	cmMake = 5,		// m
	cmQuit = 101	// q
};

struct TEvent {
	int what;    //наличие события 
	int command; //тип комманды
};