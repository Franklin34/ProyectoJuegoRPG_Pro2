#ifndef OPTION_H
#define OPTION_H
#include <iostream>
#include "World.h"
#include "Player.h"
#include <stdio.h>
#include <windows.h> 

class Option
{
public:
	Option();
	~Option() {}
	Option(int&, int&, Player*, World*);
	std::string menuOption();
	void fail();
	virtual void Options(std::string) {}
	void setCoordenadaA(int);
	int getCoordenadaA();
	int getCoordenadaB();
	void roomName();
	Player* getPlayer();
	World* getWorld();
	void gotoxy(int x, int y) {
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}
private:
	int opc, end;
	int& a;
	int& b;
	bool salira;
	Player* player;
	World* world;
};

#endif